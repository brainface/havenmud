//Artanis@Haven (July 18, 2004)

#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("dress");
  SetId( ({ "dress" }) );
  SetAdjectives( ({ "old", "faded" }) );
  SetShort("an old faded dress");
  SetLong(
     "This dress looks to have seen some use in it's time. It "
     "looks faded and has worn spots where one would kneel upon it. "
     "There are parts of the dress that still retain it's original bluish "
     "hue, suggesting that at one time this was a quality piece of clothing. "
  );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetMass(50);
  SetValue(25);
  SetDamagePoints(500);
  SetSize(SIZE_MEDIUM);
  SetMaterial("textile");
  SetRepairSkills( ([
     "textile working" : 1,
  ]) );
  SetRepairDifficulty(8);
  SetWarmth(12);
}
