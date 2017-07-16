// Thoin
// 1-25-06

#include <lib.h>
#include <dirs.h>
#include <magic.h>


inherit LIB_SPELL;

static void create(){
        spell::create();
        SetSpell("persistent bane");
        SetSpellType(SPELL_OTHER);
        SetRules("");
        SetSkills( ([
           "necromancy" : 175,
           "faith" : 175,
                ]) );
        SetMagicCost(150,200);
        SetRecoveryTime(15);
        SetDifficulty(195);
        SetReligions("Thorian");
        SetHelp(
                "This unusual spell allows a Thorian cleric to infect an area with "
                "poison that slowly spreads into the food in the area, tainting it all.");
}

int CanCast(object who, int level, mixed spell, object array targets) {
  object target = targets[0];
  object env = environment(who);

  if(env->GetProperty("poison_field")) {
    message("system", "The area already has a poison field.", who);
    return 0;
  }   
  return spell::CanCast(who, level, spell, targets);
}

varargs int eventCast(object who, int level, mixed b, object *targets) {
   int time, damage;
   object caster = who;
   object target = targets[0];
   object env = environment(who);
   object lhfield;
   damage = GetDamage(level);
   
  send_messages( ({ "cough" }),
     "$agent_name%^BOLD%^%^BLACK%^ $agent_verb %^RESET%^up a small fly.",
     who, environment(), environment(who));
     
  env->SetProperty("poison_field", 1);
  lhfield = new(DIR_SPELLS "/obj/pbane_ob.c");
  lhfield->SetCountDown(10 + random(10) );
  lhfield->eventMove(env);
  lhfield->SetMaster(who->GetKeyName());
  lhfield->SetDamageAmount(damage);

  return 1;
}
