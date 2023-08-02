#include <GL/glut.h>
#include <math.h>
#include <string.h>
#include "local.h"

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int NumInQM = 0,NumInQF = 0,NumInMM = 0,NumInBX = 0,NumTX = 0,NumInRX = 0,NumInIX = 0;

int shmID11;
int *s11;



void reset()
{
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);	// red
	glVertex2f(-0.91, 0.36);
	glEnd();


	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.4, 1.0);	// blue
	glVertex2f(-0.91, -0.37);
	glEnd();

	/// solder //
	glPointSize(19.0);
	glBegin(GL_POINTS);
	glColor3f(0, 0, 0);	// black
	glVertex2f(0.835, 0.14);
	glEnd();

	glPointSize(19.0);
	glBegin(GL_POINTS);
	glColor3f(0.0, 0, 0);	// black
	glVertex2f(0.835, 0.54);
	glEnd();

	glPointSize(19.0);
	glBegin(GL_POINTS);
	glColor3f(0, 0, 0);	// black
	glVertex2f(0.835, -0.25);
	glEnd();

	glPointSize(19.0);
	glBegin(GL_POINTS);
	glColor3f(0.0, 0, 0);	// black
	glVertex2f(0.835, -0.65);
	glEnd();

	glPointSize(15.0);
	glBegin(GL_POINTS);
	glColor3f(0.8, 0.8, 0.8);	// black
	glVertex2f(-0.25, 0.0);
	glEnd();
	
	//points in QUEU
	//10
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);
	//glColor3f(1.0, 0.0, 0.0);	// red1
	glVertex2f(-0.85, 0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.85, 0.28);
	glEnd();
	//9	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.8, 0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.8, 0.28);
	glEnd();

	//8
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.75, 0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.75, 0.28);
	glEnd();


	//7
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.7, 0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.7, 0.28);
	glEnd();
	//6
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.65, 0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.65, 0.28);
	glEnd();

	//5
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.6, 0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.6, 0.28);
	glEnd();
	//4
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.55, 0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.55, 0.28);
	glEnd();
	//3
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.5, 0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.5, 0.28);
	glEnd();
	//2
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.46, 0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.46, 0.28);
	glEnd();
	//1
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.42, 0.42);
	//glEnd();
	glPointSize(14.0);
	//glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.42, 0.28);
	glEnd();



	
	//Poins in Queu2
 	glPointSize(14.0);
	glBegin(GL_POINTS);
	//glColor3f(0.0, 0.4, 1.0);	// blue
	glColor3f(0.5, 0.5, 0.5);	// Gray

	glVertex2f(-0.85, -0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.85, -0.28);
	glEnd();
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.8, -0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.8, -0.28);
	glEnd();

	// 15 16
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.75, -0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.75, -0.28);
	glEnd();

	// 13 14 
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.7, -0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.7, -0.28);
	glEnd();

	// 11 12
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.65, -0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.65, -0.28);
	glEnd();

	//9 10 
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.6, -0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.6, -0.28);
	glEnd();

	// 7 8
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.55, -0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.55, -0.28);
	glEnd();

	// 5 6 
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.5, -0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.5, -0.28);
	glEnd();
	// 3 4
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.46, -0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.46, -0.28);
	glEnd();
	// 1 2
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.42, -0.42);
	glEnd();
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5,0.5, 0.5);	// Gray
	glVertex2f(-0.42, -0.28);
	glEnd();



    //points in Inner row 1

	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.02, 0.25);
	glEnd();
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.07, 0.25);
	glEnd();
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.17, 0.25);
	glEnd();
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.27, 0.25);
	glEnd();
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.37, 0.25);
	glEnd();
	//////////////////// row 2
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.02, 0.1);
	glEnd();
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.07, 0.1);
	glEnd();
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.17, 0.1);
	glEnd();
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.27, 0.1);
	glEnd();
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.37, 0.1);
	glEnd();
	
    /////// rwo 3
        
    glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.02, -0.08);
	glEnd();
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.07, -0.08);
	glEnd();
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.17, -0.08);
	glEnd();
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.27, -0.08);
	glEnd();
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.37, -0.08);
	glEnd();
	////// row 4
    glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.02, -0.2);
	glEnd();
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.07, -0.2);
	glEnd();
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.17, -0.2);
	glEnd();
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.27, -0.2);
	glEnd();
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.37, -0.2);
	glEnd();
 ///////////////////points in tallers
//	glVertex2f(0.72, 0.15);

 	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.72, 0.58);
	glEnd();
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.72, 0.15);
	glEnd();
	
	 glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.72, -0.25);
	glEnd();
	
	
	glPointSize(14.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(0.72, -0.65);
	glEnd();
	glFlush();


}

void restMale(){
	glPointSize(15.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.42, -0.28);
	glVertex2f(-0.42, -0.42);
	glVertex2f(-0.46, -0.28);
	glVertex2f(-0.46, -0.42);
	glVertex2f(-0.5, -0.28);
	glVertex2f(-0.5, -0.42);
	glVertex2f(-0.55, -0.28);
	glVertex2f(-0.55, -0.42);
	glVertex2f(-0.6, -0.28);
	glVertex2f(-0.6, -0.42);
	glVertex2f(-0.65, -0.28);
	glVertex2f(-0.65, -0.42);
	glVertex2f(-0.7, -0.28);
	glVertex2f(-0.7, -0.42);
	glVertex2f(-0.75, -0.28);
	glVertex2f(-0.75, -0.42);
	glVertex2f(-0.8, -0.28);
	glVertex2f(-0.8, -0.42);
	glVertex2f(-0.85, -0.28);
	glVertex2f(-0.85, -0.42);

	glEnd();
	glFlush();
}

