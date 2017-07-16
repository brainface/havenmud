#include <lib.h>
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
	SetAction(2, ({ "!say Muezzin stew is amazingly tasty.  I wish we'd "
		"tried this before!","!emote grunts.","!say I'm so hungry...",
		"!emote nibbles at the stew.","!emote pulls a humanoid bone "
		"from his stew and gnaws on it." }) );
   SetCurrency("cuicui",100+random(40));
}
