#include <lib.h>
inherit LIB_VERB;

static void create() {
  ::create();
  SetVerb("debate");
  SetRules("LIV");
  SetHelp(
    "Syntax:  debate LIV\n\n"
    "Use this command to test your mettle in a debate against a targetted living thing. "
    "This command will help you determine who has a higher bargaining skill."
    );
  SetErrorMessage("You need to debate someone.");
}

mixed can_debate_liv() {
  object who = this_player();
  
  if (who->GetSleeping()) return "You mumble a great debate... in your dream.";
  if (who->GetParalyzed()) return "You are paralyzed and unable to move your mouth.";
  if (who->GetInCombat()) return "You are in combat and more worried about a different type of 'debate'.";
  return 1;
}

mixed do_debate_liv(object target) {
  object who = this_player();
  string result = 0;
  
  if (target->GetSkillLevel("bargaining") > who->GetSkillLevel("bargaining")) {
    result = "$target_name $target_verb to have done better in the arguement.";
  }
  if (target->GetSkillLevel("bargaining") < who->GetSkillLevel("bargaining")) {
    result = "$agent_name $agent_verb to have done better in the arguement.";
  }
  if (!result)
    result = "The debate seems evenly matched.";
  send_messages( ({ "begin" }),
    "$agent_name $agent_verb to engage $target_name in debate. ",
    who, target, environment(who));
  send_messages( ({ "have" }),
    "It seems $agent_name $agent_verb done better in the debate.",
    who, target, environment(who));
  return 1;
}
