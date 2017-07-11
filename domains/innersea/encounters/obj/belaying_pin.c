// mahkefel 20101117
// belaying pin
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("belaying pin");
  SetId( ({"pin"}) );
  SetAdjectives( ({ "belaying" }) );
  SetShort("a belaying pin");
  SetLong(
    "This thick wooden rod has a smooth handle "
    "carved into one end. While designed to secure "
    "knots along the side of a ship, it can also "
    "easily open a boarder's skull."
  );
  SetClass(25);
  SetDamagePoints(2000);
  SetValue(2500);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetMass(300);
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
  SetHands(1);
}
