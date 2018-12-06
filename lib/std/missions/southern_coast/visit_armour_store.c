#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Kelan's Quality Armour");
  SetTown("Haven");
  SetMissionDescription(
    "I mean no offense, but you look like the sort of adventurer that "
    "requires a bit heavier armament than average. You may find a smith named "
    "Kelan and his apprentices have what you need. Head west out of town, "
    "beyond Beornwulf's Keep and you should see the smoke of his forge."
    );
  SetTitle("the Armoured");
  SetMissionLevel(5,500);
  SetMissionPriority(100);
  SetReward("1500 XP");
}

int CheckCompletedMission(object who) {
  if (strsrch(base_name(environment(who)),
          "/domains/southern_coast/areas/platemailstore/kelansstore") != -1) {
     who->eventPrint("You have found Kelan and his apprentices. Congratulations!");
     who->AddExperience(500);
     return 1;
    }
  return 0;
}

int CanGetMission(object who) {
  if (who->GetSkillLevel("plate armour")
      || who->GetSkillLevel("heavy plate armour")
      || who->GetSkillLevel("chain armour")) {
    return 1;
  }
  return 0;
}
