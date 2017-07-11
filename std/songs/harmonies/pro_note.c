/*  My first song for Haven!
 *  Duuktsaryth
 */
#include <music.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("protective note");
  SetRules("", "LIV");
  SetMagicCost(15, 15);
  SetSkills( ([
    "vocal music" : 10,
    "instrumental music" : 10,
    ]) );
  SetDifficulty(25);
  SetProtectionTypes(ALL_PHYSICAL);
  SetSongType(SONG_DEFENSE);
  SetShieldType(SHIELD_DAMAGE);
  SetProtectionAmount(25);
  SetMessages( ({
     ({ "sing", "$agent_name $agent_verb a %^YELLOW%^deep and powerful note"
                 "%^RESET%^ that seems to hang in the air around $target_name." }),
    ({ "", "The protective note around $agent_name %^YELLOW%^deflects "
           "%^RESET%^some of $target_possessive_noun attack." }),
    ({ "", "The%^RED%^ protective note%^RESET%^ around $agent_name "
           "quietly disperses." }),
    }) );
  SetHelp("This song of defense protects a living target "
          "from a certain amount of physical harm.");
 }
