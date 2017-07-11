#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;
#include "../goblin.h"

static void create() {
  ::create();
  SetKeyName("armour");
  SetArmourType(A_BODY_ARMOUR);
  SetShort("a suit of leather armour");
  SetLong("This is a suit of leather armour.  It is boiled into shape with "
					"wax and has seen lots of use.  It is scarred around the front and "
					"sides.  It is a dark brown in color that is made from having been "
					"exposed to the weather for years.");
  SetValue(75);
  SetMass(250);
  SetArmourClass(ARMOUR_LEATHER);
  SetDamagePoints(750);
  SetId( ({ "armour","armour" }) );
  SetAdjectives( ({ "leather","suit" }) );
  // SetProtection(SLASH, 7);
  // SetProtection(PIERCE, 3);
  // SetProtection(BLUNT, 5);
  // SetProtection(ACID, 1);
  // SetProtection(COLD, 1);
  SetMaterial( ({ "leather" }) );
  SetWarmth(15);
  SetRepairSkills( ([ 
  	"leather working" : 2,
    "armour smithing" :  1,
	]) );
  SetRepairDifficulty(2);
  SetVendorType(VT_ARMOUR);
  SetSize(SIZE_SMALL);
 }
