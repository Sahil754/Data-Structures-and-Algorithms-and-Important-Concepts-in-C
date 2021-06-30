/*Exercise
Use bit masks to manipulate some flags.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int bit;
    int storage = 10; //1010 in binary
    bit = storage & (1 << 1);
    // storage = storage | 1 << 4;
    // storage is A , 1 << 1 is B (everything on the right of the AND(&) operator)
    printf("%d\n", storage);
     
     //Checking if it's on
     //0000001 (1)
     //0000010 (2)
     //0001010 (10)
     //0000010 (2 --> Result)
}
#include <stdio.h>
#include <assert.h>

/* Finish initializing the flags */

const short FLAG_ON          = 1 << 0; // 1  (0x01)
const short FLAG_MOVEMENT    = 1 << 1; // 2  (0x02)
const short FLAG_TRANSPARENT = 1 << 2; // 4  (0x04)
const short FLAG_ALIVE       = ;
const short FLAG_BROKEN      = ;
const short FLAG_EDIBLE      = 1 << 5; // 32 (0x20)

int main() {
  short attributes = 0;

  /* Set the attributes ON, TRANSPARENT, and BROKEN */

  assert(attributes == (FLAG_ON | FLAG_TRANSPARENT | FLAG_BROKEN));

  /* Modify (set/clear/toggle) so the only attributes are ON and ALIVE */

  assert(attributes == (FLAG_ON | FLAG_ALIVE));

  /* Check if the ALIVE flag is set */
  assert(/* ??? */);

  /* Check if the BROKEN flag is not set */
  assert(/* ??? */);

  /* Modify so only the EDIBLE attribute is set */

  assert(attributes == FLAG_EDIBLE);

  printf("Done!");
}