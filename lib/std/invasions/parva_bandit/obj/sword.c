/*  A buff slashing weapon for certain paladin-oriented people */
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("cutlass");
  SetShort("a curved cutlass");
  SetId( ({ "cutlass", "sword" }) );
  SetAdjectives( ({ "curved" }) );
  SetLong(
    "This curved cutlass is the preferred weapon of vagabonds "
    "and bandits. It is obviously a weapon used in a quick "
    "slashing manner, and not one designed with skilled "
    "warriors in mind."
  );
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMass(100);
  SetValue(100);
  SetClass(12);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "metal working" : 1,
    "weapon smithing" : 1,
  ]) );
  SetProperty("history", "This sword is from the bandits near the HavenWood.");
}
