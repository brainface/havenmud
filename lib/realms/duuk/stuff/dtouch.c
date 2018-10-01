/*  Divine Touch
 * Thoin@Haven
 */
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("divine touch");
  SetRules("OBJ");
  SetMagicCost(100, 100);
  SetSpellType(SPELL_OTHER);
  SetDifficulty(200);
  SetSkills( ([
      "faith" : 200,
      "enchantment" : 200,
    ]) );
  SetHelp("A powerful cleric is able to call upon their god to permanetly bless "
      "an object greatly increasing its strength and power.");
  }


varargs int eventCast(object who, int level, mixed blah, object *targets) {
  int amt;

  amt = (who->GetSkillLevel("faith")/10 + level/10 + who->GetSkillLevel("enchantment")/20);
  
  if (amt > 100) {amt = 100;}

  send_messages( ({"kneel", "kiss"}),
       "$agent_name $agent_verb down and $agent_verb $target_name causing $target_nominative "
       "to %^BOLD%^%^WHITE%^glow%^RESET%^ with divine energies.",
        who, targets[0], environment(who));
  targets[0]->SetProperty("blessed", amt);
  return 1;
  }