void printPeopleInMaleQ(int x){
	switch(x){
        case 0:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glVertex2f(-0.46, -0.42);
			glVertex2f(-0.5, -0.28);
			glVertex2f(-0.5, -0.42);
			glVertex2f(-0.55, -0.28);
			glVertex2f(-0.55, -0.42);
			glVertex2f(-0.6, -0.28);
			glVertex2f(-0.6, -0.42);
			glVertex2f(-0.65, -0.28);
			glVertex2f(-0.65, -0.42);
			glVertex2f(-0.7, -0.28);
			glVertex2f(-0.7, -0.42);
			glVertex2f(-0.75, -0.28);
			glVertex2f(-0.75, -0.42);
			glVertex2f(-0.8, -0.28);
			glVertex2f(-0.8, -0.42);
			glVertex2f(-0.85, -0.28);
			glVertex2f(-0.85, -0.42);

			glEnd();
			glFlush();
			break;	

		
		case 1:
			restMale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glEnd();
			glFlush();
			break;
	
		case 2:
			restMale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glEnd();
			glFlush();
			break;

		case 3:
			restMale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glEnd();
			glFlush();
			break;

		case 4:
			restMale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glVertex2f(-0.46, -0.42);
			glEnd();
			glFlush();
			break;

		case 5:
			restMale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glVertex2f(-0.46, -0.42);
			glVertex2f(-0.5, -0.28);
			glEnd();
			glFlush();
			break;

		case 6:
			restMale();	
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glVertex2f(-0.46, -0.42);
			glVertex2f(-0.5, -0.28);
			glVertex2f(-0.5, -0.42);
			glEnd();
			glFlush();
			break;
			
		case 7:
			restMale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glVertex2f(-0.46, -0.42);
			glVertex2f(-0.5, -0.28);
			glVertex2f(-0.5, -0.42);
			glVertex2f(-0.55, -0.28);
			glEnd();
			glFlush();
			break;

		case 8:
			restMale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glVertex2f(-0.46, -0.42);
			glVertex2f(-0.5, -0.28);
			glVertex2f(-0.5, -0.42);
			glVertex2f(-0.55, -0.28);
			glVertex2f(-0.55, -0.42);
			glEnd();
			glFlush();
			break;

		case 9:
			restMale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glVertex2f(-0.46, -0.42);
			glVertex2f(-0.5, -0.28);
			glVertex2f(-0.5, -0.42);
			glVertex2f(-0.55, -0.28);
			glVertex2f(-0.55, -0.42);
			glVertex2f(-0.6, -0.28);
			glEnd();
			glFlush();
			break;

		case 10:
			restMale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glVertex2f(-0.46, -0.42);
			glVertex2f(-0.5, -0.28);
			glVertex2f(-0.5, -0.42);
			glVertex2f(-0.55, -0.28);
			glVertex2f(-0.55, -0.42);
			glVertex2f(-0.6, -0.28);
			glVertex2f(-0.6, -0.42);
			glEnd();
			glFlush();
			break;

		case 11:
			restMale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glVertex2f(-0.46, -0.42);
			glVertex2f(-0.5, -0.28);
			glVertex2f(-0.5, -0.42);
			glVertex2f(-0.55, -0.28);
			glVertex2f(-0.55, -0.42);
			glVertex2f(-0.6, -0.28);
			glVertex2f(-0.6, -0.42);
			glVertex2f(-0.65, -0.28);
			glEnd();
			glFlush();
			break;

		case 12:
			restMale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glVertex2f(-0.46, -0.42);
			glVertex2f(-0.5, -0.28);
			glVertex2f(-0.5, -0.42);
			glVertex2f(-0.55, -0.28);
			glVertex2f(-0.55, -0.42);
			glVertex2f(-0.6, -0.28);
			glVertex2f(-0.6, -0.42);
			glVertex2f(-0.65, -0.28);
			glVertex2f(-0.65, -0.42);
			glEnd();
			glFlush();
			break;

		case 13:
			restMale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glVertex2f(-0.46, -0.42);
			glVertex2f(-0.5, -0.28);
			glVertex2f(-0.5, -0.42);
			glVertex2f(-0.55, -0.28);
			glVertex2f(-0.55, -0.42);
			glVertex2f(-0.6, -0.28);
			glVertex2f(-0.6, -0.42);
			glVertex2f(-0.65, -0.28);
			glVertex2f(-0.65, -0.42);
			glVertex2f(-0.7, -0.28);
			glEnd();
			glFlush();
			break;

		case 14:
			restMale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glVertex2f(-0.46, -0.42);
			glVertex2f(-0.5, -0.28);
			glVertex2f(-0.5, -0.42);
			glVertex2f(-0.55, -0.28);
			glVertex2f(-0.55, -0.42);
			glVertex2f(-0.6, -0.28);
			glVertex2f(-0.6, -0.42);
			glVertex2f(-0.65, -0.28);
			glVertex2f(-0.65, -0.42);
			glVertex2f(-0.7, -0.28);
			glVertex2f(-0.7, -0.42);
			glEnd();
			glFlush();
			break;

		case 15:
			restMale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glVertex2f(-0.46, -0.42);
			glVertex2f(-0.5, -0.28);
			glVertex2f(-0.5, -0.42);
			glVertex2f(-0.55, -0.28);
			glVertex2f(-0.55, -0.42);
			glVertex2f(-0.6, -0.28);
			glVertex2f(-0.6, -0.42);
			glVertex2f(-0.65, -0.28);
			glVertex2f(-0.65, -0.42);
			glVertex2f(-0.7, -0.28);
			glVertex2f(-0.7, -0.42);
			glVertex2f(-0.75, -0.28);
			glEnd();
			glFlush();
			break;

		case 16:
			restMale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glVertex2f(-0.46, -0.42);
			glVertex2f(-0.5, -0.28);
			glVertex2f(-0.5, -0.42);
			glVertex2f(-0.55, -0.28);
			glVertex2f(-0.55, -0.42);
			glVertex2f(-0.6, -0.28);
			glVertex2f(-0.6, -0.42);
			glVertex2f(-0.65, -0.28);
			glVertex2f(-0.65, -0.42);
			glVertex2f(-0.7, -0.28);
			glVertex2f(-0.7, -0.42);
			glVertex2f(-0.75, -0.28);
			glVertex2f(-0.75, -0.42);
			glEnd();
			glFlush();
			break;

		case 17:
			restMale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glVertex2f(-0.46, -0.42);
			glVertex2f(-0.5, -0.28);
			glVertex2f(-0.5, -0.42);
			glVertex2f(-0.55, -0.28);
			glVertex2f(-0.55, -0.42);
			glVertex2f(-0.6, -0.28);
			glVertex2f(-0.6, -0.42);
			glVertex2f(-0.65, -0.28);
			glVertex2f(-0.65, -0.42);
			glVertex2f(-0.7, -0.28);
			glVertex2f(-0.7, -0.42);
			glVertex2f(-0.75, -0.28);
			glVertex2f(-0.75, -0.42);
			glVertex2f(-0.8, -0.28);
			glEnd();
			glFlush();
			break;
		
		case 18:
			restMale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glVertex2f(-0.46, -0.42);
			glVertex2f(-0.5, -0.28);
			glVertex2f(-0.5, -0.42);
			glVertex2f(-0.55, -0.28);
			glVertex2f(-0.55, -0.42);
			glVertex2f(-0.6, -0.28);
			glVertex2f(-0.6, -0.42);
			glVertex2f(-0.65, -0.28);
			glVertex2f(-0.65, -0.42);
			glVertex2f(-0.7, -0.28);
			glVertex2f(-0.7, -0.42);
			glVertex2f(-0.75, -0.28);
			glVertex2f(-0.75, -0.42);
			glVertex2f(-0.8, -0.28);
			glVertex2f(-0.8, -0.42);
			glEnd();
			glFlush();
			break;
		
		case 19:
			restMale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glVertex2f(-0.46, -0.42);
			glVertex2f(-0.5, -0.28);
			glVertex2f(-0.5, -0.42);
			glVertex2f(-0.55, -0.28);
			glVertex2f(-0.55, -0.42);
			glVertex2f(-0.6, -0.28);
			glVertex2f(-0.6, -0.42);
			glVertex2f(-0.65, -0.28);
			glVertex2f(-0.65, -0.42);
			glVertex2f(-0.7, -0.28);
			glVertex2f(-0.7, -0.42);
			glVertex2f(-0.75, -0.28);
			glVertex2f(-0.75, -0.42);
			glVertex2f(-0.8, -0.28);
			glVertex2f(-0.8, -0.42);
			glVertex2f(-0.85, -0.28);

			glEnd();
			glFlush();
			break;

		case 20:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.4, 1.0);	// blue
			glVertex2f(-0.42, -0.28);
			glVertex2f(-0.42, -0.42);
			glVertex2f(-0.46, -0.28);
			glVertex2f(-0.46, -0.42);
			glVertex2f(-0.5, -0.28);
			glVertex2f(-0.5, -0.42);
			glVertex2f(-0.55, -0.28);
			glVertex2f(-0.55, -0.42);
			glVertex2f(-0.6, -0.28);
			glVertex2f(-0.6, -0.42);
			glVertex2f(-0.65, -0.28);
			glVertex2f(-0.65, -0.42);
			glVertex2f(-0.7, -0.28);
			glVertex2f(-0.7, -0.42);
			glVertex2f(-0.75, -0.28);
			glVertex2f(-0.75, -0.42);
			glVertex2f(-0.8, -0.28);
			glVertex2f(-0.8, -0.42);
			glVertex2f(-0.85, -0.28);
			glVertex2f(-0.85, -0.42);

			glEnd();
			glFlush();
			break;	

		default:
			break;
	
	
	}

}

