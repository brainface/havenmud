#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a warm, black staff");
  SetLong("Seemingly as hard as steel, this six foot long staff is a "
          "formidable weapon.  Its glossy black surface lends to its "
          "intimidating nature.  It seems to be radiating warmth.");
  SetId( ({ "warm black staff", "warm staff", "black staff", "staff" }) );
  SetClass(15);
  SetDamagePoints(2000);
  SetValue(2000);
  SetWeaponType("pole");
  SetDamageType(BLUNT|MAGIC);
  SetKeyName("black staff");
  SetMass(200);
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({ "wood", "wooden", "warm", "black", "glossy" }) );
  SetHands(2);
  SetRepairDifficulty(15);
  SetRepairSkills( ([
    "weapon smithing" : 10,
    "wood working"    : 5,
  ]) );
  SetProperty("magic", "This staff is undeniably magical in nature, but the "
              "magic within it is so strange as to be unrecognizable.");
}
