#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("a sparkling oak scepter");
   SetShort("a sparkling oak scepter");
   SetId( ({ "scepter" }) );
   SetAdjectives( ({ "sparkling","oak" }) );
   SetLong("The scepter is made of solid oak and set with several gleaming "
           "gems. There are many designs spiraling down the handle. At the "
           "base of the scepter there is a rather large diamond that has a "
           "liquid flowing inside of it. ");
   SetClass(20);
   SetMass(100);
   SetVendorType(VT_WEAPON);
   SetValue(1000);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetDamagePoints(1000);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(60);
   SetRepairSkills( ([
                       "wood working" : 100,
                       "weapon smithing" : 100,
                  ]) );
}
