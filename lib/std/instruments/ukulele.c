#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("ukulele");
   SetShort("a brightly painted ukulele");
   SetId( ({ "ukulele", "bard_instrument" }) );
   SetAdjectives( ({ "brightly", "painted" }) );
   SetLong(
    "This small guitar-like instrument has four gut strings "
    "and a bright pink coat of paint over the thin rosewood "
    "that comprises the body.");
   SetMass(100);
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
}
