#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Purification Part 1");
  SetTown("Tairi");
  SetMissionDescription(
    "There is a story of a Shrine to the south of the city"
    " that has been over run with ghosts. Go visit the hermit"
    " Yoshitaka at the base of Shatadru Mountain and purchase"
    " a weapon capable of dealing damage to undead creatures."
    " Take this money to aid in the purchase of the weapon."
    );
//  SetTitle("");
  SetMissionLevel(7, 500);
  SetReward("1000 XP");
}

int CheckCompletedMission(object who) {
  if (strsrch(base_name(environment(who)), 
        "/domains/tairi/areas/hermitage/room/vault.c") != -1) {
     who->eventPrint("You have found Yoshimitsu's Hermitage! Now Purchase"
                     " a weapon from him.");

     who->AddExperience(1000);
     return 1;
    }
  return 0;
}

void AssignMission(object who) {
     who->AddCurrency("koken", 1000);
}
    

int CanGetMission(object who) {
  if(who->GetQuestCompleted("Ronin Slayer")) return 1;
  return 0;
}
