#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;
#include "../vergoth.h"

static void create() {
  ::create();
  SetKeyName("amulet");
  SetVendorType(VT_TREASURE|VT_GEM);
  SetArmourType(A_AMULET);
  SetShort("a silver amulet");
  SetLong("This is an amulet made of %^WHITE%^silver%^RESET%^ with a black "
	"onyx set in the middle.  The %^WHITE%^silver%^RESET%^ is carved "
	"into small ivy vines that wrap around onyx tightly.  The amulet "
	"hangs from a leather rope.");
  SetValue(400);
  SetMass(25);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(500);
  SetId( ({ "amulet" }) );
  SetAdjectives( ({ "silver" }) );
  SetMaterial( ({ "metal" }) );
  SetWarmth(0);
  SetRepairSkills( ([ "metal working" : 15 ]) );
  SetRepairDifficulty(15);
   // SetProtection(SLASH, 2);
  // SetProtection(PIERCE, 2);
  // SetProtection(BLUNT, 2);
  // SetProtection(SHOCK, 3);
  // SetProtection(HEAT, 3);
  // SetProtection(ACID, 3);
  // SetProtection(COLD, 3);
 }
