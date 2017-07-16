#include <lib.h>
#include <daemons.h>
#include <domains.h>
#include <std.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Singers of Song");
  SetTown("Karak");
  SetMissionDescription(
    "Elves and humans love their music. It hurts my ears! "
    "Find some minstrels and kill them. Make sure "
    "I cannot hear their music. Kill four minstrels "
    "along the road to Haven town. Sometimes they "
    "wander away from that road and head to other towns. "
    "Make Pranak's ears feel better. Now go and kill "
    "some minstrels."
    );
  SetTitle("the Silencer of Songs");
  SetMissionLevel(8, 500);
  SetMissionPriority(50);
  SetReward("10000 XP");
}


int CheckCompletedMission(object who) {
 mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
 if (kills[STD_NPC + "minstrel"] >= 4) {
    who->eventPrint("You have silenced the minstrels!");
    who->AddExperience(10000);
  return 1;
  }
 return 0;
}


int CanGetMission(object who) {
  if(who->GetMorality() < -999) return 1;
  return 0;
}
