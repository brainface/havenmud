// Amelia@Haven, Dec 98
#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   song::create();
   SetSong("ballad of summer");
   SetRules("","LIV");
   SetMagicCost(20,5);
   SetSongType(SONG_COMBAT);
   SetSkills( ([
       "vocal music" : 35,
            ]) );
   SetEnhanceSkills( ({ "fire magic" }) );
   SetAutoDamage(1);
   SetDifficulty(15);
   SetHelp("The ballad of summer is an ode to the hot, torrid months "
           "of the year.  When effective, it creates a dry, breeze-less "
           "and burning hot air to surround the target.");
   SetMessages( ({
	 ({"sing","$agent_name $agent_verb $agent_possessive "
                    "best, but $agent_possessive ballad of summer does "
		      "nothing to $target_name."}),
		  ({"complete","A stuffy, dry air surrounds $target_name as "
                    "$agent_name $agent_verb $agent_possessive "
                    "%^ORANGE%^ballad of summer%^RESET%^.  Wavy lines "
		      "of distortion hang in the air."}),
		  ({"","The %^ORANGE%^ballad of summer%^RESET%^ "
                    "is sung with furvor and gusto by $agent_name, "
                    "summoning a torrid blast of air that hangs "
		      "around $target_name."}),
	  ({"finish","Scorching heat surrounds $target_name as "
                    "$agent_name $agent_verb the %^ORANGE%^"
		      "ballad of summer%^."})
	   }));

}

// deal more damage in summer
int GetDamage(int level) {
  int damage;
  damage = song::GetDamage(level);
  if(query_season(time()) == "summer") {
      damage *= (12/7);
  }
  return damage;
}
