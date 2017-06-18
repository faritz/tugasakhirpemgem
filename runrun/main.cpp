#define _CRT_SECURE_NO_WARNINGS
#include<glut.h>
#include<iostream>//for strlen
#include<stdlib.h>
#    pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
 
int i,q;
int score = 0;
int screen = 0;
bool collide = false;
char buffer[10];

int vehicleX = 200, vehicleY = 70;   
int ovehicleX[4], ovehicleY[4];
int divx = 250, divy = 4, movd;

 
void drawText(char ch[],int xpos, int ypos)//menulis huruf pada layar
{
    int numofchar = strlen(ch);
    glLoadIdentity ();
    glRasterPos2f( xpos , ypos);
    for (i = 0; i <= numofchar - 1; i++)
    {
     
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);
    }
}
 
 
void drawTextNum(char ch[],int numtext,int xpos, int ypos)//ngitung score
{
    int len;
    int k;
    k = 0;
    len = numtext - strlen (ch);
    glLoadIdentity ();
    glRasterPos2f( xpos , ypos);
    for (i = 0; i <=numtext - 1; i++)
    {
    if ( i < len )
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'0');
    else
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[k]);
        k++;
    }
     
    }
}
 
 
void ovpos()
{
    glClearColor(0,0,1,0);
for(i = 0; i < 4; i++)
{
    if(rand() % 2 == 0)
    {
        ovehicleX[i] = 200;
    }
    else
    {
        ovehicleX[i] = 300;
    }  
    ovehicleY[i] = 1000 - i * 160;
}
}
 
 
void drawRoad()
{
    glBegin(GL_QUADS); 
        glColor3f(0.5,0.5,0.5);
        glVertex2f(250 - 100, 500);
        glVertex2f(250 - 100, 0);
        glVertex2f(250 + 100, 0);
        glVertex2f(250 + 100, 500);
    glEnd();
	glutPostRedisplay();
}
 
 
void drawDivider()//marka jalan
{
    glLoadIdentity();
    glTranslatef(0, movd, 0);
    for(i = 1; i <= 10; i++)
    {
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(divx  - 5, divy * 15 * i + 18);
        glVertex2f(divx  - 5, divy * 15 * i - 18);
        glVertex2f(divx  + 5, divy * 15 * i - 18);
        glVertex2f(divx  + 5, divy * 15 * i + 18);
    glEnd();
    }
    glLoadIdentity();
	glutPostRedisplay();
}
     
 
void drawSkate()
{
    glPointSize(10.0);
    glBegin(GL_POINTS);//tangan
        glColor3f(1.000, 0.871, 0.678);
        glVertex2f(vehicleX - 25, vehicleY + 6); 
        glVertex2f(vehicleX + 25, vehicleY + 6);
		glEnd();
	
	glBegin(GL_POINTS);//ban
		glColor3f(0,0,0);
		glVertex2f(vehicleX - 16, vehicleY + 35); 
		glVertex2f(vehicleX + 16, vehicleY + 35); 
		glVertex2f(vehicleX - 16, vehicleY - 35);
		glVertex2f(vehicleX + 16, vehicleY - 35);
	glEnd();
    glBegin(GL_QUADS);  
        glColor3f(1,0,0);//skate
        glVertex2f(vehicleX - 15, vehicleY + 45);
        glVertex2f(vehicleX - 10, vehicleY - 45);
        glVertex2f(vehicleX + 10, vehicleY - 45);
        glVertex2f(vehicleX + 15, vehicleY + 45);
    glEnd();
	glBegin(GL_QUADS);
		glColor3f(1, 0, 0);//skate
		glVertex2f(vehicleX + 10, vehicleY + 45);
		glVertex2f(vehicleX + 15, vehicleY - 45);
		glVertex2f(vehicleX - 15, vehicleY - 45);
		glVertex2f(vehicleX - 10, vehicleY + 45);
	glEnd();
	glBegin(GL_QUADS);//head
	glColor3f(1.000, 0.871, 0.678);
	glVertex2f(vehicleX - 10, vehicleY + 15);
	glVertex2f(vehicleX - 10, vehicleY - 15);
	glVertex2f(vehicleX + 10, vehicleY - 15);
	glVertex2f(vehicleX + 10, vehicleY + 15);
	glEnd();
    glBegin(GL_QUADS);//body
        glColor3f(0,0,1);
        glVertex2f(vehicleX - 23, vehicleY - 0);
        glVertex2f(vehicleX - 19, vehicleY - 15);
        glVertex2f(vehicleX + 19, vehicleY - 15);
        glVertex2f(vehicleX + 23, vehicleY - 0);
    glEnd();
	glutPostRedisplay();
 } 
  
