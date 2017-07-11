#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("long bow");
  SetId( ({ "bow" }) );
  SetAdjectives( ({ "long", "tan", "ivory" }) );
  SetShort("an ivory long bow");
  SetLong(
    "The bow appears to be made of a pure ivory. It is a faint "
    "tan color with several dark strips of brown running "
    "through it. The bow string is made up of braided vines from "
    "various plants throughout the forest. "
  );
  SetClass(11);
  SetDamagePoints(2500);
  SetValue(2500);
  SetWeaponType("projectile");
  SetDamageType(PIERCE);
  SetHands(2);
  SetMass(35);
  SetMaterial( ({ "wood", "natural" }) );
  SetVendorType(VT_WEAPON);    
}
