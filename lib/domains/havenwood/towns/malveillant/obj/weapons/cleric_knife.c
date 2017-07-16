/*  Portia   10-21-98
   Free equip for my clerics.
*/

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("knife");
  SetShort("a small knife");
  SetId( ({"knife"}) );
  SetAdjectives( ({"small"}) );
  SetLong("This knife doesn't look very valuable. It looks like "
          "it could be very usefull if one was attacked.");
  SetValue(30);
  SetClass(7);
  SetMass(20);
  SetDamagePoints(500);
  SetMaterials( ({"metal"}) );
  SetRepairSkills( ([
     "metal working" : 2,
     "weapon smithing" : 2,
     ]) );
  SetRepairDifficulty(10);
  SetVendorType(VT_WEAPON);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  }
