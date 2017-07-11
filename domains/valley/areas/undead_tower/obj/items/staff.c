///    Created by Severen   ///
///       Late December     ///
///         staff.c         ///

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "/domains/valley/areas/undead_tower/defs.h"
inherit LIB_ITEM;

static void create() 
{
    item::create();
    SetKeyName("rotten staff");
    SetId( ({ "staff","rotten staff" }) );
    SetShort("a rotten staff");
    SetLong("The wood on this staff is rotted. A curious "
      "purple and green colored mold seems to grow on it. It stands "
      "about 2 feet high and is not very thick.");
    SetMass(100); 
    SetValue(50);
    SetDamagePoints(250);
    SetWeaponType("pole");
    SetDamageType(BLUNT);
    SetClass(10);
    SetVendorType(VT_WEAPON);
    SetMaterial( ({ "wood" }) );
    SetRepairSkills( ([
	"wood working" : 1,
	"weapon smithing" : 1,
      ]) );
    SetRepairDifficulty(5);
}
