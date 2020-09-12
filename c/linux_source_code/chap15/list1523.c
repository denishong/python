//list1523.c
#include <dotconf.h>

DOTCONF_CB (callback_int)
{
  printf ("[int]\tKey = %s\tValue = %ld\t(%s:%ld)\n",
          cmd->name, cmd->data.value,
          cmd->configfile->filename, cmd->configfile->line);

  return NULL;
}

DOTCONF_CB (callback_str)
{
  printf ("[str]\tKey = %s\tValue = %s\t(%s:%ld)\n",
          cmd->name, cmd->data.str,
          cmd->configfile->filename, cmd->configfile->line);

  return NULL;
}

DOTCONF_CB (callback_list)
{
  int i;
  printf ("[list]\tKey = %s\n", cmd->name);

  printf ("\tValues = ");
  for (i = 0; i < cmd->arg_count; i++)
  {
    printf("%d: %s  ", i, cmd->data.list[i]);
  }
  printf ("\t(%s:%ld)\n", 
          cmd->configfile->filename, cmd->configfile->line);

  return NULL;
}

static const 
configoption_t cf_opt[] = 
{
  { "int:",  ARG_INT,  callback_int,  NULL, CTX_ALL },
  { "str1:", ARG_STR,  callback_str,  NULL, CTX_ALL },
  { "str2:", ARG_STR,  callback_str,  NULL, CTX_ALL },
  { "list:", ARG_LIST, callback_list, NULL, CTX_ALL },
  LAST_OPTION
};

int
main (int argc, char* argv[])
{
  if (argc < 2)
  {
    fprintf (stderr, "Usage: %s CONFIG_FILE\n", argv[0]);
    return 1;
  }

  /* 설정 파일 열기 */
  configfile_t* cf_file = dotconf_create (argv[1], cf_opt, NULL, NONE);
  if (cf_file == NULL)
  {
    fprintf (stderr, "Can not open config file %s\n", argv[1]);
    return 1;
  }

  /* 설정 파일 분석 */
  if (dotconf_command_loop (cf_file) == 0)
  {
    fprintf (stderr, "Error in reading config file\n");
    return 1;
  }

  dotconf_cleanup (cf_file);

  return 0;
}

