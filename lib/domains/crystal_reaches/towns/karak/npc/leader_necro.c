// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <std.h>
#include "../karak.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("zarzul");
  SetId( ({ "zarzul", "necromancer", "orc" }) );
  SetShort("Zarzul the Ever-lasting Death of Karak");
  SetLong(
    "Zarzul is an infamous orc mage from history, resurrected by the dark "
    "arts of his god in order to provide a leader in these same arts for "
    "the orcs of Karak to follow. Unlike his previous incarnation, his "
    "insatiable lust for blood and death is now encouraged by his gods and "
    "his position allows him freedom to indulge himself."
  );
  
  SetClass("necromancer");
  SetRace("orc");
  SetGender("male");
  SetLevel(50);
  SetTown("Karak");
  SetReligion("Saahagoth", "Saahagoth");
  SetMorality(-1500);
  SetPlayerTitles( ([
    "newbie"  : "the Apprentice of Darkness",
    "mortal"  : "the Heinous Despoiler of Life's Essence",
    "hm"      : "the Depraved Manipulator of Darkness",
    "legend"  : "Shadow $N, Beguiler of the Darkness Beyond",
    "avatar"  : "Banshee $N the Augury of Death",
  	]) );
  SetSpellBook( ([
    "acid blast"         : 100,
    "wither"             : 100,
    "veil from beyond"   : 100,
    "hunger"             : 100,
    "chain lightning"    : 100,
    "necromantic shield" : 100,
  	]) );
  SetCombatAction(75, ({
	  "!cast acid blast",
	  "!cast wither",
	  "!cast necromantic shield",
	  "!cast hunger",
	  "!cast chain lightning",
		}) );	
  SetInventory( ([
    KARAK_OBJ + "bflail" : "wield flail",
    KARAK_OBJ + "runea"  : "wear armour"
  	]) );
  SetFirstCommands( ({
  	"cast necromantic shield",
  	"cast necromantic shield",
  	"cast necromantic shield",
  	}) );
}
