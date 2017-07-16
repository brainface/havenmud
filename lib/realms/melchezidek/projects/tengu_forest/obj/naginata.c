#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("long-bladed naginata");
  SetId( ({ "naginata" }) );
  SetAdjectives( ({ "long-bladed" }) );
  SetShort("a long-bladed naginata");
  SetLong(
    "This naginata is a long staff that has a"
    " long blade attached to the end of it. Wielded"
    " and handled like a staff, the main objective"
    " while using the naginata is to slice the enemy"
    " with huge sweeping blows that build up momentum"
    " and power before striking."
  );
  SetHands(2);
  SetClass(18);
  SetWeaponType("pole");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1000);
  SetValue(1200);
  SetMass(200);
  SetMaterials( ({ "wood", "metal" }) );
  SetRepairDifficulty(25);
  SetRepairSkills( ([
    "wood working" : 5,
    "weapon smithing" : 5,
    "metal working" : 5,
     ]) );
 }
