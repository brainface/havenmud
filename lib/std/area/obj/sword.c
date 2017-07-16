/*  Duuktsaryth@Haven
 *  A sword for the example area
 */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("sword");
  SetShort("a sharp sword");
  SetId( ({ "sword" }) );
  SetAdjectives( ({ "sharp" }) );
  SetLong("This long and sharp sword is made of quality metal. "
          "It appears to be a fine blade for an unskilled adventurer.");
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "metal working" : 1,
    "weapon smithing" : 1,
  ]) );
  SetRepairDifficulty(10);
  SetDamagePoints(1000);
  SetClass(12);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetValue(150);
  SetMass(120);
 }
