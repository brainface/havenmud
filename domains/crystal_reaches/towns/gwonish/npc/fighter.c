/* Fighter Leader */
#include <lib.h>
#include <std.h>
#include <daemons.h>
#include <dirs.h>
#include "../gwonish.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetRace("lizardman");
  SetClass("fighter");
  SetGender("male");
  SetLevel(50);
  SetInventory( ([
    GWONISH_OBJ "serrated" : "wield sword",
    STD_CLOTHING "body/loin" : "wear loincloth",
    ]) );
  SetKeyName("largos");
  SetShort("Largos the Warchief");
  SetId( ({ "largos", "warchief" }) );
  SetLong("Largos the Warchief is responsible for teaching "
          "young lizardmen the arts of warfare and tribal "
          "combat.");
  SetTown("Gwonish");
  SetPlayerTitles( ([
    "newbie" : "the Swamprat",
    "mortal" : "the Muckraker",
    "hm"     : "the Denizen of the Swamp",
    "legend" : "the Sub-Chief of Gwonish",
    ]) );
  SetFreeEquipment( ([
    GWONISH_OBJ "serrated_newbie" : 1,
    ]) );
  SetMorality(-100);
  SetCombatAction(15, ({
  	"!disarm",
  	"!disorient",
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
