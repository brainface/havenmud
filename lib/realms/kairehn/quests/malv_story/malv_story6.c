/* Malveillant Whore Quest   
   Kairehn (12/28/2007) */
#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Negotiable Affection");
  SetTown("Malveillant");
  SetMissionDescription(
    "Well, that didn't go so well. Raspina will have to be taken care of "
    "some time soon. But first, I have a slightly more pleasant assignment "
    "for you. Aria Lanthria, a woman of negotiable affection working out of "
    "Parva, has been lately complaining about a lack of business. What she "
    "really needs is a confidence boost to get her back on track. I want "
    "you to head on over there, and ask her for some service. You'd best "
    "bring some money, she only accepts Shrydes. Have fun!"    
    );  
  SetMissionLevel(35, 500);
  SetMissionPriority(55);
  SetReward("5000 XP");
}

int CheckCompletedMission(object who) {  
  if (who->GetProperty("whoremolester"))
  {
    who->eventPrint("You have successfully boosted Aria's confidence!");
    who->AddExperience(5000);
    return 1;
  }
  return 0;
}

int CanGetMission(object who) {
  if (who->GetNationality() != "Malveillant") return 0;  
  return 1;
}
