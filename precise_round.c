#include <stdio.h>
#include <math.h>

#define DTOA_BUFF_SIZE (460 * sizeof(void *))

/* Magic value returned by dtoa() to indicate overflow */
#define DTOA_OVERFLOW 9999

extern char *dtoa(double d, int mode, int ndigits,
		  int *decpt, int *sign, char **rve);
extern void freedtoa(char *s);
extern double strtod(const char *s00, char **se);

double precise_round(double x, int digits)
{
  int width = DTOA_BUFF_SIZE-1;
  int decpt, sign, len;
  char to[DTOA_BUFF_SIZE];
  char *res, *src, *end, *dst= to;

  digits = -digits;

  res = dtoa(x, 4, width, &decpt, &sign, &end);

  //printf("res=%s\n", res);

  if (decpt == DTOA_OVERFLOW || res == end) {
    freedtoa(res);
    return NAN;
  }

  src= res;
  len= end - res;

  /* 'e' format */

  if (sign)
    *dst++= '-';

  *dst++= '0'; // guards

  if (decpt >= digits) {
    if (decpt-- == digits) {
      if (*src >= '5' && *src <= '9') {
	*(dst-1) = '1';
      }
      *dst++= '0';
    } else {
      *dst++= *src++;
    }
  }

  if (len > 1 && decpt >= digits) {
    while (src < end) {
      if (decpt-- == digits) {
	if (*src >= '5' && *src <= '9') {
	  char *s = dst;
	  while (--s) {
	    if (*s == '9') {
	      *s = '0';
	    } else {
	      *s = *s+1;
	      break;
	    }
	  }
	}
	*dst++= '0';
	break;
      }
      *dst++= *src++;
    }
  }

  *dst++= 'e';

  if (decpt < 0) {
    *dst++= '-';
    decpt = -decpt;
  }

  if (decpt >= 100) {
    *dst++= decpt / 100 + '0';
    decpt %= 100;
    *dst++= decpt / 10 + '0';
  } else if (decpt >= 10) {
    *dst++= decpt / 10 + '0';
  }
  *dst++= decpt % 10 + '0';
  *dst= '\0';

  freedtoa(res);

  //printf("to=%s\n", to);

  return strtod(to, NULL);
}
