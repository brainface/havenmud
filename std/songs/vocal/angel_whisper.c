// 
// Summary: a minor healing song for bards
// Created by: Rhakz@Haven -- Angel Cazares
// For: Bards
// Date: 12/24/98
#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("angel whisper");
  SetRules("","LIV");
  SetSongType(SONG_HEALING);
  SetSkills( ([
      "vocal music" : 15
           ]) );
  SetDifficulty(10);
  SetAutoHeal(1);
  SetMagicCost(10, 10);
  SetHealing(20, 20);
  SetMessages( ({
                 ({ "sing", "$agent_name $agent_verb a melody so sweet "
                            "and charming that it makes $target_name feel "
                            "a bit better." }),
                 ({ "intone", "$agent_name $agent_verb a sweet but "
                              "almost inaudible melody that comforts "
                              "$target_name."}),
                 ({ "whisper", "$agent_name $agent_verb a soft and sweet "
                               "melody to $target_possessive_noun, "
                               "healing some of $target_possessive "
                               "wounds."})
             }) );
  SetHelp("Angel whisper is a soft, sweet song that when sung by a "
          "bard, heals some of the ailments of a listener." );
}
