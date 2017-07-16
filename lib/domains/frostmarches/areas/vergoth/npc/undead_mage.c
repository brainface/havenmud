#include <lib.h>
#include "../vergoth.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("undead mage");
  SetRace("elf");
  SetId( ({ "elf", "mage", "undead_mage" }) );
  SetAdjectives( ({ "undead" }) );
  SetClass("evoker");
  SetGender("male");
  SetShort("an undead mage");
  SetReligion("Kylin");
  SetLevel(12);
  SetUndead(1);
  SetNoCorpse(1);
  SetSpellBook( ([
     "aura"         : 100,
     "invisibility" : 100,
     "shock"        : 100,
     "capsule"      : 100,
    ]) );
  SetCombatAction(30, ({ 
     "!shout the Vergoth Tower is under attack",
     "!cast aura",
     "!cast capsule",
     "!cast shock",
     "!cast invisibility",
    }) );
  SetAction(10, ({
    "!emote curses under his breath.",
    "!cast aura",
    "!cast invisibility",
    "!frown thoughtfully",
    "!speak Leave my tower.",
   }) );
  SetWander(10, ({ "go north", "go southwest", "go southeast", "go north",
	}), 1);
  SetLong("This undead mage seems very unhappy about something as he "
	"wanders around aimlessly.  He is very short and his skin is "
	"streched very tightly around his bones.  He wanders the top of the "
	"tower suggesting he owned the tower before his death.");
  SetInventory( ([
	V_OBJ + "robe" : "wear robe",
	V_OBJ + "staff" : "wield staff",
    ]) );
  SetCurrency("imperials", 120);
  SetMorality(-300);
 }
