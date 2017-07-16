//  Shatter
//  Thoin@haven
//
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("shatter");
  SetSpellType(SPELL_OTHER);
  SetRules("OBJ");
  SetMagicCost(250,500);
  SetSkills( ([
     "faith" : 250,
     "evokation" : 250,
     ]) );
  SetDifficulty(230);
  SetHelp(
          "Attempts to destroy an object by using the faith of the caster. "
          "Because this spell requires such great faith it can sometimes backfire."
          );
  }

varargs int eventCast(object who, int level, mixed limb, object *t) {
  object target = t[0];
  int damage = GetDamage(level);
  if (random(10)){
       object array eq = all_inventory(who);
    if(sizeof(eq)) {
      object thing = (eq[random(sizeof(eq))]);
            send_messages("fumble", "$agent_name $agent_verb $agent_possessive prayer "
                          "causing $target_name to crack and break.",who, 
                           target, environment(who));
            thing->eventDeteriorate();
           who->eventReceiveDamage(who, HEAT, damage/3, 0, limb);
    } else {
            send_messages("fumble", "$agent_name $agent_verb $agent_possessive prayer "
                          "causing $agent_name to scream as $agent_possessive skin "
                          "begins to crack and melt.",who, 
                           target, environment(who));
           who->eventReceiveDamage(who, HEAT, damage/3, 0, limb);
     }
   return 1;
  } else {
  if (target->GetDeterioration() == 10) {
            send_messages("point", "$agent_name $agent_verb  at $target_name "
                          "causing $target_objective to crumble into pieces.",who, 
                           target, environment(who));
    target->eventDestruct();
    return 1;
  }
  if(random(100) < level/2) {
            send_messages("point", "$agent_name $agent_verb at $target_name "
                          "causing $target_objective to twist and crack.",who, 
                           target, environment(who));
       target->eventDeteriorate();
       environment(target)->SetAttack(who);
        return 1;
        }
  send_messages( ({ "point" }),
      "$agent_name $agent_verb at $target_name, but nothing happens.",
       who, target, environment(who) );
  return 1;
 }
}

