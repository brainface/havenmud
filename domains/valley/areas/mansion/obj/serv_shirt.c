/* a servant shirt
   kyla 9-98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../mansion.h"
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("servant shirt");
  SetId( ({"shirt"}) );
  SetAdjectives( ({"white", "servant"}) );
  SetShort("a white shirt");
  SetLong("This shirt could only belong to a servant. Though it is "
          "freshly washed, it is still only the quality of a servant's "
          "wardrobe.");
  SetMass(20);
  SetValue(15);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(50);
  SetArmourType(A_SHIRT);
  SetVendorType(VT_ARMOUR);
  SetMaterials( ({"textile"}) );
  SetWarmth(10);
  SetRepairSkills( ([
           ]) );
  }
