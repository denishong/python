//list0722B.c
#include <glib.h>
#include <stdio.h>

int
main (int argc, char* argv[])
{
  int i;
  GList* list = NULL;

  for (i = 0; i < argc; i++)
  {
    list = g_list_append (list, argv[i]);
  }

  list = g_list_first (list);
  for ( ; list; list = g_list_next (list) )
  {
    printf ("%s\n", (char*) list->data);
  }
  return 0;
}

