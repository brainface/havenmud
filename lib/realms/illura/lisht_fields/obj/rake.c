//Illura@Haven
//Sept 2009
//rake
#include <lib.h>
#include "../fields.h"
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
inherit LIB_DIGGING;

static void create() {
  item::create();
  digging::create();
  SetKeyName("rake");
  SetShort("a crude rake");
  SetId( ({ "rake" }) );
  SetAdjectives( ({ "crude" }) );
  SetProperty("farming item", 1);
  SetMass(100);
  SetValue(50);
  SetLong(
    "This rake stands about shoulder-high on an elf and is made "
    "of a narrow pole with a comb-like bit of metal at the end. "
    "It is used for farming, and the wielder would be a laughable "
    "adversary.");
  SetWeaponType("pole");
  SetVendorType(VT_FISHING);
  SetDamageType(SLASH);
  SetDamagePoints(1000);
  SetClass(10);
  SetMaterial( ({ "metal", "wood" }) );
  SetHands(2);
}
