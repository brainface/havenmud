#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("club");
   SetShort("a soft wood club");
   SetId( ({ "club" }) );
   SetAdjectives( ({ "soft","wood" }) );
   SetLong("The soft wood club is not very large, and, as it is made from a soft wood, "
           "doesn't hurt that much when it bashes into someone.  It is just a basic "
           "blunt weapon that will allow one to start learning about those skills.");
   SetClass(10);
   SetValue(0);
   SetMass(30);
   SetVendorType(VT_WEAPON);
   SetDamageType(BLUNT);
   SetWeaponType("blunt");
   SetMaterial( ({ "wood" }) );
   SetDamagePoints(700);
   SetProperty("history","This soft wood club was given out by Gravisue, the diviner "
               "leader of ditmar.");
}