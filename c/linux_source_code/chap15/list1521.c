//list1521.c
#include <uriparser/Uri.h>

/* range->first부터 range->afterLast까지의 문자열 출력 */
static void
print_info (const char* msg, struct UriTextRangeStructA* range)
{
  printf ("%s", msg);
  const char* ptr = range->first;
  while (range->afterLast != ptr) putchar (*ptr++);
  printf ("\n");
}

int
main (int argc, char* argv[])
{
  if (argc < 2)
  {
    fprintf (stderr, "Usage: %s URI\n", argv[0]);
    return 1;
  }

  UriParserStateA state;
  UriUriA uri;
  state.uri = &uri;
  if (uriParseUriA (&state, argv[1]) != URI_SUCCESS)
  {
    fprintf (stderr, "Can not parse URI: %s\n", argv[1]);
    return 1;
  }

  /* scheme, userInfo, hostText, portText 출력 */
  print_info ("scheme = ", &uri.scheme);
  print_info ("user = ", &uri.userInfo);
  print_info ("host = ", &uri.hostText);
  print_info ("port = ", &uri.portText);

  /* path 출력 */
  struct UriPathSegmentA* path;
  int i = 0;
  for (path = uri.pathHead; path != NULL; path = path->next, i++)
  {
    print_info (((i == 0) ? "path = ": "> "), &path->text);
  }

  /* query와 fragment 출력 */
  print_info ("query = ", &uri.query);
  print_info ("fragment = ", &uri.fragment);

  uriFreeUriMembersA (&uri);

  return 0;
}

