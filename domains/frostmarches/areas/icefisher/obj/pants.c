#include <armour_types.h>
#include <vendor_types.h>
#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include "../ice.h"
inherit LIB_ARMOUR;

  static void create() {
    ::create();
    SetValue(85);
    SetArmourType(A_PANTS);
    SetVendorType(VT_CLOTHING);
    SetKeyName("brown pants");
    SetDamagePoints(350);
    SetRepairSkills( ([
	"leather working" : 1,
  	]) );
    SetRepairDifficulty(2);
    SetShort("a pair of brown pants");
  SetSize(SIZE_MEDIUM);
    SetId( ({ "pants" }) );
    SetAdjectives( ({ "brown", "otterskin", "pair", "pair of", }) );
    SetMaterial( ({ "leather" }) );
    SetLong("These glossy brown pants appear to be made of otterskin. "
  	"Warm and waterproof, they hug the legs like a second skin. "
	"They would keep their wearer dry in the worst of storms, yet "
	"show off a shapely pair of legs to their best advantage."
	);
    SetMass(45);
  SetArmourClass(ARMOUR_CLOTH);
    SetWarmth(20);
}

/** Approved by Laoise at Fri Jul  9 20:22:26 2004. **/
