#include <lib.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("chain shackles");
  SetId(({"chains","shackles","chain","chain shackles"}));
  SetShort("chain shackles");
  SetLong("Although rusted and pitted in spots the iron chains look more "
          "than sturdy enough to hold a prisoner.");
  SetMass(250);
  SetValue(10);
  SetDamagePoints(500);
}

