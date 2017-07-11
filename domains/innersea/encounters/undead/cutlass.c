// mahkefel 2010
// got a little tired of all boarders having thin stilettos
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("cutlass");
  SetId( ({ "cutlass" }) );
  SetAdjectives( ({ "old","rusty" }) );
  SetShort("an old rusty cutlass");
  SetLong(
    "This ancient sword should be a pile of rust by now. "
    "Sunlight shines through holes in the blade and the grip has long "
    "ago rotted off. It seems to be held together by some stubborn, "
    "malicious intent."
  );
  SetProperty(
    "history",
    "This weapon was recovered from The Black Night, a notorious ghost "
    "ship that prowls the ruined sea. It appears to hold no enchantment, "
    "other than its unwillingness to finally decay."
  );
  SetClass(20);
  SetDamagePoints(1500);
  SetValue(200);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMass(500);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(25);
}

