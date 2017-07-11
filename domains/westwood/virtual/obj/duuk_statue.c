#include <lib.h>
#include <domains.h>
inherit LIB_ITEM;


static void create() {
  ::create();
  SetKeyName("statue");
  SetShort("a massive statue of the Lord of Order");
  SetPreventGet("The statue is too large to move.");
  SetDamagePoints(10000);
  SetLong(
    "This massive statue of the Lord of Order sits peacefully in the WestWood."
    );
}
