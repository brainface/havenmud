// Amelia@Haven

#include <lib.h>
inherit LIB_ITEM;
#include <vendor_types.h>

static void create() {
   item::create();
   SetKeyName("leaf");
   SetShort("a gold leaf");
   SetId( ({ "gold leaf","leaf" }) );
   SetAdjectives( ({ "gold" }) );
   SetLong("The leaf gilted in gold twinkles gloomily in the light.");
   SetMass(1);
   SetValue(35);
   SetVendorType(VT_TREASURE);
   SetMaterial( ({ "natural","metal"}) );
   SetRepairSkills( ([ 
                       "natural working" : 1,
                       "metal working" : 1,
                  ]) );
   SetRepairDifficulty(3);
}