#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("knife");
   SetShort("a dull knife");
   SetId( ({ "knife" }) );
   SetAdjectives( ({ "dull" }) );
   SetLong("The dull knife is a simple little piece of metal whose design flaws and "
           "faulty workmanship ahve made it turn out quite dull.  It is better "
           "than bare hands, however, and will help one practice one's knife "
           "skills even if it doesn't kill the creature one is fighting.");
   SetClass(10);
   SetValue(0);
   SetMass(15);
   SetVendorType(VT_WEAPON);
   SetDamageType(SLASH);
   SetWeaponType("knife");
   SetMaterial( ({ "metal" }) );
   SetDamagePoints(700);
   SetProperty("history","This dull knife was given out by Tobor, the rogue leader "
               "in Ditmar.");
}