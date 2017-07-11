#include <lib.h>
inherit LIB_VERB;

static void create() {
  ::create();
  SetVerb("plant");
  SetRules("OBJ on LIV");
  SetErrorMessage("Plant what on who?");
  SetHelp("Syntax:   plant OBJECT on LIVING \n\n"
          "Use this verb to quietly place an object on another person "
          "without anyone noticing you doing it."
          );
}

mixed can_plant_obj_on_liv() {
  object who = this_player();
  
  if (who->GetSleeping()) 
    return "You are asleep!";
  if (who->GetParalyzed()) 
    return "You are unable to move!";
  if (who->GetStaminaPoints() < 50) 
    return "You are too tired.";
  if (who->GetInCombat()) 
    return "You're a bit busy for that.";
  return 1;
}

int do_plant_obj_on_liv(object item, object target) {
  object who = this_player();
  int pro, con, success;
  
  pro = who->GetStatLevel("coordination") + who->GetSkillLevel("stealing");
  con = target->GetStatLevel("wisdom") + item->GetMass();
  
  if (!(target->CanCarry((int)item->GetMass()))) {
    who->eventPrint("It doesn't seem that " + target->GetCapName() + " can carry that much.");
    return 1;
  }
  
  success = who->eventCheckSkill("stealing", pro, con);
  who->AddStaminaPoints(-50);
  if (success < -20) {
    send_messages( ({ "attempt", "are" }),
      "$agent_name clumsily $agent_verb to plant " + item->GetShort() + " on $target_name, "
      "but $agent_verb discovered.", who, target, environment(who) );
    
    if (!userp(target)) {
      target->SetAttack(who);
    }
    return 1;
  }
  if (success < 20) {
    who->eventPrint("You are unsure if " + target->GetCapName() + " noticed your attempt.");
    item->eventMove(target);
    
    if (!random(3)) {
      target->eventPrint(who->GetCapName() + " has planted " + item->GetShort() + " on you!");
      if (!userp(target)) target->SetAttack(who);
      }
    return 1;
  }
  who->eventPrint("You plant " + item->GetShort() + " on " + target->GetCapName() + ".");
  item->eventMove(target);
  
  return 1;
}