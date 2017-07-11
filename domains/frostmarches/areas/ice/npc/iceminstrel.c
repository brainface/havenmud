// Written by Vanyel
#include <lib.h>
#include <std.h>
#include "ice.h"
#include <armour_types.h>
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("minstrel");
  SetShort("a frozen minstrel");
  SetId( ({ "minstrel" }) );
  SetAdjectives( ({ "frozen", "stupid", "blue", "cold" }) );
  SetRace("human");
  SetClass("bard");
  SetLevel(random(5)+5);
  SetCurrency("imperials", random(30)+20);
  SetMorality(50);
  SetLong("His teeth chattering and his face blue from cold, this "
     "poor fellow looks like he accidently fell under the snow.");
  SetGender("male");
  SetSongBook( ([
  	 "shielding song"   : 75,
  	 ]) );
  SetInventory( ([
     ICE_OBJ + "/snowshoes" : "wear snowshoes",
     STD_KNIFE + "stiletto" : "wield stiletto",
     ]) );
  SetAction( 5, ({ 
  	"!sing shielding song",
  	"!emote chatters his teeth.", 
    "!emote hums quietly, hoping that he doesn't cause "
    "an avalanche again." }) );
  SetCombatAction( 25, ({
  	"!sing shielding song",
    }) );
}
