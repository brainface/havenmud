#include <lib.h>
#include <damage_types.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("holy sear");
  SetReligions("kylin");
  SetRules("", "LIV");
  SetSongType(SONG_COMBAT);
  SetStaminaCost(50, 50);
  SetAutoDamage(0);
  SetDamage(HEAT, 100, 100);
  SetSkills( ([
    "faith" : 6,
    "instrumental music" : 8,
    "vocal music" : 8,
    ]) );
  SetHelp("This song causes the temperature in a given area around "
          "a target to be heated with the music.  It causes flames "
          "to burst briefly into an area affected. This damage is "
          "affected by mundane armours.");
  SetDifficulty(25);
  SetMessages( ({
    ({ "play", "$agent_name $agent_verb%^RED%^ an exciting %^RESET%^song, "
               "which seems to heat the air around $target_name." }),
    ({ "play", "$agent_name $agent_verb%^RED%^BOLD%^ a violent%^RESET%^ "
               "song which causes flames to flicker around $target_name." }),
    ({ "hammer", "$agent_name%^RED%^ $agent_verb%^RESET%^ out a song of "
                 "fiery death which causes flames to dance over "
                 "$target_name!" }),
     }) );
   }

