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
   SetKeyName("jacket");
   SetShort("a forest green leather jacket");
   SetId( ({ "jacket" }) );
   SetAdjectives( ({ "forest","green","leather" }) );
   SetLong("Well-worn into softness, the leather jacket was dyed a deep "
           "forest green.  It was well-crafted.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_ARMOUR);
   SetArmourClass(ARMOUR_LEATHER);
   SetMass(25);
   SetValue(100);
   SetSize(SIZE_MEDIUM);
   SetDamagePoints(450);
}
