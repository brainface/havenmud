/* Malveillant Assassination Quest.
   Kairehn (12/28/2007) */
#include <lib.h>
inherit LIB_MISSION;
#include <domains.h>
#include <daemons.h>

static void create() {
  ::create();
  SetMissionName("Roses for the Dead 1");
  SetTown("Malveillant");
  SetMissionDescription(
    "I trust you enjoyed your last assignment? Now, time for something a "
    "little more sinister. Remember Raspina? She still undercuts our "
    "gem prices, despite our little warning. Go back to Sulumus and cut her "
    "throat. If you get any trouble from the guards, don't hold back. We must "
    "send these people a clear message."
    );
  SetMissionLevel(40, 500);
  SetMissionPriority(54);
  SetReward("50000 roni");
}

int CheckCompletedMission(object who) { 
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  if (kills[PENINSULA_AREAS + "sulumus/npc/jeweler"] >= 1)
  {
    who->eventPrint("Raspina lies dead. Your mission is complete.");
    who->AddCurrency("roni", 50000);
    return 1;
  }
  return 0;
}

int CanGetMission(object who) {
  if (who->GetNationality() != "Malveillant") return 0;  
  return 1;
}
