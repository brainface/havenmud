#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("broom");
  SetId( ({ "broom" }) );
  SetAdjectives( ({ "blood-stained","blood","stained" }) );
  SetShort("a blood-stained broom");
  SetLong(
    "This dirty and ragged mop has seen a lot of abuse over the years. "
    "Ragged and worn corncob bristles, now stained permanantly with blood "
    "and ichor, are tied to a sturdy pine handle."
  );
  SetHands(2);
  SetClass(12);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1200);
  SetValue(80);
  SetMass(200);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(5);
}

