#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() 
  {
  item::create();
  SetKeyName("greatsword");
  SetId( ({ "sword", "greatsword" }) );
  SetAdjectives( ({ "steel", "great" }) );
  SetShort("a steel greatsword");
  SetLong("This is a large sword that stands taller than a normal sized human.  It "
    "is edged on both sides with a slot running down the center.  It gleams in the "
    "light with an eery red hue.");
  SetClass(16);
  SetDamagePoints(1200);
  SetValue(300);
  SetWeaponType("slash");
  SetDamageType(SLASH);  
  SetMass(500);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
  SetHands(2);
}

