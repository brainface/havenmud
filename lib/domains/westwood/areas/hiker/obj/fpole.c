#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_POLE;

static void create() {
   pole::create();
   SetKeyName("strong fishing pole");
   SetShort("a strong fishing pole");
   SetId( ({ "pole" }) );
   SetAdjectives( ({ "strong","fishing","wooden","tough" }) );
   SetLong("The fishing pole is made from some type of tough wood, and "
           "and the string on it is also quite strong, but thin and "
           "hard to see, hiding it from fish.  A hook hangs at the "
           "end of the string, and some little bobby spheres are "
           "on the string farther up.");
   SetMass(50);
   SetValue(530);
   SetVendorType(VT_FISHING);
   SetWeaponType("pole");
   SetDamageType(BLUNT);
   SetClass(10);
   SetDamagePoints(550);
   SetMaterial( ({ "wood","metal"}) );
   SetRepairDifficulty(30);
   SetRepairSkills( ([
                       "wood working"    : 2,
                       "metal working"   : 1,
                  ]) );
  SetStrength(500);
  SetChance(60);
}
