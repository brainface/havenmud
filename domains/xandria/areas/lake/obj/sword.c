//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("sword");
  SetId( ({ "sword", }) );
  SetAdjectives( ({ "finely", "crafted" }) );
  SetShort("a finely crafted sword");
  SetLong(
    "The steel blade gleams brilliantly. It seems hardly used. "
  );
  SetClass(15);
  SetDamagePoints(1200);
  SetValue(340);
  SetWeaponType("slash");
  SetDamageType(SLASH);  
  SetMass(175);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}
