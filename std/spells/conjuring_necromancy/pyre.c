//
// The 'pyre'
// Created by Zaxan@Haven
//
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("pyre");
   SetRules("");

   SetEnhanceSkills( ({ "fire magic" }) );
   SetSkills( ([
     "conjuring" : 175,
     "necromancy" : 175,
     ]) );
   SetDamageType(HEAT);
   SetStaminaCost(100, 100);
   SetAutoDamage(0);
   SetAreaSpell(1);
   SetSpellType(SPELL_COMBAT);
   SetDifficulty(100);
   SetMessages(({ 
     ({"", "$agent_possessive_noun %^CYAN%^eerie %^BLUE%^flames%^RESET%^ miss $target_name." }),
     ({"", "$agent_possessive_noun %^CYAN%^eerie %^BLUE%^flames%^RESET%^ char $target_name." }),
     ({"", "$agent_possessive_noun %^CYAN%^eerie %^BLUE%^flames%^RESET%^ dance hungrily around $target_name!" })
   }));
  SetHelp(
    "Warring necromancers tired of assaults by their rivals' creations "
    "developed this spell to end such distractions and return to their "
    "studies. Though intended to ignite hordes of undead at once, "
    "living subjects have also described the experience as quite painful, "
    "albeit briefly."  
  );
}

int eventCast(object who, int level, mixed limb, object array targets) {
  int total_damage = 0;
  int damageboost = 0;
  if (!userp(who)) level = GetMaxSpellLevel(who);

  send_messages("snap","$agent_name $agent_verb $agent_possessive_noun fingers "

    "and a %^BOLD%^WHITE%^cyclone%^RESET%^ of %^CYAN%^eerie%^BLUE%^ blue "
    "%^CYAN%^flames%^RESET%^ erupt around $agent_objective.",
    who, who, environment(who) );

  if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
     who->eventPrint("Your powers fail you.");
     return 0;
  }

  foreach(object target in targets) {
    string array tmp;
    int damage;
    
    if( !target ) {
      continue;
    }
    
    damage = (GetDamage(level));
    
    // handle boost skill
    damageboost = who->GetSkillLevel("fire magic") / (GetSpellLevel() * 2);
    if (damageboost > 3) damageboost = 3;
    damage += damage * damageboost;
    
    // deal more damage to undead, a little less to others.
    if(target->GetUndead()) {
      damage *=2; 
    } else {
      damage *= 0.75; 
    }
    damage = target->GetDamageInflicted(who, GetDamageType(), damage, GetAutoDamage(), limb);
    tmp = GetMessage(damage);
    send_messages(tmp[0], tmp[1], who, target, environment(who));
    // describe more damage to undead.
    if(target->GetUndead()) {
      send_messages("",
        "The flames %^BOLD%^BLUE%^SURGE%^RESET%^ as they strike $target_name!",
        who,target,environment(target));
    }
    damage = target->eventInflictDamage(who, GetDamageType(), damage, GetAutoDamage(), limb);
    
    total_damage += damage;
    
  }
  return total_damage/sizeof(targets);
}
