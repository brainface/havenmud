#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   ::create();
   SetSong("aria of air");
   SetRules("","LIV");
   SetMagicCost(100,100);
  SetAutoDamage(0);
   SetSongType(SONG_COMBAT);
   SetSkills( ([
       "vocal music" : 105,
            ]) );
   SetDifficulty(75);
   //SetDamage(GAS|POISON,550,550);
   SetEnhanceSkills( ({ "poison magic" }) );
   SetDamageType(GAS|POISON);
   SetMessages( ({
                   ({ "sing","$agent_possessive_noun singing "
                        "causes the air around $target_name to "
                        "turn %^MAGENTA%^purple%^RESET%^.", }),
                   ({ "sing","$agent_name $agent_verb the aria "
                        "of air at $target_name, causing the "
                        "air around $target_objective to "
                        "to turn %^MAGENTA%^purple%^RESET%^ "
                        "and %^BLUE%^blue%^RESET%^ with poison." }),
                   ({ "sing","$agent_name $agent_verb the aria "
                        "of air at $target_name, causing the air "
                        "around $target_objective to turn "
                        "%^MAGENTA%^purple%^RESET%^, %^BLUE%^blue"
                        "%^RESET%^, and %^GREEN%^green%^RESET%^ "
                        "with poisonous fumes." }),
              }) );
   SetHelp("The bard sings the aria of air causing a cloud of poisonous gas to surround their target and damage them.");
}

