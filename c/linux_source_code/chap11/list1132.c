// list1132.c
#include <stdio.h>
#include <stdlib.h>
#include <wand/MagickWand.h>
#include <aalib.h>

/* デフォルトの幅と高さ */
#define WIDTH  160
#define HEIGHT  50

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

  /* 크기 변환 처리 */
  MagickResizeImage (m_wand, WIDTH, HEIGHT, LanczosFilter, 1.0);

  /* 여기부터 AAlib 준비 */
  aa_context* c;
  aa_savedata save_data = {
    argv[2],
    &aa_text_format,
    NULL
  };

  /* AAlib 초기화 */
  c = aa_init (&save_d, &aa_defparams, (const void*) &save_data);
  if (c == NULL)
  {
    fprintf (stderr, "Cannot initialize AA-lib\n");
    exit (1);
  }

  /* AAlib의 이미지 버퍼에 이미지 데이터 로드 */
  PixelIterator* iter = NewPixelIterator (m_wand);
  PixelWand** pix;
  unsigned long num_wands;
  double h, s, l;
  int x, y;

  y = 0;
  while ((pix = PixelGetNextIteratorRow (iter, &num_wands)) != NULL)
  {
    for (x = 0; x < num_wands; x++)
      {
        PixelGetHSL (pix[x], &h, &s, &l);
        aa_putpixel (c, x, y, 256*l);
      }
    y++;
  }

  /* 아스키 아트 렌더링과 파일에 쓰기  */
  aa_fastrender (c, 0, 0, aa_scrwidth(c), aa_scrheight(c));
  aa_flush (c);

  /* 뒷정리 */
  aa_close (c);

  if (m_wand)
  {
    m_wand = DestroyMagickWand (m_wand);
  }
  MagickWandTerminus ();

  return 0;
}

