/* For the pyro in all of us,
 * Malak@Haven
 */
#include <lib.h>
#include <music.h>
#include <damage_types.h>

inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("fire chant");
  SetRules("", "LIV");
  SetSongType(SONG_COMBAT);
  SetRequiredMagic(10);
  SetSkills( ([
    "vocal music" : 50,
  ]) );
  SetMagicCost(10, 5);
  SetDifficulty(5);
  SetMorality(0);
  SetAutoDamage(0); 
  SetDamage(HEAT, 200, 210);
  SetMessages( ({
  ({ "chant", "$agent_name $agent_verb ominously at "
               "$target_name, causing $target_objective to burn "
               "and wince in pain." }),
    ({ "scream", "$agent_name $agent_verb out a chant, pointing a finger at "
                 "$target_name, causing $target_objective to be enveloped "
                 "in %^RED%^flames%^RESET%^." }),
    ({ "chants", "With the fury of a elemental, $agent_name $agent_verb "
                 "the words to an ancient song, causing $target_name, to "
                 "be %^RED%^enveloped%^RESET%^ by flames, bringing a scream of pain "
                 "$target_possessive lips." })
}) );
  SetHelp("This basic combat song is an ancient song passed down from "
          "bard to bard.  By chanting the words of the song, the singer "
          "brings forth the primal essence of fire to burn the target to "
          "cinders.");
}
