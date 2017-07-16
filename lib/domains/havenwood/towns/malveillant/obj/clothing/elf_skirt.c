/*  Portia  Ruins 10-7-98
  A skirt for a dark elf.
*/

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("skirt");
  SetShort("a long skirt");
  SetId( ({"skirt"}) );
  SetAdjectives( ({"long", "beautiful", "flowing", "soft"}) );
  SetLong("This long, flowing skirt is beautiful and incredibly soft. "
        "It is obviously very high quality.");
  SetMass(20);
  SetMaterial( ({"textile"}) );
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetWarmth(15);
  SetRepairSkills( ([
         "textile working" : 2,
          ]) );
  SetRepairDifficulty(10);
  SetValue(150);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_PANTS);
  SetDamagePoints(300);
  }
/*   [ Portia approved ] */
