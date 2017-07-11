// mahkefel 20101117   
// pirate knife        
#include <lib.h>       
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;        


static void create() {
  item::create();     
  SetKeyName("ornate rapier");
  SetId( ({"rapier"}) );
  SetAdjectives( ({ "ornate" }) );
  SetShort("a ornate rapier");
  SetLong(
    "The ornate hilt of this weapon swirls from the crosshilt "
    "in rings fashioned to look like a sea-serpent. Slightly "
    "stained fabric wrapped around the handle provides an "
    "excellent grip. The blade itself is undecorated, and "
    "rises from a wide oval base to a needle thin point, "
    "nearly three feet in length. It could likely poke an "
    "eye right out."
  );
  SetClass(30);
  SetDamagePoints(3000);
  SetValue(5000);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetMass(50);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
  SetHands(1);
}