void restFemale(){
	glPointSize(15.0);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5, 0.5);	// Gray
	glVertex2f(-0.42, 0.28);
	glVertex2f(-0.42, 0.42);
	glVertex2f(-0.46, 0.28);
	glVertex2f(-0.46, 0.42);
	glVertex2f(-0.5, 0.28);
	glVertex2f(-0.5, 0.42);
	glVertex2f(-0.55, 0.28);
	glVertex2f(-0.55, 0.42);
	glVertex2f(-0.6, 0.28);
	glVertex2f(-0.6, 0.42);
	glVertex2f(-0.65, 0.28);
	glVertex2f(-0.65, 0.42);
	glVertex2f(-0.7, 0.28);
	glVertex2f(-0.7, 0.42);
	glVertex2f(-0.75, 0.28);
	glVertex2f(-0.75, 0.42);
	glVertex2f(-0.8, 0.28);
	glVertex2f(-0.8, 0.42);
	glVertex2f(-0.85, 0.28);
	glVertex2f(-0.85, 0.42);

	glEnd();
	glFlush();
}
 void printPeopleInFemaleQ(int x1){
	switch(x1){
        case 0:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glVertex2f(-0.46, 0.42);
			glVertex2f(-0.5, 0.28);
			glVertex2f(-0.5, 0.42);
			glVertex2f(-0.55, 0.28);
			glVertex2f(-0.55, 0.42);
			glVertex2f(-0.6, 0.28);
			glVertex2f(-0.6, 0.42);
			glVertex2f(-0.65, 0.28);
			glVertex2f(-0.65, 0.42);
			glVertex2f(-0.7, 0.28);
			glVertex2f(-0.7, 0.42);
			glVertex2f(-0.75, 0.28);
			glVertex2f(-0.75, 0.42);
			glVertex2f(-0.8, 0.28);
			glVertex2f(-0.8, 0.42);
			glVertex2f(-0.85, 0.28);
			glVertex2f(-0.85, 0.42);

			glEnd();
			glFlush();
			break;	

		
		case 1:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glEnd();
			glFlush();
			break;
	
		case 2:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glEnd();
			glFlush();
			break;

		case 3:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glEnd();
			glFlush();
			break;

		case 4:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glVertex2f(-0.46, 0.42);
			glEnd();
			glFlush();
			break;

		case 5:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glVertex2f(-0.46, 0.42);
			glVertex2f(-0.5,  0.28);
			glEnd();
			glFlush();
			break;

		case 6:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glVertex2f(-0.46, 0.42);
			glVertex2f(-0.5, 0.28);
			glVertex2f(-0.5, 0.42);
			glEnd();
			glFlush();
			break;
			
		case 7:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glVertex2f(-0.46, 0.42);
			glVertex2f(-0.5, 0.28);
			glVertex2f(-0.5, 0.42);
			glVertex2f(-0.55, 0.28);
			glEnd();
			glFlush();
			break;

		case 8:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glVertex2f(-0.46, 0.42);
			glVertex2f(-0.5, 0.28);
			glVertex2f(-0.5, 0.42);
			glVertex2f(-0.55, 0.28);
			glVertex2f(-0.55, 0.42);
			glEnd();
			glFlush();
			break;

		case 9:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glVertex2f(-0.46, 0.42);
			glVertex2f(-0.5, 0.28);
			glVertex2f(-0.5, 0.42);
			glVertex2f(-0.55, 0.28);
			glVertex2f(-0.55, 0.42);
			glVertex2f(-0.6, 0.28);
			glEnd();
			glFlush();
			break;

		case 10:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glVertex2f(-0.46, 0.42);
			glVertex2f(-0.5, 0.28);
			glVertex2f(-0.5, 0.42);
			glVertex2f(-0.55, 0.28);
			glVertex2f(-0.55, 0.42);
			glVertex2f(-0.6, 0.28);
			glVertex2f(-0.6, 0.42);
			glEnd();
			glFlush();
			break;

		case 11:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glVertex2f(-0.46, 0.42);
			glVertex2f(-0.5, 0.28);
			glVertex2f(-0.5, 0.42);
			glVertex2f(-0.55, 0.28);
			glVertex2f(-0.55, 0.42);
			glVertex2f(-0.6, 0.28);
			glVertex2f(-0.6, 0.42);
			glVertex2f(-0.65, 0.28);
			glEnd();
			glFlush();
			break;

		case 12:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glVertex2f(-0.46, 0.42);
			glVertex2f(-0.5, 0.28);
			glVertex2f(-0.5, 0.42);
			glVertex2f(-0.55, 0.28);
			glVertex2f(-0.55, 0.42);
			glVertex2f(-0.6, 0.28);
			glVertex2f(-0.6, 0.42);
			glVertex2f(-0.65, 0.28);
			glVertex2f(-0.65, 0.42);
			glEnd();
			glFlush();
			break;

		case 13:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glVertex2f(-0.46, 0.42);
			glVertex2f(-0.5, 0.28);
			glVertex2f(-0.5, 0.42);
			glVertex2f(-0.55, 0.28);
			glVertex2f(-0.55, 0.42);
			glVertex2f(-0.6, 0.28);
			glVertex2f(-0.6, 0.42);
			glVertex2f(-0.65, 0.28);
			glVertex2f(-0.65, 0.42);
			glVertex2f(-0.7, 0.28);
			glEnd();
			glFlush();
			break;

		case 14:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glVertex2f(-0.46, 0.42);
			glVertex2f(-0.5, 0.28);
			glVertex2f(-0.5, 0.42);
			glVertex2f(-0.55,0.28);
			glVertex2f(-0.55, 0.42);
			glVertex2f(-0.6, 0.28);
			glVertex2f(-0.6, 0.42);
			glVertex2f(-0.65, 0.28);
			glVertex2f(-0.65, 0.42);
			glVertex2f(-0.7, 0.28);
			glVertex2f(-0.7, 0.42);
			glEnd();
			glFlush();
			break;

		case 15:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glVertex2f(-0.46, 0.42);
			glVertex2f(-0.5, 0.28);
			glVertex2f(-0.5, 0.42);
			glVertex2f(-0.55, 0.28);
			glVertex2f(-0.55, 0.42);
			glVertex2f(-0.6, 0.28);
			glVertex2f(-0.6, 0.42);
			glVertex2f(-0.65, 0.28);
			glVertex2f(-0.65, 0.42);
			glVertex2f(-0.7, 0.28);
			glVertex2f(-0.7, 0.42);
			glVertex2f(-0.75, 0.28);
			glEnd();
			glFlush();
			break;

		case 16:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glVertex2f(-0.46, 0.42);
			glVertex2f(-0.5, 0.28);
			glVertex2f(-0.5, 0.42);
			glVertex2f(-0.55, 0.28);
			glVertex2f(-0.55, 0.42);
			glVertex2f(-0.6, 0.28);
			glVertex2f(-0.6, 0.42);
			glVertex2f(-0.65, 0.28);
			glVertex2f(-0.65, 0.42);
			glVertex2f(-0.7, 0.28);
			glVertex2f(-0.7, 0.42);
			glVertex2f(-0.75, 0.28);
			glVertex2f(-0.75, 0.42);
			glEnd();
			glFlush();
			break;

		case 17:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glVertex2f(-0.46, 0.42);
			glVertex2f(-0.5, 0.28);
			glVertex2f(-0.5, 0.42);
			glVertex2f(-0.55, 0.28);
			glVertex2f(-0.55, 0.42);
			glVertex2f(-0.6, 0.28);
			glVertex2f(-0.6, 0.42);
			glVertex2f(-0.65, 0.28);
			glVertex2f(-0.65, 0.42);
			glVertex2f(-0.7, 0.28);
			glVertex2f(-0.7, 0.42);
			glVertex2f(-0.75, 0.28);
			glVertex2f(-0.75, 0.42);
			glVertex2f(-0.8, 0.28);
			glEnd();
			glFlush();
			break;
		
		case 18:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glVertex2f(-0.46, 0.42);
			glVertex2f(-0.5, 0.28);
			glVertex2f(-0.5, 0.42);
			glVertex2f(-0.55, 0.28);
			glVertex2f(-0.55, 0.42);
			glVertex2f(-0.6, 0.28);
			glVertex2f(-0.6, 0.42);
			glVertex2f(-0.65, 0.28);
			glVertex2f(-0.65, 0.42);
			glVertex2f(-0.7, 0.28);
			glVertex2f(-0.7, 0.42);
			glVertex2f(-0.75, 0.28);
			glVertex2f(-0.75, 0.42);
			glVertex2f(-0.8, 0.28);
			glVertex2f(-0.8, 0.42);
			glEnd();
			glFlush();
			break;
		
		case 19:
			restFemale();
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glVertex2f(-0.46, 0.42);
			glVertex2f(-0.5, 0.28);
			glVertex2f(-0.5, 0.42);
			glVertex2f(-0.55, 0.28);
			glVertex2f(-0.55, 0.42);
			glVertex2f(-0.6, 0.28);
			glVertex2f(-0.6, 0.42);
			glVertex2f(-0.65, 0.28);
			glVertex2f(-0.65, 0.42);
			glVertex2f(-0.7, 0.28);
			glVertex2f(-0.7, 0.42);
			glVertex2f(-0.75, 0.28);
			glVertex2f(-0.75, 0.42);
			glVertex2f(-0.8, 0.28);
			glVertex2f(-0.8, 0.42);
			glVertex2f(-0.85, 0.28);

			glEnd();
			glFlush();
			break;

		case 20:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 0.0, 0.0);	// red
			glVertex2f(-0.42, 0.28);
			glVertex2f(-0.42, 0.42);
			glVertex2f(-0.46, 0.28);
			glVertex2f(-0.46, 0.42);
			glVertex2f(-0.5, 0.28);
			glVertex2f(-0.5, 0.42);
			glVertex2f(-0.55, 0.28);
			glVertex2f(-0.55, 0.42);
			glVertex2f(-0.6, 0.28);
			glVertex2f(-0.6, 0.42);
			glVertex2f(-0.65, 0.28);
			glVertex2f(-0.65, 0.42);
			glVertex2f(-0.7, 0.28);
			glVertex2f(-0.7, 0.42);
			glVertex2f(-0.75, 0.28);
			glVertex2f(-0.75, 0.42);
			glVertex2f(-0.8, 0.28);
			glVertex2f(-0.8, 0.42);
			glVertex2f(-0.85, 0.28);
			glVertex2f(-0.85, 0.42);

			glEnd();
			glFlush();
			break;	

		default:
			break;
	
	
	}
 }
