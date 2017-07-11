#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("soul taint");
  SetSkills( ([
    "faith" : 200,
    "necromancy" : 200,
  ]) );
  SetRules("","LIV");
  SetMagicCost(100,100);
  SetSpellType(SPELL_OTHER);
  SetReligions("Saahagoth");
  SetMaximumMorality(-2000);
  SetDifficulty(190);
  SetHelp(
    "This spell is known only to those of the unholy nature. The spell "
    "itself allows the caster to taint the soul of their target lowering "
    "their alignment."
  );
}

varargs int eventCast(object who, int level, mixed b, object array targets) {
  object target = targets[0];
  int resist;
  int chance = level + who->GetSkillLevel("necromancy");
  chance += random((int)who->GetSkillLevel("faith"));
  resist = target->GetMagicResistance() + target->GetLevel();

  if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
    who->eventPrint("Your powers fail you.");
    return 0;
  }

  if(chance < resist) {
    send_messages("blurt","$agent_name $agent_verb out some words, but they "
      "don't make any sense.",who,target,environment(who));
    return 1;
  } 
  else {
    send_messages("scream","$agent_name $agent_verb as a %^BOLD%^%^BLACK%^cloud%^RESET%^ "
      "spews from $agent_possessive body wrapping around $target_name "
      "tainting $target_possessive %^BOLD%^%^CYAN%^soul%^RESET%^."
      ,who,target,environment(who));
    if(userp(target)){
      target->SetAttack(who);
    }
    target->eventMoralAct(-level/5);
    return 1;
  }
}

