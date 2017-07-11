/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>

inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("brown snake");
  SetId( ({"snake",}) );
  SetAdjectives( ({"small","brown",}) );
  SetShort("a small brown snake");
  SetLong("Slight variances in the shade of brown are the only visible "
          "markings on the little snake.");
  
  SetMorality(0);
  SetRace("snake");
  SetClass("animal");
  SetLevel(3);
  SetGender("male");
  SetAction(10,({
                 "The snake attempts to hide under a rock.",
                 "The snake slowly coils itself, preparing its defense.",
            }) );
}
