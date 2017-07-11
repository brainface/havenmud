#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Quenching the Fire");
  SetTown("all");
  SetMissionDescription(
    "I have a challenge for you, a powerful spellcaster. There is a spell of tremendous power which is taught "
    "only to the greatest of casters. I have discovered that a scroll exists with this power. However, it is "
    "guarded by Hephaeston, the Elemental Lord of Fire. He resides deep in the Plane of Fire, and is a match "
    "for all but the greatest of mortals."
    );
  SetTitle("the Bringer of Fire");
  SetMissionLevel(250, 1000);
  SetMissionPriority(5);
  SetReward("Special");
}

int CheckCompletedMission(object who) {
  object scroll = new(LIB_SCROLL);
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  
  scroll->SetSpell("wards of light");
  
  if (kills[DOMAIN_PLANES  "npc/hephaeston"]) {
    who->eventPrint("You have slain Hephaeston!");
    who->eventPrint("You discover a scroll...");
    scroll->eventMove(who);
    return 1;
  }
  return 0;
}
int CanGetMission(object who) {
  if (who->GetSkillLevel("evokation") >= 500 && who->GetSkillLevel("conjuring") >= 500) return 1;
  return 0;
}
 