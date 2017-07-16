#include <lib.h>
#include <daemons.h>
#include <domains.h>
#include <std.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Ending the Curse");
  SetTown("Lisht");
  SetMissionDescription(
    "In the valley of tombs there exists an abandoned mastaba, the resting "
    "place of a particularly powerful necromancer from ages past. Recently, "
    "mourners have disappeared from the valley, and searchers have found only "
    "bleached bones half buried in sand. Likely some foolhardy thief has "
    "unsealed the necromancer from his tomb; someone of your particular "
    "talents should be able to place him in a far more permanent state of "
    "rest. Be wary, desecrating the grave of a revered noble is not without "
    "consequence."
    );
  SetTitle("the Cursed");
  SetMissionLevel(25, 1000);
  SetMissionPriority(5);
  SetReward("Special");
}

int CheckCompletedMission(object who) {
  object scroll = new("/std/mission_obj/mummy_scroll");
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());

  if (kills[DOMAIN_XANDRIA "areas/mastaba_area/npc/mummy"]) {
    object room = environment(who);
    if (room) {
      who->eventPrint("You have slain the mummy!");
      send_messages("gather",
        "$agent_name $agent_verb a tattered scroll among the "
        "mummy's remains with some trepidation.", who, 0, room);
      scroll->eventMove(who);
      STD_GERMS "mummy_rot"->eventInfect(who);
      return 1;
    }
  }
  return 0;
}

int CanGetMission(object who) {
  if (who->GetSkillLevel("necromancy") >= 50) return 1;
  return 0;
}

