/*    
 * Heal
 * Thoin@haven
 * 01-08-06
 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() 
{
  spell::create();
  SetSpell("heal");
  SetRules("", "LIV");
  SetAutoHeal(1);
  SetSpellType(SPELL_HEALING);
  SetSkills( ([
     "healing" : 100,
     "faith"   : 100,
  ]) );
  SetMagicCost(100,100);
  SetDifficulty(75);
  SetHealing(400,400);
  SetMorality(3);
  SetMessages(({ ({ "are", "$target_name $target_verb no better off." }),
    ({ "are", "$target_name $target_verb looking somewhat healthier." }),
    ({ ({ "heal", "provide" }), "With a small prayer $agent_name "
      "$agent_verb $target_name with divine light." }) }));
  SetHelp(
     "This spell greatly heals the target, or yourself if "
     "you specify no target.");
}
