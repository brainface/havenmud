
#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Message Courier");
  SetTown("Haven");
  SetMissionDescription(
    "Ahh, good, you're back. While you were out, I received a "
    "letter from a student at the Great Library here in town. "
    "It seems she is very concerned for the safety of her brother "
    "who is in the service of Lord Beornwulf. As you may have "
    "heard, the Lord's keep is under siege by a host of orcs and "
    "unfortunately the fighting is getting very bloody. So, please "
    "take this letter and deliver it to the mage at Lord Beornwulf's "
    "keep. You will find the keep far west of town on the south "
    "side of the Haven Road." 
    );
  SetTitle("the Haven Town Runner");
  SetMissionLevel(0, 500);
  SetMissionPriority(90);
  SetReward("500 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  object *ball = ({ });
  if (base_name(environment(who)) == "/domains/southern_coast/areas/beornwulf_keep/room/library") {
    if (who->GetTestChar()) debug("base_name");
    count = sizeof(ball = filter(all_inventory(who), 
                     (: $1->GetShort() == "a letter" :) ));
    if (who->GetTestChar()) debug("count = " + count);
    if (count >= 1) {
      who->eventPrint("You have delivered a letter to the mage.");
      while(count) {
        ball[count -1]->eventDestruct();
        count--;
      }
      who->AddExperience(500);
      return 1;
    }
  }
  return 0;
}

void AssignMission(object who) {
     object ball = new("/std/mission_obj/gletter");
     if (!ball->eventMove(who)) {
       ball->eventMove(environment(who));
      }     
      who->eventPrint("Hustin gives you a letter for the human mage.");
}


int CanGetMission(object who) {
         if(who->GetQuestCompleted("Platypus Bay")) return 1;
  return 0;
}
