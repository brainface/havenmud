/* Havenroad Bandit Quest
   Aerelus (12/07/2007) */
#include <lib.h>
#include <daemons.h>
#include <domains.h>
#include <std.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Havenroad Bandit");
  SetTown("Malveillant");
  SetMissionDescription(
    "This quest may put you in some danger, " 
    "but without risk, life would be boring, right?\n"
    "Certain individuals, who must remain nameless, "
    "I'm sure you understand, have requested that we "
    "shake up Haven Town's trade routes. Go to the Haven "
    "road, and kill at least 8 travellers. If you see any "
    "livestock, they can be disposed of also."
  );    
  SetTitle("the Havenroad Bandit");
  SetMissionLevel(10, 500);
  SetMissionPriority(80);
  SetReward("10000 XP");
}

int CheckCompletedMission(object who) {
  int total;
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  total = kills[STD_NPC + "traveller"] + kills[STD_NPC + "pig"];
  if (total >= 8) {
    who->eventPrint("You have successfully disrupted the Haven trade route!");
    who->AddExperience(10000);
  return 1;
  }
  return 0;
}

int CanGetMission(object who) {
  if((who->GetMorality() <= -1000)) {
    return 1;
  }
  return 0;
}
