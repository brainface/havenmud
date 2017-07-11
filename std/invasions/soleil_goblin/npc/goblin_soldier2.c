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
                          ({ "go up" })
                       })[random(15)];

static void create() {
  invader::create();
  SetKeyName("soldier");
  SetId( ({ "goblin", "soldier", "goblin_inv" }) );
  SetAdjectives( ({ "goblin", "small", "green", "busy" }) );
  SetShort("a goblin soldier");
  SetLong(
    "This is a small goblin soldier. He is light green "
    "in color and is a dog-faced thing. He appears to be very "
    "busy as he runs about trying to prepare for something."
    );
  SetRace("goblin");
  SetGender("male");
  SetClass("fighter");
  SetLevel(10 + random(10));
  SetInventory( ([
    GIS_OBJ + "leather_armour" : "wear armour",
    GIS_OBJ + "short_sword" : "wield sword",
  ]) );
  SetCurrency("cuicui", 100 + random(200));
  SetAction(6, ({ 
    "!say Me kill!",
    "!attack first citizen",
    "!attack first muezzin" 
  }) );
  SetCombatAction(30, ({
    "!emote stumbles about in his attack.",
    "!emote swings his sword wildly about in an attack.",
  }) );
  SetFriends( ({ "goblin_inv" }) );
  SetWanderSpeed(5);
  SetWanderPath(wanderpathlist);
  SetDie("Soldier drops to the ground and bleeds over the grass.");
}