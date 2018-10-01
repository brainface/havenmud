//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 


#include <lib.h>
#include "../dalnairn.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("turtle");
  SetId( ({"turtle"}) );
  SetAdjectives( ({"green", "slow", "small"}) );
  SetShort("a small green turtle");
  SetLong(
  "This small green turtle has a rough and worn shell. "
  "Its tiny limbs protrude from the shell defensively. "
  );
  SetRace("tortoise");
  SetClass("animal");
  SetLevel(1);
  if(random(2)) { SetGender("male"); 
    } else  {
    SetGender("female"); 
  }
  SetAction(3 + random (4), ({
    "!emote looks around.", 
    "!emote pauses walking. ",
  }) );
  SetCorpseItems( ([
    DAL_OBJ + "turtle_shell" : 1,
  ]) );
  SetProperty("dalnoleave", 1);
  SetWander(10 + random(2) + random(2) + random(2));
  SetLimit(20);
}
