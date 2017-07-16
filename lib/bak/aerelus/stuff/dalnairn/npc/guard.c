// Dalnairn
// Aerelus

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_SENTIENT;
#include "../wanted.h"
int CheckPoster();

static void create() {
  sentient::create();
  SetKeyName("Dalnairn Guard"); 
  SetId( ({ "guard", "dalnairn_people", "city guard" }) );
  SetShort("a member of the Dalnairn Guard");  
  SetLong(
    "This Duergar is in the service of the Dalnairn city guard. He is "
    "extremely strong, his body bulging with muscles. He casually glances "
    "around the area, looking out for potential threats to his city."
  );
  SetAdjectives( ({ "dalnairn" }) );
  SetFriends( ({ "dalnairn_people" }) );
  SetRace("dwarf");
  SetGender("male");  
  SetClass("fighter");
  SetLevel(65);
  SetReligion("Soirin");
  SetMorality(-200);
  SetCurrency("shards", random(150));  
  SetInventory( ([
         DAL_OBJ + "guardarmour": "wear my suit",
         DAL_OBJ + "sword" : "wield my sword",
         DAL_OBJ + "boots" : "wear my boots",
  ]) );
    
  SetWander(5);
  SetEncounter( (: CheckPoster :) );
  SetAction(1, ({
    "!speak I will protect the Duergar with my life.",
    "!speak Do what you will to any outsiders, but try not to make a mess.",    
   }) );  
}

int CheckPoster() {
  if (this_player()->GetInvis())
  {
    return 0;
  }
  
  if (member_array(this_player()->GetKeyName(), keys(Crimes)) != -1) 
  {
    eventForce("follow " + this_player()->GetKeyName());
    eventForce("yell " + capitalize(this_player()->GetKeyName()) + "! "
      "You have been sentenced to death for your crimes. Now die!"); 
    SetAttack(this_player());
    return 1;
   }  
  return 0;
 }
