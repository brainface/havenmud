/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include "../path.h"

inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("fat troll");
  SetId( ({"troll"}) );
  SetAdjectives( ({"fat",}) );
  SetShort("a fat troll");
  SetLong("Unlike other trolls, some defect has rendered this troll quite "
          "obese.");
  
  SetMorality(-100 - random(200));
  SetRace("troll");
  SetClass("rogue");
  SetLevel(32);
  SetGender("male");
  SetAction(15,({
                 "!scratch",
                 "!pant",
                 "The troll idly digs in a crevis between rolls of fat, "
                   "looking for something to eat.",
            }) );
}