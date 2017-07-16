/* Slaaneth the Shaman */
#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include "../gwonish.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("slaaneth");
  
  SetId( ({ "slaaneth", "shaman" }) );
  SetAdjectives( ({ "lizardman", "kuthar" }) );
  SetShort("Slaaneth the Shaman of Kuthar");
  SetLong(
    "Slaaneth the Shaman wields extensive power here in the village. "
    "His brand of ancestor worship tells of the lizardmen owning the land "
    "for miles around before the arrival of the halflings, and he constantly "
    "rails against the spread of halfling influence in the world."
    );
  
  SetRace("lizardman");
  SetTown("Gwonish");
  SetReligion("Kuthar");
  SetGender("male");
  SetClass("shaman");
  SetLevel(50);
  
  SetAction(10, ({
    "!speak For our children, we must not let down our guard.",
    "!speak The ancestors knew to contain the halflings.",
    "!speak A wooden curtain has fallen across the Shire, preventing "
    "decent lizardmen from experiencing the world.",
    "!speak I can convert you.",
    "!speak Become a shaman, ask me how!",
    "!cast ancestral protection",
    "!cast ancestral protection",
    "!cast spiritual rebirth",
  }) );
  SetInventory( ([
    GWONISH_OBJ "club" : "wield club",
    ]) );
  SetFreeEquipment( ([
    GWONISH_OBJ "newbie_club" : 1,
   ]) );
  SetPlayerTitles( ([
    "newbie" : "the Gwonish Acolyte",
    "mortal" : "the Shaman of the Swamp",
    "hm"     : "the Wisened Shaman of the Swamp",
    "legend" : "the Fearsome Shaman of the Swamp",
    "avatar" : "the Wise and Respected Shaman of the Swamp",
    "demi-god" : "the Divine Communicator of Ancestral Knowledge",
    ]) );
  SetSpellBook( ([
    "ancestral protection" : 100,
    "hurt"                 : 100,
    "crush"                : 100,
    "spiritual rebirth"    : 100,
    "will of old"          : 100,
    ]) );
  SetCombatAction(50, ({
    "!cast spiritual rebirth",
    "!cast will of old",
    "!cast ancestral protection",
    "!cast crush", "!cast crush", "!cast will of old",
    "!cast hurt",
  }) );
}
int eventDie(object killer) {
  object lizard_inv;
  if(!random(75)) {
    lizard_inv = new(DIR_INVASIONS + "/shire_lizardmen/lmil_inv");
    INVASION_D->eventRegisterInvasion(lizard_inv, killer);
  }
return ::eventDie(killer);
}
