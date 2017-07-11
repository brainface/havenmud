#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Tower Assault 3");
  SetTown("Jidoor");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "Today's lesson is on the dangers of hubris. The prideful mage that"
    " originated this plague of undead believes herself safe in the"
    " pinnacle of her tower. Ascend the stairs and bring this necromancer"
    " low. Be wary of her spells, and do not succumb to presumption of your"
    " own power."
  );
  SetTitle("the Tower Toppler");
  SetMissionLevel(8, 500);
  SetMissionPriority(35);
  SetReward("12500 XP");
}

int CheckCompletedMission(object who) {
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  int zombie_kills = kills[VALLEY_AREAS "undead_tower/npc/lich"];
  if ((zombie_kills >= 1)) {
    who->eventPrint("You have been dubbed \"the Tower Toppler\" for your efforts.");
    who->AddExperience(12500);
    return 1;
  }
  return 0;
}

/*
void AssignMission(object who) {
  object *rumpel = ({ });
  object stake = new("/std/mission_obj/birdcage");
  rumpel = filter(all_inventory(environment(who)),
    (: $1->GetKeyName() == "rumpel" :) );
  if (!stake->eventMove(who)) {
    stake->eventMove(environment(who));
  }     
  who->eventPrint("Rumpel gives you a wooden stake.");
  rumpel[0]->eventForce(
    "speak Take this, it may be essential."
  );
}*/

int CanGetMission(object who) {
  if (who->GetQuestCompleted("Tower Assault 2")) {
    return 1;
  } else {
    return 0;
  }
}

