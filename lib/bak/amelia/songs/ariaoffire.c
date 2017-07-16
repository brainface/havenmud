#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   ::create();
   SetSong("aria of fire");
   SetRules("","LIV");
   SetMagicCost(90,90);
   SetSongType(SONG_COMBAT);
   SetAutoDamage(1);
   SetSkills( ([
                 "vocal music" : 60,
            ]) );
   SetDifficulty(60);
   SetDamage(HEAT,215,215);
   SetMessages( ({
                   ({ ({ "begin","sing" }),"$target_name $target_verb "
			"to smoke as $agent_name $agent_verb.", }),
                   ({ "light","$agent_name "
                      "$agent_verb $target_name on fire "
			"with $agent_possessive signing.", }),
                   ({ "sing","$target_name $target_verb "
			"into %^RED%^flames%^RESET%^ with the power of "
			"of $agent_possessive_name "
			"aria of fire." }),
              }) );
   SetHelp("The aria of fire causes the target to combust.");
}
