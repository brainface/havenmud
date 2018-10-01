/* Malveillant Visit Keryth Quest   
   Kairehn (12/28/2007) */
#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Hunting Grounds");
  SetTown("Malveillant");
  SetMissionDescription(
    "Good work, my associates are pleased. As it happens, I have some "
    "more work for you. Have you heard of a place named Keryth? We "
    "have learned that they share many of our ideals, and are in the "
    "process of determining whether we should begin operating in the "
    "area. Our knowledge of the Frostmarches is slim, though the daemons "
    "and other less civilized creatures that inhabit it are known to "
    "be unpredictable. So, with that in mind, we would like you to test "
    "the water, as it were. If you make it to Keryth alive, report back "
    "to me for another assignment. Uh.. you may wish to pack a warm coat."
    );  
  SetMissionLevel(25, 500);
  SetMissionPriority(57);
  SetReward("10000 XP");
}

int CheckCompletedMission(object who) {  
  if (strsrch(base_name(environment(who)), "/domains/frostmarches/towns/keryth") != -1) {
     who->eventPrint("You have made the journey to Keryth without freezing.");          
     who->AddExperience(10000);
     return 1;
  }
}

int CanGetMission(object who) {
  if (who->GetNationality() != "Malveillant") return 0;  
  return 1;
}
