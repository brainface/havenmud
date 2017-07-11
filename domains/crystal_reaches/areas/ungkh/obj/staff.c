//Selket@Haven
//2006
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("skull staff");
  SetMaterial( ({ "wood", "natural" }) );
  SetRepairDifficulty(10);
  SetShort("a skull-topped staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "skull", "topped"} ) );
  SetLong("This long staff is topped by an ossified troll "
          "skull, painted with gruesome symbols.");
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetClass(14);
  SetVendorType(VT_WEAPON|VT_MAGIC);
  SetHands(2);
  SetValue(1200);
  SetDamagePoints(1600);
 }
