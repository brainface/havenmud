
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../camp.h"
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("dagger");
  SetRepairDifficulty(10);
  SetRepairSkills( ([
    "metal working" : 1,
   "wood working" : 1,
   "weapon smithing" : 1,
   ]) );
  SetMaterial( ({ "metal", "wood" }) );
  SetId( ({ "dagger"}) );
  SetAdjectives( ({ "graceful" }) );
  SetShort("a graceful dagger");
  SetValue(220);
  SetMass(75);
  SetClass(12);
  SetVendorType(VT_WEAPON);
  SetWeaponType("knife");
  SetDamageType(SLASH);
  SetLong("The double edged dagger has a well crafted "
       "blade that could only be described as graceful.  The "
       "handle of the dagger is made of wood painted black.");
  SetDamagePoints(600);
  }
