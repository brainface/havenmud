///    Created by Severen   ///
///       Late December     ///
///         knife.c         ///

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "/domains/valley/areas/undead_tower/defs.h"
inherit LIB_ITEM;

static void create() 
{
    item::create();
    SetKeyName("knife");
    SetId(({"knife"}));
    SetAdjectives("small","stone");
    SetShort("a small knife");
    SetLong("This is a small stone knife. The hilt and blade "
      "are made of grey stone. It has no designs except for scratch "
      "marks on its blade due to usage.");
    SetMass(20); 
    SetValue(120);
    SetDamagePoints(650);
    SetWeaponType("knife");
    SetDamageType(PIERCE);
    SetClass(5);
    SetVendorType(VT_WEAPON);
    SetMaterial( ({ "natural" }) );
    SetRepairSkills( ([
	"stone working" : 1,
	"weapon smithing" : 1,
      ]) );
    SetRepairDifficulty(5);
}
