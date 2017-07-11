#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Rabbit Food");
  SetTown("Havenwood");
  SetMissionDescription(
    "Ah hah hah hah. I see you want to do something. Good"
    " good. It just so happens that I'm quite hungry for"
    " some rabbit meat. So, your first test and duty, my friend"
    " is to go and fetch some rabbit meat for me. Surely you"
    " can find a rabbit somewhere here in the Havenwood."
    );
  SetMissionLevel(0,500);
  SetMissionPriority(90);
  SetReward("500 XP");
}

int CheckCompletedMission(object who) {
  object *meat = ({ });
  object *tyvalt = ({ });
  if (base_name(environment(who)) == "/domains/havenwood/towns/havenwood/room/gelf1") {
    meat = filter(all_inventory(who), (: $1->GetKeyName() == "rabbit meat" :) );
    tyvalt = filter(all_inventory(environment(who)), (: $1->GetKeyName() == "tyvalt" :) );
    if (sizeof(meat) < 1) return 0;
    if (sizeof(tyvalt) < 1) return 0;
    

    meat[0]->eventDestruct();
    tyvalt[0]->eventForce("speak Woo! Fantastic! Thank you!");
    tyvalt[0]->eventForce("emote devours a bit of rabbit meat.");
    who->eventPrint("You have returned with Tyvalt's lunch!");
    who->AddExperience(500);
    return 1;
    }
    return 0;
 }

void AssignMission(object who) {

}
int CanGetMission(object who) {
    return 1;
}
