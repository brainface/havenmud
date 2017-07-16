/*  inside of glim guard */

#include <lib.h>
#include "../glim.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("guard");
  SetShort("a dwarven guard");
  SetReligion("Kylin", "Kylin");
  SetId( ({ "dwarf", "guard", "town guard" }) );
  SetAdjectives( ({ "strong", "buff" }) );
  SetRace("dwarf");
  SetClass("fighter");
  SetClass("fighter");
  SetLevel(20 + random(5));
  SetLong("This is one of the dwarven guards that protects "
    "Glimmerdin and its citizens.  He seems quite contained and stern, "
    "but also very able to do his job."); 
  SetGender("male");
  SetCombatAction(10, ({
      "!shout Arise, comrades! An enemy of the dwarven folk is here! ",
      }) );
  SetMorality(200);
  SetInventory( ([
    G_OBJ + "chainmail" : "wear chainmail",
    G_OBJ + "guard_axe" : "wield axe",
   ]) );
  SetFriends( ({"tembeg", "rancor", "raal", "rallor", 
    "tabitha", "dwarf", "civak", "guard", "patrol", 
    "samik", "gracchus", "eredos", "dorscha", "bralor"}) );
}
