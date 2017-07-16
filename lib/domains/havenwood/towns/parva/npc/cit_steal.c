/* Ruthlessly copied from Torak/Ranquest/Tomes/Amelia or someone */
/* Davantalus@Haven 20000227
 * Added in the off chance for the citizens to backstab
 * sleeping people just for kicks, Duuk 8/23/04
 */
#include <lib.h>
#include <std.h>
#include "../parva.h"

inherit LIB_NPC;

void DoSteal();
void DoRunAndHide();

static void create() {
  ::create();
  SetRace("human");
  SetKeyName("citizen");
  SetId( ({ "parva citizen", "citizen", "parva_wander" }) );
  SetShort("a citizen of Parva");
  SetLong("The Parvan citizen is a shady, unwashed character.  "
           "Something about the citizen suggests that "
           "Parva is not the nicest place in the world. "
           "The citizen stares at you with a gleam in his eye.");
  SetClass("rogue");
  SetLevel(random(30)+1);
  SetGender("male");
  SetInventory( ([
    STD_WEAPON "knife/small_knife" : "wield knife",
    ]) );
  SetWander(22);
  SetCurrency("roni", 5);
  SetAction(50, (: DoSteal :));
  SetCombatAction(70, (: DoRunAndHide :) );
  SetInventory( ([
    PARVA_OBJ + "/knife_cit" : "wield knife in right hand",
    PARVA_OBJ + "/pants_cit" : "wear pants",
    PARVA_OBJ + "/shirt_cit" : "wear shirt",
    PARVA_OBJ + "/boots_cit" : "wear boots",
    ]) );
  SetFriends( ({"citizen","pecunia","minkin","drunk","arpachshad"}) );
  SetLimit(2);
}

void DoSteal() {
  object array people = ({ });
  people = filter(all_inventory(environment(this_object())), (: playerp :));

  if(sizeof(people)) {
    int number = random(sizeof(people));
    string person = (people[number]->GetKeyName());
    if (people[number]->GetNationality() == "Parva") return;
    if (people[number]->GetSleeping()) {
    	eventForce("backstab " + person);
    	}
    eventForce("steal money from " + person);
    }
}

void DoRunAndHide() {
     string direction = "";
     string array where = ({});
     where = this_object()->GetExits();

     if( sizeof(where) ) {
          int num = random(sizeof(where));
          direction = where[num];
          eventForce( "go " + direction );
          eventForce( "hide" );
     }
}
