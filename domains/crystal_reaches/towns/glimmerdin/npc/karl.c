#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_LEADER;

static void create() {
	::create();
	SetKeyName("karl");
	SetShort("Karl of Glimmerdin, Musician Extraordinaire");
	SetRace("dwarf");
	SetClass("bard");
	SetLevel(25);
	SetGender("male");
	SetId( ({ "karl", "bard", "musician", "glim_wander" }) );
	SetLong(
	  "Karl of Glimmerdin runs the Orchestral Hall here. His fame comes "
	  "from the beauty of the music he composes. His stern demeanor is "
	  "only a symptom of his fanaticism about dwarven music."
	  );
	SetFreeEquipment( ([
	  STD_INSTRUMENTS "drum" : 1,
	  STD_KNIFE       "freeknife" : 1,
	  ]) );
	SetSongBook( ([
		"aria of stone"  : 100,
		"harpy's shriek" : 100,
		"staccato"       : 100,
		"shielding song" : 100,
		]) );
	SetCombatAction(45, ({
		"!sing aria of stone",
		"!sing harpy's shriek",
		"!sing staccato",
		"!sing shielding song",
		}) );
	SetPlayerTitles( ([
	  "newbie" : "the Rumbling Basso of Glimmerdin",
	  "mortal" : "the Deeply Moving Performer of Glimmerdin",
	  "hm"     : "the Grand Musician of Glimmerdin",
	  "legend" : "the Legendary Artist of Glimmerdin",
	  "avatar" : "the Divine Artist of Glimmerdin",
          "priest" : "the Illustrius Member of the Glimmerdin Choir",
	  ]) );
	SetTown("Glimmerdin");
	SetMorality(500);
	SetAction(5, ({
		"!speak You could <ask me to join bards>",
		"!speak My music... I live for the music.",
	}) );
}
