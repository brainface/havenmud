#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Bird Watcher");
  SetTown("Jidoor");
  SetMissionDescription(
    "There are many interesting creatures around Jidoor you won't"
    " learn about in a library! You should make a journey to the"
    " nearby canyon, there are many beautiful blue birds and hummingbirds"
    " there! Just follow the road south out of town, and travel east"
    " at the first opportunity."
    );
  SetTitle("the Bird Watcher");
  SetMissionLevel(0, 500);
  SetReward("500 XP");
}

int CheckCompletedMission(object who) {
  if (strsrch(base_name(environment(who)), "/domains/valley/areas/canyon/room/cliff_edge") != -1) {
     who->eventPrint("You have found the Jidoor Canyon. Congratulations!");

     who->AddExperience(500);
     return 1;
    }
  return 0;
}

int CanGetMission(object who) {
  //if(who->GetQuestCompleted("Ronin Camp")) return 1;
  return 1;
}
