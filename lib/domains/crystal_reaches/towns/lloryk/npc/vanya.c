#include <lib.h>
#include "../path.h"
#include <std.h>
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("vanya");
  SetRace("halfling");
  SetTown("Lloryk");
  SetClass("bard"); 
  SetLevel(20);
  SetShort("Vanya das-Synga");
  SetId( ({ "vanya", "guard", "bard", "synga", }) );
  SetAdjectives( ({ "vanya", "das", }) );
  SetLong("Vanya is a small halfling, known across the Crystal Reaches and "
          "the Valley for his epic poem, \"The Charge of the Well Lit Platoon\", "
          "a saga about the efforts of a torch-bearing platoon of halflings to "
          "burn down the Gwonish Swamp."
          );
  SetGender("male");
  SetCurrency("rounds", 100);
  SetMorality(1500);
  SetLimit(1);
  SetFreeEquip( ([
    STD_WEAPON "knife/freeknife" : 1,
    STD_INSTRUMENTS "fife" : 1,
    ]) );
  SetInventory( ([ 
    STD_INSTRUMENTS "fife" : "wield fife",
    ]) );
  SetFirstCommands( ({
  	}) );
  SetPlayerTitles( ([
    "newbie" : "the Entertainer of the Shire",
    "mortal" : "the Shire Songsmith",
    "hm"     : "the Epic Poet",
    "legend" : "the Legendary Player of the People's Marches",
    ]) );
  SetAction(3, ({
  	"!speak You could ask me to join bards.",
  	"!speak A solemn saga is the \"The Charge of the Well Lit Platoon\".",
  	}) );
}