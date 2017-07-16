#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_STORAGE;

static void create() {
  ::create();
   SetKeyName("hiker backpack");
   SetShort("a hiker backpack");
   SetId( ({ "pack","backpack" }) );
   SetAdjectives( ({ "back","hiker","large" }) );
   SetLong("The backpack is made of a tough material, and is fairly "
           "large.  It looks like a lot of stuff could fit inside.");
   SetMass(40);
   SetValue(225);
   SetVendorType(VT_CLOTHING);
   // SetProtection(BLUNT,7);
   // SetProtection(SLASH,7);
   // SetProtection(PIERCE,7);
   SetDamagePoints(700);
   SetMaterial( ({ "textile" }) );
   SetWarmth(10);
   SetRepairDifficulty(20);
   SetRepairSkills( ([
      "textile working" : 2,
      ]) );
   SetCanClose(1);
   SetClosed(0);
   SetMaxCarry(700);
}
