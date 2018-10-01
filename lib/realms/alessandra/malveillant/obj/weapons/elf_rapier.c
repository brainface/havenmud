/*  Portia  10-15-98
    A beautiful rapier.
*/

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("rapier");
  SetId( ({"rapier"}) );
  SetAdjectives( ({"beautiful"}) );
  SetLong("This rapier was made by a skilled hand is very beautiful. It's beauty however, "
          "doesn't detract from it's deadliness, as it is a very formidable weapon.");
  SetMass(30);
  SetShort("a beautiful rapier");
  SetValue(100);
  SetClass(15);
  SetDamagePoints(1200);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
     "metal working" : 5,
     "weapon smithing" : 6,
     ]) );
  SetRepairDifficulty(40);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  }
