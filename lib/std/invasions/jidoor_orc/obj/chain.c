//
// Eq of the 'Jidoor Orc' invasion
//

#include <lib.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("chainmail");
   SetShort("a vest of shiny chainmail");
   SetId( ({ "vest", "chainmail" }) );
   SetAdjectives( ({ "chainmail", "shiny" }) );
   SetLong(
     "This fine suit of chainmail looks very nice, indeeed. It looks "
     "prepared to fend off some of the supernatural abilities of "
     "the world"
   );
   SetDamagePoints(1200);
    SetArmourClass(ARMOUR_CHAIN);
    SetSize(SIZE_LARGE);
   SetValue(1800+random(500));
   SetMass(300);
   SetArmourType(A_VEST);
   SetVendorType(VT_ARMOUR);
   SetProperty("magic", "This armour has some resistance to magic.");
 }
