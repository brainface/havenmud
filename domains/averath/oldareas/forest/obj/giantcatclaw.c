#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("claw");
   SetShort("a giant cat's claw");
   SetId( ({ "claw" }) );
   SetAdjectives( ({ "giant","cat's","cat" }) );
   SetLong("Razor sharp, this claw is a sparkling white color. About "
	   "as long as a child's hand, the claw could be used as a "
           "makeshift dagger.  ");
   SetMass(1);
   SetValue(400);
   SetVendorType(VT_WEAPON);
   SetWeaponType("knife");
   SetDamageType(PIERCE);
   SetDamagePoints(400);
   SetClass(15);
}
