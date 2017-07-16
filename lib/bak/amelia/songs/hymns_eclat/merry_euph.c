// eclat song, Amelia@Haven, Dec 98
#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   song::create();
   SetSong("merry euphony");
  SetReligions("eclat");
   SetRules("","LIV");
   SetMagicCost(5,5);
   SetSongType(SONG_HEALING);
   SetAutoHeal(1);
   SetSkills( ([
                 "vocal music" : 1,
            ]) );
   SetDifficulty(10);
   SetHealing(10,10);
   SetMessages( ({
                   ({ "","$agent_possessive_noun %^BLUE%^sweet voice "
                      "%^RESET%^heals $target_name a little." }),
                   ({ "mend", "Singing in a gentle, calming voice,%^BLUE%^ "
                     "$agent_name $agent_verb $target_name.%^RESET%^" }),
                   ({ ({ "sing","are" }),"$agent_name $agent_verb with such "
                      "%^BLUE%^mellifluous euphony%^RESET%^ that $target_name "
                      "$target_verb some.", }),
              }) );
   SetHelp("Merry euphony allows eclatish chorists to mend "
           "with their sweet voices.");
}
