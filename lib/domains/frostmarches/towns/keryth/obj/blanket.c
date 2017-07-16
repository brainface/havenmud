#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;


static void create() {
  armour::create();
  SetId( ({"blanket"}) );
  SetKeyName("warm blanket");
  SetAdjectives( ({"warm"}) );
  SetShort("a warm blanket");
  SetLong("It is a gray wool blanket to protect "
          "its wearer against the arctic cold.");
  SetMass(75);
  SetValue(0);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_CLOAK);
  SetDamagePoints(200);
  // SetProtection(COLD,5);
  SetMaterial( ({ "textile" }) );
  SetWarmth(30);
  SetRepairDifficulty(1);
  SetRepairSkills( ([ "armor smithing": 1,
                      "textile working" : 1, 
  ]) );

  SetWarmth(20);
}
