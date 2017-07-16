#include <lib.h>
#include <magic.h>
#include <position.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("feign death");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
    "illusion" : 104,
    ]) );
  SetMagicCost(100, 100);
  SetDifficulty(20);
  SetHelp("Using this spell, the caster attempts to fall down and play dead. "
          "This could be fairly useful under certain conditions. \n"
          "Especially when trying to avoid actually being dead.");
}

int eventCast(object who, int level, mixed limbs, object *targets) {
  object env     = environment(who);
  targets = who->GetEnemies();
  send_messages( ({ "drop", "appear" }),
    "%^RED%^" + who->GetCapName() + " $agent_verb to the ground and $agent_verb dead.%^RESET%^",
    who, 0, env);
  who->SetPosition(POSITION_LYING);
  
  if (!sizeof(targets)) {
    who->eventForce("smirk");
    }
  foreach(object target in targets) {
    if (target->GetStatLevel("intelligence") < random(who->GetStatLevel("luck")) + level) {
      target->eventEnemyDied(who);
      send_messages( ({ "are", "has" }), 
        "$target_name $target_verb %^YELLOW%^completely convinced%^RESET%^ that $agent_name $agent_verb died.",
        who, target, env);
      } else {
      send_messages( ({ "are", "has" }), 
        "$target_name $target_verb %^RED%^not convinced%^RESET%^ that $agent_name $agent_verb died.",
        who, target, env);
      }
  }
  return 1;
}