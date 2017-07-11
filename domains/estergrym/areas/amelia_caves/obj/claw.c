// Amelia@Haven
#include <damage_types.h>
#include <lib.h>
inherit LIB_ITEM;
#include <vendor_types.h>
 
static void create() {
   item::create();
   SetDestroyOnSell(1);
   SetKeyName("claw");
   SetId( ({ "claw", }) );
   SetAdjectives( ({ "rat","small" }) );
   SetShort("a rat claw");
   SetLong("This small claw appears to have come from a rat.  "
           "It might even do a little damage if wielded, for "
           "the claws are very pointy.");
   SetMass(5);
   SetValue(12);
   SetVendorType(VT_TREASURE|VT_WEAPON);
   SetWeaponType("pierce");
   SetDamageType(PIERCE);
   SetMaterial("natural");
   SetClass(5);
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "natural working" : 1,
                       "weapon smithing" : 1,
                  ]) );
   SetProperty("history","A rat in the Grymxoria Caves in the "
               "Estergrym Mountains once owned this claw until "
               "he lost it at his death.");
}
