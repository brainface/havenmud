#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("thicken blood");
  SetSpellType(SPELL_HEALING);
  SetSkills( ([
    "natural magic" : 5,
    "healing" : 5,
    ]) );
  SetRules("", "LIV");
  SetHelp("Through use of this spell, the druid makes an attempt "
          "to slow or even stop bleeding on a given target.");
  SetDifficulty(20);
}

varargs int CanCast(object who, int level, mixed x, object *t) {
  foreach(object tr in t) {
    if (!tr->GetBleeding()) { 
      who->eventPrint(tr->GetCapName() + " is not bleeding.");
       t -= ({ tr });
      }
     }
  return (::CanCast(who, level, x, t) && sizeof(t));
}

varargs int eventCast(object who, int level, mixed x, object *t) {
  object target = t[0];
  int amount = random(who->GetSkillLevel("healing"));
  int bleed = target->GetBleeding();

  target->AddBleeding(-amount);
  if (!amount) {
    send_messages( ({ "chant", "fail" }),
      "$agent_name $agent_verb deeply but%^BOLD%^RED%^ "
       "$agent_verb%^RESET%^ to stop any of $target_possessive bleeding.",
      who, target, environment(who) );
    return 1;
    }
  if (amount < bleed) {
  send_messages( ({ "chant", "staunch" }),
    "$agent_name $agent_verb deeply and%^BOLD%^GREEN%^ "
       "$agent_verb%^RESET%^ some of $target_possessive bleeding.",
      who, target, environment(who) );
  return 1;
    }
  send_messages( ({ "chant", "halt" }),
      "$agent_name $agent_verb deeply and%^BOLD%^RED%^ "
       "$agent_verb%^RESET%^ all of $target_possessive bleeding.",
      who, target, environment(who) );
  return 1;
}
