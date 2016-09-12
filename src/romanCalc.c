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

void parseIntNum(int num, char *output)
{
  const char *vals[13];
  int nums[13], i, j, index;
  
  vals[0] = "M";
  nums[0] = 1000;
  vals[1] = "CM";
  nums[1] = 900;
  vals[2] = "D";
  nums[2] = 500;
  vals[3] = "CD";
  nums[3] = 400;
  vals[4] = "C";
  nums[4] = 100;
  vals[5] = "XC";
  nums[5] = 90;
  vals[6] = "L";
  nums[6] = 50;
  vals[7] = "XL";
  nums[7] = 40;
  vals[8] = "X";
  nums[8] = 10;
  vals[9] = "IX";
  nums[9] = 9;
  vals[10] = "V";
  nums[10] = 5;
  vals[11] = "IV";
  nums[11] = 4;
  vals[12] = "I";
  nums[12] = 1;
  vals[13] = "No true Roman would use a number that large";
  index = 0;

  if (num > 3999) {
    for ( j=0; j<strlen(vals[13]); j++) {
      output[index++] = vals[13][j];
    }
    printf("No true Roman would use a number that large");
  } else {
    for ( i=0; i < 13; i++) {
      while ( num >= nums[i] ) {
	num -= nums[i];
	printf("%s",vals[i]);
	for ( j=0; j<strlen(vals[i]); j++) {
	  output[index++] = vals[i][j];
	}
      }
    }
  }
  output[index] = '\0';
  printf("\n");
}

void romanMath(char *str)
{
  int strLen, aStart, aStop, addsub, bStart, bStop, i;
  char *a, *b, c[50];

  strLen = strlen(str);
  addsub = -1;
  bStop = -1;

  //Find start of first number
  if ( isalnum(str[0])) {
    aStart = 0;
  } else {
    aStart = 1;
  }
  //Find end of first number
  for ( i=1; i < strLen; i++) {
    if ( !isalnum(str[i]) ) {
      aStop = i;
      break;
    }
  }
  //Find the operation
  for ( i=aStop; i < strLen; i++) {
    bStart = i;
    if ( str[i] == '+' ) {
      addsub = 1;
      break;
    } else if ( str[i] == '-' ) {
      addsub = 0;
      break;
    }
  }
  //Find the start of the second number
  for ( i=bStart; i < strLen; i++) {
    if ( isalnum(str[i]) ) {
      bStart = i;
      break;
    }
  }
  //Find the end of the second number
  for ( i=bStart+1; i < strLen; i++) {
    if ( !isalnum(str[i]) ) {
      bStop = i;
      break;
    }
  }
  if ( bStop == -1 ) {
    bStop = strLen;
  }

  a = (char*)malloc(aStop - aStart);
  b = (char*)malloc(bStop - bStart);

  strncpy(a, str+aStart, aStop - aStart);
  strncpy(b, str+bStart, bStop - bStart);

  if ( addsub ) {
    parseIntNum(addNumbers(a,b), c);
  } else {
    parseIntNum(subNumbers(a,b), c);
  }
  
  strcpy(str, c);
}
