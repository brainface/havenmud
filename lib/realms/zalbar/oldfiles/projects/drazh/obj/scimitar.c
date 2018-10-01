#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("scimitar");
  SetId( ({"scimitar", "sword"}) );
  SetShort("a scimitar");
  SetLong(
     "This broad-bladed curved sword has a three foot long blade "
     "with a the curved side sharpened. The hilt has a crossbar to "
     "protect the wielders hand."
	 );
  SetAdjectives( ({"curved", "broad", "bladed"}) );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(800);
  SetClass(5);
  SetValue(350);
  SetMass(70);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMaterial("metal");
  SetHands(1);
  SetRepairSkills( ([
     "metal working"   : 2,
     "weapon smithing" : 1,
     ]) );
  SetRepairDifficulty(2);
}


