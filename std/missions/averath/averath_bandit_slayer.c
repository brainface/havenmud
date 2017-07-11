#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Bandit Routing");
  SetTown("Averath");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "The Guards have received word of a bandit"
    " hideout in the sewers, but they are unable"
    " to rout them. Go down and kill at least 7"
    " bandits in the sewers to receive your reward."
    );
  SetTitle("the Subterranean Bandit Basher");
  SetMissionLevel(15, 50);
  SetMissionPriority(70);
  SetReward("45000 XP");
}


int CheckCompletedMission(object who) {
 int tot;
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  tot = (kills["/domains/averath/areas/sewers/npc/bandit"]) + 
        (kills["/domains/averath/areas/sewers/npc/bandit2"]) + 
        (kills["/domains/averath/areas/sewers/npc/bandit3"]);
  if (tot >= 7) {
  who->eventPrint("You have killed the bandits in the sewers!");
  who->AddExperience(45000);
  return 1;
  }
 return 0;
}

int CanGetMission(object who) {
  return 1;
}
