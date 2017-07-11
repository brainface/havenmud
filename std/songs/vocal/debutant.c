// Amelia
// mahk2015--made SOUND damage
#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   ::create();
   SetSong("debutant aria");
   SetRules("","LIV");
   SetMagicCost(10,5);
   SetSongType(SONG_COMBAT);
   SetAutoDamage(1);
   SetSkills( ([
       "vocal music" : 5,
            ]) );
   SetDifficulty(5);
   //SetDamage(MAGIC,20,5);
   SetDamageType(SOUND);
   SetMessages( ({
                   ({ "start","$agent_name "
                      "$agent_verb to sing "
                      "$agent_possessive "
                      "%^MAGENTA%^debutant "
                      "aria%^RESET%^ with the same "
                      "grating noises as "
                      "$agent_possessive first "
                      "time, harming $target_name.", }),
                   ({ "sing","$agent_name $agent_verb "
                      "to $target_name with "
                      "harsh, unpracticed "
                      "sounds, reminiscent of "
                      "$agent_possessive %^MAGENTA%^"
                      "debutant aria%^RESET%^.", }),
                   ({ "sing","$agent_name $agent_verb "
                      "with piercing high notes "
                      "and shrieking noises to "
                      "$target_name, painfully "
                      "alike to a %^MAGENTA%^ "
                      "debutant aria%^RESET%^." }),
              }) );
   SetHelp("Reminiscent of the bard's first time singing, "
           "this debutant aria harshly grates upon "
           "the target's ears, causing pain and "
           "discomfort.");
}

