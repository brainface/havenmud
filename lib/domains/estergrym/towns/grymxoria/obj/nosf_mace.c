#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("mace");
  SetId( ({ "mace" }) );
  SetAdjectives( ({ "red", "headed", "reddish" }) );
  SetShort("a red mace");
  SetLong(
    "A finely crafted mace with a head "
    "made of a reddish metal on top of a leather "
    "wrapped wooden shaft. "
  );
  SetVendorType(VT_WEAPON);
  SetMass(75);
  SetClass(13);
  SetDamagePoints(2000);
  SetValue(350);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetMaterial( ({
  	"metal",
  	"wood",
  	}) );
  SetRepairDifficulty(10);
}

