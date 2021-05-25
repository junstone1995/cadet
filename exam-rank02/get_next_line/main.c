#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int  main()
{
  int ret;
  char *line;

  ret = 0;
  while (get_next_line(&line) > 0)
  {
    printf("%d   %s\n", ret, line);
    free(line);
    line = NULL;
  }
  printf("%d   %s\n", ret, line);
  free(line);
  line = NULL;
  while(1)
  {

  }
  return (0);
}
