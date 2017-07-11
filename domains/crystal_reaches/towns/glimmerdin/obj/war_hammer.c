#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("war hammer");
  SetId( ({ "hammer", }) );
  SetShort("a stout war hammer");
	SetAdjectives( ({ "stout", "war" }) );
  SetLong("This a sturdy war hammer that is used to crush an opponent "
          "and any armor he or she might be wearing. It is used in two hands.");
  SetClass(15);
  SetHands(2);
  SetMaterial("natural");
  SetRepairDifficulty(10);
  SetDamagePoints(1200);
  SetValue(200);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
	SetMass(200);
	SetVendorType(VT_WEAPON);
}
