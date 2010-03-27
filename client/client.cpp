#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h> 
#include <SDL/SDL_image.h>

#include "../common/model/Tower.h"
#include "model/Blueprint.h"
#include "view/Drawer.h"
#include "model/geometrical_objects.h"

using namespace std;

#define FIELD_SIZE 321

//current map - 2D-Array of 16*16 fields (20x20 pixel each)
int current_map[16][16];

/**
 * load texture from JPEG/PNG-file using SDL_image
 */
GLuint load_texture(const char* file)
{
    SDL_Surface* surface = IMG_Load(file);
    GLuint texture;
    glPixelStorei(GL_UNPACK_ALIGNMENT,4);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    SDL_PixelFormat *format = surface->format;
    if (format->Amask)
    {
        gluBuild2DMipmaps(GL_TEXTURE_2D, 4,
            surface->w, surface->h, GL_RGBA,GL_UNSIGNED_BYTE, surface->pixels);
    }
    else
    {
        gluBuild2DMipmaps(GL_TEXTURE_2D, 3,
            surface->w, surface->h, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);
    }
    SDL_FreeSurface(surface);
    return texture;
}

void add_texture(GLuint texture) {
    glBindTexture( GL_TEXTURE_2D, texture );

    glBegin( GL_QUADS );
    
        // Top-left vertex (corner)
        glTexCoord2i( 0, 0 );
        glVertex3f( 0, 0, 0 );
        
        // Bottom-left vertex (corner)
        glTexCoord2i( 1, 0 );
        glVertex3f( FIELD_SIZE, 0, 0 );
    
        // Bottom-right vertex (corner)
        glTexCoord2i( 1, 1 );
        glVertex3f( FIELD_SIZE, FIELD_SIZE, 0 );
    
        // Top-right vertex (corner)
        glTexCoord2i( 0, 1 );
        glVertex3f( 0, FIELD_SIZE, 0 );
    glEnd();
}

/**
 * draw creep #1 - Mercury
 */
void draw_mercury(int x, int y) {
    glColor3f(0.0f,1.0f,0.0f);
    //left arrow
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x+5, y+5);
    glVertex2f(x+4, y+5);
    glVertex2f(x, y+9);
    glEnd();
    
    //right arrow
    glBegin(GL_LINES);
    glVertex2f(x+4, y);
    glVertex2f(x+9, y+5);
    glVertex2f(x+8, y+5);
    glVertex2f(x+4, y+9);
    glEnd();
}

/*
 * draw creep #2 - Mako
 */
void draw_mako(int x, int y) {
    glColor3f(1.0f,1.0f,1.0f);
    //cross in the middle
    glBegin(GL_LINES);
    glVertex2f(x+7, y+3);
    glVertex2f(x+7, y+10);
    glVertex2f(x+3, y+7);
    glVertex2f(x+10, y+7);
    glEnd();
    
    //upper circle
    glBegin(GL_LINE_STRIP);
    glVertex2f(x+6, y+4);
    glVertex2f(x+6, y+0);
    glVertex2f(x+8, y+1);
    glVertex2f(x+8, y+3);
    glEnd();
    
    //left circle
    glBegin(GL_LINE_STRIP);
    glVertex2f(x+4, y+6);
    glVertex2f(x+0, y+6);
    glVertex2f(x+1, y+8);
    glVertex2f(x+3, y+8);
    glEnd();
    
    //right circle
    glBegin(GL_LINE_STRIP);
    glVertex2f(x+9, y+6);
    glVertex2f(x+13, y+6);
    glVertex2f(x+12, y+8);
    glVertex2f(x+10, y+8);
    glEnd();

    //bottom circle
    glBegin(GL_LINE_STRIP);
    glVertex2f(x+6, y+9);
    glVertex2f(x+6, y+13);
    glVertex2f(x+8, y+12);
    glVertex2f(x+8, y+10);
    glEnd();
}

/**
 * draw basic tower
 */
void draw_basic_tower(int x, int y) {
    x+=2;
    y+=2;
    glColor3f(0.0f,1.0f,0.0f);
    //draw a "V" with line
    glBegin(GL_LINE_STRIP);
    glVertex2f(x+0, y+0);
    glVertex2f(x+17, y+0);
    glVertex2f(x+8, y+17);
    glVertex2f(x+0, y+0);
    glEnd();
    //...and the other side
    glBegin(GL_LINE_STRIP);
    glVertex2f(x+0, y+17);
    glVertex2f(x+17, y+17);
    glVertex2f(x+8, y+0);
    glVertex2f(x+0, y+17);
    glEnd();
}

/**
 * draw slow tower
 */
