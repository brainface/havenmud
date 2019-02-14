/* Mahk 2019
 * special lizardman verb
 * regenerates lost limbs
 * eats food
 */

#include <lib.h>

inherit LIB_VERB;
mixed can_regenerate_str(string);
mixed do_regenerate_str(string, object);
// int eventTend(object, object);

int Cooldown = 0;
int SetCooldown(int x) { return Cooldown = x; }
int GetCooldown() { return Cooldown; }

static void create() {
  ::create();
  SetVerb("regenerate");
  SetRules("STR");
  SetCooldown(15);
  SetErrorMessage("Regenerate which limb?");
  SetHelp("Syntax:   regenerate STR  \n\n"
    "I.e. regenerate left foot. \n"
    "Lizardmen can regenerate missing limbs. It requires a great deal of food "
    "and some time to recover before they can regrow another.");
}

mixed can_regenerate() {
  return can_regenerate_str("");
}

mixed can_regenerate_str( string limb) {
  object who = this_player();
  
  if (!sizeof(who->GetMissingLimbs()) ) {
    return "Get something lobbed off first"; 
  }
  
  // currently lizard only.
  // a spell or something could add a "can_regenerate" condition
  // special food/potion maybe?
  if (who->GetRace() != "lizardman") {
    return "Squint and strain as you might, your stump refuses to grow back.";
  } 
  if (who->GetSleeping()) {
          return "You dream about helping.";
  }
  if (who->GetParalyzed()) {
          return "You are unable to move.";
  }
  if (who->GetStaminaPoints() < 50) {
          return "You are too tired.";
  }
  if (who->GetInCombat()) {
          return "You're a bit busy.";
  }
  if (who->GetCooldown(GetVerb())) {
    return "You only grow so fast!";
  }  
  if (member_array(limb, who->GetMissingLimbs()) == -1 ) {
    if (member_array(limb, who->GetLimbs()) == -1 ) {
      return "But you never had a " + limb + ". (You may have to specify left "
        "or right in the case of some limbs. See help 'body'.)";   
    }
    return "Your " + limb + " is still attached.";     
  }
  // copy pasted from restore limb. 
  if(!(who->GetLimb((who->GetMissingLimb(limb))["parent"]))) {
    return "You have to regenerate your " + who->GetMissingLimb(limb)["parent"] + " first!"; 
  }

  if (who->GetFood() < 100) {
    return "Your belly's too empty. Eat something first!";
  }
  
  return 1;
}

mixed do_regenerate_str(string limb) {
  object who = this_player();
  send_messages( ({ "blah" }), 
    "A tiny new " + limb + " slithers out of $agent_possessive_noun bloody "
    "stump and rapidly grows to full size!", who, 0, environment(who)); 
  who->RestoreLimb(limb);
  who->AddStaminaPoints(-50);
  who->AddFood(-100);
  who->eventPrint("You feel a gnawing in your belly.");
  if (Cooldown) who->AddCooldown(GetVerb(), Cooldown);
  return 1;
}

