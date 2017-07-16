/*  A spell to mend wood
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("mend material");
  SetRules("OBJ");
  SetSpellType(SPELL_OTHER);
  SetDifficulty(20);
  SetSkills( ([
     "natural magic" : 175,
     "enchantment" : 175,
      ]) );
  SetRequiredMagic(80);
  SetMagicCost(60, 20);
  SetHelp(
       "Attempts to repair an object by use of natural magic. This spell can "
       "repair an object made of any material.");
  }

varargs int CanCast(object who, int level, mixed n, object *t) {
  object tg = t[0];
  
  if (!tg->GetDeterioration()) {
    who->eventPrint("But " + tg->GetShort() + " needs no mending!");
    return 0;
  }
  return ::CanCast(who, level, n, t);
}

varargs int eventCast(object who, int level, mixed n, object *t) {
  object target = t[0];

  if( (random(100) - (who->GetSkillLevel("natural magic") - 100)) < level ) {
    send_messages( ({ "study", "cause" }),
       "$agent_name $agent_verb $target_name, $agent_verb "
       "it to look much better!",
       who, target, environment(who) );
      target->eventRepair(who, environment(who), 1);
      return 1;
     }
  send_messages( ({ "study" }),
       "$agent_name $agent_verb $target_name, but nothing happens.",
        who, target, environment(who) );
      return 1;
    }
