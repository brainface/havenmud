// Proximo@Via Imperialis
// 06/01/2003

#include <lib.h>
#include <std.h>
#include "../sulumus.h"

inherit LIB_SENTIENT;

#include "../wanted.h"
int CheckWanted();

static void create() {
  ::create();
  SetKeyName("brodi");
  SetId( ({ "brodi", "warlord", "we_wander" }) );
  SetAdjectives( ({ "the", "sulumus" }) );
  SetShort("Brodi the self-proclaimed Sulumus Warlord");
  SetLong(
     "This tough, stern man is the local warlord operating out of this trading "
     "post. He has claimed his area in his name, willing to defend it to the "
     "death. Although his physical appearance does not make him stand out of a "
     "crowd, his ego sure does. "
  );
  SetRace("human"); SetBaseLanguage("Imperial");
  SetGender("human");
  SetStat("durability", 1, 2);
  SetStat("strength", 1, 2);
  SetClass("fighter");
  SetSkill("faith",1,2);
  SetSkill("healing",1,2);
  
  SetLevel(28);
  SetSpellBook( ([
     "mend" : 100,
  ]) );
  RemoveLanguage("Human");
  SetLanguage("Imperial", 100, 1);
  SetInventory( ([
     S_OBJ + "jsword" : "wield sword",
     S_OBJ + "e_cloak" : "wear cloak",
     S_OBJ + "leather_boots" : "wear boots",
     S_OBJ + "leather_vest" : "wear vest",
     S_OBJ + "leather_helmet" : "wear helmet",
     S_OBJ + "leather_pants" : "wear pants",
  ]) );
  SetFriends( ({
     "we_wander",
  }) );
  SetLimit(1);
  SetCurrency("imperials", random(125)+25);
  SetMorality(-77);
  SetEncounter( (: CheckWanted :) );
  SetAction(1, ({
     "!say I suggest you leave at once. ",
     "!yawn",
     "!say Hmm? Why are you here?",
     "!say I'm in charge around here. If you have a problem with the way things "
     "are done, well tough luck!",
  }) );
  SetCombatAction(5, ({
     "!cast mend",
     "!cast mend",
     "!cast mend",
     "!cast mend",
     "!cast mend",
     "!say Time to give you another hole to breath out of!",
  }) );
}

int CheckWanted() {
  if (this_player()->GetInvis()) return 0;
  if (!userp(this_player())) return 0;
  if (member_array(this_player()->GetKeyName(), Wanted) != -1) {
     eventForce("yell Get lost you degenerate!");
     eventForce("bump " + this_player()->GetKeyName());
     SetAttack(this_player());
     return 1;
  }
  if (this_player()->GetProperty("invader")) {
     eventForce("yell Invaders! Prepare for battle!");
     SetAttack(this_player());
     return 1;
  }
}
