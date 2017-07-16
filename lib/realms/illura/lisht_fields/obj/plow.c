//Illura@Haven
//Sept 2009
//hand plow
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
inherit LIB_DIGGING;

static void create() {
  item::create();
  digging::create();
  SetKeyName("hand plow");
  SetShort("a hand plow");
  SetId( ({ "plow" }) );
  SetAdjectives( ({ "hand" }) );
  SetProperty("farming item", 1);
  SetMass(100);
  SetValue(50);
  SetLong(
    "This farming tool consists of an arm-length pole with a "
    "curving sickle on one end, all made of wood. It is "
    "not very sharp, but made to trace lines in shallow "
    "silt. It is probably a poor weapon");
  SetWeaponType("pole");
  SetVendorType(VT_FISHING);
  SetDamageType(SLASH);
  SetDamagePoints(1000);
  SetClass(10);
  SetMaterial( ({ "wood" }) );
  SetHands(2);
}
