/* a warning sign
     Ela 11/19/98
*/

#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("sign");
  SetShort("a sign");
  SetRead(
     "default" , "Beware! Herein lies the den of the legendary "
     "Red Bull. To tangle with the magical demon of the Fae "
     "is a deadly undertaking. Run for your life!");
  SetLong("The words on the sign are shakily written. "
          "The sign hangs at an angle as though it was hastily "
          "hung.");
  SetPreventGet("The sign is nailed in place.");
}
