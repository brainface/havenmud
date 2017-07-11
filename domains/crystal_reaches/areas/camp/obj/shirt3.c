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
  SetShort("a bright silk shirt");
  SetId( ({"shirt"}) );
  SetAdjectives( ({"silk","bright"}) );
  SetLong("The bright silk shirt resembles a flame.  "
          "The shirt is red at the bottom and brightens to "
          "yellow at the top.  It is fitted yet comfortable "
          "allowing for movement without encumbering "
          "the wearer.");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_SHIRT);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(30);
  SetValue(60);
  SetDamagePoints(30);
  SetSize(SIZE_MEDIUM);
  SetMaterial("textile");
  SetWarmth(15);
  SetRepairDifficulty(5);   
  SetRepairSkills( ([
       "textile working" : 1,
  ]) );
}
