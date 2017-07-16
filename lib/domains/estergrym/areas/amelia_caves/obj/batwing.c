// Amelia@Haven
#include <lib.h>
#include <damage_types.h>
inherit LIB_ITEM;
#include <vendor_types.h>
 
static void create() {
   item::create();
   SetKeyName("wing");
   SetDestroyOnSell(1);
   SetId( ({ "wing" }) );
   SetAdjectives( ({ "bat" }) );
   SetShort("a bat wing");
   SetLong("The dark colored, soft bat wing is limb and plain.");
   SetMass(15);
   SetValue(6);
   SetClass(2);
   SetVendorType(VT_TREASURE);
   SetMaterial("leather");
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "leather working" : 0,
                  ]) );
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetProperty("history","A bat in the Grymxoria Caves in the "
               "Estergrym Mountains lost this wing when he "
               "died.");
}
