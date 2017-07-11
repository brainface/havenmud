/*  My first song for Haven!
 *  Duuktsaryth
 */
#include <music.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("shielding song");
  SetRules("", "LIV");
  SetMagicCost(10, 10);
  SetMagicCost(10, 10);
  SetSkills( ([
    "vocal music" : 1,
    ]) );
  SetDifficulty(20);
  SetProtectionTypes(ALL_PHYSICAL);
  SetSongType(SONG_DEFENSE);
  SetShieldType(SHIELD_DAMAGE);
  SetProtectionAmount(25);
  SetMessages( ({
     ({ "chant", "$agent_name $agent_verb and a %^YELLOW%^shield "
                 "%^RESET%^seems to form around $target_name." }),
    ({ "", "The song-shield around $agent_name %^YELLOW%^deflects "
           "%^RESET%^some of $target_possessive_noun attack." }),
    ({ "", "The%^RED%^ song-shield%^RESET%^ around $agent_name "
           "falls into legend." }),
    }) );
  SetHelp("This song of defense protects a living target "
          "from a certain amount of physical harm.");
 }
