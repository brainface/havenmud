#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;
#include "../vergoth.h"

static void create() {
  ::create();
  SetValue(0);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_BODY_ARMOUR);
  SetKeyName("rags");
  SetShort("a set of ratty clothes");
  SetAdjectives( ({ "ratty" }) );
  SetId( ({ "clothes", "set", "rags" }) );
  SetLong("These rags are nothing more than old clothes that have been "
	"worn beyond anything recognizable.  They are a pale gray in color "
	"and covered in dirt.");
  SetMaterial( ({ "textile" }) );
  SetWarmth(8);
  SetMass(60);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(500);
  // SetProtection(PIERCE, 2);
  SetMaterial( ({ "textile" }) );
  SetRepairSkills( ([ "textile working" : 1 ]) );
  SetRepairDifficulty(1);
 }
