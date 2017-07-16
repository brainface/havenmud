#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
 
inherit LIB_ARMOUR;
 
static void create() {
   armour::create();
   SetKeyName("leather vest");
   SetId( ({ "vest", }) );
   SetAdjectives( ({ "leather","medium sized","medium" }) );
   SetShort("a leather vest");
   SetLong("This is a medium sized leather vest.");
   SetVendorType(VT_ARMOUR);
   SetMass(175);
    SetArmourClass(ARMOUR_LEATHER);
   SetValue(120);
   SetDamagePoints(600);
   SetSize(SIZE_MEDIUM);
   SetArmourType(A_VEST);
   SetMaterial( ({ "leather" }) );
   SetWarmth(13);
   SetRepairDifficulty(3);
   SetRepairSkills( ([
                       "leather working" : 1,
                       "armour smithing" : 1,
                  ]) );
}
