// Amelia@Haven, jan 99

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("sackbut");
   SetShort("a plain sackbut");
   SetId( ({ "sackbut" }) );
   SetAdjectives( ({ "plain" }) );
   SetLong("This is a plain, inexpensive sackbut "
           "that was easily made and not worth "
           "much.  One blows in one end and moves "
           "a different bar to determine the pitch "
           "of the notes.");
   SetMass(20);
   SetValue(10);
   SetClass(1);
   SetHands(2);
   SetRepairSkills( ([
                       "wood working" : 1,
                       "instrumental music" : 1
                  ]) );
   SetRepairDifficulty(5);
   SetMaterial( ({ "wood" }) );
   SetDamagePoints(50);
   SetVendorType(VT_INSTRUMENT);
}
