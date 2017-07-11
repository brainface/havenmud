// Amelia@Haven

#include <lib.h>
#include <damage_types.h>
inherit LIB_ITEM;
#include <vendor_types.h>
 
static void create() {
   item::create();
   SetDestroyOnSell(1);
   SetKeyName("wing");
   SetId( ({ "wing" }) );
   SetAdjectives( ({ "bat","small" }) );
   SetShort("a small bat wing");
   SetLong("This small bat wing came from a little bat who "
           "was slightly dark and furry.");
   SetMass(5);
   SetValue(3);
   SetVendorType(VT_TREASURE);
   SetMaterial("leather");
   SetClass(2);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetRepairDifficulty(2);
   SetRepairSkills( ([
                       "leather working" : 0,
                  ]) );
   SetProperty("history","The bat wing came from one of the "
               "younger bats in some caves in the Estergrym "
               "Mountains.");
}
