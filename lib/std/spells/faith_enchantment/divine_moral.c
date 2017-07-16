/* Was Discern Morality
Edited by Ukla for use by clerics  */
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;
static void create() {
  spell::create();
  SetSpell("divine morality");
  SetSpellType(SPELL_OTHER);
  SetRules("LIV");
  SetSkills( ([
    "enchantment" : 20,
    "faith" : 20,
  ]) );
  SetRequiredMagic(30);
  SetMagicCost(20,10);
  SetDifficulty(20);
  SetHelp(
            "Enables caster to divine the exact morality of the target, "
            "whether they are good, evil, or neutral.");
  }


int eventCast(object who, int level, mixed useless, object *targets) {

  object person = targets[0];
  send_messages(  ({"call", "point"}),
    "$agent_name $agent_verb upon the power of the Gods and $agent_verb "
    "at $target_name.  ",
    who, person, environment(who) );
  message("system",
    "Through your faith, you discover that "
    + capitalize(person->GetKeyName()) + " is "
    + (person->GetMoralityDescription()) + ".",
    who);
  }




/* Approved by Dylanthalus on Tue Oct 27 18:40:54 1998. */
