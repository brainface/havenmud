// Amelia@Haven

#include <lib.h>
inherit LIB_ITEM;
#include <vendor_types.h>

static void create() {
   item::create();
   SetKeyName("leaf");
   SetShort("a silver leaf");
   SetId( ({ "silver leaf","leaf" }) );
   SetAdjectives( ({ "silver" }) );
   SetLong("The leaf gilted in silver twinkles gloomily in the light.");
   SetMass(5);
   SetValue(25);
   SetVendorType(VT_TREASURE);
   SetMaterial( ({ "natural","metal"}) );
   SetRepairSkills( ([ 
                       "natural working" : 1,
                       "metal working" : 1,
                  ]) );
   SetRepairDifficulty(3);
}