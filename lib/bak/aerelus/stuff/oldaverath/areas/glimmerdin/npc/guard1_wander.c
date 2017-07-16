/*  inside of glim guard */

#include <lib.h>
#include "../glim.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("patroller");
  SetShort("a dwarven patroller");
  SetId( ({ "dwarf", "town_wander", "patroller" }) );
  SetAdjectives( ({ "dwarven" }) );
  SetRace("dwarf");
  SetClass("fighter");
  SetSkill("hack attack", 1, 1);
  SetSkill("hack defense", 1, 1);
  SetLevel(20 + random(5));
  SetLong("This is one of the dwarven guards that protects "
    "Glistendin and its citizens.  He seems quite contained and stern, "
    "but also very able to do his job."); 
  SetGender("male");
  SetCombatAction(12, ({
      "!shout Arise, comrades! An enemy of the dwarven folk is here! ",
      }) );
  SetMorality(200);
  SetWander(4);
  SetInventory( ([
    G_OBJ + "chainmail" : "wear chainmail",
    G_OBJ + "guard_axe" : "wield axe",
   ]) );
}
