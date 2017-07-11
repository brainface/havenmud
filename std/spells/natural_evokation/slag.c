//
// The 'acid blast' spell
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("slag");
   SetSpellType(SPELL_COMBAT);
   SetRules("", "LIV");
   SetSkills( ([
     "natural magic"  : 350,
     "evokation" : 350,
    ]) );
   SetMorality(-1);
   SetDifficulty(30);
   SetAutoDamage(0);
   SetDamageType(SLASH|PIERCE);
   SetHelp(
     "This spell summons iron from beneath the earth to strike "
     "at your foes. Unlike most natural magic assaults, this "
     "spell works indoors and underground."
     );

   SetMessages( ({
    ({ "miss", "$agent_name%^BOLD%^YELLOW%^ $agent_verb%^RESET%^ $target name with a tiny chunk of ferrous ore." }),
    ({ "scratch", "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_name with a hail of iron shavings." }),
    ({ "impale", "$agent_name $agent_verb $target_name with a jagged %^BOLD%^BLACK%^iron spike%^RESET%^!" }),
    }) );
     
}



