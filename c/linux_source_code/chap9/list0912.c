// list0912.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXCONNECTION   5
#define BUFSIZE       256

static void session_with_client (int);

int
main(int argc, char *argv[])
{
  int ssid, csid;
  struct sockaddr_in s_addr, c_addr;

  if (argc < 2)
  {
    fprintf (stderr, "Usage: %s PORT\n", argv[0]);
    exit (1);
  }

  /* 소켓 작성과 데이터 준비 */
  if ((ssid = socket (PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
  {
    perror ("Socket creation failed");
    exit (1);
  }
  memset (&s_addr, 0, sizeof (s_addr));
  s_addr.sin_family = AF_INET;
  s_addr.sin_addr.s_addr = htonl (INADDR_ANY);
  s_addr.sin_port = htons (atoi (argv[1]));

  /* 포트 할당과 커넥션 접수 */
  if (bind (ssid, (struct sockaddr *) &s_addr, sizeof (s_addr)) < 0)
  {
    perror ("Binding socket failed");
    exit (1);
  }
  if (listen (ssid, MAXCONNECTION) < 0)
  {
    perror ("Listening server socket failed");
    exit (1);
  }

  /* 클라이언트와의 세션 */
  while (1)
  {
    unsigned int len = sizeof (c_addr);

    /* 클라이언트로부터의 커넥션 대기 */
    if ((csid = accept (ssid, (struct sockaddr *) &c_addr, &len)) < 0)
    {
      perror ("Client connection failed");
      exit (1);
    }
    printf ("Client connected: %s\n", inet_ntoa (c_addr.sin_addr));

    /* 세션 시작 */
    session_with_client (csid);
  }
}

void
session_with_client (int sid)
{
  char buffer[BUFSIZE];
  int received = -1;

  do
  {
    if ((received = recv (sid, buffer, BUFSIZE, 0)) < 0)
    {
      perror ("Error in receiving message from client");
      exit (1);
    }
    if (send (sid, buffer, received, 0) != received)
    {
      perror ("Error in sending message to client");
      exit (1);
    }
  } while (received > 0);

  close (sid);
}

