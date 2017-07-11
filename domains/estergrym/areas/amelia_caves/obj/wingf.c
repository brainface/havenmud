// Amelia@Haven

#include <lib.h>
#include <damage_types.h>
inherit LIB_ITEM;
#include <vendor_types.h>
 
static void create() {
   item::create();
   SetKeyName("wing");
   SetId( ({ "wing" }) );
   SetAdjectives( ({ "fly","small" }) );
   SetShort("a fly wing");
   SetLong("This small wing of a large fruit fly, which seems rather "
           "useless on the whole, might interest someone.");
   SetMass(5);
   SetValue(1);
   SetVendorType(VT_TREASURE);
   SetMaterial("natural");
   SetDamageType(BLUNT);
   SetWeaponType("blunt");
   SetDamagePoints(5);
   SetDestroyOnSell(1);
   SetRepairDifficulty(2);
   SetRepairSkills( ([
                       "natural working" : 0,
                  ]) );
   SetProperty("history","This fly wing came from a fruit "
               "fly in the caves in the Estergrym Mountains.  "
               "The flies there grew abnormally large after "
               "feeding on a strange fungus in the area.");
}
