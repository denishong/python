//list1222.c
#include <gtk/gtk.h>

#define LABEL_WIDTH  200
#define LABEL_HEIGHT  50

int
main (int argc, char* argv[])
{
  GtkWidget* window;
  GtkWidget* label;

  /* 초기화 처리 */
  gtk_init (&argc, &argv);

  /* 윈도 설정 */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (G_OBJECT (window), "destroy", 
                    G_CALLBACK (gtk_main_quit), NULL);

  /* 라벨 추가 */
  label = gtk_label_new ("Hello, world!");
  gtk_widget_set_size_request (label, LABEL_WIDTH, LABEL_HEIGHT);
  gtk_container_add (GTK_CONTAINER (window), label);
  gtk_widget_show_all (window);

  /* 이벤트 루프 */
  gtk_main ();

  return 0;
}

