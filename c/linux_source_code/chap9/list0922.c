// list0922.c
#include <stdio.h>
#include <stdlib.h>
#include <netinet/if_ether.h> // for 'struct ether_header'
#include <pcap.h>

#define TIMEOUT 1000
#define PROMISC    1
#define MAXCOUNT   0

void print_addr(u_char*, const struct pcap_pkthdr*, const u_char*);

int
main (int argc, char* argv[])
{
  pcap_t* pcd;
  char    ebuf[PCAP_ERRBUF_SIZE];

  if (argc < 2)
  {
    fprintf (stderr, "Usage: %s NETWORK_INTERFACE\n", argv[0]);
    exit (1);
  }

  /* 감시 대상 디바이스 열기 */
  if ((pcd = pcap_open_live (argv[1], BUFSIZ, PROMISC, TIMEOUT, ebuf)) == NULL)
  {
    fprintf (stderr, "Device open failed\n");
    exit (1);
  }

  /* 캡쳐 실시 */
  if (pcap_loop (pcd, MAXCOUNT, print_addr, NULL) < 0)
  {
    fprintf (stderr, "Error in pcap_loop()\n");
    exit (1);
  }

  pcap_close (pcd);

  return 0;
}

/* 패킷 정보를 출력하는 콜백 함수 */
void
print_addr (u_char* not_used, const struct pcap_pkthdr* h, const u_char* p)
{
  int i;
  struct ether_header* eh = (struct ether_header*)p;

  /* 출발지 MAC 어드레스 출력 */
  for (i = 0; i < ETH_ALEN; i++)
  {
    printf ("%02x:", eh->ether_shost[i]);
  }
  printf (" -> ");

  /* 목적지 MAC 어드레스 출력 */
  for (i = 0; i < ETH_ALEN; i++)
  {
    printf ("%02x:", eh->ether_dhost[i]);
  }

  /* 패킷의 길이 출력 */
  printf (" length = %d\n", h->len);
}

