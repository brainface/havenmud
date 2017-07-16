#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include "../gwonish.h"
#include <size.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("giant turtle");
  SetId( ({ "turtle", "tortoise" }) );
  SetAdjectives( ({ "giant" }) );
  SetShort("a giant turtle");
  SetLong("The turtle is a massive creature of green skin and "
          "shell. Her slow gait is matched by her intense "
          "ability to hide.");
  SetRace("tortoise");
  SetStat("strength", 30, 2);
  SetClass("animal");
  SetLevel(12);
  SetMorality(75);
  
  SetGender("female");
  SetSize(SIZE_VERY_LARGE);
  SetInventory( ([
    GWONISH_OBJ "shell" : "wear shell",
    ]) );
  SetAction(12, ({
  	"Giant turtle sits still ... for ... a ... long ... time.",
  	"!emote looks around VERY slowly.",
  	"!lie down",
  	"!stand up",
  	"!sleep",
  	}) );
}
  
int eventDie(object killer) {
  object lizard_inv;
  if(!random(250)) {
    lizard_inv = new(DIR_INVASIONS + "/shire_lizardmen/lmil_inv");
    INVASION_D->eventRegisterInvasion(lizard_inv, killer);
  }
return ::eventDie(killer);
}
