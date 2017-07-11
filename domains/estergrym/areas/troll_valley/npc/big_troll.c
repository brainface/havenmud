/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include "../path.h"

inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("big troll");
  SetId( ({"troll"}) );
  SetAdjectives( ({"big","large",}) );
  SetShort("a large troll");
  SetLong("One of the large creature's canines has broken off, leaving a "
          "jagged stump of a tooth in his muzzle-like face.");
  
  SetMorality(-100 - random(200));
  SetRace("troll");
  SetClass("rogue");
  SetLevel(35);
  SetGender("male");
  SetAction(15,({
                 "!growl",
                 "!grunt",
                 "An almost black tongue snakes out of the trolls mouth, to "
                   "play with it's broken tooth.",
            }) );
  SetEncounter(10);
}
