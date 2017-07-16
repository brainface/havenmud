#include <lib.h>
#include <daemons.h>
#include <music.h>
#include <damage_types.h>

inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("sonic barrier");
  SetRules("");
  SetProtectionTypes(ALL_DAMAGE);
  SetShieldType(SHIELD_TIMED);
  SetSongType(SONG_DEFENSE);
  SetUniqueSong(1);
  SetSkills( ([
     "vocal music"       : 200,
     "instrumental music" : 200,
     ]) );
  SetMagicCost(150, 150);
  SetDifficulty(200);
  SetMorality(0);
  SetHelp(
  "This song creates a a barrier of sonic waves around the singer "
  "protecting them from all damage for the duration of the song."
  );
  SetMessages( ({ 
        ({ "hum", "$agent_name $agent_verb a single continuous note, causing the "
       "air around $agent_objective to ripple and form into a %^BOLD%^%^YELLOW%^barrier of sound%^RESET%^ that surrounds "
       "$agent_objective." }),
    ({ "strike", "The %^BOLD%^%^BLUE%^air%^RESET%^ around $agent_name ripples slightly as "
       "$target_name $target_verb it!" }),
    ({ "", "The %^WHITE%^sound barrier%^RESET%^ around $agent_name fades into nothingness." }),
    }) );
}
