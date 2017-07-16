// mahkefel 2010: added a weapon from std.
#include <lib.h>
#include <std.h>
#include "../averath.h"
inherit LIB_TOWNGUARD;
#include "../wanted.h"
int CheckPoster();

static void create() {
  ::create();
  SetKeyName("Averath Guard"); 
  SetId( ({ "guard", "member", "averath_wander", "averath_person" }) );
  SetShort("a member of the Averath City Watch");  
  SetLong(
    "This strongly built man serves the Duke in the defense of his city. "
    "The people of Averath respect the members of the watch, and look to them "
    "for inspiration on many occasions."    
  );  
  SetFriends( ({ "averath_person" }) );
  SetRace("human");
  SetTown("Averath");
  SetBaseLanguage("Avera");     
  SetGender("male");  
  SetClass("fighter");
  SetSkill("melee combat",1,2);
  SetLevel(85);
  SetReligion("Aetarin");
  SetMorality(100);
  SetCurrency("ducats", 15 + random(80));  
  SetInventory( ([         
    STD_SLASH "longsword" : "wield longsword",
  ]) );
    
  SetWander(5);
  SetLimit(3);
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
