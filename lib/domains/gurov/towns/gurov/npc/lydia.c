#include <lib.h>
#include "../gurov.h"
#include <std.h>
inherit LIB_LEADER;

static void create() {
  ::create();
  SetShort("High Priestess Lydia of Aberach");
  SetKeyName("lydia");
  SetId( ({ "priestess", "lydia" }) );
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetGender("female");
  SetClass("priest");
  SetUniqueSkills( ([
      "blunt combat" : 0,
      "slash combat" : 1,
      ]) );
  SetLevel(70);
  SetSpellBook( ([
      "divine retribution" : 100,
      "wall of souls"      : 100,
     	"harm body"          : 100,
      ]) );
  SetFirstCommands( ({
  	  "cast wall of souls",
  	  "cast wall of souls",
  	  "cast wall of souls",
      }) );
  SetPlayerTitles( ([
    "newbie" : "Acolyte $N of Aberach",
    "mortal" : "$N the Cleric of Aberach",
    "hm"     : "$N the Vengence of Aberach",
    "legend" : "$N the Decimator of the Light",
    "avatar" : "$N the Destroyer of the Opposition",
    "rogue" : "Oprichnik $N the Hand of the Prince",
    ]) );
  SetReligion("Aberach");
  SetTown("Gurov");
  SetFreeEquipment( ([
    STD_SLASH "shortsword" : 1,
    ]) );
  SetInventory ( ([
    STD_SLASH "sword" : "wield sword",
    ]) );
  SetLong(
    "Lydia is a dark and imposing figure of pure evil. Malevolent fury "
    "seems to pour off of her in waves, but for those interested in "
    "serving dark powers, Lydia could be someone worth talking to."
    );
  SetAction(3, ({
    "!glare", 
    "!grin evilly", 
  	}) );
  SetCombatAction(50, ({
  	"!cast divine retribution",
  	"!cast wall of souls",
  	"!cast aura of terror",
    }) );
  SetLimit(1);
  SetMorality(-2000);
}
  
