#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("halberd");
  SetId( ({ "halberd" }) );
  SetAdjectives( ({ "steel", "tipped" }) );
  SetShort("a steel-tipped halberd");
  SetLong(
    "This is a steel-tipped halberd."
  );
  SetHands(2);
  SetClass(15);
  SetWeaponType("pole");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(800);
  SetValue(80);
  SetMass(200);
  SetMaterials( ({ "wood", "metal" }) );
  SetRepairDifficulty(5);
  SetRepairSkills( ([
    "metal working" : 1,
    "weapon smithing" : 1,
     ]) );
 }
