#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("jacket");
  SetId( ({"jacket"}) );
  SetAdjectives( ({"padded","brown","green"}) );
  SetShort("a padded jacket");
  SetLong(
     "This padded jacket ties up the front. It seems "
	 "to be made from a heavy cotton. The long green "
	 "sleeves are stitched to the torso of the brown "
	 "jacket.");
  SetMass(20);
  SetValue(50);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  SetDamagePoints(350);
  SetWarmth(15);
  // SetProtection(SLASH, 1);
  // SetProtection(PIERCE, 4);
  // SetProtection(COLD, 4);
  SetArmourType(A_SHIRT);
  SetSize(SIZE_SMALL);
  SetMaterial( ({"textile"}) );
  SetRepairSkills( ([
     "textile working"  : 2,
     ]) );
  SetRepairDifficulty(5);
  }
