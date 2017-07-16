/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include "../path.h"

inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("hunting dog");
  SetId( ({"dog",}) );
  SetAdjectives( ({"hunting","dwarven",}) );
  SetShort("a hunting dog");
  SetLong("Eager, but well trained, the muscular dog sits awaiting his "
          "master's command.");
  
  SetMorality(0);
  SetRace("dog");
  SetClass("animal");
  SetLevel(10);
  
  SetGender("male");
  SetInventory(  ([
		VALLEY_OBJ + "/dog_harness" : "wear dog harness",
		])  );
  SetFriends( ({"dwarven leader",}) );
  SetAction(10,({
                 "The dog idly scratches at a flea.",
                 "The dog's ears perk up.",
                 "!growl",
                 "The dog sniffs the air around him.",
            }) );
}
