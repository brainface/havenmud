/*  Portia  10-15-98
    A sword for the guards.
*/

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sword");
  SetShort("a large sword");
  SetId( ({"sword"}) );
  SetAdjectives( ({"large"}) );
  SetLong("This sword is quite large and should only be used by a skilled" 
          "hand.");
  SetValue(80);
  SetClass(13);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetDamagePoints(1500);
  SetRepairSkills( ([
     "metal working" : 7,
     "weapon smithing" : 6,
     ]) );
  SetRepairDifficulty(20);
  SetMaterial( ({"metal"}) );
  SetMass(120);
  }
