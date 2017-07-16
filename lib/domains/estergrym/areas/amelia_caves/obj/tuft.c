// Amelia@Haven

#include <lib.h>
#include <damage_types.h>
inherit LIB_ITEM;
#include <vendor_types.h>
 
static void create() {
   SetDestroyOnSell(1);
   item::create();
   SetKeyName("fur");
   SetId( ({ "fur","tuft" }) );
   SetShort("a dry tuft of fur");
   SetAdjectives( ({ "dry","tuft","of","fur" }) );
   SetLong("This dry tuft of fur came from a small mouse.  "
           "It is soft and silky.");
   SetMass(1);
   SetValue(3);
   SetVendorType(VT_FUR);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetDamagePoints(5);
   SetMaterial("natural");
   SetRepairDifficulty(1);
   SetRepairSkills( ([
                       "natural working" : 0,
                  ]) );
   SetProperty("history","The tuft of fur came from a small "
               "mouse that hid in a dry spot of the "
               "caves in the Estergrym Mountains.");
}
