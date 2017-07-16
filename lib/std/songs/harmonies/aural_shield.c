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
  SetSong("aural shield");
  SetRules("", "LIV");
  SetSongType(SONG_DEFENSE);
  SetShieldType(SHIELD_TIMED);
  SetSkills( ([
    "vocal music" : 75,
    "instrumental music" : 75,
    ]) );
  SetMagicCost(75, 50);
  SetDifficulty(25);
  SetHelp("Aural Shield is a musical technique that allows "
          "the vocalist to create a shield of protection against all "
          "damage for a short while. It basically creates a reverbing "
          "note that sustains itself for the duration of the effect.  "
          "Once perfected, it is an invaluable resource of the vocalist.");
  SetProtectionTypes(ALL_EXTERNAL);
  SetProtectionAmount(100);
  SetProtectionTime(15);
  SetMessages( ({
    ({  ({ "sing", "play" }), 
        "$agent_name $agent_verb and $agent_verb a song of such "
               "intensity that it creates an %^MAGENTA%^%^BOLD%^aural "
               "shield%^RESET%^ around $target_name." }),
    ({ "strike", "The %^MAGENTA%^BOLD%^aural shield %^RESET%^around "
              "$agent_name makes an eerie humming noise "
           "as $target_name $target_verb it." }),
    ({ "", "The %^MAGENTA%^BOLD%^aural shield %^RESET%^around "
           "$agent_name disperses as its harmonics gently fade "
           "into silence." }),
    }) );
 }
