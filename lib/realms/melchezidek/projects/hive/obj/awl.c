#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("awl");
   SetShort("a small awl");
   SetId( ({ "awl" }) );
   SetAdjectives( ({ "small" }) );
   SetLong("This is a small awl with a wooden grip and a metal spike. It is"
           " commonly used to poke holes in various objects, but could be"
           " made into a makeshift stabbing weapon quite easily.");
   SetMass(70);
   SetValue(300);
   SetDamagePoints(300);
   SetVendorType(VT_WEAPON);
   SetWeaponType("pierce");
   SetDamageType(PIERCE);
   SetClass(12);
   SetMaterial( ({ "natural", "metal" }) );
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "weapon smithing" : 4,
                       "natural working" : 4,
                       "metal working"   : 4,
                  ]) );
}
