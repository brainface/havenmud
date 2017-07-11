#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Tower Assault 2");
  SetTown("Jidoor");
  SetMissionDescription(
"This quest may put you in danger.\n"
    "I've recieved some disturbing news after your assault on the tower."
    " It seems a vampire is laired somewhere in the tower. Hunt this"
    " creature down and slay her before she makes more of her kind!"
  );
  SetTitle("the Vampire Hunter");
  SetMissionLevel(5, 500);
  SetMissionPriority(45);
  SetReward("2500 XP");
}

int CheckCompletedMission(object who) {
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  int zombie_kills = kills[VALLEY_AREAS "undead_tower/npc/vampire"];
  if ((zombie_kills >= 1)) {
    who->eventPrint("You have been dubbed \"the Vampire Hunter\" for your efforts.");
    who->AddExperience(2500);
    return 1;
  }
  return 0;
}


void AssignMission(object who) {
  object *rumpel = ({ });
  object stake = new("/std/mission_obj/stake");
  rumpel = filter(all_inventory(environment(who)),
    (: $1->GetKeyName() == "rumpel" || $1->GetKeyName() == "eralyon" :) );
  if (!stake->eventMove(who)) {
    stake->eventMove(environment(who));
  }     
  who->eventPrint("Rumpel gives you a wooden stake.");
  rumpel[0]->eventForce(
    "speak Take this, it may be essential."
  );
}


int CanGetMission(object who) {
  if (who->GetQuestCompleted("Tower Assault 1")) {
    return 1;
  } else {
    return 0;
  }
}

