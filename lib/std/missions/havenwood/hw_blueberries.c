#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Blueberry Picker");
  SetTown("Havenwood");
  SetMissionDescription(
    "Our local provisioner, Fendell is looking for someone to "
    "gather some blueberries and blueberry leaves. Fendell "
    "heard that some blueberries are growing in a meadow along "
    "a hiking trail in the WestWood. The hiking trail is north "
    "of the Muezzin town of Soleil. Bring Fendell four handfuls "
    "of blueberries and four blueberry leaves."
    );
  SetTitle("the Blueberry Picker");
  SetMissionLevel(0,500);
  SetMissionPriority(75); 
  SetReward("500 XP");
}

int CheckCompletedMission(object who) {
  object *berries = ({ });
  object *leaves = ({ });
  object *fendell = ({ });
  int counta = 0;
  int countb = 0;
  if (base_name(environment(who)) == "/domains/havenwood/towns/havenwood/room/gelf8") {
    counta = sizeof(berries = filter(all_inventory(who), (: $1->GetKeyName() == "blueberries" :) ));
    countb = sizeof(leaves = filter(all_inventory(who), (: $1->GetKeyName() == "blueberry leaf" :) ));
    fendell = filter(all_inventory(environment(who)), (: $1->GetKeyName() == "fendell" :) );
    if (sizeof(berries) < 4) return 0;
    if (sizeof(leaves) < 4) return 0;
    if (sizeof(fendell) < 1) return 0;
    
    if (counta >= 4) {
        while(counta) {
        berries[counta -1]->eventDestruct();
        counta--;
      }}
      
      if (countb >= 4) {
        while(countb) {
        leaves[countb -1]->eventDestruct();
        countb--;
      }}

    fendell[0]->eventForce("speak Thank you! Soon enough I will be able sell "
    											 "blueberry salads");
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
