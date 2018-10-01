//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_NPC;

static void create() {

  ::create();
  SetKeyName("boar");
  SetId( ({ "boar" }) );
  SetAdjectives( ({ "wild" }) );
  SetShort("a wild boar");
  SetLong(
    "The wild boar is a bulky, massively built swine with short and relatively thin legs. "
    "The trunk is short and massive, while the hindquarters are comparatively underdeveloped. "
    "The region behind the shoulder blades rises into a hump, and the neck is short and thick, "
    "to the point of being nearly immobile. "
    "The animal's head is very large, taking up to one third of the body's entire length."
  );
  SetRace("pig");
  SetClass("animal");
  if(random(2)) { 
    SetGender("male");
    } else {
    SetGender("female");
  }
  SetLevel(12 + random(4));
  SetAction(12 + random(4), ({
    "!grunt triumphantly",
    "!emote eats a truffle.",
    "!emote searhes the ground with its snout while grunting.",
  }) );
  SetCorpseItems( ([
    DAL_OBJ "black_truffle" : 2 + random(5),
  DAL_OBJ + "short_tusk" : 2,
  ]) );
  SetFriends( ({
    "boar",
  }) );
  SetLimit(10);
}
