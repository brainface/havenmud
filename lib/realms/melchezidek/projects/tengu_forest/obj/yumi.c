#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("long bamboo yumi");
  SetId( ({ "yumi" }) );
  SetAdjectives( ({ "long", "bamboo" }) );
  SetShort("a long bamboo yumi");
  SetLong(
    "This bamboo long bow, called a yumi, is about"
    " five feet in height. The grip of the bow is"
    " about two feet from the bottom and the arch"
    " on the upper half of the bow is dramatically"
    " sharper than that on the lower."
  );
  SetHands(2);
  SetClass(18);
  SetWeaponType("projectile");
  SetDamageType(PIERCE);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1000);
  SetValue(1200);
  SetMass(200);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(25);
  SetRepairSkills( ([
    "wood working" : 5,
    "weapon smithing" : 5,
    ]) );
 }
