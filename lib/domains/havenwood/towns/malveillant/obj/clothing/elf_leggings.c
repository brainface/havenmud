/*  Portia  Ruins  10-7-98
    Leggings for a dark elf.
*/

#include <size.h>
#include <lib.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <armour_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leggings");
  SetShort("a pair of leggings");
  SetId( ({"leggings"}) );
  SetAdjectives( ({"soft"}) );
  SetLong("These leggings are made of a soft textile, and look as "
        "if they were created for everyday wear. Although they are "
        "quite plain they seem to be very durable.");
  SetMass(20);
  SetValue(20);
   SetArmourClass(ARMOUR_LEATHER);
   SetSize(SIZE_MEDIUM);
  SetDamagePoints(350);
  SetMaterials( ({"textile"}) );
  SetWarmth(15);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_PANTS);
  SetRepairSkills( ([
        "textile working" : 2,
        ]) );
  SetRepairDifficulty(10);
  }
/*   [ Portia approved ] */
