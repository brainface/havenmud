// Coded by Zeratul
// 2-24-2000

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../vacazar.h"
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("axe");
  SetId( ({"axe","large axe","long axe","huge long axe"}) );
  SetAdjectives( ({"huge","large","long"}) );
  SetShort("a huge long axe");
  SetLong(
     "This huge long axe is the standard weapon of the watchmen fighters. The "
     "long, metal handle is capped off with a large steel head. This axe "
     "looks to be very durable. "
  );
  SetDamagePoints(950);
  SetValue(200);
  SetMass(180);
  SetClass(19);
  SetVendorType(VT_WEAPON);
  SetDamageType(SLASH);
  SetWeaponType("hack");
  SetRepairDifficulty(23);
  SetRepairSkills( ([
     "metal working" : 10,
     "weapon smithing" : 10,
  ]) );
  SetMaterial( ({"metal"}) );
  }
