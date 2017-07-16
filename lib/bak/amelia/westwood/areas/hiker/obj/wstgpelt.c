#include <size.h>
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;
inherit LIB_TOUCH;

static void create() {
   armour::create();
   SetKeyName("white pelt"); 
   SetShort("a white pelt");
   SetSize(SIZE_SMALL);
   SetId( ({ "pelt" }) );
   SetAdjectives( ({ "white","luminescent","tough","soft","beautiful" }) );
   SetLong("The pelt almost shines in a luminous white.  It is soft and "
           "beautiful, but also tough.");
   SetMass(150);
   SetMaterial("leather");
   SetWarmth(20);
   SetValue(300);
   SetVendorType(VT_TREASURE|VT_ARMOUR);
   SetArmourType(A_CLOAK);
   SetDamagePoints(400);
   SetProtection(PIERCE,8);
   SetProtection(SLASH,8);
   SetProtection(BLUNT,8);
   SetProtection(MAGIC,5);
   SetProperty("history","This used to be the pelt of the white stag of "
               "the West Wood.");
   SetProperty("magic","Sometime, long ago, perhaps even before the Gods "
               "War, this pelt was blessed as a part of the great white "
               "stag of the West Wood.");
   SetTouch("The pelt is the softest and smoothest of any stag.");
}
