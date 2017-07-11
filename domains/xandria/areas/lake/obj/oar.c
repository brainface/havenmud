//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("oar");
  SetId( ({ "oar"}) );
  SetShort("an oar");
  SetLong(
     "This is a stout oar used for steering or propelling a vessel "
     "through water. It is about the same height as a staff. "
  );
  SetClass(8);
  SetDamagePoints(500);
  SetHands(2);
  SetValue(70);
  SetWeaponType("pole");
  SetDamageType(BLUNT);  SetMass(175);
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
}
