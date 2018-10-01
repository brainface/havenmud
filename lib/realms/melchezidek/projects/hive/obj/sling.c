#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("sling");
   SetShort("a durable sling");
   SetId( ({ "sling" }) );
   SetAdjectives( ({ "durable" }) );
   SetLong("Little more than a leather rope, this sling has been cured and treated"
           " to endure the hostile environment of the desert. Outstretched it is"
           " about 6 feet long and has a small flat center for placing projectiles.");
   SetMass(70);
   SetValue(800);
   SetDamagePoints(1500);
   SetVendorType(VT_WEAPON);
   SetWeaponType("projectile");
   SetDamageType(BLUNT);
   SetClass(25);
   SetMaterial( ({ "leather" }) );
   SetRepairDifficulty(30);
   SetRepairSkills( ([
                       "weapon smithing" : 8,
                       "leather working" : 8,
                  ]) );
}
