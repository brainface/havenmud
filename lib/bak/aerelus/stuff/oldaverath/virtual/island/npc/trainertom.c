#include <lib.h>
#include <domains.h>
inherit LIB_TRAINER;

static void create() {
	::create();
	SetShort("a quiet and dignified man");
	SetId( ({ "man", "rogue", "trainer", "tom" }) );
	SetAdjectives( ({ "old", "quiet", "dignified" }) );
	SetKeyName("Old Tom");
	SetClass("rogue");
	SetLevel(25);
	SetLong("Old Tom is a quiet old man with a faintly dignified look in "
	        "his eye. Rumor says that Old Tom can train thieves in the art "
	        "of stealing without being caught.");
	SetAction(10, ({
		"!speak Do you need me to <train> you?",
		"!whistle quietly",
		"!hum softly",
		"!yell I'm not finished yet!",
	}) );
  SetRace("human");
  SetGender("male");
  SetTrainingSkills( ({
    "stealing", "stealth", "knife attack", "knife defense", "lockpicking",
    }) );
}

		
		