void drawOVehicle()
{
     
    for(i = 0; i < 4; i++)
    {
    glPointSize(10.0);
    glBegin(GL_POINTS);//ban
        glColor3f(0,0,0);                     
        glVertex2f(ovehicleX[i] - 16, ovehicleY[i] + 16); 
        glVertex2f(ovehicleX[i] + 16, ovehicleY[i] + 16); 
        glVertex2f(ovehicleX[i] - 13, ovehicleY[i] - 16); 
        glVertex2f(ovehicleX[i] + 13, ovehicleY[i] - 16);
    glEnd();
     
    glBegin(GL_QUADS);  
        glColor3f(0.99609, 0.83984, 0);//badan
        glVertex2f(ovehicleX[i] - 15, ovehicleY[i] + 45);
        glVertex2f(ovehicleX[i] - 10, ovehicleY[i] - 45);
        glVertex2f(ovehicleX[i] + 10, ovehicleY[i] - 45);
        glVertex2f(ovehicleX[i] + 15, ovehicleY[i] + 45);
    glEnd();
 
    glBegin(GL_QUADS);//spoiler
        glColor3f(0,1,0);
        glVertex2f(ovehicleX[i] - 23, ovehicleY[i] + 35);
        glVertex2f(ovehicleX[i] - 23, ovehicleY[i] + 47);
        glVertex2f(ovehicleX[i] + 23, ovehicleY[i] + 47);
        glVertex2f(ovehicleX[i] + 23, ovehicleY[i] + 35);
    glEnd();
     
    ovehicleY[i] = ovehicleY[i] - 8; 
     
    if(ovehicleY[i] > vehicleY - 25 - 25 && ovehicleY[i] < vehicleY + 25 + 25 && ovehicleX[i] == vehicleX)
    {
        collide = true;
    }
     
    if(ovehicleY[i] < -25)
    { 
        if(rand() % 2 == 0)
        {
            ovehicleX[i] = 200;
        }
        else
        {
            ovehicleX[i] = 300;
        }
        ovehicleY[i] = 600; 
    } 
    }
	glutPostRedisplay();
}
 
void Specialkey(int key, int x, int y)
{
switch(key)
{
case GLUT_KEY_UP: 
	for(i = 0; i <4; i++)
             {
              ovehicleY[i] = ovehicleY[i] - 10;  
             }
             movd = movd - 20;
             break;	
case GLUT_KEY_DOWN: 
	for(i = 0; i <4; i++)
             {
              ovehicleY[i] = ovehicleY[i] + 10;  
             }
             movd = movd + 20;
             break;
case GLUT_KEY_LEFT:vehicleX = 200;
             break;
case GLUT_KEY_RIGHT:vehicleX = 300;
             break;
			 
}

glutPostRedisplay();
}
 
void Normalkey(unsigned char key, int x, int y)
{
    switch(key)
    {
    case '1':if(screen == 0)
             screen=1;
             break;
    case '2':if(screen == 1)
             screen=2;
             break;
	
	case '3':exit(1);
		break;
	case '4':screen=1;
		glutPostRedisplay();
		break;
    case 27:exit(0);
    }
} 
 
 
void init()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, 500, 0, 500);
glMatrixMode(GL_MODELVIEW);
}
 
 
void display()
{
    if(screen == 0)
    {
    glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 1.0f, 0.5f);
    glColor3f(43,123,67);
    drawText("WELCOME", 200, 290);
    drawText("RUN & RUN GAME BY KELOMPOK 2", 130, 250);
    drawText("Press 1 to continue", 180, 150);
    glutSwapBuffers();
    }
    else if(screen == 1)
    {
    glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glColor3f(1,1,1);
    drawText("press up to accelerate", 170, 290);
    drawText("press left to move left", 170, 250);
    drawText("press right to move right", 170, 210);
    drawText("Press 2 to continue", 170, 150);
    glutSwapBuffers();
	collide = false;
    }
    else if(screen == 2 && collide==false)
    {
    glClear(GL_COLOR_BUFFER_BIT);
    drawRoad(); 
    drawDivider();
    drawSkate();
    drawOVehicle();
    movd = movd - 16;
    if(movd < - 60)
    {
        movd = 0;
    }
     
    score = score + 1;
    glColor3f(1,1,1);
    drawText("Score:", 360,455);
    _itoa (score, buffer, 10);
    drawTextNum(buffer, 6, 420,455);
    glutSwapBuffers(); 
    for(q = 0; q<= 10000000; q++){;}
	if (collide == true)
	{
		glColor3f(1, 1, 1);
		drawText("GAME OVER", 170, 290);
		drawText("press 3 to exit.", 170, 250);
		//glutPostRedisplay();
		glutSwapBuffers();
		getchar();
	}
    }
}
 
 
void main(int argc, char **argv)
{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
		glutInitWindowPosition(100, 100);
		glutInitWindowSize(800, 500);
		glutCreateWindow("Run & Run");
		ovpos();
		init();
		glutDisplayFunc(display);
		glutSpecialFunc(Specialkey);
		glutKeyboardFunc(Normalkey);
		glutIdleFunc(display);
		glutMainLoop();
	
}