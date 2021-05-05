#include<gl/glut.h>
#include<gl/glu.h>
#include<gl/gl.h>
#include <stdlib.h>
#include<GL/freeglut.h>
#include<GL/glut.h>
#include <time.h>
float mouseX;
float mouseY;
float angle = 0;
int width, height;
int spin;
void timer(int value)
{
	if (spin==1) {
		angle += 6;
	}
	else if (spin == -1) {
		angle -= 6;
	}
	glutPostRedisplay();
	glutTimerFunc(16, timer, 0);
}

void drawBody()

{
	glPushMatrix();
	
	glColor3f(255, 0, 0);

	glTranslatef(0, 0, 0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glScalef(1, 1, 1);

	glutSolidCube(0.25);

	glPopMatrix();

	glPushMatrix();

	glColor3f(0, 0, 255);

	glTranslatef(-0.35, 0.0, 0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glScalef(1, 1, 1);

	glutSolidCube(0.25);

	glPopMatrix();

}



void drawLeftArm()

{

	glPushMatrix();

	glColor3f(255, 255, 0);

	glTranslatef(-1.5, 1.0, 0);

	glScalef(0.5, 2, 0.5);

	glutSolidCube(1);

	glPopMatrix();



	glPushMatrix();

	glColor3f(0, 0, 0);

	glTranslatef(-1.5, -0.25, 0);

	glutSolidSphere(0.25, 18, 18);

	glPopMatrix();

}



void drawRightArm()

{

	glPushMatrix();

	glColor3f(255, 0, 255);

	glTranslatef(1.5, 1.0, 0);

	glScalef(0.5, 2, 0.5);

	glutSolidCube(1);

	glPopMatrix();



	//물체 push 후 pop으로 시점 초기화



	glPushMatrix();

	glColor3f(0, 0, 0);

	glTranslatef(1.5, -0.25, 0);

	glutSolidSphere(0.25, 18, 18);

	glPopMatrix();

}




void MyDisplay()

{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//display 함수에 깊이 버퍼 초기화 코드 삽입 (깊이 버퍼 초기화함)

	glBegin(GL_LINES);

	glColor3f(1.0f, 0.0f, 0.0f);              glVertex3f(0.0f, 0.0f, 0.0f);             glVertex3f(5.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);              glVertex3f(0.0f, 0.0f, 0.0f);             glVertex3f(0.0f, 5.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);              glVertex3f(0.0f, 0.0f, 0.0f);             glVertex3f(0.0f, 0.0f, 5.0f);

	glEnd();


	// 몸통 위에서 구현
	
	drawBody();

	// 팔

	//drawLeftArm();

	//drawRightArm();



	glutSwapBuffers();

}


void reshape(int  w,int  h) {

	width = w;
	height = h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	//glOrtho(-1, 1, -1, 1, -1, 2); //평행투상 
	//gluPerspective(60, 1.0, 0.1, 40.0); //시야각 fovy, 종횡비 aspect, near, far
	gluPerspective(45.0, 1.0, 1.0, 100.0); 
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	

	gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //(카메라 위치, 보는 점, 카메라 머리)

}


void mouseMove(int button,int state,int x, int y)
{
	if (state == GLUT_DOWN&& button == GLUT_LEFT_BUTTON  ) {
		if (x < width / 2) {
			spin=1;
		}
		if (x > width / 2) {
			spin=-1;
		}
	}
}



int main(int argc, char** argv)

{

	glutInit_ATEXIT_HACK(&argc, argv);



	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH|GLUT_DOUBLE);      // Depth Testing

	glutInitWindowSize(500, 500);

	glutCreateWindow_ATEXIT_HACK("16010600 LEEJEEWOONG");



	glEnable(GL_DEPTH_TEST);                  // Depth Testing





	glClearColor(1.0, 1.0, 1.0, 0.0);

	glutDisplayFunc(MyDisplay);
	glutTimerFunc(0, timer, 0);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseMove);

	glutMainLoop();

	return 0;

}
