#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("knife");
   SetShort("a small knife");
   SetId( ({ "knife" }) );
   SetAdjectives( ({ "small" }) );
   SetLong("The knife is a small piece of metal, sharpened and "
           "and melded to a hilt.  It is worth no money, but "
           "could be good for fighting.");
   SetMass(10);
   SetValue(0);
   SetClass(15);
   SetVendorType(VT_WEAPON);
   SetWeaponType("knife");
   SetDamageType(SLASH);
   SetDamagePoints(500);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(10);
   SetProperty("history","This is one of the free items given "
               "to young rogues in Parva.");
}
