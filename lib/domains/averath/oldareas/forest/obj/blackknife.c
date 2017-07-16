// Amelia
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("knife");
   SetShort("a black knife");
   SetId(({ "knife" }) );
   SetAdjectives( ({ "black","shark" }) );
   SetLong("The entire knife, both blade and handle, are a deep black in color, "
           "with almost no light escaping from it.  Its surface is otherwise "
           "smooth and undecorated.");
   SetMass(2);
   SetValue(300);
   SetVendorType(VT_WEAPON);
   SetDamagePoints(600);
   SetWeaponType("knife");
   SetDamageType(SLASH);
   SetClass(25);
}
