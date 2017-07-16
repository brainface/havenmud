/*  Skin verb
 *  Helps noobs make money
 */
#include <lib.h>
#include <std.h>
#include <daemons.h>
inherit LIB_VERB;

static void create() {
  ::create();
  SetVerb("skin");
  SetRules("OBJ");
  SetErrorMessage("Skin what?");
  SetHelp("Syntax:   skin <corpse>\n\n"
          "Attempts to create a sellable pelt from an animal corpse.\n"
          "Can be used by anyone, but is more effective with skinning skill."
          );
}

int eventSkin(object corpse, object who) {
  object skin = new(STD_OBJ + "skin");
  string adj;
  int lvl;
  if (!skin) {
    debug("Failed to create skin");
    return -1;
  }
  switch(lvl = who->GetSkillLevel("skinning")) {
    case 1..4:
      adj = "roughly";
      skin->SetPeltClass(5);
      break;
    case 5..20:
      adj = "carefully";
      skin->SetPeltClass(15);
      break;
    case 21..50:
      adj = "quickly";
      skin->SetPeltClass(25);
      break;
    case 51..150:
      adj = "skillfully";
      skin->SetPeltClass(35);
      break;
    case 151..300:
      adj = "deftly";
      skin->SetPeltClass(60);
      break;
    case 301..10000:
      adj = "flawlessly";
      skin->SetPeltClass(100);
      break;
    default:
      adj = "crudely";
      break;
    }
  send_messages( ({ "skin" }),
    "$agent_name " + adj + " $agent_verb $target_name.", who, corpse, environment(who));
  skin->SetPeltSource(corpse->GetRace());
  skin->SetPeltLevel(corpse->GetLevel());
  corpse->eventDestruct();
  if (who->CanCarry(skin->GetMass())) {
    skin->eventMove(who);
  } else {
    skin->eventMove(environment(who));
    who->eventPrint("The skin is too heavy for you to carry right now.");
  }
  skin->SetPelt();
}

mixed can_skin_obj() {
  object who = this_player();
  if (who->GetSleeping())  return "You dream of skinning a corpse.  Sicko.";
  if (who->GetParalyzed()) return "You are paralyzed.";
  if (who->GetStaminaPoints() < 50) return "You are too tired.";
  if (who->GetInCombat()) return "You're a tiny bit busy worrying about your own skin.";
  return 1;
}

mixed do_skin_obj(object corpse) {
  object who = this_player();
  who->AddStaminaPoints(-50);
  eventSkin(corpse, who);
  return 1;
}