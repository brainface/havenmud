#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("confusion");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
    "illusion" : 52,
    ]) );
  SetHelp("You babble a confusing litany of language so devoid of meaning "
    "and order that the listener is left at a loss for words or any other "
    "meaningful response.");
}

int eventCast(object who, int level, mixed limb, object *targets) {
  object target = targets[0];
  int target_recovery = target->GetRecoveryTime();
  int para_flag = (level >= 75);
  
  // Does this make it scale with char level? Mahk 2017
  // (like... they all had the same effect, same output... should just be 1 spell?)
  if( CanAttack(who, targets, who->GetLevel() + level/5) == - 1 ) {
    who->eventPrint("Your powers fail you.");
    return 0;
  }

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

