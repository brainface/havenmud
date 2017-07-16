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
  SetSpell("immersion");
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
  SetMinimumMorality(-500);
  SetMaximumMorality(500);
  SetReligions("Damhair");
  SetMessages(({ 
    ({ "are", "$target_name $target_verb not overly affected by the immersion." }),
    ({ "look", "$target_name $target_verb somewhat better after being immersed in water." }),
    ({ ({ "immerse", }), "With a small prayer $agent_name "
      "$agent_verb $target_name in a blessed, healing water." }) }));
  SetHelp(
     "This spell greatly heals the target by immersing them in the waters of the drowned god."
     );
}
