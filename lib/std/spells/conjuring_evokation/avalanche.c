/*  Avalanche spell */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("avalanche");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "conjuring" : 150,
     "evokation" : 150,
     ]) );
  SetAutoDamage(0);
  SetDamageType(COLD);
  SetEnhanceSkills( ({ "ice magic" }) );
  SetMessages( ({
   ({ "create", "Snowflakes%^BLUE%^ flitter%^RESET%^ around $target_name as $agent_name $agent_verb a cold front!" }),
   ({ "summon", "$agent_name $agent_verb %^BLUE%^a cone of snow%^RESET%^ which batters $target_name." }),
   ({ "", "An %^BOLD%^BLUE%^avalanche%^RESET%^ of snow and ice assaults $target_name at $agent_possessive_noun command!" })
   }) );
  SetHelp(
    "This spell creates a sudden drop in the temperature of the area and seeks to create "
    "a snowstorm and avalance of snow to harm the target."   
   );
  SetDifficulty(120);
}
