#include <stdio.h>
//Two or more names in an enum can have the same value, in this example being 0.
int main()
{
  enum point {x = 0, y = 0, z = 0};
  printf("%d %d %d\n", x, y, z);
  return 0; 	
}
