#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("black knife");
  SetId( ({ "knife" }) );
  SetAdjectives( ({ "black" }) );
  SetShort("a black knife");
  SetLong(
    "This black knife has serpents etched into the blade, as if the blade was "
    "the fangs and the hilt was the coiled body of the serpent. It looks extremely "
    "dangerous and deadly if placed in the proper hands."
  );
  SetClass(25);
  SetDamagePoints(7000);
  SetValue(2500);
  SetWeaponType("knife");
  SetDamageType(SLASH);
  SetMass(15);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(25);
}
