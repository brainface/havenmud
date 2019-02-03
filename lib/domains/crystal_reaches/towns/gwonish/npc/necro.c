/* Necro Leader */
#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include <std.h>
#include "../gwonish.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("essellias");
  SetId( ({ "essellias", "necromancer", }) );
  SetAdjectives( ({ }) );
  SetShort("Essellias the Bringer of Death");
  SetLong("Essellias is the leader of the Gwonish necromancers. "
          "Her status is secure due to the nature of the Kuthar "
          "faith and its worship of ancestors.  Her ability to "
          "commune with the dead is legendary. She can teach "
          "young lizardmen how to use the arts of necromancy."
          );
  SetRace("lizardman");
  SetTown("Gwonish");
  SetGender("female");
  

  SetClass("necromancer");
  SetLevel(50);
  SetSpellBook( ([
    "acid rain"      : 100,
    "wound"          : 100,
    "drain soul"     : 100,
    "mesmer barrier" : 100,
    ]) );
  SetAction(12, ({
    "!cast sphere",
    "!cast sphere",
    "!cast sphere",
    "!speak I can make you one of us",
    "!speak Necromancy is an art",
  }) );
  SetCombatAction(60, ({
    "!cast mesmer barrier",
    "!cast acid rain",
    "!cast wound",
    "!cast drain soul",
    "!cast acid rain",
  }) );
  SetFreeEquipment( ([
    STD_POLE "staff" : 1,
    ]) );
  SetPlayerTitles( ([
    "newbie" : "the Nurturer of Death",
    "mortal" : "the Practitioner of Souls",
    "hm"     : "the Harvester of Sorrows",
    "legend" : "the Bringer of Death",
    "avatar" : "the Orcas Orca",
    ]) );
  SetInventory( ([
    STD_POLE "staff" : "wield staff",
    ]) );
  SetMorality(-400);
}
int eventDie(object killer) {
  object lizard_inv;
  if(!random(75)) {
    lizard_inv = new(DIR_INVASIONS + "/shire_lizardmen/lmil_inv");
    INVASION_D->eventRegisterInvasion(lizard_inv, killer);
  }
return ::eventDie(killer);
}
