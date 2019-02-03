/* Quests Command */
#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
        object who = this_player();

        if (creatorp(who)) {
                if (!args) {
                        who->eventPrint("Lists the quests of whom?");
                        return 1;
                }
                if (!(who = find_player(args))) {
                        this_player()->eventPrint("Unable to find such a person.");
                        return 1;
                }
        }
  if (creatorp(who)) {
    this_player()->eventPrint("Immortals don't go on quests.");
    return 1;
  }
  if (who->GetProperty("mission")) {
      MISSION_D->CheckMission(who, who->GetProperty("mission"));
    }
  if (!sizeof(who->GetQuests()))  {
    this_player()->eventPrint((creatorp(this_player()) ? capitalize(args) + " has " : "You have ") + "not completed any quests.");
  } else {
          this_player()->eventPrint(sprintf("%-20s %s", "Quest", "Completed Mud Date"));
          foreach(mixed *quest in who->GetQuests()) {
                  this_player()->eventPrint(sprintf("%-20s %s", quest[1], mtime(quest[0])));
          }
        }
  if (who->GetProperty("mission")) {
    object m = load_object(who->GetProperty("mission"));
    if (m) {
     this_player()->eventPrint("Your assigned quest is: \n" + m->GetMissionDescription());
    }
  } else {
    this_player()->eventPrint("You currently have no assigned quest.");
  }
        return 1;
}

string GetHelp(string blah) {
  if( creatorp(this_player()) )
    return "Syntax: <quests [player]>\n\n"
           "This command will list all quests completed by the named player.\n"
           "stop questing is the syntax to make a player fix their dumb quest.";
  else
    return "Syntax: <quests>\n\n"
           "This command will display a list of all quests that you have completed.\n"
           "Quests can be received by <ask>ing a quest giver (such as Hustin near "
           "Haven Town). Quests are completed by following the instructions given "
           "in the Quest.  Please note that the game will not recognize that you "
           "have completed your quest until the next \"game turn\" for you. If "
           "you feel you have completed your quest, simply wait a moment, or type "
           "<score> to check your progress.\n"
           "If you lose a quest item, \"stop questing\" to drop your current "
           "quest, then talk to the quest giver again."
           ;
}

