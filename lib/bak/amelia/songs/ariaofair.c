#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   ::create();
   SetSong("aria of air");
   SetRules("","LIV");
   SetMagicCost(120,120);
   SetSongType(SONG_COMBAT);
   SetAutoDamage(1);
   SetSkills( ([
                 "vocal music" : 100,
            ]) );
   SetDifficulty(75);
   SetDamage(GAS|POISON,550,550);
   SetMessages( ({
                   ({ "sing","$agent_possessive_noun singing "
			"causes the air around $target_name to "
			"turn %^MAGENTA%^purple%^RESET%^.", }),
                   ({ "sing","$agent_name $agent_verb the aria "
			"of air at $target_name, causing the "
			"air around $target_objective to "
			"to turn %^MAGENTA%^purple%^RESET%^ "
			"and %^BLUE%^blue%^RESET%^ with poison." }),
                   ({ "sing","$agent_name $agent_verb the aria "
			"of air at $target_name, causing the air "
			"around $target_object to turn "
			"%^MAGENTA%^purple%^RESET%^, %^BLUE%^blue"
			"%^RESET%^, and %^GREEN%^green%^RESET%^ "
			"with poisoness fumes." }),
              }) );
   SetHelp("The aria of air surrounds the target with poisoness gas.");
}
	