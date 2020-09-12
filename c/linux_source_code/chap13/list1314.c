//list1314.c
#include <gtk/gtk.h>
#include <cairo/cairo.h>
#include <stdlib.h>

#define WIDTH  400
#define HEIGHT 300
#define LINE_WIDTH  10
#define BGCOLOR "White"

typedef struct { double x, y; } Node;

static
GList* nodelist = NULL;

static gboolean
repaint (GtkWidget* widget)
{
  GList* node = nodelist;
  gdk_window_clear (widget->window);

  if (node != NULL)
  {
    cairo_t* cr = gdk_cairo_create (widget->window);
    double x = ((Node*)node->data)->x;
    double y = ((Node*)node->data)->y;

    /* 선 설정 */
    cairo_set_line_width (cr, LINE_WIDTH);
    cairo_set_line_cap (cr, CAIRO_LINE_CAP_ROUND);
    cairo_set_line_join (cr, CAIRO_LINE_JOIN_ROUND);
    cairo_set_source_rgb (cr, 0.0, 0.0, 0.5); /* Navy */

    /* 시점 그리기 */
    cairo_move_to (cr, x, y);
    cairo_line_to (cr, x, y);

    /* 꺾은선 그리기 */
    while ((node = g_list_next (node)) != NULL)
    {
      x = ((Node*)node->data)->x;
      y = ((Node*)node->data)->y;
      cairo_line_to (cr, x, y);
    }

    /* 그리기와 종료 처리 */
    cairo_stroke (cr);
    cairo_destroy (cr);
  }

  return FALSE;
}

static gboolean
pressed (GtkWidget* widget, GdkEventButton* event)
{
  Node* newnode;
  if ((newnode = (Node*) malloc (sizeof (Node))) == NULL)
  {
    g_error ("Not enough memory\n");
    exit (1);
  }

  /* 꺾은선의 점을 추가 */
  newnode->x = event->x;
  newnode->y = event->y;
  nodelist = g_list_append (nodelist, newnode);

  /* 다시 그리기 */
  repaint (widget);

  return FALSE;
}

static void
set_background (GtkWidget* widget, const char* color_name)
{
  GdkColor color;  
  GdkDisplay* display = gdk_display_get_default ();
  GdkScreen* screen = gdk_display_get_default_screen (display);
  GdkColormap* cmap = gdk_screen_get_rgb_colormap (screen);

  /* 색 정보를 취득해 배경색으로 지정 */
  gdk_color_parse (color_name, &color);
  gdk_rgb_find_color (cmap, &color);
  gdk_window_set_background (widget->window, &color);
}

int
main (int argc, char* argv[])
{
  GtkWidget* window;
  GtkWidget* canvas;

  /* 초기화 처리 */
  gtk_init (&argc, &argv);

  /* 윈도 설정 */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (GTK_WIDGET (window), WIDTH, HEIGHT);
  g_signal_connect (G_OBJECT (window), "destroy", 
                    G_CALLBACK (gtk_main_quit), NULL);

  /* 그리기 영역 추가 */
  canvas = gtk_drawing_area_new ();
  gtk_container_add (GTK_CONTAINER (window), canvas);
  gtk_signal_connect (GTK_OBJECT (canvas), "expose-event",
                      G_CALLBACK (repaint), NULL);
  gtk_signal_connect (GTK_OBJECT (canvas), "button-press-event",
                      G_CALLBACK (pressed), NULL);

  /* 마우스 이벤트 추가 */
  gtk_widget_set_events (canvas, GDK_BUTTON_PRESS_MASK);
  gtk_widget_show_all (window);

  /* 배경을 하얗게 한다 */
  set_background (canvas, BGCOLOR);

  /* 이벤트 루프 */
  gtk_main ();

  return 0;
}

