// Dalnairn
// Aerelus
// updated for dalnairn recode torak@haven 2017

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
    "This dark-dwarf is in the service of the Dalnairn city guard. He is "
    "extremely strong, his body bulging with muscles. He casually glances "
    "around the area, looking out for potential threats to his city."
  );
  SetAdjectives( ({ "dalnairn" }) );
  SetFriends( ({ "dalnairn_people" }) );
  SetRace("dark-dwarf");
  SetGender("male");  
  SetClass("fighter");
  SetLevel(65);
  SetReligion("Soirin");
  SetMorality(-200);
  SetCurrency("shards", random(150)+25);  
  SetInventory( ([
         DAL_ARM + "guardarmour": "wear my suit",
         DAL_WPN + "sword" : "wield my sword",
         DAL_ARM + "boots" : "wear my boots",
  ]) );
  SetEncounter( (: CheckPoster :) );
  SetAction(1, ({
    "!speak I will protect Dalnairn with my life.",
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
