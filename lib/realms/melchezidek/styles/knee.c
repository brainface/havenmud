#include <lib.h>
#include <damage_types.h>
#include <vision.h>
#include <position.h>
inherit LIB_ACTION;


static void create() {
	 ::create();
	SetVerb("knee");
	SetHelp("An attempt to knee your opponent in the groin causing severe pain and possible paralysis.");
	SetStaminaCost(50);
	SetRequiredSkills( ([
	  "brawling"     : 75,
	  "melee combat" : 75,
	  ]) );
}

mixed can_knee() {
	 if(!this_player()->GetInCombat()) { return "Knee who?"; }
	 if(!this_player()->GetTestChar()) { return "You cannot knee.";}
	 return CanAction(this_player());
	}

mixed can_knee_liv() {
	return CanAction(this_player());
}

mixed do_knee_liv(object target) {
//	if (target->GetParalyzed() > 0) { return "But that person is already paralyzed"; }
	return eventAction(this_player(), target);
}

mixed do_knee() {
	return do_knee_liv(this_player()->GetCurrentEnemy());
}


int eventAttack(object who, object target) {
	int pro, con, result, amt;


// 4 possible outcomes
//  1 miss and knock yourself down
//  2 knee them and do some damage
//  3 knee them and do a lot of damage
//  4 knee them and do a lot of damage and paralyze them


  // case 1
  send_messages( ({ "attempt", "knee", "miss", "fall" }), "$agent_name $agent_verb to $agent_verb $target_name" 
							  " but $agent_verb and $agent_verb flat on" 
							  " $agent_possessive face.", 
							  who, target, environment(who));
//You attempt to knee soandso but miss and over correct yourself and fall flat on your face.
  send_messages( ({ "run", "knee" }), "$agent_name $agent_verb at $target_name and $agent_verb $target_possessive" 
				      " in the groin!", who, target, environment(who));
//You run at soandso and knee him in the groun!
  send_messages( ({ "jump", "slam" }), "$agent_name $agent_verb at $target_name and $agent_verb $agent_possessive"
				       " knee into $target_posessive groin!", who, target, environment(who));
//You jump at soandso and slam your knee into their groin!
  send_messages( ({ "slam", "fall" }), "$agent_name $agent_verb $agent_possesive knee into $target_name groin so hard $target_nominative $target_verb down!", who, target, environment(who));

//You slam your knee into soandsos groin so hard they fall down in pain!



  pro = who->GetOffense( ({ "melee combat", "brawling" }) );
  pro += who->GetStatLevel("luck");
  
  con = target->GetStatLevel("luck");
  con += target->GetSkillLevel("dodge");
  con += target->GetStatLevel("agility");
  con += target->GetStatLevel("coordination");
  
  pro = random(pro); con = random(con);
  if ((who->GetLevel()) / (target->GetLevel()) > 1)  pro += 20;
  if ((who->GetLevel()) / (target->GetLevel()) > 2)  pro += 30;
  if ((pro *2) < con) result = 0;
     else if (pro < con) result = 1;
  if (pro > con) result = 2;
 	
  if (!result) {
  	   send_messages( ({ "twist", "fall" }), "$agent_name $agent_verb $agent_possessive ankle trying to knee $target_name and $agent_verb"
  	                  " to the ground.", who, target, environment(who));
  	                  who->SetPosition(POSITION_LYING);
  	               return 1;
  	             }
  if (result == 1) {
  	  	   send_messages("dodge", "$target_name $target_verb $agent_possessive_noun knee attempt.", 
  	                 who, target, environment(who));
  	               return 1;
  	             }
  send_messages( ({ "sidestep", "kick" }), "$agent_name $agent_verb nimbly and $agent_verb dirt into $target_possessive_noun"
                    " face blinding $target_objective.", who, target, environment(who));
  amt = (who->GetSkillLevel("brawling")/10);
	debug(amt); 
 if (amt > 7) amt = 7;
  target->eventBlind(who, amt);
  return 1;
}
