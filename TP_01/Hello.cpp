/*
 * Copyright (c) 1993-1997, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED
 * Permission to use, copy, modify, and distribute this software for
 * any purpose and without fee is hereby granted, provided that the above
 * copyright notice appear in all copies and that both the copyright notice
 * and this permission notice appear in supporting documentation, and that
 * the name of Silicon Graphics, Inc. not be used in advertising
 * or publicity pertaining to distribution of the software without specific,
 * written prior permission.
 *
 * THE MATERIAL EMBODIED ON THIS SOFTWARE IS PROVIDED TO YOU "AS-IS"
 * AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR
 * FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL SILICON
 * GRAPHICS, INC.  BE LIABLE TO YOU OR ANYONE ELSE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY
 * KIND, OR ANY DAMAGES WHATSOEVER, INCLUDING WITHOUT LIMITATION,
 * LOSS OF PROFIT, LOSS OF USE, SAVINGS OR REVENUE, OR THE CLAIMS OF
 * THIRD PARTIES, WHETHER OR NOT SILICON GRAPHICS, INC.  HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH LOSS, HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE
 * POSSESSION, USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * US Government Users Restricted Rights
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions set forth in FAR 52.227.19(c)(2) or subparagraph
 * (c)(1)(ii) of the Rights in Technical Data and Computer Software
 * clause at DFARS 252.227-7013 and/or in similar or successor
 * clauses in the FAR or the DOD or NASA FAR Supplement.
 * Unpublished-- rights reserved under the copyright laws of the
 * United States.  Contractor/manufacturer is Silicon Graphics,
 * Inc., 2011 N.  Shoreline Blvd., Mountain View, CA 94039-7311.
 *
 * OpenGL(R) is a registered trademark of Silicon Graphics, Inc.
 */

/*
 * hello.c
 * This is a simple, introductory OpenGL program.
 */
#include <math.h>
#include <GL/glut.h>

const float PI = 3.14159265359;

//***********TRIANGLE**************//
void drawTriangle(){

	
   glBegin(GL_LINE_LOOP);
   glColor3f (1.0, 1.0, 1.0);
      glVertex3f (0.05, 0.25, 0.0);
      glVertex3f (0.35, 0.25, 0.0);
      glVertex3f (0.05, 0.75, 0.0);
   glEnd();

   glBegin(GL_LINE_LOOP);
   glColor3f (1.0, 0.0, 1.0);
      glVertex3f (0.40, 0.25, 0.0);
      glVertex3f (0.60, 0.25, 0.0);
      glVertex3f (0.40, 0.50, 0.0);
   glEnd();

   glBegin(GL_LINE_LOOP);
   glColor3f (1.0, 1.0, 0.0);
      glVertex3f (0.65, 0.25, 0.0);
      glVertex3f (0.80, 0.25, 0.0);
      glVertex3f (0.65, 0.40, 0.0);
   glEnd();
}


	//***********CERCLE***************//
void drawCircle(float rayon, float nb_cotée){

   //Centre : 0.5,0.5,0.0.
   float angle = 2*PI/nb_cotée;

	  glBegin(GL_LINE_LOOP);
	  glColor3f (1.0, 1.0, 1.0);
   for(float i=0;i<nb_cotée;i++){
      glVertex3f (0.5+rayon*cos(angle*i), 0.5+rayon*sin(angle*i), 0.0);
   }
   glEnd();

}

void drawexo2(float rayon, float nb_cotée,float nb_cercle){
	
	float angle = 2*PI/nb_cotée;
	int j,i;
	float centre=0.1;

	for(j=0;j<nb_cercle;j++){
		glBegin(GL_LINE_LOOP);	
			glColor3f (1.0, 1.0, 1.0);
			for(i=0;i<nb_cotée;i++){
				glVertex3f (centre+rayon*cos(angle*i), 0.5+rayon*sin(angle*i), 0.0);
			}
			
			centre+=rayon;
			rayon=rayon*2;
		glEnd();
	}
}

void drawexo3(float rayon, float nb_cotée,float nb_cercle){
	float angle = 2*PI/nb_cotée;
	int j,i;
	float centre=0.1;

	for(j=0;j<nb_cercle;j++){
		glBegin(GL_LINE_LOOP);	
			glColor3f (1.0, 1.0, 1.0);
			for(i=0;i<nb_cotée;i++){
				glVertex3f (centre+rayon*cos(angle*i), 0.5+rayon*sin(angle*i), 0.0);
			}
			
			centre+=rayon;
			rayon=rayon/1.5;
			centre+=rayon;
		glEnd();
	}
}
void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);

	//drawTriangle();
	//drawCircle(0.4,100.);
   //drawexo2(0.1,100.,5.);
   drawexo3(0.1,100,6.);


   glutSwapBuffers();
}

void init (void)
{
/* select clearing color     */
   glClearColor (0.0, 0.0, 0.0, 0.0);

/* initialize viewing values  */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

/*
 * Declare initial window size, position, and display mode
 * (double buffer and RGB).  Open window with "hello"
 * in its title bar.  Call initialization routines.
 * Register callback function to display graphics.
 * Enter main loop and process events.
 */
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (1000, 1000);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("TP_01");
   init ();
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;   /* ANSI C requires main to return int. */
}
