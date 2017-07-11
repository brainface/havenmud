#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("Flotsam");
  SetRace("human");
  SetClass("druid");
  SetSkill("practical magic", 1, 1);
  SetTown("all");
  SetLevel(80);
  SetMorality(1500);
  SetShort("Flotsam, Baba Yaga's assistant");
  SetLong(
    "Flotsam is the assistant of Baba Yaga. He can teach the spells "
    "for which the witch trains people."
    );
  SetId( ({ "assistant", "flotsam" }) );
  SetAdjectives( ({ }) );
  SetGender("male");
  SetCurrency("rubles", 2500);
  SetInventory( ([
    STD_POLE "staff" : "wield staff",
    ]) );
  SetSpellBook( ([
    "wall of wood"	 : 100,
    "lunar blast"	   : 100,
    "freeze"      	 : 100,
    "tangle"    	   : 100,
    "heat"    	     : 100,
    "soothe"	       : 100,
    "natural charge" : 100,
    "ice storm"			 : 100,
    ]) );
  SetCombatAction(60, ({
    "!cast freeze",
    "!cast soothe",
    "!cast ice storm",
    "!cast tangle",
    "!cast lunar blast",
    "!cast heat",
  }) );
  SetLimit(1);
  SetPlayerTitles( ([
    "newbie" : "the Elven Purist",
    "mortal" : "the Keeper of Ancient Ways",
    "hm"     : "Wild $N",
    "legend" : "the Reactionary Forest Dweller",
    "avatar" : "the Divine Walker of the Ancient Wood",
    ]) );
  SetNoJoin(1);
}

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 5) {
    eventForce("cast wall of wood");
  }
}

    
