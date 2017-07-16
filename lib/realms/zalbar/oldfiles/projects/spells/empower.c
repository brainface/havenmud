/*  Empower Spell
 *  Malak@Haven
 */
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("empower");
  SetRules("OBJ", "LIV");
  SetMagicCost(75, 75);
  SetSpellType(SPELL_OTHER);
  SetDifficulty(80);
  SetSkills( ([
      "faith" : 100,
      "enchantment" : 100,
    ]) );
  SetHelp("Gives an object the empowering touch of his or her god, "
      "greatly increasing the object's strength and power.");
  }

varargs int eventCast(object who, int level, mixed blah, object *targets) {
  int amt, time;

  amt = (who->GetSkillLevel("faith")/10 + level/10);
  time = (who->GetSkillLevel("faith") * 2);

  send_messages("empower",
       "$agent_name $agent_verb $target_name.",
        who, targets[0], environment(who));
  targets[0]->eventBless(amt, time);
  return 1;
  }



/* Approved by Rhakz on Thu Jan  7 03:22:44 1999. */
