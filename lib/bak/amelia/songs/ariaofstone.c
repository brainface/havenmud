
#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   ::create();
   SetSong("aria of stone");
   SetRules("","LIV");
   SetMagicCost(90,90);
   SetSongType(SONG_COMBAT);
   SetAutoDamage(1);
   SetSkills( ([
                 "vocal music" : 45,
            ]) );
   SetDifficulty(50);
   SetDamage(BLUNT,125,125);
   SetMessages( ({
                   ({ "","$agent_possessive_noun "
                      "deep singing summons a handful "
			"of large stones that fly towards "
			"$target_name.", }),
                   ({ "sing","$agent_name $agent_verb "
                      "deeply, calling many stones out of "
			"the earth and smashing them into "
			"$target_name.", }),
                   ({ "sing","$agent_name $agent_verb "
                      "forcefully and deeply, forcing "
			"huge stones to smash into "
			"$target_name, crushing "
			"$target_objective." }),
              }) );
   SetHelp("The aria of stone causes huge blocks of stone to be hurled "
	"at the target.");
}
