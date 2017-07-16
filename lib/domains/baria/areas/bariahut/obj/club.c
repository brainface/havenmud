//Alex@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create(){
  item::create();
  SetKeyName("club");
  SetId( ({ "club" }) );
  SetShort("a hunter's club");
  SetAdjectives( ({ "hunters", "hunter's" }) );
  SetLong(
    "This is a large piece of wood, good for hunting down "
    "the occasional monkey dinner for four, or playing a "
    "rousing game of whack-a-tarantula.");
  SetClass(5);
  SetDamagePoints(350);
  SetValue(50);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetMass(75);
  SetMaterial( ({"wood"}) );
  SetVendorType(VT_WEAPON);
  SetRepairDifficulty(5);
}
