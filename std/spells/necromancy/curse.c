/* Curse Spell
 * Duuktsaryth@Haven
 * 31/03/2007
 */
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("curse");
  SetRules("OBJ", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
    "necromancy" : 1,
    ]) );
  SetHelp(
    "Curses an object or person, causing it to perform unreliably in combat."
    );
}

varargs int eventCast(object who, int level, mixed blah, object *targets) {
  int amt, time;
  object target = targets[0];
  amt = who->GetSkillLevel("necromancy") * level/100;
  if (amt < 1) amt = 1;
  if (amt > 20) amt = 20;
  if (!living(target)) {
    time = level + (who->GetSkillLevel("necromancy"));
    send_messages("curse",
     "$agent_name%^BOLD%^BLUE%^ $agent_verb%^RESET%^ $target_name.",
      who, target, environment(who));
      target->eventCurse(amt, time);
    return 1;
  }
  if (living(target)) {
    send_messages("curse",
     "$agent_name%^BOLD%^BLUE%^ $agent_verb%^RESET%^ $target_name.",
      who, target, environment(who));
target->AddCursed(amt);
    return 1;
  }
  return 1;
}   
