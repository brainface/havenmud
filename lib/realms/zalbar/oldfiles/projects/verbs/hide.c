/* A hide verb for rogue types */
#include <lib.h>
inherit LIB_VERB;

static void create() {
  ::create();
  SetVerb("hide");
  SetRules("");
  SetHelp(
    "Syntax:  <hide>\n\n"
    "This verb is used by stealthy people to hide in the shadows "
    "of a given area. Be warned that ANY action you take (except "
    "chat lines) will cause you to be revealed with NO warning "
    "message to you. In order to make the use of <hide> realistic, "
    "hide works as it would in real life. That is, you can attempt "
    "it, but will not know if it has worked until you see if others "
    "in the room notice you. Obviously your chances of success "
    "increase with increased skill."
  );
}

mixed can_hide() {
  if (this_player()->GetSleeping()) {
    return "You are asleep!";
    }
  if (this_player()->GetParalyzed()) {
    return "You cannot move!";
    }
  if (this_player()->GetStaminaPoints() < 20) {
    return "You are too tired.";
    }
  if (this_player()->GetHiding()) {
    return "You are already hidden!";
    }
  if (this_player()->GetInCombat()) {
    return "You are fighting!";
    }
  return 1;
}

mixed do_hide() {
  int chance;
  send_messages("attempt",
    "$agent_name $agent_verb to duck into the shadows.",
    this_player() );
  this_player()->AddStaminaPoints(-20);
  switch(environment(this_player())->GetClimate()) {
    case "indoors"      : chance = 200; break;  
    case "temperate"    : chance = 150; break;
    case "tropical"     : chance = 100; break;
    case "sub-tropical" : chance = 125; break;
    case "sub-arctic"   : chance = 175; break;
    case "arctic"       : chance = 200; break;
    case "underground"  : chance = 150; break;
    default             : chance = 150; break;
   }
  if (random(chance) < (this_player()->GetSkillLevel("stealth") + this_player()->GetStatLevel("agility")) ) {
      
      this_player()->SetHiding(1);
  } 
  return 1;
}
