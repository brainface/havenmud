#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   ::create();
   SetSong("aria of ice");
   SetRules("","LIV");
   SetMagicCost(75,100);
  SetAutoDamage(0);
   SetSongType(SONG_COMBAT);
   SetSkills( ([
       "vocal music" : 85,
            ]) );
   SetDifficulty(65);
   SetDamage(COLD|PIERCE,350,350);
   SetMessages( ({
                   ({ "sing","A few ice crystals pierce $target_name "
		"as $agent_name $agent_verb.", }),
                   ({ "sing","A myriad of tiny ice crystals appear in "
			"the air as $agent_name $agent_verb, surrounding "
			"$target_name with a flurry of chilling attacks." }),
                   ({ "","A cyclone of tiny %^BLUE%^ice crystals "
			"%^RESET%^emanates from $agent_name, "
			"and quickly surrounds $target_name, "
			"obscurring $target_objective from view." }),
              }) );
   SetHelp("The aria of ice creates a whirlwind of tiny ice crystals "
	"around the target.");
}
