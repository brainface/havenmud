/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include "../path.h"

inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("old troll");
  SetId( ({"troll"}) );
  SetAdjectives( ({"old","decrepit","grey", "bald"}) );
  SetShort("a decrepit old troll");
  SetLong("Bones show through the loose skin of the old troll.  Even the "
          "color of it's now bald skin has faded to almost grey.");
  
  SetMorality(-100 - random(200));
  SetRace("troll");
  SetClass("rogue");
  SetLevel(30);
  SetGender("male");
  SetAction(15,({
                 "!growl",
                 "!grunt",
                 "!pant",
            }) );
}
