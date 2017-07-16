
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../camp.h"
inherit LIB_ITEM;


static void create() {
        item::create();
        SetShort("an ornate knife");
        SetLong("This weapon has a beautifully carved  "
                "wood handle.  The blade is finely made with "
                "swirling lines engraved into it.");
        SetId( ({"knife"}) );
        SetAdjectives( ({"ornate"}) );
        SetMaterial( ({ "metal", "wood" }) );
        SetRepairSkills( ([
           "metal working" : 1,
           "wood working" : 1,
           "weapon smithing" : 1,
              ]) );
        SetClass(9);
        SetDamagePoints(600);
        SetValue(150);
        SetWeaponType("knife");
        SetDamageType(PIERCE);
        SetKeyName("knife");
        SetMass(30);
        SetVendorType(VT_WEAPON);
        SetProperty("history", "This knife has "
           "been handed down through five "
           "generations of gypsy leaders.");
}
