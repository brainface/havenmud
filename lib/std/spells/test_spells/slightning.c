#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

void eventElec();

static void create() {
   spell::create();
   SetSpell("sheet lightning");
   SetRules("","LIV");
   SetSpellType(SPELL_COMBAT);
   SetUniqueSpell(1);
   SetSkills( ([
    "conjuring" : 500,
    "evokation" : 500,
   ]) );
   SetAutoDamage(0);
   SetDamageType(SHOCK);
   SetMorality(0);
   SetDifficulty(120);
   SetEnhanceSkills( ({ "shock magic" }) );
   SetMessages( ({ 
    ({ "destroy", 
      "$agent_name $agent_verb $target_name with a powerful lightning strike." }),
    ({ "are",
      "$target_name $target_verb %^RED%^obliterated%^RESET%^ by " +
      "$agent_possessive_noun lightning strike." }),
    ({ "eradicate",
      "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ $target_name with a " +
      "massive lightning strike." }),
    }) );
   SetHelp(
     "This spell creates a sheet of lightning that will strike the caster's target "
     "doing massive amount of damage. Sometimes lightning strikes twice. "
     );
}

int eventCast(object who, int level, mixed limb, object array targets) {
    object target = targets[0];
    int damage, damageboost;    
    damage = GetDamage(level);
        damageboost = who->GetSkillLevel("shock magic") / (GetSpellLevel() * 2);
        if (damageboost > 3) damageboost = 3;
        damage += damage * damageboost;
        
   if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
           return ::eventCast(who, level, limb, targets);
      } else {
      if( random(level) > 50 ) {
      send_messages("",
        "The %^RED%^BOLD%^lightning%^RESET%^ dancing around $target_name strikes "
        "$target_possessive_noun body.",who, target, environment(target));
      target->eventForce("scream painfully");
      target->eventReceiveDamage(who, SHOCK, damage, GetAutoDamage());
    return ::eventCast(who, level, limb, targets);
   }
 }
  return ::eventCast(who, level, limb, targets);
}
