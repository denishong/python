//list1322.c
#include <GL/glut.h>

static
int angle = 0;

/* 물체를 그리는 처리를 하는 콜백 함수 */
static void
display ()
{
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity ();
  gluLookAt (0.0, 30.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  glPushMatrix ();
  glRotatef (angle, 0.0, 1.0, 0.0);
  glEnable (GL_COLOR_MATERIAL);
  glColor3f (0.9, 0.5, 0.2);
  glutSolidTeapot (25.0);
  glDisable (GL_COLOR_MATERIAL);
  glPopMatrix ();

  glutSwapBuffers ();
}

/* 윈도가 리사이즈되었을 때 호출되는 함수 */
static void
reshape (int w, int h)
{
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  glViewport (0, 0, w, h);
  gluPerspective (40.0, (w / (double)h), 1.0, 1000.0);
}

/* 아이들 상태에서 수시로 호출되는 함수 */
static void
idle ()
{
  angle = (angle + 1) % 360;
  glutPostRedisplay ();
}

int
main (int argc, char* argv[])
{
  /* GLUT 초기 설정 */
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (400, 300);
  glutCreateWindow (argv[0]);

  /* OpenGL 설정 */
  glClearColor (1.0, 1.0, 1.0, 0.0);
  glShadeModel (GL_SMOOTH);
  glCullFace (GL_FRONT);
  glEnable (GL_CULL_FACE);
  glEnable (GL_DEPTH_TEST);

  /* 라이팅 설정 */
  GLfloat light_position[] = {10000.0, 10000.0, 10000.0, 0.0};
  GLfloat light_ambient[]  = {0.2, 0.2, 0.2, 1.0};
  GLfloat light_diffuse[]  = {1.0, 1.0, 1.0, 1.0};
  glLightfv (GL_LIGHT0, GL_POSITION, light_position);
  glLightfv (GL_LIGHT0, GL_AMBIENT,  light_ambient);
  glLightfv (GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
  glEnable (GL_LIGHTING);
  glEnable (GL_LIGHT0);

  /* 콜백 함수 등록 */
  glutDisplayFunc (display);
  glutReshapeFunc (reshape);
  glutIdleFunc (idle);

  /* 메인 루프*/
  glutMainLoop ();

  return 0;
}

