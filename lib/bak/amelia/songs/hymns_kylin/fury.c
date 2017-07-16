#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("holy fury");
  SetRules("","LIV");
  SetMagicCost(25, 25);
  SetSkills( ([
    "faith" : 4,
    "instrumental music" : 6,
    "vocal music" : 6,
    ]) );
  SetDifficulty(20);
  SetAutoDamage(1);
  SetSongType(SONG_COMBAT);
  SetReligions("kylin");
  SetDamage(SHOCK, 75, 75);
  SetHelp("This song is a harsh tone which causes the listener "
          "extreme pain internally.  The damage done is not affected "
          "by mundane armours.");
  SetMessages( ({
    ({ "chant", "$agent_name $agent_verb a song of%^RED%^BOLD$% Holy Fury "
                "%^RESET%^which seems to have little effect on $target_name."
                }),
    ({ "play", "$agent_name%^YELLOW%^BOLD%^ $agent_verb%^RESET%^ a tune "
               "of the Fury of Duuktsaryth, causing $target_name to be "
               "wracked with pain!" }),
    ({ ({ "chant", "play" }), "$agent_name%^YELLOW%^ $agent_verb and "
                              "$agent_verb%^RESET%^ a violent song of "
                              "fury, vengence and pain, causing "
                              "$target_name to scream out!" }),
    }) );
  }

