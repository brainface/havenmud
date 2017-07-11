#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create()
{
  item::create();
  SetKeyName("hoe");
  SetId( ({ "hoe","garden hoe" }) );
  SetShort("a garden hoe");
  SetLong("A short metal blade is attached to the end of this three "
          "foot long hoe.");
  SetMaterial( ({"wood","metal"}) );
  SetRepairSkills( ([
                     "metal working" : 1,
                     "wood working" : 1
                 ]) );
  SetRepairDifficulty(5);
  SetMass(175);
  SetValue(150);
  SetDamagePoints(400);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetClass(8);
  SetVendorType(VT_WEAPON);
}

