/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"

#include <stdlib.h>

int myAtoi(char* str)
{
    // Code adapted frpm https://www.geeksforgeeks.org/write-your-own-atoi/
    quote_t res = 0;
    if (str[4] == '\0')
    {
      res = (res << 3) + (res << 1) + str[0] - '0';
      res = (res << 3) + (res << 1) + str[1] - '0';
      res = (res << 3) + (res << 1) + str[2] - '0';
      res = (res << 3) + (res << 1) + str[3] - '0';
      return res;
    }
    for (unsigned i = 0; str[i] != '\0'; i++)
      res = (res << 3) + (res << 1) + str[i] - '0';
    return res;
}

void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
    nums[i] = myAtoi(lines[i]);
  }
}
