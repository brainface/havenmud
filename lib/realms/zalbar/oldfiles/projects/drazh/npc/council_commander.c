#include <lib.h>
#include "../drazh.h"

inherit LIB_NPC;

void DoCombatSomething();
int CheckWanted();
#include "../wanted.h"

static void create() {
  ::create();
  SetKeyName("skrisnik");
  SetShort("Skrisnik, Commander of the Council Agents");
  SetId( ({"skrisnik","commander","skaven","council"}) );
  SetLong(
    "Skrisnik is an rare albino skaven. He is a massive skaven "
    "that if not for being an albino he would be just a "
    "regular stormvermin. Since Skrisnik is an albino he "
    "was trained since birth to be an inner chamber guard, "
    "the highest honor bestowed apon a skaven."
    );
  SetRace("skaven");
  SetClass("fighter");
  SetClass("priest");
  AddSkill("poison magic",1,2);
  SetLevel(125);
  SetGender("male");
  SetAction(5, ({
     "!speak Halt you goes there?",
     "!speak If you are here to see the council, it better be important!",
     "!sniff."
     }) );
  SetCurrency("roni", 10000);
  SetMorality(-1500);
  SetTown("Drazh");
  SetReligion("Soirin");
  SetInventory( ([
     V_OBJ + "scale_armour" : 
       "wear armour on torso and left arm and right arm and left leg and right leg",
     V_OBJ + "a_sword"      : "wield sword",
     V_OBJ + "a_knife"      : "wield knife",
     ]) );
  SetSpellBook( ([
     "unholy guardian"     : 100,
     "corruption"          : 100,
     "touch of death"      : 100,
     "divine retributions" : 100,
     "poison arrow"        : 100,
     "stab in the dark"    : 100,
     "poison weapon"       : 100,
   ]) );
  SetCombatAction(10, (: DoCombatSomething :) );
  SetFirstCommands( ({
     "cast unholy guardian",
     "cast unholy guardian",
     }) );
}

void DoCombatSomething() {
  object who = this_object();
  object target = GetCurrentEnemy();

  switch(random(8)) {
    case 0:
      eventForce("cast poison arrow");
      break;
    case 1:
      eventForce("disorient");
      break;
    case 2:
      eventForce("cast corruption on " + target->GetKeyName());
    case 3:
      if (sizeof(GetMagicProtection()) < 5) 
        eventForce("cast unholy guardian");
      break;
    case 4:
      if((who->GetWielded() > 0) && (who->GetWielded() < 2))
        eventForce("cast poison weapon on " + who->GetWielded());
      if(who->GetWielded() > 1)
        eventForce("cast poison weapon on " + 
          (random(2) ? who->GetWielded("left claw") : who->GetWielded("right claw")));
      break;
    case 5:
      eventForce("cast touch of death");
      break;
    default:
      eventForce("cast stab in the dark");
      break;
    }
}

int CheckWanted() {
  if (this_player()->GetInvis()) return 0;
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

