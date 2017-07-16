/* A large one handed axe */
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("large axe");
  SetId( ({ "axe" }) );
  SetAdjectives( ({ "large" }) );
  SetShort("a large axe");
  SetLong(
    "This large one-handed axe seems to have "
    "been designed with warriors in "
    "mind. Its heavy blade dangles "
    "from an easy to swing handle, balanced "
    "carefully for ease of use."
  );
  SetClass(15);
  SetDamagePoints(1750);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "weapon smithing" : 1,
    "metal working" : 1,
    ]) );
  SetValue(250);
  SetMass(300);
  SetVendorType(VT_WEAPON);
}
