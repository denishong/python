//list1431.c
#include <libthinkfinger.h>
#include <stdio.h>

int
main (int argc, char* argv[])
{
  if (argc < 2)
  {
    fprintf (stderr, "Usage: %s BIR_FILE\n", argv[0]);
    return 1;
  }

  /* 인증 오브젝트 생성 */
  libthinkfinger* tf;
  libthinkfinger_init_status init_status;
  if ((tf = libthinkfinger_new (&init_status)) == NULL)
  {
    fprintf (stderr, 
             "Cannot create ThinkFinger handle: error code = %d\n",
             init_status);
    return 1;
  }

  /* 인증 데이터 세트 */
  if (libthinkfinger_set_file (tf, argv[1]) < 0)
  {
    fprintf (stderr, "Cannot set file: %s\n", argv[1]);
    return 1;
  }

  /* 인증 실시 */
  libthinkfinger_result result = libthinkfinger_verify (tf);

  switch (result)
  {
    case TF_STATE_VERIFY_SUCCESS:       /* 인증성공 */
      fprintf (stderr, "Fingerprint DOES match\n");
      break;
    case TF_STATE_VERIFY_FAILED:        /* 인증실패 */
      fprintf (stderr, "Fingerprint does NOT match\n");
      break;
    default:
      fprintf (stderr, "Something wrong\n");
  }

  /* 종료 처리 */
  libthinkfinger_free (tf);
  return 0;
}

