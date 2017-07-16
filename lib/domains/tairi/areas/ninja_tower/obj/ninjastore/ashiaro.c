/* changed 10/30/07 Zalbar
		cloth armour to natural(wooden) armour
		added natural working
 */


#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("ashiaro");
  SetShort("a black ashiaro");
  SetId( ({ "ashiaro", "boot" }) );
  SetAdjectives( ({ "black" }) );
  SetLong("This ashiaro is a wooden pad that is"
          " to be worn over a tabi. The ashiaro"
          " has been carved in such a way that"
          " the print left by the wearer will"
          " resemble that of a small child, and"
          " as such, be less likely to raise"
          " suspicion. There is a durable cloth"
          " thong for attaching it to a tabi.");
  SetValue(250);
  SetMass(20);
  SetSize(SIZE_MEDIUM);
  SetWarmth(0);
  SetArmourType(A_BOOT);
  SetMaterial( ({ "natural" }) );
  SetArmourClass(ARMOUR_NATURAL);
  SetDamagePoints(450);
  SetVendorType(VT_ARMOUR);
  SetRepairSkills( ([
          "armour smithing" : 10,
          "textile working" : 10,
          "natural working" : 10,
         ]) );   
  SetRepairDifficulty(15);
}
