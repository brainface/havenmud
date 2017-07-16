#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("forging hammer");
  SetId( ({ "hammer" }) );
  SetAdjectives( ({ "forging", "heavy" }) );
  SetShort("a heavy forging hammer");
  SetLong(
    "A heavy iron head caps a sturdy wooden handle, creating a "
    "formidable hammer used to forge weapons in a smithy."
  );
  SetMaterial( ({ "metal", }) );
  SetMass(230);
  SetValue(150);
  SetDamagePoints(1200);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetClass(16);
  SetMaterial( ({
  	"metal",
  	"wood"
  	}) );
  SetRepairDifficulty(25);
  SetVendorType(VT_WEAPON);
}
