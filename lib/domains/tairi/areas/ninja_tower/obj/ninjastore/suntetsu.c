
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("suntetsu");
  SetShort("a suntetsu");
  SetId( ({ "suntetsu", "shobo" }) );
  SetAdjectives( ({  "ninja" }) );
  SetLong("This suntetsu is a small metal rod that has been"
          " crafted with a ring attached to the middle of it."
          " Gripped in various fashions the suntetsu can either"
          " be a fist pack or, more commonly, it can be used"
          " to apply extreme force to sensitive pressure points"
          " on the opponents body. Coupled with a knowledge of"
          " anatomy, and this can be a very deadly weapon." 
  );
  SetWeaponType("melee");
  SetDamageType(PIERCE);
  SetVendorType(VT_WEAPON);
  SetClass(15);
  SetDamagePoints(1200);
  SetValue(600);
  SetMass(85);
  SetMaterial("metal");
  SetRepairSkills( ([
     "metal working" : 2,
     "weapon smithing" : 2,
    ]) );
  SetRepairDifficulty(9);
}
