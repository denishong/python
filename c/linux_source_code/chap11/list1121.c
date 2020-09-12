// list1121.c
#include <stdio.h>
#include <stdlib.h>
#include <ppm.h>

#define TYPE_SWITCH   0

int
main (int argc, char* argv[])
{
  if (argc < 3)
  {
    fprintf (stderr, "Usage: %s IN_FILE OUT_FILE\n", argv[0]);
    exit (1);
  }

  int x1, x2, y;
  FILE *in_fp, *out_fp;
  int cols, rows, format;
  pixval maxval, r, g, b;
  pixel *src_row, *dst_row;

  in_fp = pm_openr (argv[1]);
  ppm_readppminit (in_fp, &cols, &rows, &maxval, &format);
  src_row = ppm_allocrow (cols);

  out_fp = pm_openw (argv[2]);
  ppm_writeppminit (out_fp, cols, rows, maxval, 0);
  dst_row = ppm_allocrow (cols);

  for (y = 0; y < rows; y++)
  {
    /* 이미지의 한 줄을 파일에서 읽어들인다 */
    ppm_readppmrow (in_fp, src_row, cols, maxval, format);

    /* 왼쪽부터 1픽셀씩 읽어들여 오른쪽부터 1픽셀씩 써낸다 */
    for (x1 = 0, x2 = cols-1; x1 < cols; x1++, x2--)
    {
      r = PPM_GETR (src_row[x1]);
      g = PPM_GETG (src_row[x1]);
      b = PPM_GETB (src_row[x1]);

      PPM_ASSIGN (dst_row[x2], r, g, b);
    }
    /* 파일에 한 줄 써낸다 */
    ppm_writeppmrow (out_fp, dst_row, cols, maxval, TYPE_SWITCH);
  }

  ppm_freerow (src_row);
  ppm_freerow (dst_row);
  pm_close (in_fp);
  pm_close (out_fp);

  return 0;
}

