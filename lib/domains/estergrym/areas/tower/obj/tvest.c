#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
 
inherit LIB_ARMOUR;
 
static void create() {
   ::create();
   SetKeyName("vest");
   SetId( ({ "vest", }) );
   SetAdjectives( ({ "tattered","leather","brown" }) );
   SetShort("a tattered brown leather vest");
   SetLong("This leather vest has seen better days. The bottom of the vest "
           "has tear marks along the edges which make strings and pieces of "
           "leather hang off it. The leather is in poor condition, some "
           "patches of the brown leather is scuffed exposing the light orange "
           "leather underneath.");
   SetVendorType(VT_ARMOUR);
   SetMass(175);
   SetArmourClass(ARMOUR_LEATHER);
   SetValue(70);
   SetDamagePoints(600);
   SetSize(SIZE_MEDIUM);
   SetArmourType(A_VEST);
   SetMaterial( ({ "leather" }) );
   SetWarmth(10);
   SetRepairDifficulty(13);
}
