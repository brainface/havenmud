#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
void DestMe();

static void create() {
  item::create();
  SetKeyName("energy blade");
  SetId( ({ "blade" }) );
  SetAdjectives( ({"glowing", "energy", "small"}) );
  SetShort("a glowing blade");
  SetLong(
    "This small blade has a slight glow of power "
    "to it."
  );
  SetClass(20);
  SetDamagePoints(400);
  SetValue(350);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetMass(25);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal","magic" }) );
  call_out((: DestMe() :), 240);      
}

void DestMe() {
  message(
    "my_action","Your glowing blade suddenly turns into dust "
    "and disappears.",this_player());
  eventDestruct();
}
