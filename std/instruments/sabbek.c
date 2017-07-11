// Amelia@Haven, jan 99

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("sabbek");
   SetShort("a beautiful sabbek");
   SetId( ({ "sabbek" }) );
   SetAdjectives( ({ "beautiful" }) );
   SetLong("Carved into the wood of this "
           "harp-like instrument are "
           "beautiful, intricate designs.");
   SetMass(100);
   SetValue(1000);
   SetClass(4);
   SetHands(2);
   SetRepairSkills( ([
                       "wood working" : 3,
                       "natural working" : 1,
                       "instrumental music" : 2,
                  ]) );
   SetRepairDifficulty(25);
   SetMaterial( ({ "wood","natural" }) );
   SetDamagePoints(250);
   SetVendorType(VT_INSTRUMENT);
}
