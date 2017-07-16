#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
item::create();
  SetKeyName("mallet");
  SetId( ({ "hammer", "mallet" }) );
  SetAdjectives( ({ "large", "two", "handed" }) ); 
  SetShort("a two-handed mallet");
  SetLong("This large mallet has a long wooden handle with a "
          "large black iron head. The head and handle are "
          "both worn but still in good condition. The mallet "
          "can be used as a weapon if the need arised.");
  SetMass(400);
  SetValue(100);
  SetDamagePoints(2000);
  SetHands(2);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetClass(20);
  SetMaterial( ({"metal", "wood"}) );
  SetRepairDifficulty(10);
  SetVendorType(VT_WEAPON);
}