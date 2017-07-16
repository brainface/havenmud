#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("crossbow");
   SetShort("a plain crossbow");
   SetId( ({ "crossbow" }) );
   SetAdjectives( ({ "plain" }) );
   SetLong("The plain crossbow is slightly flawed and isn't the best at aiming, it "
           "appears.  It is a good weapon to start work with and learn about "
           "projectile attacks, however.");
   SetClass(10);
   SetValue(0);
   SetMass(45);
   SetVendorType(VT_WEAPON);
   SetDamageType(PIERCE);
   SetWeaponType("projectile");
   SetMaterial( ({ "wood","leather" }) );
   SetDamagePoints(700);
   SetProperty("history","This plain crossbow was given out by Namime, the ranger leader "
               "in Ditmar.");
}