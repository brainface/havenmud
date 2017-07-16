#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("halt bleeding");
  SetSpellType(SPELL_HEALING);
  SetSkills( ([
     "faith"   : 10,
     "healing" : 10,
    ]) );
  SetRules("", "LIV");
  SetHelp("Through use of this spell, the cleric makes an attempt "
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
  int amount = random(who->GetSkillLevel("faith"));
  int bleed = target->GetBleeding();

  target->AddBleeding(-amount);
  if (!amount) {
    send_messages( ({ "pray", "fail" }),
      "$agent_name $agent_verb mightily but%^BOLD%^RED%^ "
       "$agent_verb%^RESET%^ to stop any of $target_possessive bleeding.",
      who, target, environment(who) );
    return 1;
    }
  if (amount < bleed) {
  send_messages( ({ "pray", "staunch" }),
    "$agent_name $agent_verb mightily and%^BOLD%^GREEN%^ "
       "$agent_verb%^RESET%^ some of $target_possessive bleeding.",
      who, target, environment(who) );
  return 1;
    }
  send_messages( ({ "pray", "halt" }),
      "$agent_name $agent_verb mightily and%^BOLD%^RED%^ "
       "$agent_verb%^RESET%^ all of $target_possessive bleeding.",
      who, target, environment(who) );
  return 1;
}
