#include <lib.h>
#include "../path.h"
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("xylophant");
  SetShort("Xylophant the Healer of Glimmerdin");
  SetId( ({ "xylophant", "healer", "dwarf" }) );
  SetAdjectives( ({ }) );
  SetRace("dwarf");
  SetGender("male");
  SetClass("priest");
  SetTown("Glimmerdin");
  SetReligion("Kylin", "Kylin");
  SetSkill("melee combat",1,2);
  SetLevel(90);
  SetStat("wisdom", 10000, 1);
  SetCurrency("nuggets", 10);
  SetMorality(2500);
  SetLong(
    "Xylophant the Healer is a very respected individual here in town. "
    "He is the one that keeps people healthy and alive. Asking him to "
    "heal you is a fine way to stay that way."
    );
  SetLocalCurrency("nuggets");
  SetFees( ([
    "resurrect" : 20,
    "stamina"   : 10,
    "health"    : 10,
    "restore"   : 10,
    ]) );
  SetLimit(1);
  SetSpellBook( ([
    "divine magic fully" : 100,
    "mend" 							 : 100,
    "revive" 						 : 100,
    "sanctify" 					 : 100,
    "bless" 						 : 100,
    "wall of force" 		 : 100,
    "kylin touch"        : 100,
    "wrath"              : 100,
    "desert banishment"  : 100,
    ]) );
  SetCombatAction(50, ({
    "!cast sanctify",
    "!cast wall of force",
    "!cast wrath",
  	"!cast kylin touch",
   	"!cast desert banishment",
    }) );
}
