// by Dahaka
// Aug 2004

#include <lib.h>
#include <std.h>
#include "../drazh.h"

inherit LIB_NPC;

void DoCombatSomething();
void DoSomething();
int CheckWanted();
#include "../wanted.h"

int type = random(3);

string CheckSetShort();

static void create() {
  npc::create();
  SetKeyName("agent");
  SetTown("Drazh");
  SetReligion("Soirin");
  SetId( ({"agent","skaven","wander"}) );
  SetShort( (:CheckSetShort:) );
  SetLong( 
   "This skaven is rather normal looking for his kind "
   "except for the light grey fur he has covering his "
   "body. This skaven has been blessed by Melchezidek with "
   "his grey fur and is charged with defending the "
   "Council of Thirteen.");
  SetGender("male");
  SetRace("skaven");
  SetClass("priest");
  SetClass("fighter");
  AddSkill("poison magic",1,1);
  SetLevel(50 +  random(26));
  SetFriends( ({
     "skaven","councilman","watchman","agent"
   }) );
  SetWander(5);
  SetAction(10, (: DoSomething :) );
  SetCombatAction(10, (: DoCombatSomething :) );
  SetMorality(-1500);
  SetSpellBook( ([
     "barrier of faith" : 100,
     "dim"              : 100,
     "poison weapon"    : 100,
     "poison arrow"     : 100,
     "stab in the dark" : 100,
     ]) );
  
  switch(type) {
    case 0:
      SetInventory( ([
         V_OBJ + "breastplate" : "wear breastplate",
         V_OBJ + "a_sword"     : 2,
         V_OBJ + "grey_robe"   :
           "wear robe on torso and left arm and right arm and left leg and right leg ",
         ]) );  
      call_out((: eventForce, "wield 1st sword" :),1 );
      call_out((: eventForce, "wield sword" :),1 );
      break;
   case 1:
      SetInventory( ([
         V_OBJ + "breastplate" : "wear breastplate",
         V_OBJ + "wall_shield" : "wear shield on left arm and left claw",
         V_OBJ + "a_longsword" : "wield longsword",
         V_OBJ + "tail_spike"  : "wear spike",
         V_OBJ + "grey_robe"   : 
           "wear robe on torso and left arm and right arm and left leg and right leg ",
         ]) );  
      break;
   default:
      SetInventory( ([
         V_OBJ + "breastplate" : "wear breastplate",
         V_OBJ + "a_knife"     : "wield knife",
         V_OBJ + "a_longsword" : "wield longsword",
         V_OBJ + "grey_robe"   : 
           "wear robe on torso and left arm and right arm and left leg and right leg ",
         ]) );  
  }
  SetFirstCommands( ({
     "cast barrier of faith",
     "cast barrier of faith",
     }) );
  SetLimit(8);
  
}



string CheckSetShort() {
  if(!GetInvis(1)) {
  return "an agent of the Council";
  }
  else {
  return "an invisible agent";
  }
}

void DoSomething() {
  if (GetStaminaPoints() > (GetMaxStaminaPoints()/4)) {
    if(!GetInvis(1))
    eventForce("cast dim");
    
   if ((sizeof(GetMagicProtection()) < 2)) {
    eventForce("cast barrier of faith");
    return;
    }
  }
}



void DoCombatSomething() {
  object who = this_object();
  int num = 0;
  
  if(random(50)) {
    eventForce("say with Melchezidek's powers you will die!");
    }

  switch(random(8)) {
    case 0:
      eventForce("cast poison arrow");
      break;
    case 1:
      eventForce("disorient");
      break;
    case 3:
      if (sizeof(GetMagicProtection()) < 5) 
        eventForce("cast barrier of faith");
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