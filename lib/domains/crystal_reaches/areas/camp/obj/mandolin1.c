
/*modified by Xera@Haven*/
#include <lib.h>
#include <vendor_types.h>
#include "../camp.h"
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("decorated mandolin");
   SetShort("a decorated mandolin");
   SetId( ({ "mandolin","bard_instrument" }) );
   SetAdjectives( ({ "decorated" }) );
   SetLong("The mandolin has a round, hollow "
        "body, a long neck, and eight strings.  The "
        "body has been varnished a deep red.  The "
        "neck is made of dark black wood.");
   SetMass(120);
   SetVendorType(VT_INSTRUMENT);
   SetValue(200);
   SetDamagePoints(45);
   SetMaterial( ({ "wood","natural" }) );
   SetRepairDifficulty(25);
   SetRepairSkills( ([
                       "instrumental music" : 1,
                       "wood working" : 1,
                       "natural working" : 1,
                  ]) );
   SetClass(2);
   SetHands(2);
   SetProperty("history","This mandolin was made by one of the "
               "gypsies.");
}
