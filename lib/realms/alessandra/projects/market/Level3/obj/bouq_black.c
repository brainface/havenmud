#include <lib.h>
inherit LIB_ITEM;
inherit LIB_SMELL;
inherit LIB_TOUCH;

static void create() {
  item::create();

  SetKeyName("bouquet");
  SetShort("a bouquet of black roses");
  SetId(  ({"bouquet", "rose", "roses", "flower", "flowers"}) );
  SetAdjectives( ({"black", "rose", "roses"}) );
  SetLong(
     ""
     );
  SetSmell("");
  SetTouch("");
  SetMass(10);

}
