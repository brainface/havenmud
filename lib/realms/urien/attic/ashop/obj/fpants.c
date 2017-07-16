#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create(); 
   SetArmourClass(ARMOUR_CLOTH); 
   SetKeyName("pants");
   SetShort("a pair of light brown pants");
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "pair of","light","brown" }) );
   SetLong("These pants have been made of a thick "
           "light brown fabric. It has been made rather "
           "simply with two seams that run down the "
           "outside of the legs.");
   SetMass(10);
   SetValue(60);
   SetSize(SIZE_MEDIUM);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_PANTS);
   SetDamagePoints(130);
   SetWear("The pants fit easily.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(10);
   SetRepairDifficulty(4);
   SetRepairSkills( ([
                       "textile working" : 6,
                  ]) );
}
