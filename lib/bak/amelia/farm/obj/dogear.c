#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("dog's ear");
   SetShort("a dog's ear");
   SetId( ({ "dog ear","dog's ear","dog","ear" }) );
   SetAdjectives( ({ "dog's","dog" }) );
   SetLong("This looks to have been chopped off of a dog's head during "
           "the end of a battle.  It might be worth something to someone!");
   SetMass(2);
   SetValue(random(50)+200);
   SetVendorType(VT_TREASURE);
}