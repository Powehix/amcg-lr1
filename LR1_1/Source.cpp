#if defined(linux) || defined(_WIN32)
#include <GL/glut.h> /*Для Linux и Windows*/
#else
#include <GLUT/GLUT.h> /*Для Mac OS*/
#endif

#include<math.h>

void reshape(int w, int h);
void display();

float left = -100, right = 100, bottom = -50, top = 50;

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutCreateWindow("LR1_1");
	glClearColor(1, 1, 1, 1); //белый цвет фона
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
	//gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//рисование осей
	glColor3d(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(0, bottom);
	glVertex2f(0, top);
	glVertex2f(left, 0);
	glVertex2f(right, 0);
	glEnd();

	//рисование функции
	glColor3d(0, 0, 1);
	glBegin(GL_LINE_STRIP);
	for (float x = -100; x < 100; x += 0.5)
		glVertex2f(x, fabs(0.25*x + 3 * cos(100 * x)*sin(x)));
	glEnd();

	glutSwapBuffers();
}