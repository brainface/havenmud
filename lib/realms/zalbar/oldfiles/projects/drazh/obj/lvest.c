#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
 
inherit LIB_ARMOUR;
 
static void create() {
   armour::create();
   SetKeyName("leather vest");
   SetId( ({ "vest", }) );
   SetAdjectives( ({ "leather","medium sized","medium" }) );
   SetShort("a leather vest");
   SetLong(
     "This medium sized leather vest has been dyed in red coloring. "
     "A black equilateral triangle, consisting of three overlapping "
     "lines, with one of the points facing down is embroided onto "
     "the left breast of the vest. This leather vest seems to offer "
     "some protection for the cold and wounds."
     );
   SetVendorType(VT_ARMOUR);
   SetMass(175);
   SetValue(120);
   SetDamagePoints(600);
   SetArmourClass(ARMOUR_LEATHER);
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