// amelia
#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("socks");
   SetShort("a pair of long black socks");
   SetId( ({ "socks" }) );
   SetAdjectives( ({ "pair of","long","black"}) );
   SetLong("Formed from a tough, resilient material, the black socks easily " 
           "reach to knee-high on any average adult male, "
           "warming the feet and leg of the owner.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_LONG_SOCK);
   SetArmourClass(ARMOUR_CLOTH);
   SetMass(1);
   SetValue(40);
   SetProperty("multiples",1);
   SetDamagePoints(200);
   SetSize(SIZE_MEDIUM);
}
