#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;
#include "../vergoth.h"

static void create() {
  ::create();
  SetValue(0);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_BODY_ARMOUR);
  SetKeyName("dress");
  SetShort("a green dress");
  SetAdjectives( ({ "green" }) );
  SetId( ({ "dress" }) );
  SetLong("The dress is a forest green in color and is made for a very "
	"small woman.  It has a golden fringe hanging down at the bottom "
	"and a blue lace along the collar.  It appears to be a very expensive "
	"dress.");
  SetMaterial( ({ "textile" }) );
  SetWarmth(15);
  SetRepairSkills( ([ "textile working" : 1 ]) );
  SetRepairDifficulty(1);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetMass(60);
  SetDamagePoints(500);
  // SetProtection(PIERCE, 2);
 }
