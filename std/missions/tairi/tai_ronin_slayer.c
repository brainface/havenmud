


#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Ronin Slayer");
  SetTown("Tairi");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "For this quest, you must enter the Ronin camp and slay "
    "5 of those within. This quest allows you to choose your "
    "foes though, so choose wisely. Any creatures within the "
    "camp will count towards your total. You can track your "
    "kills using the <bio> command."
    );
  SetTitle("the Ronin Slayer");
  SetMissionLevel(0, 500);
  SetMissionPriority(55);
  SetReward("1000 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  string CAMP = TAIRI_AREAS "camp/npc/";
  foreach(string npc in get_dir(CAMP)) {
    npc = CAMP + npc[0..sizeof(npc)-3];
    if (kills[npc]) count += kills[npc];
    }
  if (count >= 5) {
    who->eventPrint("You have slain at least 5 of the Ronin Camp denizens.");
    who->AddExperience(1000);
    return 1;
  }
  return 0;
}

int CanGetMission(object who) {
  if(who->GetQuestCompleted("Cherry Blossom")) return 1;
  return 0;
}

int GetCount(object who) {
  int count = 0;
  string CAMP = TAIRI_AREAS "camp/npc/";
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  foreach(string npc in get_dir(CAMP)) {
    npc = npc[0..sizeof(npc)-3];
    debug(npc);
    if (kills[CAMP + npc]) count += kills[CAMP + npc];
    }
  return count;
} 
