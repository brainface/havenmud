#include <lib.h>
#include <damage_types.h>
#include <std.h>
#include "../minos.h"


inherit LIB_NPC;

void DoSomething(); 
void DoCombatSomething();
void HeadBash(object target);
string horn, horns;
string hair_color;
string height;

static void create() {
  ::create();

  switch(random(5)) {
    case 0:
      horn = "about a foot and half long,";
      break;
    case 1:
      horn = "a little over two feet long,";
      break;
    default:
      horn = "about a foot long,";
      break;
    }
  
  switch(random(10)) {
    case 0:
      horns = "only one horn, " + horn + " and the other cut off at the base";
      break;
    default:
      horns = "a pair of horns, " + horn;
      break;
    }
  
  switch(random(5)) {
    case 0:
      hair_color = "reddish brown";
      break;
    case 1:
      hair_color = "dark brown";
      break;
    case 2:
      hair_color = "black";
      break;
    default:
      hair_color = "brown";
      break;
    }
 
   switch(random(10)) {
    case 0:
      height = "a little under seven feet";
      break;
    case 1:
      height = "at eight feet";
      break;
    case 2:
      height = "a little under eight feet";
      break;
    case 3:
      height = "a little over eight feet";
      break;
    case 4:
      height = "at nine feet";
      break;
    case 5:
      height = "a little under nine feet";
      break;
    case 6:
      height = "a little over nine feet";
      break;
    default:
      height = "a little over seven feet";
      break;
    } 

  SetKeyName("guard");
  SetId( ({ "guard", "minotaur" }) );
  SetShort("a minotaur guard");
  SetAdjectives( ({ "minotaur" }) );
  SetLong(
    "This gargantuan brute stands " + height + " tall with a head reminiscent "
    "of a bull. He has " + horns + " growing out of his forehead. There is short "
    + hair_color + " fur covering his massive muscles and scared body." 
    );
  SetRace("minotaur");
  SetGender("male");
  SetClass("fighter");
  SetSkill("brawling",1,2);
  SetLevel(250 + random(51));
  SetReligion("Damhair");
  SetMorality(random(1000) - random(1000));

  SetCombatAction(25, (: DoCombatSomething :) ); 
  SetInventory( ([
    M_OBJ + "axe"     : "wield axe",
    M_OBJ + "harness" : "wear harness",                   
    ]) );
  SetFriends( ({"minotaur"}) );
    
}



void DoCombatSomething() {
    object target = GetCurrentEnemy();
    object bull = this_object();
    switch(random(8)) {
      case 0:
        if(target->GetTestChar()) debug("Minoan guard disorient");
        eventForce("disorient");
        break;
      case 2:
         if(target->GetTestChar()) debug("Minoan guard HeadBash");
        bull->HeadBash(bull,target);
        break;
      case 3:
         if(target->GetTestChar()) debug("Minoan guard disarm");
        eventForce("disarm");
        break;
      default:
         if(target->GetTestChar()) debug("Minoan guard disorient");
        eventForce("disorient");
        break;
      }  
}

void HeadBash(object who, object target) {
  
  if(present(target)) { 
    switch(random(8)) {
      case 0..6:
        send_messages( ({"send","toward"}), 
              "%^YELLOW%^Slamming $agent_possessive hoof against the ground, $agent_name "
		          "$agent_verb a shockwave $agent_verb $target_name knocking $target_objective "
		          "down!%^RESET%^", who, target, environment(target) );
		    target->eventCollapse(1);
		    target->SetParalyzed(5);
		    target->eventReceiveDamage(who, BLUNT, 500, 0, target->GetTorso());
		    break;
		  default:
		    if(who->GetRecoveryTime() < 1000) {
          if(random(who->GetSkillLevel("melee combat")) > random(target->GetSkillLevel("dodge"))) {
		        send_messages( ({"run"}),
		            "%^CYAN%^Lowering $agent_possessive head, $agent_name $agent_verb towards "
		            "$target_name piercing $target_objective with $agent_possessive_noun horns!%^RESET%^",
		            who, target, environment(target) );
		        target->eventReceiveDamage(who, PIERCE, 2000, 0, target->GetTorso());
		      }
          else {
            send_messages( ({"run"}),
		            "%^BLUE%^Lowering $agent_possessive head, $agent_name $agent_verb towards "
		            "$target_name but $target_name dodges $agent_possessive_noun horns!%^RESET%^",
		            who, target, environment(target) );
          }
        }
        break;
      }
    }
  return;
}
