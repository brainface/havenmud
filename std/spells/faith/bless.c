#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;


static void create() {
  spell::create();
  SetSpell("bless");
  SetRules("OBJ", "LIV");
  SetSpellType(SPELL_OTHER);
  SetMagicCost(20, 20);
  SetSkills( ([
    "faith" : 1,
    ]) );
  SetHelp(
    "Blesses an object or person, causing it to perform better in combat."
    );
}

varargs int eventCast(object who, int level, mixed blah, object *targets) {
  int amt, time;
  object target = targets[0];
  amt = who->GetSkillLevel("faith") * level/100;
  if (amt < 1) amt = 1;
  if (amt > 20) amt = 20;
  
  // mahkefel 2014: no idea if this has any effect on vehicles.
  // fixed a display bug, though at least.
  if (vehiclep(target)) {
    time = level + (who->GetSkillLevel("faith"));
    send_messages("bless",
     "$agent_name%^BOLD%^BLUE%^ $agent_verb%^RESET%^ the ship.",
      who, target, environment(who));
      target->eventBless(amt, time);
    return 1;
  }
  
  if (!living(target)) {
    time = level + (who->GetSkillLevel("faith"));
    send_messages("bless",
     "$agent_name%^BOLD%^BLUE%^ $agent_verb%^RESET%^ $target_name.",
      who, target, environment(who));
      target->eventBless(amt, time);
    return 1;
  }
  if (living(target)) {
    send_messages("bless",
     "$agent_name%^BOLD%^BLUE%^ $agent_verb%^RESET%^ $target_name.",
      who, target, environment(who));
    target->AddBlessed(amt);
    return 1;
  }
  return 1;
}

