#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("fife");
   SetShort("a wooden fife");
   SetId( ({ "fife","bard_instrument" }) );
   SetAdjectives( ({ "fife" }) );
   SetLong("The fife is plain and wooden.  It was well-crafted "
           "to make good sounds, but it is not very beautiful "
           "beyond its simple delicate prettiness that comes "
           "from being an instrument.");
   SetMass(10);
   SetVendorType(VT_INSTRUMENT);
   SetValue(150);
   SetDamagePoints(50);
   SetMaterial( ({ "wood" }) );
   SetRepairSkills( ([
                       "wood working" : 1,
                       "instrumental music" : 1,
                  ]) );
   SetClass(2);
   SetHands(2);
   SetProperty("history","One of the younger monks in the "
               "Eclatish monastery made this fife.");
}
