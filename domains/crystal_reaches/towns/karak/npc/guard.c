// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_TOWNGUARD;

void ChatRes();
int CheckWanted();
#include "../wanted.h"

static void create() {
  ::create();
  SetKeyName("guard");
  SetId( ({ "guard", "orc", "karak_wander" }) );
  SetAdjectives( ({ "town", "karak" }) );
  SetShort("a member of the Karak Guard");
  SetLong(
    "This large orc is one of many guards who have been given the "
    "task of keeping recent attacks against Karak controlled and to "
    "keep a relative amount of peace in the streets. Huge muscles build "
    "this warrior's arms, and he looks like he's not at all happy with the "
    "miscreants who have forced him to take this job."
  );
  SetRace("orc");
  SetTown("Karak");
  SetClass("fighter");
  SetGender("male");
  SetLevel(random(20)+20);
  SetReligion("Saahagoth", "Saahagoth");
  SetMorality(-50-random(100));
  SetInventory( ([
    KARAK_OBJ + "axe" : "wield axe",
  ]) );
  SetCurrency("orcteef",random(20) + 1);
  SetWander(5);
  SetFriends( ({ 
  "impus", "grond", "ouphe", "alai", "vyrten", "monk", "citizen",
  "guard", "soldier", "lieutenant", "scout", "priest",
  "dannel", "garret", "modious", "orc"
  }) );
}

int CheckWanted() {
  if (member_array(this_player()->GetKeyName(), Wanted) != -1) {
    eventForce("follow " + this_player()->GetKeyName());
    eventForce("yell A criminal!  Kill him!");
  return 1;
  }
  if(this_player()->GetProperty("invader")) {
    eventForce("yell Defend the city!!");
  return 1;
  }
return 0;
}
