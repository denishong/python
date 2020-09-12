//list0723.c
#include <glib.h>
#include <stdio.h>
#include <string.h>

void
print (gpointer data, gpointer userdata)
{
  printf ("%s\n", (char*)data);
}

gint
compare (gconstpointer a, gconstpointer b)
{
  return (gint) strcmp (*(const char**)a, *(const char**)b);
}

int
main (int argc, char* argv[])
{
  int i;
  GPtrArray* array = g_ptr_array_new ();

  for (i = 0; i < argc; i++)
  {
    g_ptr_array_add (array, argv[i]);
  }
  printf ("The length of the array is %d\n", array->len);

  printf ("----- before -----\n");
  g_ptr_array_foreach (array, print, NULL);
  g_ptr_array_sort (array, compare);
  printf ("----- after -----\n");
  g_ptr_array_foreach (array, print, NULL);
  
  return 0;
}

