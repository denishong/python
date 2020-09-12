//list1421.c
#include <usb.h>
#include <stdio.h>

int
main (int argc, char* argv[])
{
  usb_init ();

  /* 버스와 디바이스의 수를 가져온다 */
  int busses  = usb_find_busses ();
  int devices = usb_find_devices ();

  printf ("# of bus : %d, # of devices : %d\n", busses, devices);

  /* 버스 목록을 가져와 디바이스를 찾아간다 */
  struct usb_bus* bus = usb_get_busses ();
  while (bus != NULL)
  {
    struct usb_device* device = bus->devices;
    while (device != NULL)
    {
      /* 버스와 디바이스 표시 */
      printf ("Bus %s Device %s: ID %04x:%04x\n", 
              bus->dirname, device->filename, 
              device->descriptor.idVendor, 
              device->descriptor.idProduct);
      device = device->next;
    }
    bus = bus->next;
  }

  return 0;
}

