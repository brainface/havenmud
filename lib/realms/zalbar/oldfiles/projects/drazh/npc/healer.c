// by Dahaka
// Aug 2004

#include <lib.h>
#include "../drazh.h"

inherit LIB_HEALER;

void DoCombatSomething();

static void create() {
  healer::create();
  SetKeyName("Gazzel");
  SetFriends( ({"wander","seer"}) );
  SetGender("female");
  SetLong(
     "This skaven is shorter than most with light gray fur. This skaven "
	   "looks to be female. She has a calm appearance on her face, suggesting "
	   "she could help anyone if paid well enough."
	   );
  SetShort("Gazzel the healer");
  SetRace("skaven");
  SetId( ({"healer","gazzel","skaven"}) );
  SetReligion("Soirin");
  SetTown("Drazh");
  SetClass("priest");
  SetSkill("poison magic",1,2);
  SetLevel(40);
  SetMorality(-1000);
  SetSpellBook( ([
     "shield of faith"  : 100,
     "poison weapon"    : 100,
     "poison arrow"     : 100,
     "stab in the dark" : 100,
     ]) );
  SetCombatAction(10, (: DoCombatSomething :));
  SetCurrency("roni",random(1000));
  SetLocalCurrency("imperials");
  SetFees( ([
    "resurrect" : 100,
    "stamina"	  : 5,
    "health"	  : 5,
    "restore"	  : 50,
    ]) );
}

void DoCombatSomething() {
object who = this_object();
int randnum = random(10);

if (!random(50)) {
  eventForce("say you will die!");
  }
  

  switch(random(8)) {
    case 0:
      eventForce("cast poison arrow");
      break;
    case 1:
      eventForce("disorient");
    case 3:
      if (sizeof(GetMagicProtection()) < 5) 
        eventForce("cast shield of faith");
      break;
    case 4:
      if((who->GetWielded() > 0) && (who->GetWielded() < 2))
        eventForce("cast poison weapon on " + who->GetWielded());
      if(who->GetWielded() > 1)
        eventForce("cast poison weapon on " + 
          (random(2) ? who->GetWielded("left claw") : who->GetWielded("right claw")));
      break; 
    default:
      eventForce("cast stab in the dark");
      break;
}
}