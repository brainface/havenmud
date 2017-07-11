/* Portia  Ruins 10-7-98
  A blouse for a dark elf.
*/

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("blouse");
  SetShort("a high-quality blouse");
  SetId( ({ "blouse" }) );
  SetAdjectives( ({ "high", "quality" }) );
  SetLong("This blouse is very high quality and looks as though "
        "it has been worn quite often. There are stains on the sleeves "
       "that indicate it gets quite a bit of use.");
  SetMass(10);
  SetMaterial( ({"textile"}) );
  SetWarmth(10);
  SetValue(30);
   SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);
  SetDamagePoints(200);
  SetRepairSkills( ([
          "textile working" : 1,
            ]) );
  SetRepairDifficulty(5);
 SetVendorType(VT_CLOTHING);
  SetArmourType(A_SHIRT);
  }
/*   [ Portia approved ] */


/* Approved by Duuktsaryth on Mon Nov 16 23:31:53 1998. */
