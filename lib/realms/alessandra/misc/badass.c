//  An Avatar fighter for Malveillant
//  Alessandra  11/04
//  Description by Selket, who is teh shit

#include <lib.h>
//#include "../mal.h"
inherit LIB_SENTIENT;

void DoCombatSomething();

static void create() {
  ::create();

  SetKeyName("badass");
  SetId( ({ "badass", "warrior", "dark-elf", "wander" }) );
  SetAdjectives( ({ "kickass", "dark-elf" }) );
  SetShort("badass the Kickass Warrior of Malveillant (dark-elf)");
  SetLong(
     "Badass is a total fuckin' badass."
     );
  SetRace("dark-elf");
  SetGender("male");
  SetClass("cavalier");
  SetMorality(-2250);
  SetTown("Malveillant");
  SetReligion("Soirin");
  SetLevel(230);
  SetSkill("pierce defense", 200, 1);
  SetSkill("knife attack", 200, 1);
  SetClass("cleric");
  SetSkill("evokation", 200, 1);
  SetSkill("healing", 200, 1);
  SetWanderSpeed(10);
  SetInventory( ([
     ]) );
  SetCurrency( ([
     "roni" : random(9000),
     ]) );
  AddFood(2500);
  AddDrink(2500);
  SetSpellBook( ([
     "barrier of faith" : 100,
     ]) );
  SetAction(5, ({ 
     "!cast barrier of faith",
     "!speak I defend this city from harm.",
     }) );
  SetCombatAction(10, ({
     "!cast barrier of faith",
     }) );

if (environment()) call_out( (: eventForce, "cast barrier of faith" :), 0 );

  SetCombatStyleLevel("blade dancing", 60);
  SetCombatAction(10, (: DoCombatSomething :) );

}

void DoCombatSomething() {
	 	
if(GetStaminaPoints() > ( to_int (GetMaxStaminaPoints() /2 )) ) {
	eventForce("set style to blade dancing");
	  }
	  
	else
	  eventForce("set style to none");
	return;
	
}	
