/*  Avalanche spell */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("fireburst");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "conjuring" : 600,
     "evokation" : 600,
     ]) );
  SetAutoDamage(0);
  SetDamageType(HEAT);
  SetEnhanceSkills( ({ "fire magic" }) );
  SetMessages( ({
   ({ "strike", "$agent_name $agent_verb out at $target_name with a %^RED%^fiery burst%^!" }),
   ({ "hurl", "$agent_name $agent_verb %^BOLD%^RED%^a massive burst of fire%^RESET%^ at $target_name!" }),
   ({ "", "A %^BOLD%^RED%^massive explosion of fire%^RESET%^ burns $target_name at $agent_possessive_noun fiery command!" })
   }) );
  SetHelp(
    "This spell creates a burst of fire which can cause severe damage to the target."   
   );
  SetDifficulty(120);
}
