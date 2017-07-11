// meteor swarm
// Thoin
// 1-25-06

#include <lib.h>
#include <magic.h>

int eventSwarm(object);

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("meteor swarm");
  SetSpellType(SPELL_OTHER);
  SetRules("");
  SetSkills( ([
     "conjuring" : 250,
     "evokation" : 250,
          ]) );
  SetMagicCost(400,400);
  SetRecoveryTime(25);
  SetUniqueSpell(1);
  SetDifficulty(195);
  SetHelp(
     "This powerful spell allows the caster to call down "
     "a swarm of meteors to strike everyone in the area (including "
     "the caster)."
     );
}

int CanCast(object who, int level, mixed spell, object array targets) {
  object target = targets[0];
  object env = environment(who);

  if(env->GetProperty("meteor_swarm")) {
    message("system", "The area is already being rained down upon by "
            "meteors.", who);
    return 0;
  } 
  if( (env->GetClimate() == "indoors") ){
      message("system","Your spell fizzles and refuses to work "
              "in these types of environmental settings.",who);
      return 0;
   }
  
  return spell::CanCast(who, level, spell, targets);
}

varargs int eventCast(object who, int level, mixed b, object *targets) {
   int time, damage;
   object caster = who;
   object target = targets[0];
   object env = environment(who);
   object mswarm;
   damage = GetDamage(level);
   
  send_messages( ({ "concentrate" }),
     "$agent_name $agent_verb deeply.",
     who, environment(), environment(who));
  env->SetProperty("meteor_swarm", 1);
  mswarm = new(DIR_SPELLS "/obj/mswarm_obj.c");
  mswarm->SetCountDown(10);
  mswarm->eventMove(env);
  mswarm->SetMaster(who->GetKeyName());
  mswarm->SetDamageAmount(damage);
  return 1;
}
