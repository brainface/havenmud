
#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../durgoroth.h"
inherit LIB_SENTIENT;
 
static void create() {
  sentient::create();
  SetKeyName("survivor");
  SetRace("daemon");
  SetClass("fighter");
  SetLevel(180 + random(50));
  SetGender("female");
  SetShort("a weak looking daemon survivor");
  SetId( ({ "daemon","survivor","fighter","durg_wander",
            "durg_combat" }) );
  SetAdjectives( ({ "weak", "daemon" }) );
  SetLong("This daemon is weak and pathetic looking."
          " She is an embarassment to her race. It"
          " is unlikely that she will survive long"
          " in the harsh dog-eat-dog society of"
          " Durgoroth.");
  SetWander(5);
  SetAction(5, ({
    "!emote looks around for useful items.",
    "!emote scurries about looking for a safe place to hide.",
    "!emote cowers at some imperceptible noise.",
    "!emote looks around for possible threats.",
    }) );
  SetCombatAction(50, ({
    "!go west",
    "!go east",
    "!go north",
    "!go south",
    "!go northeast",
    "!go northwest",
    "!go southwest",
    "!go southeast",
    "!scream pathetic",
    }) );
  SetCurrency("crystals", 2000);
  SetReligion("Saahagoth","Saahagoth");
  SetTown("Durgoroth");
  SetMorality(-1000);
  SetInventory( ([
     ]) );
  }
