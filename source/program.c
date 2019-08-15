#include <stdio.h>
#include "mathprog.h"

void main()
{
   int result, a, b;

   a = 5;
   b = 10;

   result = integer_add(a, b);

   printf("result: %i\n", result);
}
