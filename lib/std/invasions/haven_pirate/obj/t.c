
/* Queen's tiara
  Ela 4/19/98
  Fixed Amelia@Haven Sept 10, 1998
*/

#include <lib.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <armour_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("tiara");
  SetShort("a jeweled tiara");
  SetId( ({"tiara"}) );
  SetAdjectives( ({"jeweled","magnificent","exquisite"}) );
  SetLong("This magnificent jeweled tiara is exquisite. The gold's luster is "
         "a perfect setting for the true, deep hues of the gems it " 
         "supports.");
  SetMass(20);
  SetValue(500);
    SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_TREASURE|VT_ARMOUR);
  SetArmourType(A_VISOR);
  SetDamagePoints(30);
  SetMaterial( ({ "natural","metal" }) );
  SetRepairDifficulty(19);
  SetRepairSkills( ([
                      "natural working" : 1,
                      "metal working" : 0,
                 ]) );
}
