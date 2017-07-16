#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("axe");
   SetShort("a dull axe");
   SetId( ({ "axe" }) );
   SetAdjectives( ({ "dull" }) );
   SetLong("The axe is designed for hacking away at one's opponent until they die or "
           "give up, or maybe kill the bearer of the axe instead.  It isn't a very "
           "sharp axe, but it's a weapon, and would probably be better than bare "
           "hands.");
   SetClass(10);
   SetValue(0);
   SetMass(50);
   SetVendorType(VT_WEAPON);
   SetDamageType(SLASH);
   SetWeaponType("hack");
   SetMaterial( ({ "wood","metal" }) );
   SetDamagePoints(700);
   SetProperty("history","This dull axe was given out by Vanta, the fighter leader "
               "in Ditmar.");
}