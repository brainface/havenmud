#include <lib.h>
#include <music.h>
#include <damage_types.h>
#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   ::create();
   SetSong("aria of fire");
   SetRules("","LIV");
   SetMagicCost(50,50);
   SetSongType(SONG_COMBAT);
  SetAutoDamage(0);
   SetSkills( ([
       "vocal music" : 65,
            ]) );
   SetDifficulty(60);
   SetDamageType(HEAT);//,215,215);
   SetEnhanceSkills( ({"fire magic"}) );
   SetMessages( ({
                   ({ ({ "begin","sing" }),"$target_name $target_verb "
                        "to smoke as $agent_name $agent_verb.", }),
                   ({ "light","$agent_name "
                      "$agent_verb $target_name on fire "
                        "with $agent_possessive singing.", }),
                   ({ ({ "burst","sing" }),"$target_name $target_verb "
                        "into %^RED%^flames%^RESET%^ while "
                        "$agent_name $agent_verb the aria of fire."
                      }),
              }) );
   SetHelp("By singing this aria the bard can set their target on fire inflicting a moderate amount of damage.");
}

