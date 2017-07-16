#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Purification Part 2");
  SetTown("Tairi");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "Now that you've got a weapon capable of vanquishing"
    " the undead, go aid Mirogu at the Shrine of the"
    " Ancients. Kill at least 15 of the yurei that have"
    " returned to haunt the Shrine and you will be"
    " rewarded. You can track your kills using the <bio>"
    " command."
    );
  SetTitle("the Exorcist");
  SetMissionLevel(7, 500);
  SetMissionPriority(55);
  SetReward("50000 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  string CAMP = TAIRI_AREAS "shrine/npc/";
  foreach(string npc in get_dir(CAMP)) {
    npc = CAMP + npc[0..sizeof(npc)-3];
    if (kills[npc]) count += kills[npc];
    }
  if (count >= 15) {
    who->eventPrint("Now 15 of the yurei have been returned to the"
                    " spirit realm.");
    who->AddExperience(50000);
    return 1;
  }
  return 0;
}

int CanGetMission(object who) {
  if(who->GetQuestCompleted("Purifcation Part 1")) return 1;
  return 0;
}

int GetCount(object who) {
  int count = 0;
  string CAMP = TAIRI_AREAS "shrine/npc/";
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  foreach(string npc in get_dir(CAMP)) {
    npc = npc[0..sizeof(npc)-3];
    debug(npc);
    if (kills[CAMP + npc]) count += kills[CAMP + npc];
    }
  return count;
} 
