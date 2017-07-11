// Coded by Zeratul 11-27-99
#include <lib.h>
#include "../lake.h"
inherit LIB_KEY;
inherit LIB_ITEM;

static void create() {
  item::create();
  key::create();
  SetKeyName("small key");
  SetId( ({"small key","key","cabin_key"}) );
  SetShort("a small key");
  SetLong("This small key looks to be worn down from years of use. It is "
     "a key to the door of the cabin. "
     );
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
     "metal working" : 1,
     "lock picking" : 1,
     ]) );
  SetRepairDifficulty(9);
  SetMass(1);
  SetValue(9);
  SetDamagePoints(75);
}
