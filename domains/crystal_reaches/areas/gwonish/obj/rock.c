
#include <lib.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("rock");
  SetId(({"small rock", "rock"}));
  SetShort("a rock");
  SetLong("A tiny grey rock");
  SetMass(1);
  SetValue(0);
  SetDamagePoints(100);
}

