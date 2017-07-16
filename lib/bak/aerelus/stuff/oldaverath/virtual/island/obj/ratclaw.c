#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("claw");
   SetShort("a rat claw");
   SetId( ({ "claw" }) );
   SetAdjectives( ({ "rat" }) );
   SetLong("About as beautiful as a hog's behind, the rat claw functions "
              "as an inept knife.");
   SetClass(5);
   SetValue(5);
   SetDamagePoints(100);
   SetVendorType(VT_WEAPON);
   SetWeaponType("knife");
   SetDamageType(PIERCE);
}
