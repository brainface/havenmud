#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("pole");
   SetShort("a soft wood pole");
   SetId( ({ "pole" }) );
   SetAdjectives( ({ "soft","wood" }) );
   SetLong("The soft wood club is not very large, and, as it is made from a soft wood, "
           "doesn't hurt that much when it hits someone.  It is just a basic "
           "pole that will allow one to start learning about the skill of pole "
           "attack.");
   SetClass(10);
   SetValue(0);
   SetMass(25);
   SetVendorType(VT_WEAPON);
   SetDamageType(BLUNT);
   SetWeaponType("pole");
   SetMaterial( ({ "wood" }) );
   SetDamagePoints(700);
   SetProperty("history","This soft wood pole was given out by Conta, the enchanter "
               "leader of ditmar.");
}