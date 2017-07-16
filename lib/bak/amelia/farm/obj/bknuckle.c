#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("brass knuckles");
   SetShort("brass knuckles");
   SetLong("These would fit nicely over a hand to augment melee attack.");
   SetId( ({"brass knuckles","knuckles","brass","knuckles"}) );
   SetClass(10);
   SetDamagePoints(700);
   SetValue(200);
   SetWeaponType("melee");
   SetDamageType(BLUNT);
   SetMass(20);
   SetVendorType(VT_WEAPON);
   SetAdjectives( ({ "brass" }) );
}