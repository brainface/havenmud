#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   ::create();
   SetSong("vulgar verse");
   SetRules("","LIV");
   SetMagicCost(50,50);
   SetAutoDamage(0);
   SetSongType(SONG_COMBAT);
   SetSkills( ([
     "vocal music" : 40,
   ]) );
   SetDifficulty(50);
   SetDamageType(SHOCK); //,125,125);
   SetEnhanceSkills( ({ "shock magic" }) );
   SetMessages( ({
     ({ ({"chant", "do" }),"$agent_name smoothly $agent_verb a few barely "
       "rhyming lines leading to some punchline. $target_name $target_verb not "
       "get it." }),
     ({ "sing", "$agent_name silkily $agent_verb a few terribly obscene lines "
       "that cause the hair on $target_possessive head to stand on end and "
       "somehow smell of ozone." }),
     ({ "belt", "$agent_name bellowingly $agent_verb out a crude and vulgar "
       "verse that shocks $target_name, literally %^BOLD%^YELLOW%^SHOCKS%^RESET%^ "
       "$target_objective!" }),
   }) );
   SetHelp("Alternatively thought to be a bad joke of Parvan bards taken too "
     "far, or the weapon that caused the final downfall of wild elf civilzation "
     "and the split with their haven kin, the effects of this terribly obscene "
     "oration are no laughing matter.");
}

