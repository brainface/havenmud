#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
 
inherit LIB_ARMOUR;
 
static void create() {
   armour::create();
   SetKeyName("vest");
   SetId( ({ "vest", }) );
   SetAdjectives( ({ "plush", "leather", "brown" }) );
   SetShort("a plush brown leather vest");
   SetLong("This vest has been sewn together with a black stitch "
           "and a very soft brown leather. The craftsmanship of "
           "this vest is very impressive and well done as if "
           "done by a true professional. Although crafted "
           "to great standards it appears to be worn for "
           "comfort more than battle. An embroidered fancy "
           "letter \"L\" has been sewn in the back with red "
           "thread.");
   SetVendorType(VT_ARMOUR);
   SetMass(175);
   SetArmourClass(ARMOUR_LEATHER);
   SetValue(15);
   SetDamagePoints(15);
   SetSize(SIZE_SMALL);
   SetArmourType(A_VEST);
   SetMaterial( ({ "leather" }) );
   SetWarmth(10);
   SetRepairDifficulty(3);
   SetRepairSkills( ([
     "leather working" : 45,
     "armour smithing" : 45,
     ]) );
}
