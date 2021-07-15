#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

// Number of subdivisions
#define N 256

#define _PI 3.14159f

// Coordinates and function values
GLfloat x_coords[N];
GLfloat y_values[N];

// Set x coordinates to go through -pi to pi by step of 2*pi/N
static void set_x_coords()
{
    GLfloat x_start = -_PI;
    GLfloat delta_x = 2.0f * _PI / (N - 1);
    int i;
    for (i = 0; i < N; ++i)
    {
        x_coords[i] = x_start + i * delta_x;
    }
}

// Set y_values to y = sin(x)
static void set_y_values()
{
    int i;
    for (i = 0; i < N; ++i)
    {
        y_values[i] = sinf(x_coords[i]);
    }
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    int i;
    glColor3f(0.f, 0.f, 0.f);
    glLineWidth(2.f);
    glScalef(1.f / _PI, 1.f / _PI, 1.f);

    // Complete:
    // Plot the sine curve by connecting the points (x_coords[i], y_values[i])
    // with line segments.

    glBegin(GL_LINE_STRIP);

        for (i = 0; i < N; ++i)
    {
       glVertex2f(x_coords[i], y_values[i]);
    }
    glEnd();
    // End of complete

    glutSwapBuffers();
}

// No need to modify the functions below
//

static void init(void)
{
    // set the color for painting the background
    glClearColor(1.0, 1.0, 1.0, 1.0);

    // set an orthographic projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);

    // prepare the curve coordinates
    set_x_coords();
    set_y_values();
}

static void keyHandle(unsigned char key, int x, int y)
{
    // exit when ESC is pressed
    if (key == 27)
        exit(0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ex01");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyHandle);
    glutMainLoop();
    return 0;
}