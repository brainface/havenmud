#include <lib.h>
#include <std.h>
#include "../haven.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("raunthala");
  SetRace("elf");
  SetClass("druid");
  SetReligion("Kylin");
  SetTown("Haven");
  SetLevel(80);
  SetMorality(1500);
  SetShort("Raunthala of the Wood");
  SetLong(
    "Raunthala is a bit of an oddity for Haven Town.  She is a wilder elf. Her "
    "advanced age make it apparent that she is from a time long past when the "
    "elves of Kailie were not strictly born within cities. Her roots as a druid "
    "for the Kylin faith are not those that can be followed by modern elves, but "
    "for those that somehow find her skills, she is a willing teacher of magic."
    );
  SetId( ({ "raunthala", "teacher", }) );
  SetAdjectives( ({ }) );
  SetGender("female");
  SetCurrency("imperials", 2500);
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
}

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 5) {
    eventForce("cast wall of wood");
  }
}

    
