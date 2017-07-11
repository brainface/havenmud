#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   ::create();
   SetSong("staccato");
   SetRules("","LIV");
   SetMagicCost(20,5);
   SetSongType(SONG_COMBAT);
   SetAutoDamage(1);
   SetSkills( ([
       "vocal music" : 20,
            ]) );
   SetDifficulty(5);
   //SetDamage(MAGIC,50,5);
   SetDamageType(SOUND);
   SetMessages( ({
                   ({ "","$agent_possessive_noun "
                      "voice sharply pierces "
                      "$target_name with %^RED%^"
                      "staccato%^RESET%^.", }),
                   ({ "sing","$agent_name $agent_verb "
                      "%^RED%^staccato%^RESET%^ at "
                      "$target_name, hurting "
                      "$target_objective.", }),
                   ({ "sing","$agent_name $agent_verb "
                      "%^RED%^staccato%^RESET%^ "
                      "with sharp, fierce notes, "
                      "causing $target_name to wince "
                      "from the pain." }),
              }) );
   SetHelp("When a bard sings staccato, sharp, "
           "vibrant noises come from his "
           "mouth, hurting his target.");
}


/* Approved by Duuktsaryth on Thu Dec 31 21:10:38 1998. */


