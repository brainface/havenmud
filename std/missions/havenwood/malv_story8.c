/* Malveillant Assassination Quest.
   Kairehn (12/28/2007) */
#include <lib.h>
inherit LIB_MISSION;
#include <domains.h>
#include <daemons.h>

static void create() {
  ::create();
  SetMissionName("Roses for the Dead 2");
  SetTown("Malveillant");
  SetMissionDescription(
    "Excellent work, my friend. Now, this next assignment may put you "
    "in extreme danger. I trust you can handle it. Brook of the Divine "
    "Chalice has yet to remove our competitors that frequent her tavern. "
    "Remove her from existence, please. Be warned, the Haven guards are "
    "extremely well trained, and will cut you down if they spot you "
    "attacking her. Use caution, move unseen. Good luck."    
    );  
  SetMissionLevel(45, 500);
  SetMissionPriority(53);
  SetReward("100000 roni");
  SetTitle("the Malveillant Executor");
}

int CheckCompletedMission(object who) { 
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  if (kills[SOUTHERN_COAST_TOWNS + "haven/npc/brook"] >= 1)
  {
    who->eventPrint("Brook lies dead. Your mission is complete.");
    who->AddCurrency("roni", 100000);
    return 1;
  }
  return 0;
}

int CanGetMission(object who) {
  if (who->GetNationality() != "Malveillant") return 0;  
  return 1;
}
