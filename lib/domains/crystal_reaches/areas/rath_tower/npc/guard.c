/*  A standard guard */
#include <lib.h>
#include "../rath.h"
inherit LIB_SENTIENT;
int eventStumble();

static void create() {
  sentient::create();
  SetKeyName("undead guard");
  SetGender("male");
  SetShort("a member of Rath Khan's guard");
  SetRace("elf");
  RemoveLanguage("Eltherian");
  SetLanguage("Archaic", 100, 1);
  SetClass("fighter");
  
  SetLevel(random(15)+10);
  SetMorality(-300);
  SetCurrency("imperials", random(300)+1);
  SetFriends( ({ "guard","rath","elite guard","priest","diplomat" }) );
  SetInventory( ([
      TOWER_O + "/ssword" : "wield shortsword",
      TOWER_O + "/chain" : "wear chainmail",
    ]) );
  SetId( ({ "guard", "member", "skeleton", "tower_guard" }) );
  SetAdjectives( ({ "undead" }) );
  SetUndead(1);
  SetUndeadType("skeleton");
  SetLong("This aged skeleton is a remnant of Rath Khan's guard. "
          "His appearance belies the fact that he has served in the "
          "tower for centuries.");
  SetWanderSpeed(3);
  SetLimit(8);
  SetProperty("rath_guard", 1);
}
