#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("rake");
   SetShort("a rake");
   SetLong("The rake is mostly wood.");
   SetId( ({"wood rake","rake"}) );
   SetClass(8);
   SetDamagePoints(700);
   SetValue(150);
   SetWeaponType("pole");
   SetDamageType(BLUNT);
   SetMass(15);
   SetVendorType(VT_WEAPON);
   SetAdjectives( ({ "wood" }) );
}