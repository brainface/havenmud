/*  mix verb
 *  mixes a dying vat to a specific color
 *  currently just works and requires no
 *  skill or ingredients.
 */
#include <lib.h>
#include <std.h>
#include <daemons.h>
inherit LIB_VERB;

int eventMixDye(object vat, string color);

static void create() {
  ::create();
  SetVerb("mix");
  SetRules("OBJ to STR");
  SetErrorMessage("mix <dyeing vat> to <color>?");
  SetHelp(
    "Syntax:   mix vat to <color>\n"
    "Mixes the variety of herbal and alchemical ingredients\n"
    "inside a dyeing vat to a specific color. This currently \n"
    "works exactly as you intend and requires no ingredients,\n"
    "but may require some sort of alchemy in the future."
  );
}

mixed do_mix_obj_to_str(object vat, string color) {
  object who = this_player();
  string LIB_DYE = STD_CRAFTING + "clothing/include/dye";
  
  if (!LIB_DYE->GetLegalColor(color)) {
    who->eventPrint("You don't know how to mix that color. The possible hues are: ");
    who->eventPrint(conjunction(LIB_DYE->GetColors()));
    return 0;
  }

  who->AddStaminaPoints(-50);
  eventMixDye(vat, color);
  return 1;
}

mixed can_mix_obj_to_str() {
  object who = this_player();
  if (who->GetSleeping()) return "You dream of rainbows.";
  if (who->GetParalyzed()) return "You are paralyzed.";
  if (who->GetStaminaPoints() < 50) return "You are too tired.";
  if (who->GetInCombat()) return "You're in a very different sort of mix.";
  return 1;
}

int eventMixDye(object vat, string color) { 
  object who = this_player();
  send_messages("mix","$agent_name $agent_verb $target_name until the "
    "liquid inside reaches a solid " + color + " hue.",
    who, vat, environment(who));   
  vat->SetColor(color);
  return 1;
}
