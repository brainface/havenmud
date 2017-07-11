#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
#include "../camp.h"
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shirt");
  SetShort("a bright yellow shirt");
  SetId( ({"shirt"}) );
  SetAdjectives( ({"silk","yellow","bright"}) );
  SetLong("The bright yellow shirt is made of the "
          "finest silk.  It is loose and open to mid-chest."
          "  The cuffs are fitted and edged in red satin.");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_SHIRT);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(30);
  SetValue(55);
  SetDamagePoints(30);
  SetSize(SIZE_MEDIUM);
  SetMaterial("textile");
  SetWarmth(15);
  SetRepairDifficulty(5);  
  SetRepairSkills( ([
       "textile working" : 1,
  ]) );
}
