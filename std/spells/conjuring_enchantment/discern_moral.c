#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;
static void create() {
  spell::create();
  SetSpell("detect morality");
  SetSpellType(SPELL_OTHER);
  SetRules("LIV");
  SetSkills( ([
    "conjuring" : 20,
    "enchantment" : 20,
  ]) );
  SetMagicCost(20, 10);
  SetDifficulty(30);
  SetHelp(
          "Enables caster to detect the exact morality of the target, "
          "whether they are good, evil, or neutral.");
  }


int eventCast(object who, int level, mixed useless, object *targets) {

  object person = targets[0];
  send_messages("raise",
    "$agent_name $agent_verb an inquisitive eyebrow at $target_name.",
    who, person, environment(who) );
  message("system",
    "Through your divinational abilities, you discover that "
    + capitalize(person->GetKeyName()) + " is "
    + (person->GetMoralityDescription()) + ".",
    who);
  }


/* Approved by Zaxan on Wed Apr  8 01:01:03 1998. */
