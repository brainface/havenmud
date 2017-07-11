#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include "../so.h"
inherit LIB_NPC;

static void create() {
	::create();
	SetKeyName("orc");
	SetShort("a filthy orc");
	SetId( ({ "orc" }) );
	SetAdjectives( ({ "filthy" }) );
	SetLong("The tough, green skin of the orc is covered in dirt and slime.  "
		"His arms are weak and his physique is emancipated.");
	SetRace("orc");
	SetGender("male");
	SetClass("fighter");
	SetLevel(3);
	SetMorality(-250);
	SetInventory( ([
			SO_OBJ + "loincloth" : "wear loincloth",
			SO_OBJ + "rustysword" : "wield sword in right hand",
			SO_OBJ + "smallaxe" : "wield axe in left hand",
			SO_OBJ + "muezzinstew" : 1,
			]) );
	SetAction(2, ({ "!say Muezzin stew is amazingly tasty.  I wish we'd "
		"tried this before!","!emote grunts.","!say I'm so hungry...",
		"!emote nibbles at the stew.","!emote pulls a humanoid bone "
		"from his stew and gnaws on it." }) );
   SetCurrency("cuicui",10 + random(40));
}

int eventDie(object agent) {
  object goblin_inv;
   if(!random(500)) {
    goblin_inv = new(DIR_INVASIONS + "/soleil_goblin/gis_inv");
    INVASION_D->eventRegisterInvasion(goblin_inv, agent);
   }
  return (npc::eventDie(agent));
  }