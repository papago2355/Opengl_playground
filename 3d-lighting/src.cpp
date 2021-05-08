#include<gl/glut.h>
#include<gl/glu.h>
#include<gl/gl.h>
#include <stdlib.h>
#include<GL/freeglut.h>
#include<GL/glut.h>
#include <time.h>
#include<stdio.h>
float mouseX;
float mouseY;
float angle = 0;
int width, height;
int spin;

GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient[] = { 1.0, 0.7, 0.7, 1.0 };
GLfloat mat_ambientB[] = { 0.5, 0.7, 1.0, 1.0 };
GLfloat mat_diffuseG[] = { 0.5, 1.0, 0.7, 1.0 };
GLfloat  mat_diffuseY[] = { 1.0, 1.0, 0.5, 1.0 };
GLfloat  mat_diffuseNR[] = { 0.0, 0.7, 1.0, 1.0 };
GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
GLfloat mat_diffuse[] = { 1.0, 0.5, 0.8, 1.0 };
GLfloat mat_diffuseB[] = { 0.0, 0.5, 1.0, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat no_shininess[] = { 0.0 };
GLfloat low_shininess[] = { 5.0 };
GLfloat high_shininess[] = { 100.0 };
GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };

void init(void)
{
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[] = { 0.5, 0.5, 1.0, 0.0 };

	GLfloat ambient1[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat diffuse1[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat specular1[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position1[] = {0.0, 0.5, 0.5, 0.0 };

	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat local_view[] = { 0.0 };
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
	glLightfv(GL_LIGHT1, GL_POSITION, position1);
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	//glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
}

void timer(int value)
{
	if (spin==1) {
		angle += 6;
	}
	else if (spin == -1) {
		angle -= 6;
	}
	else if (spin == 0) {
		angle = angle;
	}
	glutPostRedisplay();
	glutTimerFunc(16, timer, 0);
}

void  materialContainer(GLfloat mat[], GLfloat diffuse[], GLfloat specular[], GLfloat shiness[], GLfloat emission[]) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
};


void drawBody()

{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(angle, 0.0, 1.0, 1.0);
	glScalef(1, 1, 1);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuseB);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidCylinder( 0.1f, 0.1f, 32, 32);
	glPopMatrix();


	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glTranslatef(-0.35, 0.0, 0);
	glRotatef(angle, 0.0, 1.0, 1.0);
	glScalef(1.5, 1.5, 1.5);
	glutSolidCylinder(0.1f, 0.1f, 32, 32);
	glPopMatrix();

	glPushMatrix();
	materialContainer(no_mat, mat_diffuseY, mat_specular, high_shininess, no_mat);
	glTranslatef(0.55, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 1.0);
	glScalef(1, 1, 1);
	glutSolidSphere(0.15, 20.0, 20.0);
	glPopMatrix();

	glPushMatrix();
	materialContainer(no_mat, mat_diffuseG, mat_specular, high_shininess, no_mat);
	glTranslatef(0.0, 0.0, 0.45);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glScalef(1, 1, 1);
	glutSolidSphere(0.15, 20.0, 20.0);
	glPopMatrix();

	glPushMatrix();
	materialContainer(no_mat, mat_diffuseNR, mat_specular, low_shininess, no_mat);
	glTranslatef(0.40, 0.0, 0.40);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glScalef(1, 1, 1);
	glutSolidSphere(0.15, 20.0, 20.0);
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
	if (state == GLUT_DOWN && button == GLUT_MIDDLE_BUTTON) {
		spin = 0;
	}
}

void handleKeypress(unsigned char key, int x, int y) {


	switch (key) {
	case '0':
		printf("0  is pressed\n");
		glEnable(GL_LIGHT0);
		break;
	case '1':
		printf("1  is pressed\n");
		glEnable(GL_LIGHT1);
		break;
	case '2':
		printf("2  is pressed\n");
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
		break;
	case '3':
		printf("3  is pressed\n");
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
		break;
	case 27: //Escape key
		exit(0);
	default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)

{

	glutInit_ATEXIT_HACK(&argc, argv);



	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH|GLUT_DOUBLE);      // Depth Testing

	glutInitWindowSize(500, 500);

	glutCreateWindow_ATEXIT_HACK("16010600 LEEJEEWOONG");



	glEnable(GL_DEPTH_TEST);                  // Depth Testing



	init();

	glClearColor(1.0, 1.0, 1.0, 0.0);

	glutDisplayFunc(MyDisplay);
	glutTimerFunc(0, timer, 0);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseMove);
	glutKeyboardFunc(handleKeypress);
	glutMainLoop();

	return 0;

}
