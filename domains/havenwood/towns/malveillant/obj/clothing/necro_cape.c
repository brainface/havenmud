/*  Portia  10-19-98
   A cape for the necromancer leader.
*/

#include <lib.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("cape");
  SetShort("a black cape");
  SetId( ({"cape"}) );
  SetAdjectives( ({"black"}) );
  SetLong("This black cape is very long and very shiny. It is "
          "also extremely heavy and warm.");
  SetMass(100);
  SetValue(90);
  SetMaterials( ({"textile"}) );
  SetWarmth(30);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(700);
  SetRepairSkills( ([
         "textile working" : 10,
           ]) );
  SetRepairDifficulty(80);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_CLOAK);
  }
