#include <lib.h>
#include <daemons.h>
#include <domains.h>

inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Repel the Kylin Invaders");
  SetTown("Durgoroth");
  SetMissionDescription(
    "Those arrogants elves and their allies dare to invade my home in these "
    "ruins. I help release the daemons and they successfully killed the "
    "nosferatu and turned the city into ruins. Go into the Kylin's camp "
    "and kill at least ten of those invaders. Kill the Inquisitors, but "
    "if you need to kill the templars, monks, effigies or paladins that "
    "will help our cause.");
  SetMissionLevel(150, 500);
  SetMissionPriority(80);
  SetReward("1000000 XP");
}


int CheckCompletedMission(object who) {
 int total = 0;
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  
  total += kills[FROSTMARCHES_AREAS + "outpost/npc/dwarf_worker"];
  total += kills[FROSTMARCHES_AREAS + "outpost/npc/dwarf_paladin"];
  total += kills[FROSTMARCHES_AREAS + "outpost/npc/inquisitor"];
  total += kills[FROSTMARCHES_AREAS + "outpost/npc/inquisitor_offduty"];
  total += kills[FROSTMARCHES_AREAS + "outpost/npc/kylin_effigy"];
  total += kills[FROSTMARCHES_AREAS + "outpost/npc/orthodox_monk"];
  total += kills[FROSTMARCHES_AREAS + "outpost/npc/paladin"];

  if (total >= 10) {
    who->eventPrint("You have successfully disrupted the Kylin Inquisitor's invasion!");
    who->AddExperience(1000000);
    return 1;
  }
  return 0;
}


int CanGetMission(object who) {
  if (who->GetMorality() < -500)
     return 1;
  return 0;
}
