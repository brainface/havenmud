#include <lib.h>
#include <daemons.h>
#include <domains.h>

inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Kill the Kylin Leaders");
  SetTown("Durgoroth");
  SetMissionDescription(
    "Taigis be praised. You have brought chaos to the light. The leaders "
    "within the Kylin outpost are trying to heal the wounded and "
    "resurrect the dead. They must not be able to regroup their forces! "
    "Go back into that camp and kill the leaders!" );
  SetTitle("a Scion of Taigis");
  SetMissionLevel(175, 500);
  SetMissionPriority(80);
  SetReward("1500000 XP");
}


int CheckCompletedMission(object who) {
 int total = 0;
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  total += kills[FROSTMARCHES_AREAS + "outpost/npc/archdeacon_monk"];
  total += kills[FROSTMARCHES_AREAS + "outpost/npc/dwarf_commander"];
  total += kills[FROSTMARCHES_AREAS + "outpost/npc/gm_inquisitor"];
  if (total >= 3) {
    who->eventPrint("You have successfully disrupted the Kylin Inquisitor's invasion!");
    who->AddExperience(1500000);
  return 1;
  }
  return 0;
}


int CanGetMission(object who) {
  if(who->GetQuestCompleted("Repel the Kylin Invaders")) {
    if(who->GetMorality() < -500)
      return 1;
    }
  return 0;
}
