#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "romanCalc.h"

int parseRomeNum(char *str)
{
  int output, size, i;

  size = strlen(str);
  output = 0;

  for ( i=size; i>=0; --i) {

    switch(str[i])
      {

      case 'I' :
	output += 1;
	break;
      case 'V' :
	output += 5;
	break;
      case 'X' :
	output += 10;
	break;
      case 'L' :
	output += 50;
	break;
      case 'C' :
	output += 100;
	break;
      case 'D' :
	output += 500;
	break;
      case 'M' :
	output += 1000;
	break;
      }
  }

  return output;
}
