#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
item::create();
  SetKeyName("stick");
  SetId( ({ "stick" }) );
  SetAdjectives( ({ "wooden" }) );
  SetShort("a wooden stick");
  SetLong(
    "A simple wooden stick, long dead and dried. Teeth marks "
    "and dirt mar the surface."
  );
  SetMass(20); 
  SetValue(0);
  SetDamagePoints(1150);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetClass(5);
  SetHands(1);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "wood" }) );
  SetRepairSkills( ([
    "wood working" : 1,
    ]) );
  SetRepairDifficulty(5);
}