void printPeopleInMCHQ(int x2){
	switch(x2){
        case 0:
			glPointSize(17.0);
			glBegin(GL_POINTS);
			glColor3f(0.8, 0.8, 0.8);	// black
			glVertex2f(-0.25, 0.0);
			glEnd();
			glFlush();
			break;
		case 1:
			glPointSize(17.0);
			glBegin(GL_POINTS);
			glColor3f(1.3, 0.0, 0.8);
			glVertex2f(-0.25, 0.0);
			glEnd();
			glFlush();
			break;

	}
}
void printPeopleInInnerEreaQ(int x3){
	switch(x3){
        case 0:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(-0.02, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.37, 0.25);
			glVertex2f(-0.02, 0.1);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.37, 0.1);
			glVertex2f(-0.02, -0.08);
			glVertex2f(0.07, -0.08);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.37, -0.08);
			glVertex2f(-0.02, -0.2);
			glVertex2f(0.07, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.37, -0.2);
			

			glEnd();
			glFlush();
			break;	

		
		case 1:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glEnd();
			glFlush();

			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.07, -0.08);
			glVertex2f(0.07, -0.2);
			glVertex2f(-0.02, -0.2);
			glVertex2f(-0.02, -0.08);
			glVertex2f(-0.02, 0.1);
			glVertex2f(-0.02, 0.25);
			glEnd();
			glFlush();
			break;
	
		case 2:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glEnd();
			glFlush();

			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.07, -0.08);
			glVertex2f(0.07, -0.2);
			glVertex2f(-0.02, -0.2);
			glVertex2f(-0.02, -0.08);
			glVertex2f(-0.02, 0.1);
			glVertex2f(-0.02, 0.25);
			glEnd();
			glFlush();
			break;

		case 3:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glEnd();
			glFlush();

			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.07, -0.08);
			glVertex2f(0.07, -0.2);
			glVertex2f(-0.02, -0.2);
			glVertex2f(-0.02, -0.08);
			glVertex2f(-0.02, 0.1);
			glVertex2f(-0.02, 0.25);
			glEnd();
			glFlush();
			break;

		case 4:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glEnd();
			glFlush();

			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.07, -0.08);
			glVertex2f(0.07, -0.2);
			glVertex2f(-0.02, -0.2);
			glVertex2f(-0.02, -0.08);
			glVertex2f(-0.02, 0.1);
			glVertex2f(-0.02, 0.25);
			glEnd();
			glFlush();
			break;

		case 5:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glEnd();
			glFlush();

			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.07, -0.08);
			glVertex2f(0.07, -0.2);
			glVertex2f(-0.02, -0.2);
			glVertex2f(-0.02, -0.08);
			glVertex2f(-0.02, 0.1);
			glVertex2f(-0.02, 0.25);
			glEnd();
			glFlush();
			break;

		case 6:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glEnd();
			glFlush();

			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.07, -0.08);
			glVertex2f(0.07, -0.2);
			glVertex2f(-0.02, -0.2);
			glVertex2f(-0.02, -0.08);
			glVertex2f(-0.02, 0.1);
			glVertex2f(-0.02, 0.25);
			glEnd();
			glFlush();
			break;

		case 7:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glEnd();
			glFlush();

			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray		
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.07, -0.08);
			glVertex2f(0.07, -0.2);
			glVertex2f(-0.02, -0.2);
			glVertex2f(-0.02, -0.08);
			glVertex2f(-0.02, 0.1);
			glVertex2f(-0.02, 0.25);
			glEnd();
			glFlush();
			break;

		case 8:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);

			
			glEnd();
			glFlush();

			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.07, -0.08);
			glVertex2f(0.07, -0.2);
			glVertex2f(-0.02, -0.2);
			glVertex2f(-0.02, -0.08);
			glVertex2f(-0.02, 0.1);
			glVertex2f(-0.02, 0.25);
			glEnd();
			glFlush();
			break;

		case 9:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glEnd();
			glFlush();

			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.07, -0.08);
			glVertex2f(0.07, -0.2);
			glVertex2f(-0.02, -0.2);
			glVertex2f(-0.02, -0.08);
			glVertex2f(-0.02, 0.1);
			glVertex2f(-0.02, 0.25);
			glEnd();
			glFlush();
			break;

		case 10:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glEnd();
			glFlush();

			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.07, -0.08);
			glVertex2f(0.07, -0.2);
			glVertex2f(-0.02, -0.2);
			glVertex2f(-0.02, -0.08);
			glVertex2f(-0.02, 0.1);
			glVertex2f(-0.02, 0.25);
			glEnd();
			glFlush();
			break;

		case 11:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.07, -0.08);
			glVertex2f(0.07, -0.2);
			glVertex2f(-0.02, -0.2);
			glVertex2f(-0.02, -0.08);
			glVertex2f(-0.02, 0.1);
			glVertex2f(-0.02, 0.25);
			glEnd();
			glFlush();
			glEnd();
			glFlush();
			break;

		case 12:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glEnd();
			glFlush();
			
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.07, -0.08);
			glVertex2f(0.07, -0.2);
			glVertex2f(-0.02, -0.2);
			glVertex2f(-0.02, -0.08);
			glVertex2f(-0.02, 0.1);
			glVertex2f(-0.02, 0.25);
			glEnd();
			glFlush();
			break;
			
		case 13:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glEnd();
			glFlush();

			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glEnd();
			glFlush();
			break;

		case 14:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glEnd();
			glFlush();

			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glEnd();
			glFlush();
			break;

		case 15:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.07, -0.08);
			glEnd();
			glFlush();

			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(0.07, -0.2);
			glVertex2f(-0.02, -0.2);
			glVertex2f(-0.02, -0.08);
			glVertex2f(-0.02, 0.1);
			glVertex2f(-0.02, 0.25);
			glEnd();
			glFlush();
			break;	

		case 16:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.07, -0.08);
			glVertex2f(0.07, -0.2);
			glEnd();
			glFlush();

			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(-0.02, -0.2);
			glVertex2f(-0.02, -0.08);
			glVertex2f(-0.02, 0.1);
			glVertex2f(-0.02, 0.25);
			glEnd();
			glFlush();
			break;	

		case 17:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.07, -0.08);
			glVertex2f(0.07, -0.2);
			glVertex2f(-0.02, -0.2);
			glEnd();
			glFlush();

			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(-0.02, -0.08);
			glVertex2f(-0.02, 0.1);
			glVertex2f(-0.02, 0.25);
			glEnd();
			glFlush();
			break;

		case 18:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.07, -0.08);
			glVertex2f(0.07, -0.2);
			glVertex2f(-0.02, -0.2);
			glVertex2f(-0.02, -0.08);
			glEnd();
			glFlush();

			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(-0.02, 0.1);
			glVertex2f(-0.02, 0.25);
			glEnd();
			glFlush();
			break;

		case 19:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.07, -0.08);
			glVertex2f(0.07, -0.2);
			glVertex2f(-0.02, -0.2);
			glVertex2f(-0.02, -0.08);
			glVertex2f(-0.02, 0.1);
			glEnd();
			glFlush();


			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);	// Gray
			glVertex2f(-0.02, 0.25);
			glEnd();
			glFlush();

			break;

		case 20:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 0.0);	// yallow
			glVertex2f(0.37, 0.1);
			glVertex2f(0.37, -0.08);
			glVertex2f(0.37, -0.2);
			glVertex2f(0.37, 0.25);
			glVertex2f(0.27, 0.25);
			glVertex2f(0.27, 0.1);
			glVertex2f(0.27, -0.08);
			glVertex2f(0.27, -0.2);
			glVertex2f(0.17, -0.2);
			glVertex2f(0.17, -0.08);
			glVertex2f(0.17, 0.1);
			glVertex2f(0.17, 0.25);
			glVertex2f(0.07, 0.25);
			glVertex2f(0.07, 0.1);
			glVertex2f(0.07, -0.08);
			glVertex2f(0.07, -0.2);
			glVertex2f(-0.02, -0.2);
			glVertex2f(-0.02, -0.08);
			glVertex2f(-0.02, 0.1);
			glVertex2f(-0.02, 0.25);
			glEnd();
			glFlush();
			break;
			
			default:
				break;

	}
}

