/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include "../path.h"

inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("raccoon");
  SetId( ({"raccoon",}) );
  SetAdjectives( ({"large"}) );
  SetShort("a raccoon");
  SetLong("The raccoon is as large as a muezzin.");
  
  SetMorality(0);
  SetRace("rodent");
  SetClass("animal");
  SetLevel(7);
  SetGender("male");
  SetAction(10,({
                 "The raccoon searches for some food.",
            }) );
}
