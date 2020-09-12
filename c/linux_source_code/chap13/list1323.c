//list1323.c
#include <gtk/gtk.h>
#include <gtk/gtkgl.h>
#include <GL/glut.h>

static
int angle = 0;

/* 물체를 그리는 처리를 하는 콜백 함수 */
static gboolean
display (GtkWidget* widget, GdkEventExpose *event)
{
  GdkGLContext* glcontext = gtk_widget_get_gl_context (widget);
  GdkGLDrawable* gldrawable = gtk_widget_get_gl_drawable (widget);

  gdk_gl_drawable_gl_begin (gldrawable, glcontext);

  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity ();
  gluLookAt (0.0, 30.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  glPushMatrix ();
  glRotatef (angle, 0.0, 1.0, 0.0);
  glEnable (GL_COLOR_MATERIAL);
  glColor3f (0.9, 0.5, 0.2);
  gdk_gl_draw_teapot (TRUE, 25.0);
  glDisable (GL_COLOR_MATERIAL);
  glPopMatrix ();

  gdk_gl_drawable_swap_buffers (gldrawable);

  gdk_gl_drawable_gl_end (gldrawable);

  return TRUE;
}

/* 윈도가 리사이즈 되었을 때 호출되는 함수 */
static gboolean
reshape (GtkWidget* widget, GdkEventConfigure* event)
{
  GdkGLContext* glcontext = gtk_widget_get_gl_context (widget);
  GdkGLDrawable* gldrawable = gtk_widget_get_gl_drawable (widget);
  int w = event->width;
  int h = event->height;

  gdk_gl_drawable_gl_begin (gldrawable, glcontext);

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

  /* 투시투영변환 설정 */
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  glViewport (0, 0, w, h);
  gluPerspective (40.0, (w / (double)h), 1.0, 1000.0);

  gdk_gl_drawable_gl_end (gldrawable);

  return TRUE;
}

/* 아이들상태에서 수시로 호출되는 함수 */
static gboolean
idle (gpointer user_data)
{
  GtkWidget* widget = GTK_WIDGET (user_data);

  angle = (angle + 1) % 360;

  /* gultPostRequet()과 같은 처리 */
  gdk_window_invalidate_rect (widget->window, &widget->allocation, FALSE);
  gdk_window_process_updates (widget->window, FALSE);

  return TRUE;
}

int
main (int argc, char* argv[])
{
  GtkWidget* window;
  GtkWidget* drawarea;
  GdkGLConfig* glconfig;

  /* GTK+とGtkGLExt의 초기 설정 */
  gtk_init (&argc, &argv);
  gdk_gl_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  drawarea = gtk_drawing_area_new ();
  gtk_widget_set_size_request (drawarea, 400, 300);
  gtk_container_add (GTK_CONTAINER (window), drawarea);
  g_signal_connect (G_OBJECT (window), "destroy", 
                    G_CALLBACK (gtk_main_quit), NULL);
  gtk_widget_set_events (drawarea, GDK_EXPOSURE_MASK);

  /* GtkGLConfig 설정 */
  glconfig = gdk_gl_config_new_by_mode (
    GDK_GL_MODE_RGB | GDK_GL_MODE_DEPTH | GDK_GL_MODE_DOUBLE);
  gtk_widget_set_gl_capability (drawarea, glconfig, 
                                NULL, TRUE, GDK_GL_RGBA_TYPE);
                                       
  /* 콜백 함수 등록 */
  gtk_signal_connect (GTK_OBJECT (drawarea), "expose-event", 
                      G_CALLBACK (display), NULL);
  gtk_signal_connect (GTK_OBJECT (drawarea), "configure-event", 
                      G_CALLBACK (reshape), NULL); 
  g_idle_add (idle, drawarea);

  /* 윈도 표시와 메인 루프 */
  gtk_widget_show_all (window);
  gtk_main ();

  return 0;
}

