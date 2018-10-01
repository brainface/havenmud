/*  Spin verb
 *  Spins thread from mats
 */
#include <lib.h>
#include <std.h>
#include <daemons.h>
inherit LIB_VERB;

static void create() {
  ::create();
  SetVerb("spin");
  SetRules("STR with OBJ");
  SetErrorMessage("Spin <yarn/thread> with <wheel>?");
  SetHelp(
    "Syntax:   spin thread with <wheel>\n"
    "          spin yarn with <wheel>\n"
    "Attempts to make thread from a fiberous material.\n"
    "Farmed cotton, hemp, and flax can all be spun \n"
    "into thread, as well as refined mithril ingots.\n"
    "You must attach the material to be spun to a spinning wheel.\n"
    "You need to know how to work the relevant textiles or mithril.\n"
  );
}

int eventSpinThread(string good, object wheel, object who) {
    object thread;
  string adj;
  object material = 0;
  int lvl = 0;  
  
  foreach(object thing in all_inventory(wheel)) {
    if (thing->GetProperty("craft_fiber")) {
      material = thing;
    }
  }
  
  if (!material) {
    who->eventPrint("But there's nothing to spin on the wheel!");
    who->eventPrint("(Try attaching farmed cotton, hemp, flax, or a mithril "
      "ingot to the wheel.)");
    return 0;
  }
  


  if (good == "thread") {
    thread = new(STD_CRAFTING + "clothing/thread");
  } else if (good == "yarn") {
    thread = new(STD_CRAFTING + "clothing/yarn");    
  }
  
  if (!thread) {
    debug("Failed to create thread");
    return -1;
  }

  if (!material->GetMaterials() || !sizeof(material->GetMaterials()) ) {
    debug("Bad sewing mat: " + material->GetShort());
    return -1;  
  }
  
  // for each type of material in the material, test the player's relevant skill.
  foreach(string mat_type in material->GetMaterials() ){
    lvl += who->eventCheckSkill(mat_type + " working",10,who->GetLuck(),0);  
  }
  lvl /= sizeof(material->GetMaterials());
  lvl /= 2; // skill #s are double player level #s.
  
  // failed the skill check.
  if (lvl < 1) {
   send_messages("ruin","$agent_name $agent_verb $target_name", 
    who, material, environment(who));
   material->eventDest();
   return 0;
  }
  
  switch(lvl) {
    case 1..4:
      adj = "roughly";
      break;
    case 5..20:
      adj = "carefully";
      break;
    case 21..50:
      adj = "quickly";
      break;
    case 51..150:
      adj = "skillfully";
      break;
    case 151..300:
      adj = "deftly";
      break;
    case 301..10000:
      adj = "flawlessly";
      break;
    default:
      adj = "crudely";
      break;
    }
  thread->SetLevel(lvl);  
  send_messages( ({ "spin" }),
    "$agent_name " + adj + " $agent_verb $target_name into " + good, 
    who, material, environment(who));
  thread->SetCraftMaterials(material->GetMaterials());
  // use the first word in mat for source, i.e. "mithril ingot" -> "mithril"
  thread->SetCraftSources( ({ explode(material->GetKeyName()," ")[0] }) );
  material->eventDestruct();
  if (who->CanCarry(thread->GetMass())) {
    thread->eventMove(who);
  } else {
    thread->eventMove(environment(who));
    who->eventPrint("The thread is too heavy for you to carry right now.");
  }
  thread->SetCraftResult();
}

mixed can_spin_str_with_obj() {
  object who = this_player();
  if (who->GetSleeping())  return "You spin wildly in your dreams.";
  if (who->GetParalyzed()) return "You are paralyzed.";
  if (who->GetStaminaPoints() < 50) return "You are too tired.";
  if (who->GetInCombat()) return "There's no good way to spin this.";
  return 1;
}

mixed do_spin_str_with_obj(string good, object wheel) {
  object who = this_player();
  
  if (good != "thread" && good != "yarn") {
  who->eventPrint("You can only spin thread or yarn.");
  return 0;
  }
  who->AddStaminaPoints(-50);
  eventSpinThread(good, wheel, who);
  return 1;
}

