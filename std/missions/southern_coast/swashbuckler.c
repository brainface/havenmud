#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Swashbuckling");
  SetTown("Haven");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "The pirates hiding in the cove near Haven have been raiding of late. "
    "Track them to their ship anchored west of Haven Town and put a dent "
    "in their ranks. Slay 10 pirates (including the Captain) to complete "
    "this mission. Track your kills using the <bio> command."
    );
  SetTitle("the Swashbuckler");
  SetMissionLevel(25, 500);
  SetMissionPriority(55);
  SetReward("100000 XP");
}

int CheckCompletedMission(object who) {
  int count = 0, captain = 0;
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  string CAMP = SOUTHERN_COAST_AREAS "acove/npc/";
  foreach(string npc in get_dir(CAMP)) {
    npc = CAMP + npc[0..sizeof(npc)-3];
    if (kills[npc]) count += kills[npc];
    }
  if (kills[CAMP + "captain"] >= 1) captain = 1;
  if (who->GetTestChar()) debug("count : " + count + " captain = " + captain);
  if (count >= 10 && captain) {
    who->eventPrint("You have put a dent in the Pirate Life.");
    who->AddExperience(100000);
    return 1;
  }
  return 0;
}

int CanGetMission(object who) {
  if(who->GetMorality() > 500) return 1;
  return 0;
}