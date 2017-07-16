// Proximo@Via Imperialis
// 05/30/2003

#include <lib.h>
#include "../sulumus.h"

inherit LIB_SENTIENT;


#include "../wanted.h"
int CheckWanted();

static void create() {
  sentient::create();
  SetKeyName("enforcer");
  SetId( ({ "enforcer","guard","we_wander" }) );
  SetShort("a mercenary enforcer");
  SetLong(
     "This sword-for-hire has loaned his talents out to the Warlord Brodi to "
     "protect this area from the many dangers of the world. He appears to be content "
     "and satisfied with his job, suggesting the pay fits his lifestyle comfortably. "
     "He looks strong and experienced, not someone to be trifled with. "
  );
  SetGender("male");
  SetRace("human"); SetBaseLanguage("Imperial");
  SetClass("fighter");
  SetSkill("pierce combat", 1, 1);
  SetSkill("melee combat", 1, 1);
  SetStat("durability", 1, 2);
  SetFriends( ({
     "we_wander",
  }) );
  SetLimit(1);
  SetProperty("no bump", 1);
  SetWander(1);
  SetWanderSpeed(1);
  SetWanderPath( ({
     "go south", "go west", "go west", "go north", "go north", "go east", 
     "go east", "go south",
  }) );
  SetWanderRecurse(1000);
  SetLevel(10+random(10));
  SetCurrency("imperials", random(50));
  RemoveLanguage("Human");
  SetLanguage("Imperial", 100, 1);
  SetEncounter( (: CheckWanted :) );
  SetInventory( ([
     S_OBJ + "leather_pants" : "wear pants",
     S_OBJ + "leather_glove" : "wear glove on right hand",
     S_OBJ + "spear" : "wield spear",
     S_OBJ + "leather_vest" : "wear vest on torso",
     S_OBJ + "leather_helmet" : "wear helmet",
     S_OBJ + "leather_boots" : "wear boots",
     S_OBJ + "cloak" : "wear cloak",
  ]) );
  SetAction(2, ({
     "!say We're watching you. ",
     "!nod",
     "!hmm",
     "!emote eyes you over suspiciously. ",
     "!say Stay out of trouble. ",
     "!smirk",
     "!say This is not a bad job, pay is good, area isn't too dangerous...what "
     "more could you want? ",
     "!say Move along. ",
  }) );
  SetCombatAction(20, ({
  }) );
}

int CheckWanted() {
  if (this_player()->GetInvis()) return 0;
  if (!userp(this_player())) return 0;
  if (member_array(this_player()->GetKeyName(), Wanted) != -1) {
    eventForce("follow " + this_player()->GetKeyName());
    eventForce("yell Suffer, Criminal!");
     SetAttack(this_player());
    return 1;
  }
  if(this_player()->GetProperty("invader")) {
     eventForce("yell Invaders!");
     SetAttack(this_player());
     return 1;
  }
}
