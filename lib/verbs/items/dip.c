/*  dye verb
 *  dyes things for crafting
 */
#include <lib.h>
#include <std.h>
#include <daemons.h>
inherit LIB_VERB;

int eventDyeThing(object good, object vat, object who);

static void create() {
  ::create();
  SetVerb("dip");
  SetRules("OBJ in OBJ");
  SetErrorMessage("Dip <yarn/thread> in <vat>?");
  SetHelp(
    "Syntax:   dip thread/yarn into <vat>\n"
    "Attempts to dye thread or yarn in a dyeing vat.\n"
    "Fabric and finished clothing cannot be dyed--\n"
    "it's too late then!"
  );
}

mixed do_dip_obj_in_obj(object good, object vat) {
  object who = this_player();
  
  if ( !good->GetProperty("craft_thread") && !good->GetProperty("craft_yarn") ) {
    who->eventPrint("You can currently only dye thread or yarn.");
    return 0;
  }
  who->AddStaminaPoints(-50);
  eventDyeThing(good, vat, who);
  return 1;
}

mixed can_dip_obj_in_obj() {
  object who = this_player();
  if (who->GetSleeping())
    return "Some say if you dye while sleeping your life is color forever.";
  if (who->GetParalyzed()) return "You are paralyzed.";
  if (who->GetStaminaPoints() < 50) return "You are too tired.";
  if (who->GetInCombat()) return "You're already trying to make someone dye.";
  return 1;
}

int eventDyeThing(object good, object vat, object who) {
  string color = "";
  if (!vat->GetColor()) {
    who->eventPrint("Something's wrong with the vat. Please bug this!");
    return 0;
  }
 
  color = vat->GetColor();
  send_messages("dip","$agent_name $agent_verb " + good->GetShort() + " "
    "into " + vat->GetShort() + ", dyeing it " + color + ".",
    who, 0, environment(who));   
  good->SetCraftColors( ({color}) );
  // forces item to remake
  good->SetCraftResult();
  return 1;
}
