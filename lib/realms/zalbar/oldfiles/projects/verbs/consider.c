#include <lib.h>

inherit LIB_VERB;

static void create() {
  ::create();
  SetVerb("consider");
  SetRules("LIV");
  SetErrorMessage("You consider your place in the world.  Zen.");
  SetHelp(
    "Syntax:     consider <living>\n\n"
    "Use of this verb allows you to consider the relative difficulty "
    "you would have in physically assaulting another living creature. "
    "While this may sound like a fine way to find a date for a Freeday "
    "evening, it does NOT take certain abilities (like fireballs and "
    "touch of death spells) into account. This may cause some difficulty, "
    "so it is still wisest to examine your opponents very carefully."
  );
}

mixed can_consider_liv() {
  if (this_player()->GetSleeping()) {
    return "In a pleasant dream, you can beat anyone.";
  }
  return 1;
}

mixed do_consider_liv(object target) {
  object who = this_player();
  object winner, loser;
  int MyScore     = 0;
  int TargetScore = 0; 
  float comparison;
  string *msg = ({ });

  send_messages( ({ "look" }),
    "$agent_name $agent_verb over $target_name in consideration.",
    who, target, environment(who) );

  MyScore     = who->GetLevel();
  TargetScore = target->GetLevel();
  if (MyScore > TargetScore) { winner = who; loser = target; } else { winner = target; loser = who; }
  comparison = (winner->GetLevel() * 1.0) / (loser->GetLevel() || 1);
  
  MyScore = to_int(comparison * 100) - 100;
  if (who->GetTestChar()) debug(who->GetCapName() + " " + target->GetCapName() + " " + MyScore + "%/ " + comparison);
  /* Start at 10x or greater */
  msg = ({ "have", "$target_name $target_verb no hope.  None." });
  if (comparison  < 10.0) 
    msg = ({ "", "$agent_possessive_noun vastly superior combat skills will be too much "
                 "for $target_name to overcome." });
  if (comparison < 8.0) 
    msg = ({ "give", "Courtesy would dictate that $agent_name $agent_verb $target_name "
                    "a moment to collect $target_possessive thoughts before dispatching $target_objective." });
  if (comparison < 5.0)
    msg = ({ "", "Fighting $target_name would be a waste of $agent_possessive_noun time and attention." });
  if (comparison < 3.0)
    msg = ({ "are", "If $agent_name $agent_verb looking for someone to bully, $target_name could be just right!" });
  if (comparison < 2.0)
    msg = ({ "get", "$target_name would be in trouble if $agent_name $agent_verb angry." });
  if (comparison < 1.5)
    msg = ({ "", "Parvan oddsmakers will wager heavily on $agent_name winning against $target_name." });
  if (comparison < 1.3)
    msg = ({ "", "$agent_name should emerge bruised but victorious over $target_name." });
  if (comparison < 1.2)
    msg = ({ "have", "$agent_name $agent_verb the edge in a battle with $target_name." });
  if (comparison < 1.1)
    msg = ({ "seem", "$agent_name $agent_verb to be very comparable to $target_name." });
  if (comparison < 1.0)
    msg = ({ "are", "$agent_name $agent_verb unable to make a firm comparison with $target_name." });
  send_messages(msg[0], msg[1] + " (" + winner->GetCapName() + " is favored by " + (MyScore > 100 ? "Over 100" : MyScore) + "%)", winner, loser, 0);
  return 1;
}