void draw_slow_tower(int x, int y) {
    glColor3f(0.0f,1.0f,0.0f);
    //draw a star
    glBegin(GL_LINE_STRIP);
    glVertex2f(x+9, y+0);
    glVertex2f(x+16, y+19);
    glVertex2f(x+0, y+8);
    glVertex2f(x+19, y+8);
    glVertex2f(x+3, y+19);
    glVertex2f(x+9, y+0);
    glEnd();

}

/**
 * draw splash tower
 */
void draw_splash_tower(int x, int y) {
    x+=4;
    y+=2;
    glColor3f(0.0f,1.0f,0.0f);
    
    glBegin(GL_LINE_STRIP);
    glVertex2f(x+0, y+0);
    glVertex2f(x+16, y+1);
    glVertex2f(x+16, y+17);
    glVertex2f(x+0, y+17);
    glVertex2f(x+0, y+0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(x+4, y+4);
    glVertex2f(x+12, y+5);
    glVertex2f(x+12, y+13);
    glVertex2f(x+4, y+13);
    glVertex2f(x+4, y+4);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    glVertex2f(x+6, y+6);
    glVertex2f(x+10, y+7);
    glVertex2f(x+10, y+11);
    glVertex2f(x+6, y+11);
    glVertex2f(x+6, y+6);
    glEnd();
    
    glBegin(GL_POINTS);
    glVertex2f(x+8, y+9);
    glEnd();
}

void load_config(char * filename) {
    ifstream file( filename );
    
    string s;
    while( getline(file,s) ) {
        
        if (s.compare(0, 2, string("")) == 1)
            //newline - next section
            cout << "newline" << endl;
        else if (s.compare(0, 1, string("#")) == 0)
            //ignore #
            continue;
        else
            cout << s << endl;
    };
}

int main(int argc, char ** argv)
{
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        printf("SDL konnte nicht initialisiert werden: %s\n", SDL_GetError());
        exit(1);
    }
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    SDL_Surface * display = SDL_SetVideoMode( 800, FIELD_SIZE*2, 16, SDL_OPENGL );
    if ( display == NULL )
    {
        printf("Konnte kein Fenster oeffnen: %s\n", SDL_GetError());
        exit(1);
    }
    
    glClearColor( 0, 0, 0, 0 );
	
	glEnable( GL_TEXTURE_2D ); // Need this to display a texture
	
	glViewport( 0, 0, 800, FIELD_SIZE*2 );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    glOrtho( 0, 800, FIELD_SIZE*2, 0, -1, 1 );
    
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    load_config("maps/map_blue.map");
    
    // Load the OpenGL texture
    GLuint texture = load_texture("maps/map_blue.jpg");
    
    glClear( GL_COLOR_BUFFER_BIT );

    glPushMatrix(); //Save matrix
    add_texture(texture);

    glTranslatef(FIELD_SIZE*2, 0, 0); //Position Sprite
    glRotatef(90, 0, 0, 1); //Rotate Sprite
    add_texture(texture);
    glRotatef(-90, 0, 0, 1); //reset rotation
    glTranslatef(-FIELD_SIZE*2, 0, 0); //reset Position
    
    glTranslatef(0, FIELD_SIZE*2, 0); //Position Sprite
    glRotatef(270, 0, 0, 1); //Rotate Sprite
    add_texture(texture);
    glRotatef(-270, 0, 0, 1); //reset rotation
    glTranslatef(0, -FIELD_SIZE*2, 0); //reset Position
    
    glTranslatef(FIELD_SIZE*2, FIELD_SIZE*2, 0); //Position Sprite
    glRotatef(180, 0, 0, 1); //Rotate Sprite
    add_texture(texture);
    glRotatef(-180, 0, 0, 1);
    glTranslatef(-FIELD_SIZE*2, -FIELD_SIZE*2, 0);
    
    //finished creating map
    
    struct point* points=new struct point[4];
    struct point p1={0,0};
    struct point p2={0,10};
    struct point p3={10,10};
    struct point p4={10,0};

    points[0]=p1;
    points[1]=p2;
    points[2]=p3;
    points[3]=p4;


   Linestrip ls(4,points);
   Blueprint bp(1,&ls);
//
//    Drawer d;

   // d.drawBlueprint(bp,30,30);

    //draw creep - mercury
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            /*if (j*i%3==0 )
                draw_mercury(20*j, 20*i);
            else if (j*i%3==1)
                draw_mako(20*j, 20*i);
            else if (j*i%3==2)*/
               // draw_splash_tower(20*j, 20*i);
        }
    }
    
    SDL_GL_SwapBuffers();

    SDL_Delay(500);
    
    //delete texture
    glDeleteTextures( 1, &texture );

    SDL_Quit();
    
    return 0;
}

