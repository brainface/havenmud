#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Treasure Hunting pt 1");
  SetTown("TreasureHunter");
  SetMissionDescription(
    "So, ye want to make a name for yerself, hmm? I suppose"
    " I can help you with that. Not so long ago, a young"
    " half-elf was in here, see, and he was looking mighty"
    " worried. He came to me and gave me this map, see. But"
    " he disappeared before I could find out what the map"
    " lead to. Given what the lad was wearing though, I'm"
    " assuming whatever it was, had to be pretty valuable."
    " So, here ye go. Go find the treasure and reap the"
    " rewards! Don't forget your shovel!");
  SetMissionLevel(10, 500);
  SetReward("10000 XP");
  SetMissionPriority(90);
  }
 
int CheckCompletedMission(object who) {
    if (who->GetProperty("Treasure1") == 1) {
     who->RemoveProperty("Treasure1");
     who->eventPrint("You have found the treasure!");
     who->AddExperience(10000);
     return 1;
     }
   return 0;
 }
 
void AssignMission(object who) {
   object map = new("/std/mission_obj/treasure/map1.c");
     if (!map->eventMove(who)) {
       map->eventMove(environment(who));
      }  
      who->eventPrint("Fernando Cortez hands you an old map.");
 }

int CanGetMission(object who) {
  return 1;
 }

