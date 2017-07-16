#include <lib.h>
#include "../argoth.h"
inherit LIB_SENTIENT;
void ChatRes();
int CheckWanted();
#include "../wanted.h"

static void create() {
  sentient::create();
  SetKeyName("guard");
SetFriends( ({ "impus", "grond", "ouphe", "alai", "vyrten", "monk", "citizen",
                "guard", "soldier", "lieutenant", "scout", "priest",
                "dannel", "garret", "modious" }) );
  SetShort("a member of the Argoth town Guard");
  SetRace("orc");
  SetLevel(random(20)+20);
  SetClass("cavalier");
  SetGender("male");
  SetLong("This large orc is one of many guards who have been given the "
    "task of keeping recent attacks against Argoth controlled and to "
    "keep a relative amount of peace in the streets.  Huge muscles build "
    "this warrior's arms, and he looks like he's not at all happy with the "
    "miscreants who have forced him to take this job.");
  SetInventory( ([
    ARGOTH_OBJ + "pike.c" : "wield pike",
                  ]) );
  SetCurrency("khuca",random(20));
  SetId( ({ "guard", "town guard" }) );
  SetWander(5);
 SetEncounter( (: CheckWanted :) );
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
