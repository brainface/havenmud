/*  inside of glim guard */

#include <lib.h>
#include "../glim.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("patroller");
  SetShort("a dwarven patroller");
  SetReligion("Kylin", "Kylin");
  SetId( ({ "dwarf", "guard", "glim_wander", "patroller" }) );

  SetAdjectives( ({ "strong", "buff" }) );
  SetRace("dwarf");
  SetClass("fighter");
  SetClass("barbarian");
  SetProperty("glimcitizen", 1);
  SetLevel(20 + random(5));
  SetLong("This is one of the dwarven guards that protects "
    "Glimmerdin and its citizens.  He seems quite contained and stern, "
    "but also very able to do his job."); 
  SetGender("male");
  SetProperty("glimnoleave", 1);
  SetCombatAction(12, ({
      "!shout Arise, comrades! An enemy of the dwarven folk is here! ",
      }) );
  SetMorality(200);
  SetFriends( ({"tembeg", "rancor", "raal", "rallor", 
    "tabitha", "dwarf", "civak", "guard", "patrol", 
    "samik", "gracchus", "eredos", "dorscha", "bralor"}) );
  SetWander(4);
  SetInventory( ([
    G_OBJ + "chainmail" : "wear chainmail",
    G_OBJ + "guard_axe" : "wield axe",
   ]) );
}
