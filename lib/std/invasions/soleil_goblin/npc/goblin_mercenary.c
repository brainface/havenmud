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
  SetKeyName("mercenary");
  SetId( ({ "goblin","mercenary" }) );
  SetShort("a goblin mercenary");
  SetAdjectives( ({ "goblin", "cunning", "grim", "tall" }) );
  SetLong(
    "This goblin appears to more cunning than most. He "
    "has a grim look on his face and stands about six "
    "inches taller than a normal goblin. He has a stance "
    "only a skilled fighter would use. His skin is dark "
    "green and scarred."
  );
  SetRace("goblin");
  SetGender("male");
  SetClass("fighter");
  SetLevel(15 + random(5));
  SetAction(6, ({ 
    "!emote looks about intently.",
    "!attack first citizen",
    "!attack first muezzin" }));
  SetCombatAction(30, ({
    "!say be gone or I will slaughter you",
    "!say there are others coming, leave while you can",
    "!emote deftly moves about in an attack pattern",
    "!emote swings his sword in very skilled arcs",
  }) );
  SetInventory( ([
    GIS_OBJ + "chain_armour" : "wear armour",
    GIS_OBJ + "long_sword" : "wield sword",
  ]) );
  SetCurrency("cuicui", 100 + random(200));
  SetWanderSpeed(5);
  SetWanderPath(wanderpathlist);
  SetDie("Mercenary screams in agony!");
}
