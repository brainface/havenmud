/*  Avalanche spell */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("frostbite");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "conjuring" : 500,
     "evokation" : 500,
     ]) );
  SetAutoDamage(0);
  SetDamageType(COLD);
  SetEnhanceSkills( ({ "ice magic" }) );
  SetMessages( ({
   ({ "strike", "$agent_name $agent_verb out at $target_name with a %^BLUE%^frozen touch%^!" }),
   ({ "hurl", "$agent_name $agent_verb %^BOLD%^BLUE%^a massive icicle%^RESET%^ which freezes $target_name!" }),
   ({ "", "A %^BOLD%^BLUE%^massive burst of icy doom%^RESET%^ chills $target_name at $agent_possessive_noun cold whim!" })
   }) );
  SetHelp(
    "This spell creates a freezing chill which can cause severe damage to the target."   
   );
  SetDifficulty(120);
}
