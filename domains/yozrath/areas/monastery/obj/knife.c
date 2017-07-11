// Monastery
// Aerelus
// 07/05/2006

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../monastery.h"
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("knife");
  SetId( ({ "knife" }) );
  SetShort("a dull chopping knife");
  SetAdjectives( ({ "dull", "chopping", "wooden" }) );
  SetLong(
    "This knife is very blunt. It is used for the chopping of vegetables. "
    "It looks as if it wouldn't do too much damage to a person, but is by no "
    "means worthless. The wooden hilt looks almost new, suggesting that the "
    "blade itself has been in use for quite some time."
  );
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetClass(3);
  SetDamagePoints(500);
  SetValue(50);
  SetMass(30);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(5);
  SetVendorType(VT_WEAPON);
}
