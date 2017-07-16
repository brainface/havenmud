/* Updated to include non-faith based religions
 * Taisoka and Eclat and Kylin Druids
 *  -Melchezidek 09 Aug 2008
 */

#include <lib.h>
#include <daemons.h>
inherit LIB_VERB;

static void create() {
  ::create();
  SetVerb("atone");
  SetRules( "" );
  SetHelp(
    "Syntax:   <atone>\n\n"
    "This allows a person of faith to atone for their wrongs "
    "and move his morality in a direction acceptable to his gods."
    );
}

mixed can_atone() {
  if ((this_player()->GetSkillLevel("faith") < 1) && 
    (this_player()->GetSkillLevel("natural magic") < 1)) {
        return "You lack the faith unto which you may atone.";
      }
  if (this_player()->GetMagicPoints() < 100) return "You lack the magical power right now.";
  if (this_player()->GetStaminaPoints() < 100) return "You are too tired to atone right now.";
  if (this_player()->GetSleeping() != 0) return "You cannot atone while sleeping!";
  if (this_player()->GetTestChar()) debug("Faith found, good to go");
  return 1;
}

int do_atone() {
  object who = this_player();
  string direction = MORALITY_D->GetReligionAlignment(who->GetReligion());
  string *message = ({ "atone", "$agent_name $agent_verb for $agent_possessive sins." });
  
  if (direction == "evil")
   send_messages(({"darken", "atone" }), "$agent_name%^BOLD%^BLACK%^ $agent_verb%^RESET%^ $agent_possessive soul and $agent_verb"
                                        " for all acts of goodness, charity, and mercy.", who, 0, environment(who));
  if (direction == "good")
    send_messages(({"atone", "beg" }), "$agent_name%^BOLD%^WHITE%^ $agent_verb%^RESET%^ for all malicious acts and humbly "
                                      "$agent_verb $agent_possessive god for forgiveness.", who, 0, environment(who));
                                      
 // send_messages(message[0], message[1], who, 0, environment(who));
  who->AddStaminaPoints(-100);
  who->AddMagicPoints(-100);
  switch(direction) {
    case "evil":
      who->eventMoralAct(-50);
      break;
    case "good":
      who->eventMoralAct(50);
      break;
    case "neutral":
      if (who->GetMorality() > 0) who->eventMoralAct(-50);
      if (who->GetMorality() < 0) who->eventMoralAct(50);
      break;
  }
  return 1;
}
