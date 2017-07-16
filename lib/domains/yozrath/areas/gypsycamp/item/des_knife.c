#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "gypsycamp.h"

inherit LIB_ITEM;

static void create() {
    item::create();
     SetKeyName("knife");
     SetId( ({"knife"}) );
     SetAdjectives( ({"desert"}) );
     SetShort("a desert knife");
     SetLong("This is a desert knife. It was made by the gypsies "
             "in the Yozrath desert.");
     SetVendorType(VT_WEAPON);
     SetDamagePoints(250);
     SetClass(10);
     SetValue(100);
     SetMass(110);
     SetWeaponType("knife");
     SetDamageType(PIERCE);
     SetMaterial( ({ "metal"}) );
     SetRepairSkills( ([ "metal working" : 3,
       "weapon smithing" : 3,
     ]) );
     SetRepairDifficulty(5);
}