void printPeopleInBxQ(int x4){
	switch(x4){
        case 0:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);
			glVertex2f(0.72, 0.58);
			glEnd();
			glFlush();
			break;
		case 1:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.3, 0.0, 0.8);
			glVertex2f(0.72, 0.58);
			glEnd();
			glFlush();
			break;

	}
}
void printPeopleInTxQ(int x5){
	switch(x5){
        case 0:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);
			glVertex2f(0.72, 0.15);
			glEnd();
			glFlush();
			break;
		case 1:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.3, 0.0, 0.8);
			glVertex2f(0.72, 0.15);
			glEnd();
			glFlush();
			break;

	}
}
void printPeopleInRxQ(int x6){
	switch(x6){
        case 0:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);
			glVertex2f(0.72, -0.25);
			glEnd();
			glFlush();
			break;
		case 1:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.3, 0.0, 0.8);
			glVertex2f(0.72, -0.25);
			glEnd();
			glFlush();
			break;

	}
}
void printPeopleInIxQ(int x7){

	switch(x7){
        case 0:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(0.5, 0.5, 0.5);
			glVertex2f(0.72, -0.65);
			glEnd();
			glFlush();
			break;
		case 1:
			glPointSize(15.0);
			glBegin(GL_POINTS);
			glColor3f(1.3, 0.0, 0.8);
			glVertex2f(0.72, -0.65);
			glEnd();
			glFlush();
			break;
	}
}



