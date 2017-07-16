#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Centaur Hunting");
  SetTown("Parva");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "I have been told of a mythical being within the"
    " HavenWood. The Golden Hind is supposedly a centaur"
    " with a golden coat. Seek out and find this"
    " Golden Hind and bring me the pelt and you shall"
    " be rewarded."
    );
  SetTitle("the Centaur Hunter");
  SetMissionLevel(40, 500);
  SetMissionPriority(75);
  SetReward("250000 XP");
}


int CheckCompletedMission(object who) {
 mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
 int count = 0;
 object *pelt = ({ });
 count = sizeof(pelt = filter(all_inventory(who), (: $1->GetShort() == "the golden hind's pelt" :) ));

if (base_name(environment(who)) == "/domains/havenwood/towns/parva/room/path2") {
if (count >= 1) {
     if (kills[HAVENWOOD_AREAS "wood/npc/tarandus"] >= 1) {
      who->eventPrint("You have slain the Golden Hind!!");
      who->AddExperience(250000);
      while(count) {
      pelt[count -1]->eventDestruct();
      count--;
      }
  return 1;
  }
 return 0;
  }
 }
}

int CanGetMission(object who) {
  if(who->GetQuestCompleted("Organ Delivery") &&
     (who->GetMorality() < -1000)) return 1;
  return 0;
}
