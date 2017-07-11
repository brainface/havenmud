/*
 * reroll.c
 * 
 */

int CanReroll(object who);

mixed cmd() {
  object who = this_player();

  if (creatorp(who)) return "Can't roll a joint correctly the first time eh?";

  if (CanReroll(who)) {
    who->SetRace(who->GetRace());
    who->eventPrint("Yeehaw!  Your stats have been rerolled!");
    who->eventForce("stats");
    return 1;
  }
  else return "You can not reroll.";
}

int CanReroll(object who) {
  if (sizeof(who->GetSkills())) {
    who->eventPrint("You may not reroll once you have started playing.");
    return 0;
    }
  return 1;
}

string GetHelp() {
  return "Syntax:  \"reroll\"\n\n"
         "Reroll your character's stats.  This can only be done before you "
         "select a class.";
}
