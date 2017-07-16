///    Created by Severen      ///
///     Late December :)       ///
///      sceptre.c             ///

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "/domains/valley/areas/undead_tower/defs.h"
inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("sceptre");
    SetRepairDifficulty(10);
    SetMaterial( ({ "metal" }) );
    SetRepairSkills( ([
	"metal working" : 1,
	"weapon smithing" : 3,
      ]) );
    SetShort("a gem inlaid sceptre");
    SetAdjectives( ({ "inlaid", "gem" }) );
    SetId( ({ "sceptre" }) );
    SetLong("Gems of many colors are inlaid into this "
      "sceptre. It is about a foot long and its top is a "
      "ball of gems while its bottom comes to a point. It "
      "is made of a gleaming metal.");
    SetClass(10);
    SetDamagePoints(300);
    SetValue(160);
    SetMass(60);
    SetVendorType(VT_WEAPON);
    SetWeaponType("blunt");
    SetDamageType(BLUNT);
}
