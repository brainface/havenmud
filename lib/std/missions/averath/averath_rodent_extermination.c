#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Rodent Extermination");
  SetTown("Averath");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "Felix Monteil has been complaining for weeks"
    " about how many rats are invading his storage"
    " room in the tavern. He says that the rats are"
    " coming up from the sewers and are leaving"
    " feces everywhere in addition to ruining whole"
    " bags of grain. Go into the sewers and kill"
    " at least five rats so that Felix will stop"
    " complaining."
    );
  SetTitle("the Rodent Exterminator");
  SetMissionLevel(1, 500);
  SetMissionPriority(90);
  SetReward("500 XP");
}


int CheckCompletedMission(object who) {
 mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
 if (kills[AVERATH_AREAS "sewers/npc/rat"] >= 5) {
    who->eventPrint("You have relieved Felix' headache by killing 5 rats!");
    who->AddExperience(500);
  return 1;
  }
 return 0;
}


int CanGetMission(object who) {
  return 1;
}
