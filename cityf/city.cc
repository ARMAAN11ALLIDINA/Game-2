#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <math.h>
#include <cstdlib>
#include <time.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int Window_ID;
int Window_Width = 600;
int Window_Height = 400;

const double PI = 3.14;

float Z_Off = -1.0f;

float xCar = 0.0f;
float yCar = 0.0f;
float zCar = 0.0f;

float xCarCam = xCar;
float yCarCam = yCar;
float zCarCam = zCar;

float xEye = xCar-3.0f;
float yEye = yCar+2.0f;
float zEye = zCar-5.0f;

float rotation = 0.0f;
float contRot = 0.0f;

float X_Rot=0.9f;
float Y_Rot=0.0f;
float X_Speed=0.0f;
float Y_Speed=0.05f;

float colour[4]={1.0f,1.0f,0.0f,0.0f};

GLUquadricObj *cylin;


//*******************
int ranNum(int i)
{
    srand(i);
    return rand()%20;
}
//*******************

static void PrintString(void *font, char *str)
{
   int i,len=strlen(str);

   for(i=0;i < len; i++)
      glutBitmapCharacter(font,*str++);
}

void RenderScene(void){
    cylin = gluNewQuadric();
    gluQuadricDrawStyle(cylin, GLU_FILL);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(xEye, yEye, zEye, xCarCam, yCarCam, zCarCam, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, Z_Off);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Below is what I have been trying to do
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
        {
            //if()
            //{
                int row=ranNum(i)*10, col=ranNum(j)*10;
                //Square Building
                glPushMatrix();
                glTranslatef(5.0,0.0,+2.0);
                glBegin(GL_QUADS);
                //top
                glNormal3f(0.0f, 0.0f, 0.0f);
                glColor3f(0.5f, 0.5f, 0.5f);
                glTexCoord2f(0.0f, 0.0f); glVertex3f(row+0.0f, 2.0f, col+0.0f);
                glTexCoord2f(0.0f, 2.0f); glVertex3f(row+1.0f, 2.0f, col+0.0f);
                glTexCoord2f(1.0f, 2.0f); glVertex3f(row+1.0f, 2.0f, col+1.0f);
                glTexCoord2f(1.0f, 0.0f); glVertex3f(row+0.0f, 2.0f, col+1.0f);
                //front
                glNormal3f(0.0f, 0.0f, 0.0f);
                glColor3f(0.5f, 0.5f, 0.5f);
                glTexCoord2f(0.0f, 0.0f); glVertex3f(row+0.0f, 0.0f, col+0.0f);
                glTexCoord2f(1.0f, 0.0f); glVertex3f(row+1.0f, 0.0f, col+0.0f);
                glTexCoord2f(1.0f, 2.0f); glVertex3f(row+1.0f, 2.0f, col+0.0f);
                glTexCoord2f(0.0f, 2.0f); glVertex3f(row+0.0f, 2.0f, col+0.0f);
                //back
                glNormal3f(0.0f, 0.0f, 0.0f);
                glColor3f(0.5f, 0.5f, 0.5f);
                glTexCoord2f(0.0f, 2.0f); glVertex3f(row+0.0f, 0.0f, col+1.0f);
                glTexCoord2f(1.0f, 2.0f);glVertex3f(row+1.0f, 0.0f, col+1.0f);
                glTexCoord2f(1.0f, 0.0f);glVertex3f(row+1.0f, 2.0f, col+1.0f);
                glTexCoord2f(0.0f, 0.0f); glVertex3f(row+0.0f, 2.0f, col+1.0f);
                //left
                glNormal3f(0.0f, 0.0f, 0.0f);
                glColor3f(0.5f, 0.5f, 0.5f);
                glTexCoord2f(0.0f, 0.0f); glVertex3f(row+0.0f, 0.0f, col+0.0f);
                glTexCoord2f(1.0f, 0.0f); glVertex3f(row+0.0f, 0.0f, col+1.0f);
                glTexCoord2f(1.0f, 2.0f); glVertex3f(row+0.0f, 2.0f, col+1.0f);
                glTexCoord2f(0.0f, 2.0f); glVertex3f(row+0.0f, 2.0f, col+0.0f);
                //right
                glNormal3f(0.0f, 0.0f, 0.0f);
                glColor3f(0.5f, 0.5f, 0.5f);
                glTexCoord2f(1.0f, 0.0f); glVertex3f(row+1.0f, 0.0f, col+0.0f);
                glTexCoord2f(1.0f, 2.0f); glVertex3f(row+1.0f, 0.0f, col+1.0f);
                glTexCoord2f(0.0f, 2.0f); glVertex3f(row+1.0f, 2.0f, col+1.0f);
                glTexCoord2f(0.0f, 0.0f); glVertex3f(row+1.0f, 2.0f, col+0.0f);

                glEnd();

                //Square Windows
                glBegin(GL_QUADS);
                //front
                glColor3f(0.0f, 0.0f, 1.0f);
                glVertex3f(row+0.3f, 0.5f, col+-0.01f);
                glVertex3f(row+0.7f, 0.5f, col+-0.01f);
                glVertex3f(row+0.7f, 1.5f, col+-0.01f);
                glVertex3f(row+0.3f, 1.5f, col+-0.01f);
                //back
                glColor3f(0.0f, 0.0f, 1.01f);
                glVertex3f(row+0.3f, 0.5f, col+1.01f);
                glVertex3f(row+0.7f, 0.5f, col+1.01f);
                glVertex3f(row+0.7f, 1.5f, col+1.01f);
                glVertex3f(row+0.3f, 1.5f, col+1.01f);
                //left
                glColor3f(0.0f, 0.0f, 1.0f);
                glVertex3f(row+-0.01f, 0.8f, col+0.0f);
                glVertex3f(row+-0.01f, 0.8f, col+1.0f);
                glVertex3f(row+-0.01f, 1.2f, col+1.0f);
                glVertex3f(row+-0.01f, 1.2f, col+0.0f);
                //right
                glColor3f(0.0f, 0.0f, 1.0f);
                glVertex3f(row+1.01f, 0.8f, col+0.0f);
                glVertex3f(row+1.01f, 0.8f, col+1.0f);
                glVertex3f(row+1.01f, 1.2f, col+1.0f);
                glVertex3f(row+1.01f, 1.2f, col+0.0f);

                glEnd();
                glPopMatrix();
            //}
        }
    }
    /*
    //Square Building
    glPushMatrix();
    glTranslatef(5.0,0.0,+2.0);
    glBegin(GL_QUADS);
    //top
    glNormal3f(0.0f, 0.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 2.0f, 0.0f);
    glTexCoord2f(0.0f, 2.0f); glVertex3f(1.0f, 2.0f, 0.0f);
    glTexCoord2f(1.0f, 2.0f); glVertex3f(1.0f, 2.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 2.0f, 1.0f);
    //front
    glNormal3f(0.0f, 0.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 2.0f); glVertex3f(1.0f, 2.0f, 0.0f);
    glTexCoord2f(0.0f, 2.0f); glVertex3f(0.0f, 2.0f, 0.0f);
    //back
    glNormal3f(0.0f, 0.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0f, 2.0f); glVertex3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(1.0f, 2.0f);glVertex3f(1.0f, 0.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(1.0f, 2.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 2.0f, 1.0f);
    //left
    glNormal3f(0.0f, 0.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(1.0f, 2.0f); glVertex3f(0.0f, 2.0f, 1.0f);
    glTexCoord2f(0.0f, 2.0f); glVertex3f(0.0f, 2.0f, 0.0f);
    //right
    glNormal3f(0.0f, 0.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 2.0f); glVertex3f(1.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 2.0f); glVertex3f(1.0f, 2.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 2.0f, 0.0f);

    glEnd();

    //Square Windows
    glBegin(GL_QUADS);
    //front
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.3f, 0.5f, -0.01f);
    glVertex3f(0.7f, 0.5f, -0.01f);
    glVertex3f(0.7f, 1.5f, -0.01f);
    glVertex3f(0.3f, 1.5f, -0.01f);
    //back
    glColor3f(0.0f, 0.0f, 1.01f);
    glVertex3f(0.3f, 0.5f, 1.01f);
    glVertex3f(0.7f, 0.5f, 1.01f);
    glVertex3f(0.7f, 1.5f, 1.01f);
    glVertex3f(0.3f, 1.5f, 1.01f);
    //left
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-0.01f, 0.8f, 0.0f);
    glVertex3f(-0.01f, 0.8f, 1.0f);
    glVertex3f(-0.01f, 1.2f, 1.0f);
    glVertex3f(-0.01f, 1.2f, 0.0f);
    //right
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.01f, 0.8f, 0.0f);
    glVertex3f(1.01f, 0.8f, 1.0f);
    glVertex3f(1.01f, 1.2f, 1.0f);
    glVertex3f(1.01f, 1.2f, 0.0f);

    glEnd();
    glPopMatrix();
    */

    // TEST RNG WITH CYLINDER BUILDING


    /*
    GLUquadric* q = gluNewQuadric();
    for(int i = 0; i < 50000; i++)
    {
        for(int j=0; j<20; j++)
        {
            glPushMatrix();
            glTranslatef(-500 + rand() % 1000, 7 + rand() % 100, -500 + rand() % 1000);
            gluSphere(q, 10, 10, 10);
            glPopMatrix();
        }
    }
    gluDeleteQuadric(q);
    */

    //This has the basic loop.

    //Cylinder building
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
        {
            /*int rng=ranNum();
            if(rng<5)
            {*/
                GLUquadric *cylBuild=gluNewQuadric();
                int row=ranNum(i)*10, col=ranNum(j)*10;

                glPushMatrix();
                glTranslatef(row+7.0,0.0,col+7.0);
                glRotatef(-90.0,1,0,0);
                glColor3f(0.3,0.3,0.7);
                gluCylinder(cylin,0.5,0.5,2.0,16,10);
                glPopMatrix();
                gluDeleteQuadric(cylBuild);
            //}
                glPushMatrix();
                glTranslatef(7,2.0,7);
                glRotatef(contRot,0,1,0);
                glTranslatef(-0.5,0,-0.5);
                glBegin(GL_QUADS);
                //top
                glNormal3f(0.0f, 0.0f, 0.0f);
                glColor3f(0.8f, 0.8f, 0.8f);
                glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.5f, 0.0f);
                glTexCoord2f(0.0f, 2.0f); glVertex3f(1.0f, 0.5f, 0.0f);
                glTexCoord2f(1.0f, 2.0f); glVertex3f(1.0f, 0.5f, 1.0f);
                glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.5f, 1.0f);
                //front
                glNormal3f(0.0f, 0.0f, 0.0f);
                glColor3f(0.8f, 0.8f, 0.8f);
                glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
                glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 0.0f, 0.0f);
                glTexCoord2f(1.0f, 2.0f); glVertex3f(1.0f, 0.5f, 0.0f);
                glTexCoord2f(0.0f, 2.0f); glVertex3f(0.0f, 0.5f, 0.0f);
                //back
                glNormal3f(0.0f, 0.0f, 0.0f);
                glColor3f(0.8f, 0.8f, 0.8f);
                glTexCoord2f(0.0f, 2.0f); glVertex3f(0.0f, 0.0f, 1.0f);
                glTexCoord2f(1.0f, 2.0f);glVertex3f(1.0f, 0.0f, 1.0f);
                glTexCoord2f(1.0f, 0.0f);glVertex3f(1.0f, 0.5f, 1.0f);
                glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.5f, 1.0f);
                //left
                glNormal3f(0.0f, 0.0f, 0.0f);
                glColor3f(0.8f, 0.8f, 0.8f);
                glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
                glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f, 1.0f);
                glTexCoord2f(1.0f, 2.0f); glVertex3f(0.0f, 0.5f, 1.0f);
                glTexCoord2f(0.0f, 2.0f); glVertex3f(0.0f, 0.5f, 0.0f);
                //right
                glNormal3f(0.0f, 0.0f, 0.0f);
                glColor3f(0.8f, 0.8f, 0.8f);
                glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 0.0f, 0.0f);
                glTexCoord2f(1.0f, 2.0f); glVertex3f(1.0f, 0.0f, 1.0f);
                glTexCoord2f(0.0f, 2.0f); glVertex3f(1.0f, 0.5f, 1.0f);
                glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 0.5f, 0.0f);

                glEnd();
                glPopMatrix();
        }
    }


    // Sphere Building
      /*  for(int i=0; i<20; i++){
            for(int j=0; j<20; j++){
                int row=ranNum(i)*10, col=ranNum(j)*10;
                glPushMatrix();
                glTranslatef(row+3.0,0.0,col+3.0);
                GLUquadricObj *quadric;
                quadric = gluNewQuadric();
                gluQuadricDrawStyle(quadric, GLU_FILL );
                glColor3f(1.0f, 0.0f, 0.0f);
                gluSphere( quadric , .5 , 36 , 18 );
                gluDeleteQuadric(quadric);
                glPushMatrix();
                glTranslatef(0.0f, 0.5f, 0.0f);
                glRotatef(X_Rot, 1.0f, 0.0f, 0.0f);
                glRotatef(Y_Rot, 0.0f, 1.0f, 0.0f);
                glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
                GLUquadricObj *quadric2;
                quadric2 = gluNewQuadric();
                gluQuadricDrawStyle(quadric2, GLU_FILL );
                glColor3f(0.0f, 1.0f, 0.0f);
                gluCylinder(quadric2, .25, .25, .25, 36, 18);
                gluDisk(quadric2, 0, .25, 36, 18);
                gluDeleteQuadric(quadric2);
                glPopMatrix();
                }
        }
*/

    glBegin(GL_QUADS); //road and surrounding development

    for(int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
        {
            float row=i*10, col=j*10;

            glColor3f(0.251,0.51,0.427);
            glVertex3f(row+1,0.1,col+10);
            glVertex3f(row+1,0.1,col+1);         //a green surroundings
            glVertex3f(row+10,0.1,col+1);
            glVertex3f(row+10,0.1,col+10);

            glColor3f(0.7,0.7,0.7);
            glVertex3f(row+1,0.1,col+0);
            glVertex3f(row+1,0.1,col+0.45);         //Xroad1
            glVertex3f(row+10,0.1,col+0.45);
            glVertex3f(row+10,0.1,col+0);

            glColor3f(1.0,0.75,0.0);
            glVertex3f(row+1,0.1,col+0.45);       //Xmedian
            glVertex3f(row+1,0.1,col+0.55);
            glVertex3f(row+10,0.1,col+0.55);
            glVertex3f(row+10,0.1,col+0.45);

            glColor3f(0.7,0.7,0.7);
            glVertex3f(row+1,0.1,col+0.55);
            glVertex3f(row+1,0.1,col+1);         //Xroad2
            glVertex3f(row+10,0.1,col+1);
            glVertex3f(row+10,0.1,col+0.55);

            glColor3f(0.7,0.7,0.7);
            glVertex3f(row+0,0.1,col+10);
            glVertex3f(row+0,0.1,col+1);         //Zroad1
            glVertex3f(row+0.45,0.1,col+1);
            glVertex3f(row+0.45,0.1,col+10);

            glColor3f(1.0,0.75,0.0);
            glVertex3f(row+0.45,0.1,col+10);       //Zmedian
            glVertex3f(row+0.45,0.1,col+1);
            glVertex3f(row+0.55,0.1,col+1);
            glVertex3f(row+0.55,0.1,col+10);

            glColor3f(0.7,0.7,0.7);
            glVertex3f(row+0.55,0.1,col+10);
            glVertex3f(row+0.55,0.1,col+1);         //Zroad2
            glVertex3f(row+1,0.1,col+1);
            glVertex3f(row+1,0.1,col+10);

            glColor3f(0.7,0.7,0.7);
            glVertex3f(row+0.0,0.1,200.0);
            glVertex3f(row+0.0,0.1,201.0);            //Middle Chunk
            glVertex3f(row+1.0,0.1,201.0);
            glVertex3f(row+1.0,0.1,200.0);

            glColor3f(0.7,0.7,0.7);
            glVertex3f(row+1,0.1,200);
            glVertex3f(row+1,0.1,200.45);         //End Xroad1
            glVertex3f(row+10,0.1,200.45);
            glVertex3f(row+10,0.1,200);

            glColor3f(1.0,0.75,0.0);
            glVertex3f(row+1,0.1,200.45);       //End Xmedian
            glVertex3f(row+1,0.1,200.55);
            glVertex3f(row+10,0.1,200.55);
            glVertex3f(row+10,0.1,200.45);

            glColor3f(0.7,0.7,0.7);
            glVertex3f(row+1,0.1,200.55);
            glVertex3f(row+1,0.1,201);         //End Xroad2
            glVertex3f(row+10,0.1,201);
            glVertex3f(row+10,0.1,200.55);

            glColor3f(0.7,0.7,0.7);
            glVertex3f(row+0.0,0.1,col+0.0);
            glVertex3f(row+0.0,0.1,col+1.0);            //End XMiddle Chunk
            glVertex3f(row+1.0,0.1,col+1.0);
            glVertex3f(row+1.0,0.1,col+0.0);

            glColor3f(0.7,0.7,0.7);
            glVertex3f(200,0.1,col+10);
            glVertex3f(200,0.1,col+1);         //End Zroad1
            glVertex3f(200.45,0.1,col+1);
            glVertex3f(200.45,0.1,col+10);

            glColor3f(1.0,0.75,0.0);
            glVertex3f(200.45,0.1,col+10);       //End Zmedian
            glVertex3f(200.45,0.1,col+1);
            glVertex3f(200.55,0.1,col+1);
            glVertex3f(200.55,0.1,col+10);

            glColor3f(0.7,0.7,0.7);
            glVertex3f(200.55,0.1,col+10);
            glVertex3f(200.55,0.1,col+1);         //End Zroad2
            glVertex3f(201,0.1,col+1);
            glVertex3f(201,0.1,col+10);

            glColor3f(0.7,0.7,0.7);
            glVertex3f(200.0,0.1,col+0.0);
            glVertex3f(200.0,0.1,col+1.0);            //End ZMiddle Chunks
            glVertex3f(201.0,0.1,col+1.0);
            glVertex3f(201.0,0.1,col+0.0);
        }
    }
    glColor3f(0.7,0.7,0.7);
    glVertex3f(200.0,0.1,200.0);
    glVertex3f(200.0,0.1,201.0);            //End ZMiddle Chunk
    glVertex3f(201.0,0.1,201.0);
    glVertex3f(201.0,0.1,200.0);
    glEnd();

    glPopMatrix();



    //Placeholder vehicle
    glPushMatrix();

    glTranslatef(xCar,yCar,zCar);
    glTranslatef(0.5,0.0,0.5);
    glRotatef(rotation,0.0,1.0,0.0);
    glTranslatef(-0.5,0.0,-0.5);

    glBegin(GL_QUADS);

    // Far face.  Green, 50% opaque, non-uniform texture cooridinates.
    glNormal3f( 0.0f, 0.0f,-1.0f);
    glColor4f(0.2,0.9,0.2,.5);

    glTexCoord2f(0.995f, 0.005f); glVertex3f(0.0f, 0.5f, 0.0f);
    glTexCoord2f(2.995f, 2.995f); glVertex3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.005f, 0.995f); glVertex3f(1.0f, 1.0f, 0.0f);
    glTexCoord2f(0.005f, 0.005f); glVertex3f(1.0f, 0.5f, 0.0f);

    // Right face.  Blue; 25% opaque
    glNormal3f( 1.0f, 0.0f, 0.0f);
    glColor4f(0.2,0.2,0.9,.25);

    glTexCoord2f(0.995f, 0.005f); glVertex3f( 1.0f, 0.5f, 0.0f);
    glTexCoord2f(0.995f, 0.995f); glVertex3f( 1.0f, 1.0f, 0.0f);
    glTexCoord2f(0.005f, 0.995f); glVertex3f( 1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.005f, 0.005f); glVertex3f( 1.0f, 0.5f, 1.0f);

    // Front face; offset.  Multi-colored, 50% opaque.
    glNormal3f( 0.0f, 0.0f, 1.0f);
    glColor4f( 0.9f, 0.2f, 0.2f, 0.5f);

    glTexCoord2f( 0.005f, 0.005f); glVertex3f(0.0f, 0.5f, 1.0f);
    glColor4f( 0.2f, 0.9f, 0.2f, 0.5f);
    glTexCoord2f( 0.995f, 0.005f); glVertex3f(1.0f, 0.5f, 1.0f);
    glColor4f( 0.2f, 0.2f, 0.9f, 0.5f);
    glTexCoord2f( 0.995f, 0.995f); glVertex3f(1.0f, 1.0f, 1.0f);
    glColor4f( 0.1f, 0.1f, 0.1f, 0.5f);
    glTexCoord2f( 0.005f, 0.995f); glVertex3f(0.0f, 1.0f, 1.0f);


    // Left Face.  Yellow, varying levels of opaque.
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glColor4f(0.9,0.9,0.2,0.0);

    glTexCoord2f(0.005f, 0.005f); glVertex3f(0.0f, 0.5f, 0.0f);
    glColor4f(0.9,0.9,0.2,0.66);
    glTexCoord2f(0.995f, 0.005f); glVertex3f(0.0f, 0.5f,  1.0f);
    glColor4f(0.9,0.9,0.2,1.0);
    glTexCoord2f(0.995f, 0.995f); glVertex3f(0.0f, 1.0f,  1.0f);
    glColor4f(0.9,0.9,0.2,0.33);
    glTexCoord2f(0.005f, 0.995f); glVertex3f(0.0f, 1.0f, 0.0f);

    // Top face.  Red, 50% opaque, non-uniform texture cooridinates.
    glNormal3f( 0.0f, 0.0f,-1.0f);
    glColor4f(0.9,0.2,0.2,.5);

    glTexCoord2f(0.995f, 0.995f); glVertex3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(2.995f, 2.005f); glVertex3f(0.0f, 1.0f, 1.0f);
    glTexCoord2f(0.005f, 0.995f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.005f, 0.005f); glVertex3f(1.0f, 1.0f, 0.0f);

    // Bottom face.  Turquoise, 50% opaque, non-uniform texture cooridinates.
    glNormal3f( 0.0f, 0.0f,-1.0f);
    glColor4f(0.2,0.9,0.9,.5);

    glTexCoord2f(0.995f, 0.995f); glVertex3f(0.0f, 0.5f, 0.0f);
    glTexCoord2f(2.995f, 2.005f); glVertex3f(0.0f, 0.5f, 1.0f);
    glTexCoord2f(0.005f, 0.995f); glVertex3f(1.0f, 0.5f, 1.0f);
    glTexCoord2f(0.005f, 0.005f); glVertex3f(1.0f, 0.5f, 0.0f);

    // All polygons have been drawn.
    glEnd();

    glPopMatrix();


    glLoadIdentity();

    glTranslatef(5.0f, 0.0f, Z_Off);

    int i=0;

    float mult=1;

    //top
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    float a=i*PI/180;
    glVertex3f(mult*cos(a), mult+sin(a), 1);
    i+=360/3;
    a=i*PI/180;
    glVertex3f(mult*cos(a), mult+sin(a), 1);
    i+=360/3;
    a=i*PI/180;
    glVertex3f(mult*cos(a), mult+sin(a), 1);
    i+=360/3;
    glEnd();
    i=0;
    //bottom
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    float b=i*PI/180;
    glVertex3f(mult*cos(b), mult+sin(b), 0.0);
    i+=360/3;
    b=i*PI/180;
    glVertex3f(mult*cos(b), mult+sin(b), 0);
    i+=360/3;
    b=i*PI/180;
    glVertex3f(mult*cos(b), mult+sin(b), 0);
    i+=360/3;
    glEnd();
    i=0;
    glBegin(GL_QUAD_STRIP);

    glColor3f(1.0f, 0.0f, 0.0f);

    float c=i*PI/180;

    glVertex3f(mult*cos(c), mult*sin(c), 0.0);
    glVertex3f(mult*cos(c), mult*sin(c), 1.0);
    i+=360/3;
    c=i*PI/180;
    glVertex3f(mult*cos(c), mult*sin(c), 0.0);
    glVertex3f(mult*cos(c), mult*sin(c), 1.0);
    i+=360/3;
    c=i*PI/180;
    glVertex3f(mult*cos(c), mult*sin(c), 0.0);
    glVertex3f(mult*cos(c), mult*sin(c), 1.0);
    i+=360/3;
    c=i*PI/180;
    glVertex3f(mult*cos(c), mult*sin(c), 0.0);
    glVertex3f(mult*cos(c), mult*sin(c), 1.0);
    i+=360/3;

    glEnd();

    glLoadIdentity();
    glTranslatef(5.0f, 1.0f, Z_Off);
    glRotatef(0.9f, 1.0f, 0.0f, 0.0f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);

    glBegin(GL_QUADS);
    //top
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);
    glVertex3f(1.0f, 2.0f, 0.0f);
    glVertex3f(1.0f, 2.0f, 1.0f);
    glVertex3f(0.0f, 2.0f, 1.0f);
    //front
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 2.0f, 0.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);
    //back
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, 2.0f, 1.0f);
    glVertex3f(0.0f, 2.0f, 1.0f);
    //left
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 2.0f, 1.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);
    //right
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, 2.0f, 1.0f);
    glVertex3f(1.0f, 2.0f, 0.0f);

    glEnd();

    glLoadIdentity();

    glTranslatef(3.0f, 0.0f, -3.0f);

    glBegin(GL_LINE_LOOP);
    GLUquadricObj *quadric;
    quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL );
    gluSphere( quadric , .5 , 36 , 18 );
    gluDeleteQuadric(quadric);
    glEndList();

    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);

    glPushMatrix();
    glLoadIdentity();
    char bro[10];
    glColor4f(0.6,1.0,0.6,1.00);
    sprintf(bro,"xCar=%f    zCar=%f", xCar, zCar); // Print the string into a buffer
    glRasterPos2f(-1.0,0.5);                 // Set the coordinate
    PrintString(GLUT_BITMAP_HELVETICA_12, bro);

    glLoadIdentity();
    char yeet[100];
    glColor4f(0.6,1.0,0.6,1.00);
    sprintf(yeet,"xEye=%f    yEye=%f    zEye=%f    xCarCam=%f    yCarCam=%f    zCarCam=%f", xEye, yEye, zEye, xCarCam, yCarCam, zCarCam); // Print the string into a buffer
    glRasterPos2f(-1.0,0.6);                 // Set the coordinate
    PrintString(GLUT_BITMAP_HELVETICA_12, yeet);
    glPopMatrix();

    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);

    glutSwapBuffers();

    contRot+=0.05;
}
void CallBackKeyPressed(unsigned char key, int x, int y){
    switch (key) {
        case 27: // ESC
        // Destroy the window and quit.
        glutDestroyWindow(Window_ID);
        exit(1);
        break;
        case 113: // q
            if((fmod(zCar, 10)==0)&&(fmod(xCar, 10)==0))
            {
                rotation+=90;
            }
        break;
        case 119: // w
            if((fmod(zCar, 10)==0)&&(fmod(xCar, 10)==0))
            {
                rotation-=90;
            }
        break;
        case 114: // r
            xCar = 0.0f;
            zCar = 0.0f;
            xCarCam = xCar;
            yCarCam = yCar;
            zCarCam = zCar;
            xEye = xCar-3.0f;
            yEye = yCar+2.0f;
            zEye = zCar-5.0f;
            rotation = 0.0f;
            glutPostRedisplay();
        break;
        case 97:  // a
            if((fmod(((rotation/360.0)*4.0),4.0)==0.0)&&zCar!=200.0)
            {
                zCar+=1.0;
                zCarCam+=1.0;
                zEye+=1.0;
            }
            else if((fmod(((rotation/360.0)*4.0),4.0)==1.0)&&xCar!=200.0)
            {
                xCar+=1.0;
                xCarCam+=1.0;
                xEye+=1.0;
            }
            else if((fmod(((rotation/360.0)*4.0),4.0)==2.0)&&zCar!=0.0)
            {
                zCar-=1.0;
                zCarCam-=1.0;
                zEye-=1.0;
            }
            else if((fmod(((rotation/360.0)*4.0),4.0)==3.0)&&xCar!=0.0)
            {
                xCar-=1.0;
                xCarCam-=1.0;
                xEye-=1.0;
            }
            glutPostRedisplay();
        break;
        case 122: // z
            if((fmod(((rotation/360.0)*4.0),4.0)==0.0)&&zCar!=0.0)
            {
                zCar-=1.0;
                zCarCam-=1.0;
                zEye-=1.0;
            }
            else if((fmod(((rotation/360.0)*4.0),4.0)==1.0)&&xCar!=0.0)
            {
                xCar-=1.0;
                xCarCam-=1.0;
                xEye-=1.0;
            }
            else if((fmod(((rotation/360.0)*4.0),4.0)==2.0)&&zCar!=200.0)
            {
                zCar+=1.0;
                zCarCam+=1.0;
                zEye+=1.0;
            }
            else if((fmod(((rotation/360.0)*4.0),4.0)==3.0)&&xCar!=200.0)
            {
                xCar+=1.0;
                xCarCam+=1.0;
                xEye+=1.0;
            }
            glutPostRedisplay();
        break;

    default:
        printf ("KP: No action for %d.\n", key);
        break;
    }
}
void CallBackSpecialKeyPressed(int key, int x, int y){
    switch (key) {
    case GLUT_KEY_F1: // Look forward
        if((fmod(((rotation/360.0)*4.0),4.0)==0.0))
        {
            xEye=xCar+0.5;
            yEye=yCar+1.5f;
            zEye=zCar-2.5;
            xCarCam=xCar+0.5;
            yCarCam=yCar+1.5f;
            zCarCam=zCar+1.0;
        }
        else if((fmod(((rotation/360.0)*4.0),4.0)==1.0))
        {
            xEye=xCar-1.5;
            yEye=yCar+1.5f;
            zEye=zCar-0.5;
            xCarCam=xCar+1.0;
            yCarCam=yCar+1.5f;
            zCarCam=zCar-0.5;
        }
        else if((fmod(((rotation/360.0)*4.0),4.0)==2.0))
        {
            xEye=xCar+0.5;
            yEye=yCar+1.5f;
            zEye=zCar+1.5;
            xCarCam=xCar+0.5;
            yCarCam=yCar+1.5f;
            zCarCam=zCar-1.0;
        }
        else if((fmod(((rotation/360.0)*4.0),4.0)==3.0))
        {
            xEye=xCar+2.5;
            yEye=yCar+1.5f;
            zEye=zCar-0.5;
            xCarCam=xCar-1.0;
            yCarCam=yCar+1.5f;
            zCarCam=zCar-0.5;
        }
        glutPostRedisplay();
        break;
        case GLUT_KEY_F2: // Look Right
        if((fmod(((rotation/360.0)*4.0),4.0)==0.0))
        {
            xEye=xCar+2.5;
            yEye=yCar+1.5f;
            zEye=zCar-0.5;
            xCarCam=xCar-1.0;
            yCarCam=yCar+1.5f;
            zCarCam=zCar-0.5;
        }
        else if((fmod(((rotation/360.0)*4.0),4.0)==1.0))
        {
            xEye=xCar+0.5;
            yEye=yCar+1.5f;
            zEye=zCar-2.5;
            xCarCam=xCar+0.5;
            yCarCam=yCar+1.5f;
            zCarCam=zCar+1.0;
        }
        else if((fmod(((rotation/360.0)*4.0),4.0)==2.0))
        {
            xEye=xCar-1.5;
            yEye=yCar+1.5f;
            zEye=zCar-0.5;
            xCarCam=xCar+1.0;
            yCarCam=yCar+1.5f;
            zCarCam=zCar-0.5;
        }
        else if((fmod(((rotation/360.0)*4.0),4.0)==3.0))
        {
            xEye=xCar+0.5;
            yEye=yCar+1.5f;
            zEye=zCar+1.5;
            xCarCam=xCar+0.5;
            yCarCam=yCar+1.5f;
            zCarCam=zCar-1.0;
        }
        glutPostRedisplay();
        break;
    case GLUT_KEY_F3: // Look Left
        if((fmod(((rotation/360.0)*4.0),4.0)==0.0))
        {
            xEye=xCar-1.5;
            yEye=yCar+1.5f;
            zEye=zCar-0.5;
            xCarCam=xCar+1.0;
            yCarCam=yCar+1.5f;
            zCarCam=zCar-0.5;
        }
        else if((fmod(((rotation/360.0)*4.0),4.0)==1.0))
        {
            xEye=xCar+0.5;
            yEye=yCar+1.5f;
            zEye=zCar+1.5;
            xCarCam=xCar+0.5;
            yCarCam=yCar+1.5f;
            zCarCam=zCar-1.0;
        }
        else if((fmod(((rotation/360.0)*4.0),4.0)==2.0))
        {
            xEye=xCar+2.5;
            yEye=yCar+1.5f;
            zEye=zCar-0.5;
            xCarCam=xCar-1.0;
            yCarCam=yCar+1.5f;
            zCarCam=zCar-0.5;
        }
        else if((fmod(((rotation/360.0)*4.0),4.0)==3.0))
        {
            xEye=xCar+0.5;
            yEye=yCar+1.5f;
            zEye=zCar-2.5;
            xCarCam=xCar+0.5;
            yCarCam=yCar+1.5f;
            zCarCam=zCar+1.0;
        }
        glutPostRedisplay();
        break;
    case GLUT_KEY_F4: // Default camera location
        xEye=xCar-2.0f;
        yEye=yCar+2.0f;
        zEye=zCar-5.0f;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F5: // Back right
        xEye=(xCar+0.0f)-5.0f;
        yEye=(yCar+1.0f)+3.0f;
        zEye=(zCar+5.0f);
        glutPostRedisplay();
        break;
    case GLUT_KEY_F6: // Front right
        xEye=(xCar+0.0f)+5.0f;
        yEye=(yCar+1.0f)+3.0f;
        zEye=(zCar+5.0f);
        glutPostRedisplay();
        break;
    case GLUT_KEY_F7: // Front left
        xEye=(xCar+0.0f)+5.0f;
        yEye=(yCar+1.0f)+3.0f;
        zEye=(zCar+5.0f)-10.0f;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F8: // Back left
        xEye=(xCar+0.0f)-5.0f;
        yEye=(yCar+1.0f)+3.0f;
        zEye=(zCar+5.0f)-10.0f;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F9: // Far back right
        xEye=(xCar+0.0f)-10.0f;
        yEye=(yCar+1.0f)+6.0f;
        zEye=(zCar+5.0f)+5.0f;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F10: // Far front right
        xEye=(xCar+0.0f)+10.0f;
        yEye=(yCar+1.0f)+6.0f;
        zEye=(zCar+5.0f)+5.0f;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F11: // Far front left
        xEye=(xCar+0.0f)+10.0f;
        yEye=(yCar+1.0f)+6.0f;
        zEye=(zCar+5.0f)-15.0f;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F12: // Far back left
        xEye=(xCar+0.0f)-10.0f;
        yEye=(yCar+1.0f)+6.0f;
        zEye=(zCar+5.0f)-15.0f;
        glutPostRedisplay();
        break;
    default:
        printf ("SKP: No action for %d.\n", key);
        break;
    }
}

void ResizeScene(int Width, int Height){
    if (Height == 0)
        Height = 1;
    glViewport(0, 0, Width, Height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
    glMatrixMode(GL_MODELVIEW);
    Window_Width  = Width;
    Window_Height = Height;
}
void MyInit(int Width, int Height){
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
    glClearDepth(1.0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    ResizeScene(Width,Height);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(Window_Width, Window_Height);
    Window_ID = glutCreateWindow("buildings");
    glutDisplayFunc(&RenderScene);
    glutIdleFunc(&RenderScene);
    glutKeyboardFunc(&CallBackKeyPressed);
    glutSpecialFunc(&CallBackSpecialKeyPressed);
    MyInit(Window_Width, Window_Height);
    glutMainLoop();
    return 1;
}

