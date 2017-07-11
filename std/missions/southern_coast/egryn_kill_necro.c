#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Lich Killer");
  SetTown("Haven");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "For this task, you must investigate the mysterious tower "
    "that formed in the Estergrym Mountains. We have reports that "
    "this particular mage has a Daemonic guardian and can raise "
    "corpses of undead from the ground. Be careful, this Lich "
    "is no mortal being to trifle with."
    );
  SetTitle("the Scourge of the Necromancers");
  SetMissionLevel(75, 150);  //Duuk said 150 max due to higher player cap
  SetMissionPriority(65);
  SetReward("165000 XP");
}

int CheckCompletedMission(object who) {
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  if (kills[ESTERGRYM_AREAS  "tower/npc/necromancer"]) {
    who->eventPrint("You have slain the evil Lich.");
    who->AddExperience(165000);
    return 1;
  }
  return 0;
}