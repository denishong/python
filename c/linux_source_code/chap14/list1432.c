//list1432.c
#include <libimobiledevice/libimobiledevice.h>
#include <stdio.h>

int
main (int argc, char* argv[])
{
  char** devices;
  idevice_t device;
  int i, count;

  /* 디바이스 목록 가져오기 */
  if (idevice_get_device_list (&devices, &count) != 0)
  {
    fprintf (stderr, "Cannot get device list\n");
    return 1;
  }
  printf ("%d device(s) found.\n", count);
  
  for (i = 0; i < count; i++)
  {
    /* 디바이스 작성 */
    if (idevice_new (&device, devices[i]) != 0)
    {
      fprintf (stderr, "Cannot create device[%s]\n", devices[i]);
      return 1;
    }
    printf ("device %d [%s] is ready.\n", i, devices[i]);

    /* 디바이스 해제 */
    if (idevice_free (device) != 0)
    {
      fprintf (stderr, "Cannot free device[%s]\n", devices[i]);
      return 1;
    }
  }

  /* 디바이스 목록 해제 */
  if (idevice_device_list_free (devices) != 0)
  {
    fprintf (stderr, "Cannot free device list\n");
    return 1;
  }

  return 0;
}

