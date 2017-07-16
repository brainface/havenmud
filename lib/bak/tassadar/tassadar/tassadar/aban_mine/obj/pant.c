/* pant.c for Abandoned Mine
   Tassadar@Haven
   11SEP04
*/

#include <armour_types.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>
#include <lib.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetId( ({ "pants" }) );
  SetAdjectives( ({ "dirty", "cloth" }) );
  SetWarmth(15);
  SetShort("a dirty pair of pants");
  SetLong(
     "These cloth pants appear to be dark blue in color, though it is "
     "nearly impossible to tell. Rock dust covers the pants "
     "almost completely. There is a hole in the left knee where "
     "it has been worn through from years of kneeling."
     );
  SetValue(20);
  SetArmourType(A_PANTS);
  SetVendorType(VT_CLOTHING);
  SetKeyName("dirty pants");
  SetDamagePoints(250);
  SetSize(SIZE_SMALL);
  SetMass(40);
  SetMaterial( ({ "textile" }) );
  SetRepairSkills( ([
    "textile working" : 1,
    ]) );
  SetRepairDifficulty(2);
  SetProtection(SLASH, 1);  
  SetProtection(COLD, 1);
}
