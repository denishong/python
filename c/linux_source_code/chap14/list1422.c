//list1422.c
#include <hid.h>
#include <stdio.h>

#define VENDOR_ID  0x0483
#define PRODUCT_ID 0x2016;

int
main (int argc, char* argv[])
{
  HIDInterface* hid = NULL;
  int if_no = 0;
  HIDInterfaceMatcher matcher = 
    { VENDOR_ID, PRODUCT_ID, NULL, NULL, 0 };

  /* 초기화 */
  if (hid_init() != 0)
  {
    fprintf (stderr, "Cannot initialize HID library\n");
    return 1;
  }

  /* 인터페이스 생성 */
  if ((hid = hid_new_HIDInterface()) == NULL)
  {
    fprintf (stderr, "Cannot create HID interface\n");
    return 1;
  }

  /* 디바이스 열기 */
  if (hid_force_open (hid, if_no, &matcher, 3) != 0)
  {
    fprintf (stderr, "Cannot open HID device\n");
    return 1;
  }

  /* 디바이스 정보 출력 */
  if (hid_write_identification (stdout, hid) != 0)
  {
    fprintf (stderr, "Cannot write identification\n");
    return 1;
  }

  /* 디바이스 닫기 */
  if (hid_close (hid) != 0)
  {
    fprintf (stderr, "Cannot close HID device\n");
    return 1;
  }

  /* 종료 처리 */
  if (hid_cleanup () != 0)
  {
    fprintf (stderr, "Cannot cleanup HID library\n");
    return 1;
  }

  return 0;
}

