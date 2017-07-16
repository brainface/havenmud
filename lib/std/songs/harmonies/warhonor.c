#include <lib.h>
#include <damage_types.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("warrior's honor");
  SetRules("", "LIV");
  SetSongType(SONG_DEFENSE);
  SetShieldType(SHIELD_DAMAGE);
  SetSkills( ([
    "instrumental music" : 35,
    "vocal music" : 35,
    ]) );
  SetMagicCost(50, 50);
  SetDifficulty(50);
  SetHelp("This song about a valiant and honorable warrior who defended himself "
     "against great odds and survived. The harmony of the song creates a protective "
     "shield around the target, protecting them against all physical damage.");
  SetProtectionTypes(ALL_PHYSICAL);
  SetMessages( ({
    ({  ({ "sing", "play" }), 
        "$agent_name $agent_verb and $agent_verb a song about a valiant "
               "warrior. The song ripples slightly "
               "around $target_name creating a %^ORANGE%^flickering shield%^RESET%^." }),
    ({ "strike", "The %^ORANGE%^BOLD%^flickering shield%^RESET%^ around "
              "$agent_name makes an eerie humming noise "
           "as $target_name $target_verb it." }),
    ({ "", "The %^ORANGE%^BOLD%^flickering shield%^RESET%^ around "
           "$agent_name disperses as its melody fades "
           "into silence." }),
    }) );
 }

