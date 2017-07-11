#include <lib.h>
#include <damage_types.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("holy cleansing");
  SetSongType(SONG_COMBAT);
  SetRules("","LIV");
  SetReligions("Kylin");
  SetAutoDamage(1);
  SetDamage(MAGIC, 20, 20);
  SetSkills( ([
    "faith" : 2,
    "vocal music" : 2,
    ]) );
  SetDifficulty(15);
  SetMagicCost(10, 10);
  SetMessages( ({
    ({ "unleash",  "$agent_name%^BOLD%^ $agent_verb%^RESET%^ "
                     "a cleansing note towards $target_name, but "
                     "it has little effect." }),
    ({ "whip", "$agent_name vocally%^YELLOW%^ $agent_verb%^RESET%^ "
                  "$target_name with a purifying hymn of praise for "
                  "Duuktsaryth." }),
    ({ "spew",  "$agent_name $agent_verb a %^YELLOW%^hymn%^RESET%^ "
                  "which shakes $target_name badly." }),
     }) );
  SetHelp("This hymn is a worthy self-reflective piece which causes "
          "the target's soul to examine his life in a negative manner. "
          "The hymn does damage directly to the psyche of the target.");
  }

