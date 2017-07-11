#include <lib.h>
#include <damage_types.h>
#include <vision.h>
#include <position.h>
inherit LIB_ACTION;


static void create() {
	 ::create();
	SetVerb("dirtkick");
  SetRules("LIV", "");
	SetHelp("Allows you to blind your opponent temporarily by kicking dirt into their eyes.");
	SetStaminaCost(25);
	SetRequiredSkills( ([
	  "brawling"     : 25,
	  "melee combat" : 25,
	  ]) );
}

mixed can_dirtkick() {
	 if(!this_player()->GetInCombat()) { return "Dirtkick who?"; }
	 if(!this_player()->GetTestChar()) { return "You cannot dirtkick.";}
	 return CanAction(this_player());
	}

mixed can_dirtkick_liv() {
	return CanAction(this_player());
}

mixed do_dirtkick_liv(object target) {
//	if (target->GetBlind() > 0) { return "But that person is already blind."; }
	return eventAction(this_player(), target);
}

mixed do_dirtkick() {
	return do_dirtkick_liv(this_player()->GetCurrentEnemy());
}


int eventAttack(object who, object target) {
	int pro, con, result, amt;


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
  	   send_messages( ({ "twist", "fall" }), "$agent_name $agent_verb $agent_possessive ankle"
						 " trying to dirtkick $target_name and $agent_verb"
  	                  			 " to the ground.", who, target, environment(who));
  	   who->SetPosition(POSITION_LYING);
  	   return 1;
  	             }
  if (result == 1) {
  	   send_messages("dodge", "$target_name $target_verb $agent_possessive_noun dirtkick"
				  " attempt.", who, target, environment(who));
  	   return 1;
  	             }
  
  send_messages( ({ "sidestep", "kick" }), "$agent_name $agent_verb nimbly and $agent_verb dirt into" 
					   " $target_possessive_noun face blinding $target_objective.",
					   who, target, environment(who));
  amt = (who->GetSkillLevel("brawling")/10);
//	debug(amt); 
  if (amt > 7) amt = 7;
  target->eventBlind(who, amt);
  return 1;
}
