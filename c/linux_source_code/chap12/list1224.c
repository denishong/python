//list1224.c
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

#define BTN_WIDTH  200
#define BTN_HEIGHT  50

static void
clicked (GtkWidget* button)
{
  printf ("Current label is \"%s\"\n",
          gtk_button_get_label (GTK_BUTTON (button)));
}

static gboolean
key_pressed (GtkWidget* button, GdkEventKey* key)
{
  switch (key->keyval)
  {
    case GDK_a:
      gtk_button_set_label (GTK_BUTTON (button), "Good afternoon!");
      break;

    case GDK_e:
      gtk_button_set_label (GTK_BUTTON (button), "Good evening!");
      break;

    case GDK_m:
      gtk_button_set_label (GTK_BUTTON (button), "Good morning!");
      break;

    case GDK_q:
    case GDK_Escape:
      gtk_main_quit ();
      break;

    default:
      break;
  }
  return FALSE;
}

int
main (int argc, char* argv[])
{
  GtkWidget* window;
  GtkWidget* button;

  /* 초기화 처리 */
  gtk_init (&argc, &argv);

  /* 윈도 설정 */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (G_OBJECT (window), "destroy", 
                    G_CALLBACK (gtk_main_quit), NULL);

  /* 버튼 추가와 콜백 함수 등록 등 */
  button = gtk_button_new_with_label ("Press me!");
  gtk_widget_set_size_request (button, BTN_WIDTH, BTN_HEIGHT);
  gtk_signal_connect (GTK_OBJECT (button), "key_press_event", 
                      G_CALLBACK (key_pressed), NULL);
  gtk_signal_connect (GTK_OBJECT (button), "clicked", 
                      G_CALLBACK (clicked), NULL);
  gtk_container_add (GTK_CONTAINER (window), button);
  gtk_widget_show_all (window);

  /* 이벤트 루프 */
  gtk_main ();

  return 0;
}

