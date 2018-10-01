/*  Portia  10-14-98
   A shirt.
*/
#include <lib.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <armour_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shirt");
  SetShort("a shirt");
  SetId( ({"shirt"}) );
  SetAdjectives( ({}) );
  SetLong("This cotton shirt is very well made and looks like it would last quite a "
                   "while.");
  SetMaterials( ({"textile"}) );
  SetWarmth(15);
  SetRepairSkills( ([
          "textile working" : 3,
                 ]) );
  SetRepairDifficulty(10);
  SetVendorType(VT_CLOTHING);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_SHIRT);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(30);
  SetValue(40);
  SetDamagePoints(400);
  }
