/* Malveillant Assassination Quest.
   Kairehn (12/28/2007) */
#include <lib.h>
inherit LIB_MISSION;
#include <domains.h>
#include <daemons.h>

static void create() {
  ::create();
  SetMissionName("Vermin Disposal");
  SetTown("Malveillant");
  SetMissionDescription(
    "Well, it seems you make a fine courier. Let's test some of your "
    "other skills though, shall we? It has been brought to the attention "
    "of my associates that a filthy beggar, known to some as Quintis, has "
    "been interfering with some of our affairs. This unwashed fool must be "
    "taught a harsh lesson, if you follow. I'll leave the method up to you, "
    "just don't get caught, and be sure to hide the corpse."    
    );  
  SetMissionLevel(20, 500);
  SetMissionPriority(58);
  SetReward("3000 roni");
}

int CheckCompletedMission(object who) { 
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  if (kills[PENINSULA_VIRTUAL + "npc/wandering_man"] >= 1)
  {
    who->eventPrint("Quintis lies dead. Your mission is complete.");    
    who->AddCurrency("roni", 3000);
    return 1;
  }
  return 0;
}

int CanGetMission(object who) {
  if (who->GetNationality() != "Malveillant") return 0;  
  return 1;
}
