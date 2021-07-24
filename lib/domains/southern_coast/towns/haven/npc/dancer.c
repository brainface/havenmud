/*  A dancer for Haven Town */
#include <lib.h>
#include <std.h>
#include "../haven.h"

inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("Caerthynna");
  SetShort("Caerthynna the Professor of Kinesis");
  SetId( ({ "caerthynna", "professor", "kinesis" }) );
  SetAdjectives( ({ "caerthynna", "the", "professor", "of" }) );
  SetRace("elf");
  SetGender("female");
  SetClass("dancer");

  SetLevel(30);
  SetMorality(500);
  SetLong(
    "Caerthynna is a frail old wiry elf, standing here in a very subdued "
    "and formal robe. She teaches prospective students some of the ancient "
    "ritual dances of the old Elven empire, as well as certain jigs and "
    "frolics of other towns, purely in a theortical or historical context, "
    "she quickly informs anyone who asks."
	  );
  SetInventory( ([
		  "/std/instruments/mandolin" : 1,
		  ]) );
  SetAction(5, ({
        "!emote tries to pirouette when she thinks no one is looking.",
	  "!emote snaps her fingers to some unheard tune and then sheepishly drops her arms at her side.",
	  }) );
  SetCombatAction(40, ({
        "!sing ballad of seasons",
	  "!sing melody of war",
	  "!sing reverberating note",
	  "!disorient",
	  }) );
  SetLimit(1);
  SetPlayerTitles( ([
		     "newbie" : "the Apprentice of Acceleration",
		     //"mortal" : "the Storyteller of Haven Town",
		     //"hm"     : "the SongMaster of Haven Town",
		     //"legend" : "the Bardic Legend of Haven Town",
		     //"avatar" : "the Truly Divine SongMaster of Haven Town",
		     //"priest" : "the Chorist of Haven Town",
		     ]) );
  SetFreeEquip( ([
		  STD_INSTRUMENTS "mandolin" : 1,
		  STD_KNIFE       "small_knife" : 2,
		  ]) );
  SetTown("Haven");
}

