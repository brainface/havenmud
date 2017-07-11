// Amelia@Haven, jan 99

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("spinet");
   SetShort("a decorative spinet");
   SetId( ({ "spinet" }) );
   SetAdjectives( ({ "decorative"}) );
   SetLong("The spinet is a heavy keyboard "
           "instrument made of wood and "
           "various other natural items.  "
           "It is brightly painted.");
   SetMass(500);
   SetValue(2000);
   SetClass(8);
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
