// Amelia
#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_STORAGE;

static void create() {
   ::create();
   SetKeyName("backpack");
   SetShort("a sturdy backpack");
   SetId( ({ "pack","backpack","bp" }) );
   SetAdjectives( ({ "back","sturdy","large" }) );
   SetLong(
     "The backpack is made of a tough material, and is fairly "
     "large. It looks like a lot of stuff could fit inside."
   );
   SetVendorType(VT_ARMOUR);
   SetMass(40);
   SetValue(225);
   SetDamagePoints(700);
   SetCanClose(1);
   SetClosed(0);
   SetMaxCarry(1000);
   
}
