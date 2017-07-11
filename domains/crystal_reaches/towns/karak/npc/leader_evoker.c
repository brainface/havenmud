// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <std.h>
#include "../karak.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("gag");
  SetId( ({ "gag", "orc", "evoker" }) );
  SetAdjectives( ({ "gag", "orc", "evoker" }) );
  SetShort("Gag the Senior Battle-mage of Karak");
  SetLong(
    "Gag is an infamous orc evoker, whose prowess in battle "
    "is so legendary that it has overcome even the short orcish attention "
    "span and made him both feared and revered among his race. His mere "
    "presence has often been used to dishearten enemies, often causing "
    "them to flee. Lately this has made him unpopular, as all orcs enjoy "
    "a good fight and rather peeved when the fight can run away faster "
    "than them."
  );
  
  SetRace("orc");
  SetGender("male");
  SetClass("evoker");
  SetSkill("fire magic",1,2);
  SetLevel(30);
  SetTown("Karak");
  SetReligion("Saahagoth");
  SetMorality(-450);
  SetInventory( ([
  	KARAK_OBJ + "r_knife" : "wield knife",
  	]) );
  SetSpellBook( ([
		"fireball"   : 100,
		"lava storm" : 100,
		"sphere"     : 100,
  	]) );
  SetPlayerTitles( ([
    "newbie" : "the Aspiring Evoker",
    "mortal" : "the Fire-starter",
    "hm"     : "the Magi Pyromaniac",
    "legend" : "the Flame Touched Mage",
    "avatar" : "the Thaumaturgist of the Black Flame",
    ]) );
   SetCombatAction(50, ({
   	"!cast fireball",
   	"!cast lava storm",
   	"!cast sphere",
  	}) );
}
