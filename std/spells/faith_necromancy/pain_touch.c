//-- Torak@Haven --//
//-- based of disintegrate --//
//-- Faith Necro --//
//-- Pain Touch --//

#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("pain touch");
  SetDifficulty(40);
  SetHelp(
    "Using the evil powers of the dark priest's deity, the caster focuses "
    "a flash of pure evil into his hand, allowing the slightest touch to "
    "cause exquisite pain."
    );
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetDamageType(SHOCK);
  SetAutoDamage(0);
  SetEnhanceSkills( ({ "shock magic" }) );
  SetSkills( ([
     "necromancy" : 75,
     "faith" : 75,
      ]) );
    SetMessages( ({ 
    ({ "scratch", "$agent_name%^BLUE%^ $agent_verb%^RESET%^ $target_name "
    	            "lightly." }),
    ({ "grasp", "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ hold of $target_name "
    	          "shocking $target_objective badly!" }),
    ({ "zap",  "$agent_name $agent_verb%^RED%^ $target_name%^RESET%^ with a touch "
    	         "of $agent_possessive palm." }),
     }) );
}


/* Approved by Zeddicus on Fri Jul  2 21:25:43 1999. */
