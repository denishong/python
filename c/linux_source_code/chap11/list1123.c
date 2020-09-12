// list1123.c
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

int
main (int argc, char* argv[])
{
  if (argc < 3)
  {
    fprintf (stderr, "Usage: %s IN_FILE OUT_FILE\n", argv[0]);
    exit (1);
  }

  GdkPixbuf* srcbuf;
  GdkPixbuf* dstbuf;
  GError* error = NULL;
  int w, h;

  /* 초기화 */
  gtk_init (&argc, &argv);

  /* 이미지 파일 읽기  */
  if ((srcbuf = gdk_pixbuf_new_from_file (argv[1], &error)) == FALSE)
  {
    fprintf (stderr, "Cannot read image: %s\n", argv[1]);
    exit (1);
  }
  w = gdk_pixbuf_get_width (srcbuf);
  h = gdk_pixbuf_get_height (srcbuf);

  /* 크기 변환 처리 */  
  dstbuf = gdk_pixbuf_scale_simple (srcbuf, w/2, h/2, 
                                    GDK_INTERP_BILINEAR);

  /* 이미지 파일 쓰기 */
  if (gdk_pixbuf_save (dstbuf, argv[2], "jpeg", &error, 
                       "quality", "90", NULL) == FALSE)
  {
    fprintf (stderr, "Cannot wright image: %s\n", argv[2]);
    exit (1);
  }

  /* 뒷정리 */
  gdk_pixbuf_unref (srcbuf); 
  gdk_pixbuf_unref (dstbuf);

  return 0;  
}

