#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("recorder");
   SetShort("a brightly painted recorder");
   SetId( ({ "recorder","bard_instrument" }) );
   SetAdjectives( ({ "brightly","painted" }) );
   SetLong("The recorder is a bright wooden instrument "
           "with a numble of holes in it that one can "
           "close up with one's fingers to change the note.");
   SetMass(5);
   SetVendorType(VT_INSTRUMENT);
   SetValue(20);
   SetDamagePoints(25);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(5);
   SetRepairSkills( ([
                       "instrumental music" : 1,
                       "wood working" : 1,
                  ]) );
   SetClass(2);
   SetHands(2);
   SetProperty("history","This recorder was made by someone in "
               "the Eclatish monastery.  The craftsman was not "
               "extremely talented, but made a good instrument.");
}
