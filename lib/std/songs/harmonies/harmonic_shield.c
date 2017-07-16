/* ----------------------------------------------------------------------- */
// Filename: harmonic_shield.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Dec 19th, 1998
// Abstract: This is a shielding song against magical damage.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <damage_types.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("harmonic shield");
  SetRules("", "LIV");
  SetSongType(SONG_DEFENSE);
  SetShieldType(SHIELD_TIMED);
  SetSkills( ([
    "vocal music" : 1,
    "instrumental music" : 1,
    ]) );
  SetMagicCost(15, 15);
  SetDifficulty(18);
  SetHelp("Harmonic Shield is a vocal technique that allows "
          "the vocalist to create a shield of protection against magical "
          "damage for a short while. It basically creates a reverbing "
          "note that sustains itself for the duration of the effect.  "
          "Once perfected, it is an invaluable resource of the vocalist.");
  SetProtectionTypes(MAGIC|ALL_ELEMENTS);
  SetProtectionAmount(6);
  SetProtectionTime(15);
  SetMessages( ({
    ({  ({ "sing", "play" }), "$agent_name $agent_verb and "
               "$agent_verb a single note of such "
               "intensity that it creates a %^GREEN%^%^BOLD%^harmonic "
               "shield%^RESET%^ around $target_name." }),
    ({ "strike", "The %^GREEN%^BOLD%^harmonic shield %^RESET%^around "
              "$agent_name makes an eerie humming noise "
           "as $target_name $target_verb it." }),
    ({ "", "The %^GREEN%^BOLD%^harmonic shield %^RESET%^around "
           "$agent_name disperses as its harmonics gently fade "
           "into silence." }),
    }) );
 }
