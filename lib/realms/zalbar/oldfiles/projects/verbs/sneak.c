#include <lib.h>
inherit LIB_VERB;

static void create() {
  verb::create();
  SetVerb("sneak");
  SetRules("WRD");
  SetErrorMessage("Sneak where?");
  SetHelp(
    "Syntax: <sneak [direction]>\n\n"
    "Allows a living creature to move in a given direction, "
    "attempting to be unseen by local living creatures (e.g. "
    "others in the room). In order to make the use of <sneak> "
    "realistic, it works as it would in real life. That is, you will not know "
    "if you have succeeded until you see if others in the room notice "
    "you. Obviously your chances of success increase with increased "
    "skill."
  );
}

mixed can_sneak_wrd(string args) {
  if (this_player()->GetSleeping()) return "You are asleep!";
  if (this_player()->GetStaminaPoints() < 10)
      return "You are too tired.";
  if (this_player()->GetParalyzed()) {
      return "You cannot move!";
      }
  if (this_player()->GetInCombat()) {
    return "Difficult to sneak out while in combat, yes?";
    }
  if (!(environment(this_player())->GetExit(args))) {
     return "You cannot sneak in that direction.";
     }
  return (mixed)environment(this_player())->CanGo(this_player(), args);
  }

mixed do_sneak_wrd(string dir) {
  string dest, imsg;
  int chance, livs, flag;
  livs = 0;
  imsg = this_player()->GetMessage("come");
  dest = environment(this_player())->GetExit(dir);
  chance = this_player()->GetSkillLevel("stealth");
  foreach(object thing in all_inventory(environment(this_player()))) {
    if (living(thing) && thing != this_player()) livs += thing->GetStatLevel("wisdom");
  }
  if (random(chance) >= (livs)) {
    if (!(this_player()->GetInvis())) {
      flag = 1;
      this_player()->SetInvis(1);
    }
  }
  environment(this_player())->eventGo(this_player(), dir);
  if (flag) this_player()->SetInvis(0);
  return 1;
}
