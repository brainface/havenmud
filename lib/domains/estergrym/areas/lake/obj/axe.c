#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("axe");
  SetId( ({ "axe", "wood axe", "heavy axe" }) );
  SetAdjectives( ({ "large", "heavy" }) );
  SetShort("a large heavy wood axe");
  SetLong("The large axe seems to have a few chips in it "
          "as it is used for wood cutting. It is heavy "
          "and is double bladed for a heavier cutting head."
          " It is of dwarven craftsmanship.");
  
  SetMaterials( ({ "metal" }) );
  SetRepairDifficulty(12);
  SetRepairSkills( ([
    "metal working" : 1,
    "weapon smithing" : 1,
   ]) );
  
  SetHands(2);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(750);
  SetClass(13);
  SetMass(275);
  SetValue(300);
 }