void printPeople(int num){
	s11 = (int *) shmat(shmID11, NULL, 0);
	printPeopleInMaleQ(s11[0]);
	printPeopleInFemaleQ(s11[1]);
	printPeopleInMCHQ(s11[2]);
	printPeopleInInnerEreaQ(s11[3]);
	printPeopleInBxQ(s11[4]);
	printPeopleInTxQ(s11[5]);
	printPeopleInRxQ(s11[6]);
	printPeopleInIxQ(s11[7]);
	shmdt(s11);

}

void initGL()
{
	glClearColor(0.0, 1.1, 0.0, 1.0);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);    // Clear the color buffer
    glMatrixMode(GL_MODELVIEW);      // To operate on Model-View matrix
    glLoadIdentity();

	//glBegin(GL_LINE_LOOP);
	//glColor3f(0.0, 1.0, 1.0);
	//glVertex2f(1.2, 0.8);	//x, y
	//glVertex2f(-1.2, 0.8);
	//glVertex2f(-1.2, -0.8);
	//glVertex2f(1.2, -0.8);
	//glEnd();


	glColor3f (1.0, 0.9, 1.0);
    glRasterPos2f(-0.8, 0.55);
  	int len, i;
	char string[] = "Queu For Female";
  	len = (int)strlen(string);
  	for (i = 0; i < len; i++) {
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
  	}


	glColor3f (1.0, 0.9, 1.0);
    glRasterPos2f(-0.8,-0.15);
	char string1[] = "Queu For Male";
  	len = (int)strlen(string1);
  	for (i = 0; i < len; i++) {
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string1[i]);
  	}

	glColor3f (1.0, 0.9, 1.0);
    glRasterPos2f(-0.23,0.15);
	char string2[] = "Officer";
  	len = (int)strlen(string2);
  	for (i = 0; i < len; i++) {
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string2[i]);
  	}

	glColor3f (1.0, 0.9, 1.0);
    glRasterPos2f(0.07,0.45);
	char string3[] = "Inner grouping area";
  	len = (int)strlen(string3);
  	for (i = 0; i < len; i++) {
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string3[i]);
  	}

	glColor3f (1.0, 0.9, 1.0);
    glRasterPos2f(0.75,0.77);
	char string4[] = "Tellers";
  	len = (int)strlen(string4);
  	for (i = 0; i < len; i++) {
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string4[i]);
  	}
	//
	glColor3f (1.0, 0.9, 1.0);
    glRasterPos2f(0.87,0.14);
	char s1[] = "travel\ndocument";
	
  	len = (int)strlen(s1);
  	for (i = 0; i < len; i++) {
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s1[i]);
  	}

	glColor3f (1.0, 0.9, 1.0);
    glRasterPos2f(0.87,0.54);
	
	char s2[] = "birth\ncertificate";

  	len = (int)strlen(s2);
  	for (i = 0; i < len; i++) {
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s2[i]);
  	}

	glColor3f (1.0, 0.9, 1.0);
    glRasterPos2f(0.87,-0.25);
	char s3[] = "family\nreunion";
  	len = (int)strlen(s3);
  	for (i = 0; i < len; i++) {
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s3[i]);
  	}

	glColor3f (1.0, 0.9, 1.0);
    glRasterPos2f(0.87,-0.65);
	char s4[] = "ID\nrelated";
  	len = (int)strlen(s4);
  	for (i = 0; i < len; i++) {
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s4[i]);
  	}

	 
	
	//  glColor3f(0.0, 1.0, 0.0);
	//  glBegin(GL_POLYGON);
	//  glVertex3f(2.0, 4.0, 0.0);
	//  glVertex3f(8.0, 4.0, 0.0);
	//  glVertex3f(8.0, 6.0, 0.0);
	//  glVertex3f(2.0, 6.0, 0.0);
	//  glEnd();
	 
	 
	glColor3f(0.8, 0.9, 0.8);
	glBegin(GL_QUADS);
	glVertex2f(-0.88, 0.2);	//x, y
	glVertex2f(-0.88, 0.5);
	glVertex2f(-0.4, 0.5);
	glVertex2f(-0.4, 0.2);
	glEnd();
	
	
	glColor3f(0.8, 0.9, 0.8);
	glBegin(GL_QUADS);
	glVertex2f(-0.88, -0.2);	//x, y
	glVertex2f(-0.88, -0.5);
	glVertex2f(-0.4, -0.5);
	glVertex2f(-0.4, -0.2);
	glEnd();
	
	glPointSize(19.0);
	glBegin(GL_POINTS);
	glColor3f(0.9, 0.6, 0.6);	
	glVertex2f(-0.2, 0.0);
	glEnd();

	glBegin(GL_LINE_LOOP);//line between point  and weting room
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(-0.0, 0.05);	//x, y
	glVertex2f(-0.0, -0.05);
	glVertex2f(-0.2, -0.01);
	glVertex2f(-0.2, 0.01);

	glEnd();

	glBegin(GL_LINE_LOOP);//line between box and point
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(-0.4, 0.4);	//x, y
	glVertex2f(-0.4, 0.34);
	glVertex2f(-0.2, -0.01);
	glVertex2f(-0.2, 0.01);

	glEnd();
	
	glBegin(GL_LINE_LOOP);//line between box and point
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(-0.4, -0.4);	//x, y
	glVertex2f(-0.4, -0.34);
	glVertex2f(-0.2, 0.01);
	glVertex2f(-0.2, -0.01);

	glEnd();
	
	
	
	////////////////////////////////////
	glColor3f(0.3, 0.9, 0.6);
	glBegin(GL_QUADS);
	glVertex2f(0.86, -0.8);	//x, y
	glVertex2f(0.86, -0.5);
	glVertex2f(0.67, -0.5);
	glVertex2f(0.67, -0.8);
	glEnd();


	glLineWidth((GLfloat)5);
	glBegin(GL_LINE_LOOP);//line between Solder and arab people
	glColor3f(2.0, 1.0, 2.0);
	glVertex2f(0.8, -0.8);	//x, y
	glVertex2f(0.8, -0.5);
	glEnd();

	glLineWidth((GLfloat)2);
	glBegin(GL_LINE_LOOP);//line between box and point
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(0.67, -0.6);	//x, y
	glVertex2f(0.67, -0.63);
	glVertex2f(0.45, -0.28);
	glVertex2f(0.45, -0.25);
	glEnd();
	//
	glColor3f(0.3, 0.9, 0.6);
	glBegin(GL_QUADS);
	glVertex2f(0.86, -0.1);	//x, y
	glVertex2f(0.86, -0.4);
	glVertex2f(0.67, -0.4);
	glVertex2f(0.67, -0.1);
	glEnd();

	glLineWidth((GLfloat)5);
	glBegin(GL_LINE_LOOP);//line between Solder and arab people
	glColor3f(2.0, 1.0, 2.0);
	glVertex2f(0.8, -0.4);	//x, y
	glVertex2f(0.8, -0.1);
	glEnd();

	glLineWidth((GLfloat)2);
	glBegin(GL_LINE_LOOP);//line between box and point
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(0.67, -0.25);	//x, y
	glVertex2f(0.67, -0.28);
	glVertex2f(0.45, -0.13);
	glVertex2f(0.45, -0.1);
	glEnd();
	//
	glColor3f(0.3, 0.9, 0.6);
	glBegin(GL_QUADS);
	glVertex2f(0.86, 0.0);	//x, y
	glVertex2f(0.86, 0.3);
	glVertex2f(0.67, 0.3);
	glVertex2f(0.67, 0.0);
	glEnd();

	glLineWidth((GLfloat)5);
	glBegin(GL_LINE_LOOP);//line between Solder and arab people
	glColor3f(2.0, 1.0, 2.0);
	glVertex2f(0.8, 0.3);	//x, y
	glVertex2f(0.8, 0.0);
	glEnd();

	glLineWidth((GLfloat)2);
	glBegin(GL_LINE_LOOP);//line between box and point
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(0.67, 0.15);	//x, y
	glVertex2f(0.67, 0.12);
	glVertex2f(0.45, 0.05);
	glVertex2f(0.45, 0.08);
	glEnd();
	//
	glColor3f(0.3, 0.9, 0.6);
	glBegin(GL_QUADS);
	glVertex2f(0.86, 0.4);	//x, y
	glVertex2f(0.86, 0.7);
	glVertex2f(0.67, 0.7);
	glVertex2f(0.67, 0.4);
	glEnd();

	glLineWidth((GLfloat)5);
	glBegin(GL_LINE_LOOP);//line between Solder and arab people
	glColor3f(2.0, 1.0, 2.0);
	glVertex2f(0.8, 0.7);	//x, y
	glVertex2f(0.8, 0.4);
	glEnd();

	glLineWidth((GLfloat)2);
	glBegin(GL_LINE_LOOP);//line between box and point
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(0.67, 0.55);	//x, y
	glVertex2f(0.67, 0.52);
	glVertex2f(0.45, 0.2);
	glVertex2f(0.45, 0.23);
	glEnd();

	////////////////////
	glColor3f(0.2, 0.2, 0.4);//Blue-Green
	glBegin(GL_QUADS);
	glVertex2f(0.45, -0.35);	//x, y
	glVertex2f(0.45, 0.35);
	glVertex2f(-0.1, 0.35);
	glVertex2f(-0.1, -0.35);
	glEnd();




	reset();

	glFlush();	// Render now  
}
void reshape(GLsizei width, GLsizei height)
{
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);

}


int main(int argc, char **argv)
{

	struct sigaction sa = { 0 };
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &printPeople;
	sigaction(SIGUSR1, &sa, NULL);	// green

   	shmID11 = shmget(1111, sizeof(int)*8 , 0666 | IPC_CREAT);
    if (shmID11 < 0) {
        printf("error shmID10\n");
        exit(1);
    }
	
	glutInit(&argc, argv);
	glutInitWindowSize(1620, 600);
	glutInitWindowPosition(140, 190);
	glutCreateWindow("Running Processes");
	glutDisplayFunc(display);
	//glutReshapeFunc(reshape);

	glutMainLoop();

	initGL();

	while (1);
	

	
	

	return 0;
}





