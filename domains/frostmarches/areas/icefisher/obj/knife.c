#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../ice.h"
inherit LIB_ITEM;


static void create() {
        item::create();
        SetKeyName("cat claw");
        SetShort("a slender, hooked double blade");
        SetLong(
		"This expertly-forged double knife straps to "
                "the back of the hand, making it an excellent "
		"weapon for a lightning-quick, vicious "
		"attack. The twin blades are slightly curved "
		"along their length, and sharpened to an "
		"almost invisible edge. ");
        SetId( ({ "blade","claw","knife", }) );
        SetAdjectives( 
		({ "slender", "hooked", "double", "curved",}) );
        SetClass(14);
        SetDamagePoints(850);
        SetValue(200);
        SetWeaponType("knife");
        SetDamageType(PIERCE);
	SetMass(250);
	SetVendorType(VT_WEAPON);
        SetMaterial( ({ "metal" }) );
  	SetRepairSkills( ([
      		"metal working" : 0,
      		"weapon smithing" : 1,
    		]) );
	SetRepairDifficulty(12);

  }

/** Approved by Laoise at Fri Jul  9 20:22:22 2004. **/