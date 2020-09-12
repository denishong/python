// list1122.c
#include <stdio.h>
#include <stdlib.h>
#include <wand/MagickWand.h>

#define QUALITY    90

int
main (int argc, char* argv[])
{
  if (argc < 3)
  {
    fprintf (stderr, "Usage: %s IN_FILE OUT_FILE\n", argv[0]);
    exit (1);
  }

  MagickWand* m_wand;
  int w, h;

  /* 초기화 처리 */
  MagickWandGenesis ();
  m_wand = NewMagickWand ();

  /* 이미지 파일 읽기  */
  if (MagickReadImage (m_wand, argv[1]) == MagickFalse)
  {
    fprintf (stderr, "Cannot read image: %s\n", argv[1]);
    exit (1);
  }
  w = MagickGetImageWidth (m_wand);
  h = MagickGetImageHeight (m_wand);

  /* 크기 변환 처리 */	
  MagickResizeImage (m_wand, w/2, h/2, LanczosFilter, 1.0);
  MagickSetImageCompressionQuality (m_wand, QUALITY);

  /* 이미지 파일 쓰기 */
  if (MagickWriteImage (m_wand, argv[2]) == MagickFalse)
  {
    fprintf (stderr, "Cannot wright image: %s\n", argv[2]);
    exit (1);
  }
	
  /* 뒷정리 */
  if (m_wand)
  {
    m_wand = DestroyMagickWand (m_wand);
  }
  MagickWandTerminus ();

  return 0;
}

