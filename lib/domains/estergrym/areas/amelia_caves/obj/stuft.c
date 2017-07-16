// Amelia@Haven

#include <lib.h>
#include <damage_types.h>
inherit LIB_ITEM;
#include <vendor_types.h>
 
static void create() {
   item::create();
   SetDestroyOnSell(1);
   SetKeyName("fur");
   SetId( ({ "fur","tuft" }) );
   SetShort("a tuft of wet fur");
   SetLong("This tuft of wet fur came from a small mouse.  "
           "It is very wet.");
   SetMass(5);
   SetValue(1);
   SetClass(1);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetVendorType(VT_FUR);
   SetMaterial("textile");
   SetRepairDifficulty(4);
   SetRepairSkills( ([
                       "natural working" : 0,
                  ]) );
}
