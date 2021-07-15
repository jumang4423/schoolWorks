#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>


static void display(void) {
  // repaint the background with the color 
  // specified by glClearColor()
  glClear (GL_COLOR_BUFFER_BIT);

  // Points
  glPointSize(5.f);
  glBegin(GL_POINTS);
  glColor3f(0.f,0.f,0.f);
  glVertex3f(0.1f,0.1f,0.f);
  glVertex3f(0.25f,0.1f,0.f);
  glEnd();

  // Lines
  glBegin(GL_LINES);
  glVertex3f(0.2f,0.2f,0.f);
  glVertex3f(0.45f,0.5f,0.f);
  glEnd();

  // Triangles
  glColor3f(0.1f,0.1f,1.f);
  glBegin(GL_TRIANGLES);
  glVertex3f(0.6f,0.6f,0.f);
  glVertex3f(0.9f,0.6f,0.f);
  glVertex3f(0.8f,0.9f,0.f);
  glEnd();

  glutSwapBuffers();
}


// No need to modify the functions below
//

static void init (void) {
  // set the color for painting the background
  glClearColor (1.0, 1.0, 1.0, 1.0);

  // set an orthographic projection
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0); 
}


static void keyHandle(unsigned char key, int x, int y) {
  // exit when ESC is pressed
  if (key == 27) exit(0);
}


int main(int argc, char** argv) {
   glutInit(&argc, argv); 
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(400,400);
   glutInitWindowPosition(100, 100);
   glutCreateWindow ("Setup");

   init(); 
   glutDisplayFunc(display);
   glutKeyboardFunc(keyHandle); 
   glutMainLoop(); 
   return 0;
}