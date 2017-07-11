// Eclat spell, Amelia@Haven, Dec 98
#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   song::create();
   SetSong("joyous cacophony");
  SetReligions("Eclat");
   SetRules("","LIV");
   SetMagicCost(20,5);
   SetSongType(SONG_COMBAT);
   SetAutoDamage(1);
   SetSkills( ([
                 "instrumental music" : 1,
                 "vocal music" : 1,
            ]) );
   SetDifficulty(5);
   SetDamage(MAGIC, 30, 10);
   SetMessages( ({
                   ({ "pitch","$agent_name $agent_verb "
                      "$agent_possessive instrument and voice "
                      "to conflicting notes, creating a %^RED%^cacophony "
                      "%^RESET%^that hurts $target_name." }),
                   ({ "sing","$agent_possessive_noun instrument "
                      "%^RED%^whines%^RESET%^ at high "
                      "pitches while $agent_nominative "
                      "$agent_verb painfully %^RED%^off-key%^RESET%^, "
                      "causing $target_name to shudder from the pain." }),
                   ({ "scream","$target_name $target_verb in "
                      "agony at $agent_possessive_noun "
                      "%^RED%^cacophony%^RESET%^.", }),
              }) );
   SetHelp("Joyous cacophony allows Eclatish chorists to "
           "use an instrument with their voice in such an "
           "off-key manner that it hurts the target.");
}


/* Approved by Duuktsaryth on Thu Dec 31 17:21:27 1998. */
