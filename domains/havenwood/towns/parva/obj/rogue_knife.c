#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("knife");
   SetShort("a simple little knife");
   SetId( ({ "knife" }) );
   SetAdjectives( ({ "simple","little" }) );
   SetLong("There is nothing exceptional about this knife.  "
           "Its quality is fair, and its design normal.");
   SetMass(10);
   SetValue(35);
   SetClass(7);
   SetVendorType(VT_WEAPON);
   SetWeaponType("knife");
   SetDamageType(SLASH);
   SetDamagePoints(150);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(5);
   SetProperty("history","This knife used to be the property of "
               "Pecunia, the rogue leader and a barmaid in "
               "Parva.");
}
