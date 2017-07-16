#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("blunt training sword");
   SetShort("a blunt training sword");
   SetId( ({ "sword" }) );
   SetAdjectives( ({ "blunt","training","wooden" }) );
   SetLong("This is a wooden sword, purposefully made blunt to "
           "help people train their slashing skills.  It has the word "
           "'Soleil' written cross one edge.");
   SetMass(55);
   SetValue(10);
   SetVendorType(VT_WEAPON);
   SetWeaponType("slash");
   SetDamageType(BLUNT);
   SetDamagePoints(200);
   SetClass(2);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(1);
   SetRepairSkills( ([
                       "weapon smithing" : 1,
                       "wood working" : 1,
                  ]) );
}
