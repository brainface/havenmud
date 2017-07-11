#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("decorated mandolin");
   SetShort("a decorated mandolin");
   SetId( ({ "mandolin","bard_instrument" }) );
   SetAdjectives( ({ "decorated" }) );
   SetLong("The mandolin has some decorative lines around the strings "
           "to make it more beautiful.");
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
               "younger monks in the Eclatish monastery.");
}
