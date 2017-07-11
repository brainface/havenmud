#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("staff");
   SetShort("a light wood staff");
   SetId( ({ "staff" }) );
   SetAdjectives( ({ "light","wood" }) );
   SetLong("Delicate designs are carved into this staff made from "
           "a light colored wood.  The staff is a nice length for "
           "a human to use as a walking staff.");
   SetMass(100);
   SetClass(9);
   SetValue(350);
   SetVendorType(VT_WEAPON);
   SetWeaponType("pole");
   SetDamageType(BLUNT);
   SetDamagePoints(150);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "weapon smithing" : 0,
                       "wood working" : 1,
                  ]) );
   SetProperty("history","This staff used to be the property of "
               "Magnum, the Banker of Parva.");
    SetHands(2);
}
