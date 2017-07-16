#include <lib.h>
#include "../drazh.h"

inherit LIB_MAYOR;

void DoCombatSomething();
int CheckWanted();
#include "../wanted.h"

static void create() {
  ::create();
  SetKeyName("skirszarr");
  SetId( ({"skaven","mayor","councilman","grey lord"}) );
  SetAdjectives( ({"grey","lord","of","drazh"}) );
  SetShort("Grey Lord Skirszarr, Lord of Drazh");
  SetLong(
     "This medium sized skaven with white fur matted to his body "
     "and red beady eyes watching the his citizens. By the color "
     "of filthy fur, this skaven must be an infamous grey lord, "
	   "Skirszarr. The look in his unblinking eyes is a crazed one."
	   );
  SetRace("skaven");
  SetGender("male");
  SetMorality(-2200);
  SetTown("Drazh");
  SetTax(50);
  SetLocalCurrency("roni");
  SetReligion("Soirin");
  SetClass("necromancer");
  SetSkill("faith",1,1);  
  SetSkill("poison magic",1,2);
  SetLevel(150);
  SetMorality(-2500);
  SetCurrency("roni", 15000);
  SetSpellBook( ([
     "temperature shield" : 100,
     "avalanche"          : 100,
     "poison explosion"   : 100,
     "unholy guardian"    : 100,
     "corruption"         : 100,
     ]) );
  SetAction(5, ({ 
       "!say Do you wish to become a denizen of my town?",
       "!say the Council of Thirteen welcomes you",
       }) );
  SetCombatAction(60, (: DoCombatSomething :) );
  SetInventory( ([
	   V_OBJ + "seer_staff" : "wield staff",
	   V_OBJ + "black_robe" : 
	     "wear robe on torso and left arm and left leg and right arm and right leg",
     ]) );
  SetFirstCommands( ({
     "cast temperature shield",
     "cast temperature shield",
     "cast unholy guardian",
     }) );
}

void DoCombatSomething() {

int randnum = random(10);

if (!random(50)) 
 eventForce("speak Challenge the Council of Thirteen?");
   
  

  switch(random(8)) {
    case 0:
      eventForce("cast poison explosion");
      break;
    case 1:
      eventForce("cast corruption");
      break;
    case 3:
      if (sizeof(GetMagicProtection()) < 5) 
        eventForce("cast temperature shield");
      break;
    default:
      eventForce("cast avalanche");
      break;
}
}

int CheckWanted() {
  if (!userp(this_player())) return 0;
  if (member_array(this_player()->GetKeyName(), keys(Crimes)) != -1) {
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