//list1221.c
#include <gtk/gtk.h>

int
main (int argc, char* argv[])
{
  GtkWidget* window;

  /* 초기화 처리 */
  gtk_init (&argc, &argv);

  /* 윈도 설정 */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (G_OBJECT (window), "destroy", 
                    G_CALLBACK (gtk_main_quit), NULL);
  gtk_widget_show (window);

  /* 이벤트 루프 */
  gtk_main ();

  return 0;
}

