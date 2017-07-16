
#include <lib.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("pebble");
  SetId(({"small pebble", "pebble"}));
  SetShort("a pebble");
  SetLong("A tiny brown pebble");
  SetMass(1);
  SetValue(0);
  SetDamagePoints(100);
}

