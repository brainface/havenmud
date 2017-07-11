// Goblin invasion of Soleil
// Original coder: Unknown
// Edited: Laoise, 2005

#include <lib.h>
#include "../gis.h"

inherit LIB_INVADER;

   string array wanderpathlist = ({
                          ({ "attack first guard" }),
                          ({ "attack second guard" }),
                          ({ "go up","enter townhall",
                             "attack fossis" }),
                          ({ "go up","enter townhall",
                             "attack aegri" }),
                          ({ "go up","enter townhall",
                             "attack miserum" }),
                          ({ "go up","go south","go down",
                             "attack foret" }),
                          ({ "go up","go south","go down",
                             "attack nascima" }),
                          ({ "go up","go south","go down",
                             "go southwest","attack oppugno" }),
                          ({ "go up","go south","go down",
                             "enter inn","attack barkeep" }),
                          ({ "go up","go south","go southeast"
                             "attack acclima" }),
                          ({ "go up","go south","go southeast"
                             "go up","attack sorgan" }),
                          ({ "go up","go south","go southeast"
                             "go up","attack dulcae" }),
                          ({ "go up","go south","attack tia" }),
                          ({ "go up","go south","go southeast",
                             "go east","attack kiee" }),
                          ({ "go up" }),
                       })[random(15)];

static void create() {
  invader::create();
  SetKeyName("soldier");
  SetId( ({ "goblin", "soldier" }) );
  SetAdjectives("goblin");
  SetShort("a goblin soldier");
  SetLong(
    "This is a small goblin soldier. He is light green "
    "in color and is a dog-faced thing. He stands here "
    "on guard for anything that would seek to pass by "
    "him. There is a determined look on his face.");
  SetRace("goblin");
  SetGender("male");
  SetClass("fighter");
  SetLevel(15 + random(5));
  SetMorality(-20);
  SetInventory( ([
    GIS_OBJ + "leather_armour" : "wear armour",
    GIS_OBJ + "short_sword" : "wield sword",
  ]) );
  SetCurrency("cuicui", 200 + random(100));
  SetAction(6, ({ 
    "!attack first citizen",
    "!attack first muezzin",
  }) );
  SetCombatAction(30, ({
    "!say be gone or me smash you.",
    "!say me call boss if you not go.",
    "!emote stumbles about in his attack.",
    "!emote swings his sword wildly about in an attack.",
  }) );
  SetWanderSpeed(5);
  SetWanderPath(wanderpathlist);
  SetDie("Soldier falls down in a melodramatic manner.");
}
