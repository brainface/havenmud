#include <lib.h>
#include "../averath.h"
inherit LIB_SENTIENT;
#include "../wanted.h"
int CheckPoster();

static void create() {
  sentient::create();
  SetKeyName("Averath Guard"); 
  SetId( ({ "guard", "member", "averath_wander", "averath_person" }) );
  SetShort("a member of the Averath City Watch");  
  SetLong(
    "This strongly built man serves the Duke in the defense of his city. "
    "The people of Averath respect the members of the watch, and look to them "
    "for inspiration on many occasions."    
  );  
  SetFriends( ({ "averath_people" }) );
  SetRace("human");
  SetGender("male");  
  SetClass("fighter");
  SetLevel(85);
  SetReligion("Aetarin");
  SetMorality(0);
  SetCurrency("ducats", random(150));  
  SetInventory( ([         
  ]) );
    
  SetWander(5);
  SetEncounter( (: CheckPoster :) );
  SetAction(1, ({
    "!say Good day, citizens.",    
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
    eventForce("say There is no honor in running. Stand and face your "
      "destiny.");    
    SetAttack(this_player());
    return 1;
   }  
  return 0;
 }
