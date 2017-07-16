/*  cook verb
 *  Helps noobs make money
 */
#include <lib.h>
#include <std.h>
#include <daemons.h>
inherit LIB_VERB;

static void create() {
  ::create();
  SetVerb("cook");
  SetRules("OBJ");
  SetErrorMessage("Cook what?");
  SetHelp("Syntax:   cook <corpse>\n\n"
          "Attempts to create an eatable meal from an animal corpse.\n"
          "Can be used by anyone, but is more effective with cooking skill."
          );
}

int eventCook(object corpse, object who) {
  object cook = new(STD_OBJ + "meat");
  string adj;
  int lvl;
  if (!cook) {
    debug("Failed to create meat.");
    return -1;
  }
  switch(lvl = who->GetSkillLevel("cooking")) {
    case 1..4:
      adj = "badly";
      cook->SetMeatClass(5);
      break;
    case 5..20:
      adj = "carefully";
      cook->SetMeatClass(15);
      break;
    case 21..50:
      adj = "quickly";
      cook->SetMeatClass(25);
      break;
    case 51..150:
      adj = "skillfully";
      cook->SetMeatClass(30);
      break;
    case 151..300:
      adj = "deftly";
      cook->SetMeatClass(40);
      break;
    case 301..10000:
      adj = "flawlessly";
      cook->SetMeatClass(50);
      break;
    default:
      adj = "crudely";
      break;
    }
  send_messages( ({ "cook" }),
    "$agent_name " + adj + " $agent_verb $target_name.", who, corpse, environment(who));
  cook->SetMeatSource(corpse->GetRace());
  cook->SetMeatLevel(corpse->GetLevel());
  corpse->eventDestruct();
  cook->eventMove(who);
  cook->SetMeat();
}

mixed can_cook_obj() {
  object who = this_player();
  if (who->GetSleeping())  return "You dream of cooking a corpse.  Sicko.";
  if (who->GetParalyzed()) return "You are paralyzed.";
  if (who->GetStaminaPoints() < 50) return "You are too tired.";
  if (who->GetInCombat()) return "You're a tiny bit busy.";
  return 1;
}

mixed do_cook_obj(object corpse) {
  object who = this_player();
  who->AddStaminaPoints(-50);
  eventCook(corpse, who);
  return 1;
}
