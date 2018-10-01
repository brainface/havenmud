// updated for dalnairn recode torak@haven 2017

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("bazir");
  SetShort("Bazir the Healer");
  SetId( ({ "bazir", "healer", "dalnairn_people" }) );
  SetAdjectives( ({"", "bazir" }) );
  SetRace("dark-dwarf");
  SetGender("male");
  SetClass("priest");
  SetSkill("hack combat",1,1);
  SetFriends("dalnairn_people"); 
  SetLevel(90);
  SetStat("wisdom", 10000, 1);
  SetCurrency("shards", 70);
  SetMorality(-1500);
  SetLong("Bazir is the local healer of Dalnairn.  His abilities range "
          "from both the mundane healing of minor wounds to the full "
          "resurrection of the dead. Of course, he reserves the right "
          "to be richly compensated for all of his services.");
  SetLocalCurrency("shards");
  SetFees( ([
    "resurrect" : 5,
    "stamina"   : 1,
    "health"    : 3,
    "restore"   : 6,
    ]) );
  SetTown("Dalnairn");
  SetLimit(1);
  SetSpellBook( ([
  	"wall of souls"      : 100,
  	"touch of death"     : 100,
  	"pious obstructions" : 100,
  	"purify"             : 100,
    ]) );
  SetInventory( ([
    DAL_WPN + "hooked_axe" : "wield axe",
    DAL_ARM + "lorica" : "wear lorica",
    DAL_ARM + "greaves" : "wear greaves",
    DAL_ARM + "chainhelm" : "wear helm",
  	]) );
  SetCombatAction(80, ({
  	"!cast purify",
  	"!cast walls of souls",
  	"!cast pious obstructions",
  	"!cast touch of death",
    }) );
}
