#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include "../ice.h"
inherit LIB_ARMOUR;
static void create() {
  armour::create();
  SetKeyName("vest");
  SetId( ({"vest"}) );
  SetShort("a warm bearskin vest");
  SetLong("This warm vest is made of the hide of a black bear. The fur is "
	"glossy and well-cared-for. It is double-layered and warm, and will keep "
	"the chest snug and toasty.");
  SetAdjectives( ({"warm,", "bearskin", "fur",
	}) );
  SetMass(95);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_LEATHER);
  SetValue(200);
  SetMaterial( ({"natural"}) );
  SetWarmth(20);
  SetRepairSkills( ([
	"armour smithing" : 4,
	]) );
  SetRepairDifficulty(5);
  SetDamagePoints(410);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_VEST);
  // SetProtection(SLASH,10);
  // SetProtection(PIERCE,10);
}



/** Approved by Laoise at Fri Jul  9 20:22:36 2004. **/
