//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create()
{
item::create();
  SetKeyName("card");
  SetId( ({ "wool", "card" }) );
  SetAdjectives( ({ "for", "carding" }) );
  SetShort("a card for carding wool");
  SetLong(
    "This hand tool separates wool fibers with nary a "
    "struggle and appears very sharp."
  );
  SetMaterial( ({"metal","wood"}) );
  SetMass(230);
  SetValue(150);
  SetDamagePoints(1200);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetClass(12);
  SetVendorType(VT_WEAPON);
}
