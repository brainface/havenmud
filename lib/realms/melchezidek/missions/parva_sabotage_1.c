#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Sabotage pt 1");
  SetTown("Parva");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "Ah hah! A street urchin. Excellent. Word has"
    " been recieved that the humans in Lord Beornwulf's"
    " keep are getting short on food. If you were to,"
    " I don't know, kill off the animals within the"
    " keep, perhaps the siege would end. Kill one"
    " cow and one sheep and you will be rewarded."
    );
  SetTitle("the Initiate of Sabotage");
  SetMissionLevel(1, 24);
  SetMissionPriority(99);
  SetReward("1000 XP");
}


int CheckCompletedMission(object who) {
 int sheep = 0, cow = 0;
 mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
 if (kills[SOUTHERN_COAST_AREAS "beornwulf_keep/npc/cow"]) cow = 1;
 if (kills[SOUTHERN_COAST_AREAS "beornwulf_keep/npc/sheep"]) sheep = 1;
 if(sheep >= 1 && cow >= 1) {
    who->eventPrint("You have destroyed the food supply in the Keep!");
    who->AddExperience(1000);
  return 1;
  }
 return 0;
}


int CanGetMission(object who) {
  if((who->GetMorality() < -20) && (who->GetNationality() != "Haven")) return 1;
  return 0;
}



