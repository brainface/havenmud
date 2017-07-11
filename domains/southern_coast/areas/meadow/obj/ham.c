// A fresh pice of ham for fishing
// For Platypus Bay
// Urien@Haven 06JUL08

#include <lib.h>
#include <vendor_types.h>
inherit LIB_BAIT_WITH;
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("ham");
   SetShort("a piece of ham");
   SetId( ({ "ham" }) );
   SetAdjectives( ({ "piece" }) );
   SetLong(
           "This piece of ham is square in size and it still contains "
           "its natural juices."
           );
   SetMass(1);
   SetValue(4);
   SetVendorType(VT_FISHING);
   SetBaitStrength(2);
   SetMaterial( ({ "natural" }) );
   SetDamagePoints(1);
}

static mixed AddSave(mixed *vars) {
   return item::AddSave(vars);
}

