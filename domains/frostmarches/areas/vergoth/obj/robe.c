#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;
#include "../vergoth.h"

static void create() {
  ::create();
  SetValue(0);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_BODY_ARMOUR);
  SetKeyName("robe");
  SetShort("a red robe");
  SetAdjectives( ({ "red","long" }) );
  SetId( ({ "robe" }) );
  SetLong("This is a %^RED%^red robe%^RESET%^ that is not very special "
	"looking.  There is a %^WHITE%^silver thread%^RESET%^ along the "
	"trim and a small hood.  It is very long and is in bad condition.  "
	"It has been worn a very long time and has holes in it from being "
	"moth eaten.");
  SetRepairSkills( ([
      "textile working" : 1,
      ]) );
  SetWarmth(15);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
  SetRepairDifficulty(2);
  SetMass(60);
  SetDamagePoints(500);
  // SetProtection(PIERCE, 2);
  SetMaterial( ({ "textile" }) );
  SetRepairSkills( ([ "textile working" : 2 ]) );
  SetRepairDifficulty(2);
 }
