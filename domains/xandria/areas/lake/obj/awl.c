//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("awl");
  SetId( ({ "awl" }) );
  SetShort("an awl");
  SetLong(
    "This is a very thin, sharply pointed awl used "
    "to pierce through almost any material."
  );      
  SetClass(12);
  SetDamagePoints(550);
  SetValue(60);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetMass(100);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}
