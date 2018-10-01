#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "evoker", "tall" }) );
  SetShort("a tall evoker staff");
  SetLong(
    "This long staff is twice the height of the average "
    "gnome. The head of the staff is a mass of energy swirling "
    "around the tip which glows brightly. The energy has small "
    "bits of matter that swirl quickly around the tip of the "
    "staff."
  );
  SetHands(2);
  SetClass(12);
  SetWeaponType("pole");
  SetDamageType(BLUNT|SOUND|VACUUM);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1800);
  SetValue(8000);
  SetMass(125);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(75);
  SetRepairSkills( ([
    "wood working" : 90,
    "weapon smithing" : 90,
     ]) );
 }
