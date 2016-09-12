#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "romanCalc.h"

int lastOutput(int digit, int lastnum, int num)
{
  if ( lastnum > digit ) {
    return num - digit;
  } else {
    return num + digit;
  }
}

int parseRomeNum(char *str)
{
  int output, lastout, size, i;

  size = strlen(str);
  output = 0;
  lastout = 0;

  for ( i=size; i>=0; --i) {

    switch ( str[i] )
      {

      case 'I' :
	output = lastOutput(1, lastout, output);
	lastout = 1;
	break;
      case 'V' :
	output = lastOutput(5, lastout, output);
	lastout = 5;
	break;
      case 'X' :
	output = lastOutput(10, lastout, output);
	lastout = 10;
	break;
      case 'L' :
	output = lastOutput(50, lastout, output);
	lastout = 50;
	break;
      case 'C' :
	output = lastOutput(100, lastout, output);
	lastout = 100;
	break;
      case 'D' :
	output = lastOutput(500, lastout, output);
	lastout = 500;
	break;
      case 'M' :
	output = lastOutput(1000, lastout, output);
	lastout = 1000;
	break;
      }
  }

  return output;
}

int addNumbers(char *str1, char *str2)
{
  return parseRomeNum(str1) + parseRomeNum(str2);
}

int subNumbers(char *str1, char *str2)
{
  return parseRomeNum(str1) - parseRomeNum(str2);
}
