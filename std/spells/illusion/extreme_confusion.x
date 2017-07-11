#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("extreme confusion");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
    "illusion" : 120,
    ]) );
}

int eventCast(object who, int level, mixed limb, object *targets) {
  object target = targets[0];
  int target_recovery = target->GetRecoveryTime();
  int para_flag = (level >= 75);
  
  send_messages( ({ "begin" }),
    "$agent_name $agent_verb to shout a confusing series of nonsense words "
    "at $target_name.", who, target, environment(who) );
  
  if (target_recovery <= level) {
    target->SetRecoveryTime(level);
    send_messages( ({ "appear" }),
      "$target_name $target_verb %^BOLD%^MAGENTA%^confused%^RESET%^ by the sheer idiocy "
      "of $agent_possessive_noun gibberish!", who, target, environment(who) );
  }
  if (para_flag) {
    target->AddParalyzed(2);
    send_messages( ({ "are" }),
      "$target_name $target_verb %^BOLD%^MAGENTA%^stunned%^RESET%^ by the level of stupidity "
      "of $agent_possessive_noun nonsensical babbling!", who, target, environment(who) );
  }
  return 1;
}