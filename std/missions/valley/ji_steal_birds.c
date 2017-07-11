/*
 * Bird Thief, Jidoor mission
 * player must go to yozrath and steal
 * the shiek's birds by capturing them
 * in a birdcage, then return to jidoor.
 * mahkefel 7/2010
 */

#include <lib.h>       
inherit LIB_MISSION;   

static void create() {
  ::create();         
  SetMissionName("Bird Thief");
  SetTown("Jidoor");           
  SetMissionDescription(       
    "You, you're the one that likes birds so much, right?"
    " I have another lesson for you. There's only so much"
    " we can learn about avians by examining the local fauna."
    " However, our scryers say the Sheik of Yozrath has assembled"
    " quite a group of birds in his palace aviary. Go there and"  
    " acquire as many as you can, and return them here. The city" 
    " is hidden somewhere in an oasis in the Yozrath Desert."     
    " Perhaps you could ask some nomads you see for"              
    " directions--some of them are known to help travellers."           
  );                                                                    
  SetMissionLevel(20, 500);                                              
  SetMissionPriority(90);                                               
  SetReward("10000 XP");                                                 
  SetTitle("the Thief of Wings");                                                
}                                                                                


int CheckCompletedMission(object who) {
  object *correctBirds = ({ });                           
  object *birds = ({ });                                  
  object *cage = ({ });                                   
  object *rumpel = ({ });                                 
  if (base_name(environment(who)) == "/domains/valley/towns/jidoor/room/twnsquare") {
    cage = filter(all_inventory(who), (: $1->GetKeyName() == "birdcage" :) );        
    rumpel = filter(all_inventory(environment(who)),                                 
      (: $1->GetKeyName() == "rumpel" :) );                                          
    if (sizeof(cage) < 1) return 0;                                                  
    if (sizeof(rumpel) < 1) return 0;                                                
    birds = cage[0]->GetCaptives();                                                  
    if (sizeof(birds) < 1) return 0;                                                 
    correctBirds = filter(birds,                                                     
      (: $1->GetKeyName() == "bustard" :) );                                         
    correctBirds += filter(birds,                                                    
      (: $1->GetKeyName() == "roller" :) );                                          
    correctBirds += filter(birds,                                                    
      (: $1->GetKeyName() == "waxbill" :) );                                         
    if (sizeof(correctBirds) < 1) return 0;                                          
    cage[0]->eventMove(rumpel[0]);                                                   
    //cage[0]->eventDest();Cage doesn't dest and I don't care.
    rumpel[0]->eventForce(
      "speak Excellent! Our scholars of natural philosophy will be pleased."
      " You should accept a small reward for your work. 2000 rupies for each"
      " living bird should be acceptable, I think."
    );
    rumpel[0]->eventForce("emote beams with pride.");
    who->eventPrint("You have returned from the desert with rare fauna!");
    who->eventPrint("You have been dubbed \"The Thief of Wings\" for your efforts.");
    who->AddExperience(1000);
    who->AddCurrency("rupies",2000*sizeof(correctBirds));
    return 1;
  }
  return 0;
}

void AssignMission(object who) {
  object cage = new("/std/mission_obj/birdcage");
  if (!cage->eventMove(who)) {
    cage->eventMove(who);
  }
  who->eventPrint("Rumpel hands you a gilded birdcage");
}

int CanGetMission(object who) {
  if (who->GetQuestCompleted("Bird Watcher")) {
    return 1;
  } else {
    return 0;
  }
}

