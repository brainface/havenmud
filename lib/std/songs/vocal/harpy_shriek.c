/* For the musically inept Bard.
 * Arathorn@Haven
 *
 * Modified by Rhakz@Haven
 * Made SOUND by MAHK
 */
#include <lib.h>
#include <music.h>
#include <damage_types.h>

inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("harpy's shriek");
  SetRules("", "LIV");
  SetSongType(SONG_COMBAT);
  SetSkills( ([
    "vocal music" : 10,
  ]) );
  SetMagicCost(10, 5);
  SetDifficulty(15);
  SetAutoDamage(1);
  //SetDamage(MAGIC, 15, 15);
  SetDamageType(SOUND);
  SetMessages( ({
    ({ "holler", "$agent_name $agent_verb loudly and offkey at "
                 "$target_name, causing $target_objective to flinch "
                 "in distaste." }),
    ({ "scream", "$agent_name $agent_verb loudly and offkey at "
                 "$target_name, causing $target_objective to wince "
                 "and even shed a few tears in protest." }),
    ({ "shriek", "With the fury of a harpy, $agent_name $agent_verb "
                 "at $target_name, causing a stream of %^RED%^blood%^RESET%^ to "
                 "flow from $target_possessive ears." })
  }) );
  SetHelp("This basic combat song is a high pitched harpy scream in the "
          "direction of the enemy of the bard using it. It takes some "
          "effort for the bard to properly imitate the sound of a harpy.");
}


/* Approved by Rhakz on Tue Jan 12 20:06:13 1999. */

