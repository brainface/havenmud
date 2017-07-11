/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include "../path.h"

inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("filthy troll");
  SetId( ({"troll"}) );
  SetAdjectives( ({"filthy",}) );
  SetShort("a filthy troll");
  SetLong("Mucus and drool hang from the nose and mouth of this filthy "
          "creature.  Short, stiff, black hair grows in tufts all over the "
          "troll's lanky body.");
  
  SetMorality(-100 - random(200));
  SetRace("troll");
  SetClass("rogue");
  SetLevel(30);
  SetGender("male");
  SetAction(15,({
                 "!growl",
                 "!grunt",
                 "The troll scratches one of its clumps of hair.",
            }) );
  SetEncounter(10);
}