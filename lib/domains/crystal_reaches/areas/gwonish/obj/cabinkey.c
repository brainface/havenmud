
#include <lib.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("cabin key");
  SetId(({"cabin key", "key"}));
  SetShort("a key");
  SetLong("Many of the teeth are nearly worn smooth with on this key from "
          "years of use.");
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
                     "metal working" : 1,
                     "lock picking" : 1
                 ]) );
  SetRepairDifficulty(12);
  SetMass(1);
  SetValue(10);
  SetDamagePoints(100);
}

