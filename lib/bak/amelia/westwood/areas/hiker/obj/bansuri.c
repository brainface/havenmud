#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("bansuri");
   SetShort("a bamboo bansuri");
   SetId( ({ "bansuri","bard_instrument","flute" }) );
   SetAdjectives( ({ "bamboo" }) );
   SetLong("Made from a single length of bamboo, the bansuri flute has only 6 holes "
	   "along its length.  Bright purple ribbons are tied tightly around the "
	   "bamboo between each of the holes.");
   SetMass(10);
   SetVendorType(VT_INSTRUMENT);
   SetValue(200);
   SetDamagePoints(75);
   SetMaterial( ({ "wood" }) );
   SetRepairSkills( ([
                       "wood working" : 1,
                       "instrumental music" : 1,
                  ]) );
   SetClass(3);
   SetHands(2);
}
