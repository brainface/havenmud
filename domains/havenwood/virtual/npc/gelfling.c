#include <lib.h>
inherit LIB_SENTIENT;
#define NPCS "/domains/havenwood/virtual/npcs"

static void create() {
   sentient::create();
   SetKeyName("gelfling");
   SetShort("a mournful gelfling");
   SetId( ({ "gelfling" }) );
   SetAdjectives( ({ "mournful" }) );
   SetWander(19);
   SetLong("This gelfling seems to be melancholy, "
           "missing his family and friends that "
           "died during the second GodsWar.  "
           "He now wanders his homelands, "
           "instead of staying in his new town "
           "of Soleil.  He looks tired and "
           "out of shape.");
   SetGender("male");
   SetRace("gelfling");
  SetClass("ranger");
  SetTown("Soleil");
   SetLevel(5+random(5));
   SetInventory( ([
                    NPCS + "/crossbow" : "wield crossbow in left hand",
                    NPCS + "/sword" : "wield sword in right hand",
                    NPCS + "/pants" : "wear pants",
                    NPCS + "/cloak" : "wear cloak",
               ]) );
   SetAction(10, ({ "!speak I miss my old town.",
                    "!speak When the Gods go to "
                    "war, be careful!  It gets "
                    "dangerous and so many of my "
                    "friends and family died.",
                    "!sigh","!sniffle","!say "
                    "I live in Soleil now.  It's "
                    "a great town, but there is "
                    "something to be said for "
                    "growing old in the town you "
                    "were born in." }) );
   SetCombatAction(30, ({ "!slash","!slash",
                          "!say Haven't I lost "
                          "enough already?",
                          "!shout Help!  I'm "
                          "being attacked!","!trip",
                          "!disarm" }) );
}
