//list0722A.c
#include <glib.h>
#include <stdio.h>

int
main (int argc, char* argv[])
{
  int i;
  GSList* slist = NULL;

  for (i = 0; i < argc; i++)
  {
    slist = g_slist_prepend (slist, argv[i]);
  }

  for ( ; slist; slist = g_slist_next (slist) )
  {
    printf ("%s\n", (char*) slist->data);
  }
  return 0;
}

