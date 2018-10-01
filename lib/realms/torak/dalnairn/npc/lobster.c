//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_NPC;

static void create() {

  ::create();
  SetKeyName("lobster");
  SetId( ({ "lobster" }) );
  SetAdjectives( ({ "bay" }) );
  SetShort("a bay lobster");
  SetLong(
    "This shelled crustacean has a long body and muscular tail. Two large claws "
    "emerge from its abdomen before two rows of legs. Sets of antennae and eyestalks "
    "protrude from its head. Its exoskeleton is a deep blue with coalescing spots "
    "and a yellow underbelly."
  );
  SetRace("lobster");
  SetSkill("swimming", 1, 1);
  SetClass("animal");
  if(random(2)) { 
    SetGender("male");
    } else {
    SetGender("female");
  }
  SetLevel(5 + random(7));
  SetAction(12 + random(4), ({
    "!emote snaps its claws open and shut in a threatening stance.",
    "!emote scuttles about in the sand.",
  }) );
  SetCorpseItems( ([
    DAL_OBJ + "lobster_tail" : 1,
  ]) );
}
