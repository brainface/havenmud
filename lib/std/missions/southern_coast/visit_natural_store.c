#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Talamar's Talented Taxidermy");
  SetTown("Haven");
  SetMissionDescription(
    "I would be remiss if I allowed you to endanger yourself further without "
    "informing you of this trade of our lost kin. There is a... taxidermist "
    "and half-kin leatherworker who run a shop between Havenwood and Parva. "
    "You may find armour there more to your suiting. You'll need to travel "
    "west out of town, northeast at the crossroads and then east through the "
    "town of Havenwood. You'll find it on the road just outside of the "
    "wild-elf town." 
    );
  SetTitle("the Hidebound");
  SetMissionLevel(5,500);
  SetMissionPriority(100);
  SetReward("1500 XP");
}

int CheckCompletedMission(object who) {
  if (strsrch(base_name(environment(who)),
          "/domains/havenwood/areas/nat_store/room/cabin") != -1) {
     who->eventPrint("You have found Talamar and Constanza. Congratulations!");
     who->AddExperience(500);
     return 1;
    }
  return 0;
}

int CanGetMission(object who) {
  if (who->GetSkillLevel("natural armour")
      || who->GetSkillLevel("reinforced armour")) {
    return 1;
  }
  return 0;
}

