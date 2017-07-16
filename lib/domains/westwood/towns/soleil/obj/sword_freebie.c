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
           "help people train their slashing skills.  It is a little "
           "more solid than most, however, and could probably do "
           "some amount of damage, if one tried.  It has the word "
           "'Soleil' written cross one edge.");
   SetMass(55);
   SetVendorType(VT_WEAPON);
   SetWeaponType("slash");
   SetDamageType(BLUNT);
   SetDamagePoints(200);
   SetClass(10);
   SetMaterial( ({ "wood" }) );
   SetRepairDifficulty(15);
}
