
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../camp.h"
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("dulcimer");
   SetShort("a beautiful dulcimer");
   SetId( ({ "dulcimer", "bard_instrument" }) );
   SetAdjectives( ({ "beautiful"}) );
   SetLong("The dulcimer is an oblong wooden box "
           "with two bridges.  Four strings are stretched "
           "across the bridges and are plucked to produce "
           "a wide range of notes.  On either side of the "
           "strings, two f slots and two hearts are carved to "
           "allow the sound to resonant.  The dulcimer has "
           "been varnished a deep red and painted with vines"
           "and flowers.");
   SetMass(250);
   SetValue(1000);
   SetClass(6);
   SetHands(2);
   SetRepairSkills( ([
                       "wood working" : 3,
                       "natural working" : 1,
                       "instrumental music" : 2,
                  ]) );
   SetRepairDifficulty(25);
   SetMaterial( ({ "wood","natural" }) );
   SetDamagePoints(450);
   SetVendorType(VT_INSTRUMENT);
}
