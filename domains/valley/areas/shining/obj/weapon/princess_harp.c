#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("a golden harp");
   SetShort("a small golden harp");
   SetId( ({ "harp", "bard_instrument" }) );
   SetAdjectives( ({ "golden","harp","small" }) );
   SetLong("The small golden harp is rather amazing. Its frame is all "
           "solid gold. The strings are made up of spider silk weaved "
           "multiple times for amazing strength. There are some etchings "
           "carved into the handle. ");
   SetClass(20);
   SetMass(5);
   SetVendorType(VT_INSTRUMENT);
   SetValue(1000);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetDamagePoints(3000);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(100);
   SetRepairSkills( ([
                       "metal working" : 100,
                       "weapon smithing" : 100,
                  ]) );
}


