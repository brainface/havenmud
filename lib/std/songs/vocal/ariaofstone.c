#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   ::create();
   SetSong("aria of stone");
   SetRules("","LIV");
   SetMagicCost(50,50);
   SetAutoDamage(0);
   SetSongType(SONG_COMBAT);
   SetSkills( ([
                 "vocal music" : 45,
            ]) );
   SetDifficulty(50);
   SetDamageType(BLUNT); //,125,125);
   SetMessages( ({
                   ({ "bellow","$agent_name $agent_verb loudly "
                      "causing a handful of rocks "
                        "to crash into $target_name." }),
                   ({ "sing","$agent_name $agent_verb "
                      "deeply, calling many stones out of "
                        "the earth and smashing them into "
                        "$target_name." }),
                   ({ "sing","$agent_name $agent_verb "
                      "forcefully and deeply, forcing "
                        "huge stones to smash into "
                        "$target_name, crushing "
                        "$target_objective." }),
              }) );
   SetHelp("The aria of stone causes huge blocks of stone to be hurled "
        "at the target.");
}

