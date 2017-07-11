//
// The 'mage's bane' spell
// Created by Zaxan@Haven
//
// Changed the duration and amt variable settings to reflect the 
// the strength and duration of the similiar planar strength spell.
// Also added in a SetRecoveryTime() because of the nature of the 
// spell's effects on the caster.
// ~ Dylanthalus  06/27/99
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("mage's bane");
   SetSpellType(SPELL_OTHER);
   SetRules("LIV");
   SetSkills( ([
     "conjuring" : 50,
     "enchantment" : 50,
      ]) );
   SetMagicCost(50,25);
   SetStaminaCost(15,10);
   SetDifficulty(30);
   SetRecoveryTime(2+random(4));
   SetHelp(
           "It is rumoured that this spell allows the caster to steal "
           "the mental power of another creature and utilize it for "
           "themself.");
}

int CanCast(object who, int level, mixed limb, object array targets) {
   object target = targets[0];

   if(target == who) {
      message("system","Cast it on yourself?",who);
      return 0;
   }
    if(target->GetProperty("nature_bane") || target->GetProperty("mage_bane")) {
      message("system","For some reason, the spell refuses "
              "to make any attempt to draw "+possessive(target->GetName())+
              " intelligence.",who);
     return 0;
   }

   if(who->GetProperty("mage_bane")) {
      message("system","You seem to already be affected by this spell.", who);
   return 0;
  }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets) {
   object target = targets[0];
   int amt = (level + who->GetSkillLevel("enchantment") +
         who->GetSkillLevel("conjuring"))/10;
   int dur = (level * (15 + who->GetSkillLevel("enchantment")/20));
   int chance = level + random(who->GetSkillLevel("enchantment"));
   chance -= target->GetLevel()*5;

   if(chance < 30) {
      if(random(50) > 40) {
         send_messages(({"falter","fumble","fire"}), "$agent_name "
                       "$agent_verb and $agent_verb the spell. Amazingly, "
                       "$agent_nominative $agent_verb it upon "
                       "$agent_reflexive.",who, target, environment(who));
         message("system","You feel less intelligent.",who);
         who->AddStatBonus("intelligence", -amt, dur);
         who->SetProperty("mage_bane",1);
         call_out(function(object putz) {
            if(putz) {
               message("system","%^BOLD%^GREEN%^You feel normal "
                                "again.%^RESET%^",putz);
               putz->RemoveStatBonus("intelligence");
               putz->RemoveProperty("mage_bane");
            }
         }, dur, who);
         return 1;
      } else {
        send_messages(({"falter", "fail"}), "$agent_name $agent_verb "
                      "and $agent_verb $agent_possessive attempt at "
                      "drawing for additional intelligence.",who,target,
                       environment(who));
        return 1;
      }
   } else {
      send_messages("drain","Drawing upon great powers, $agent_name "
                    "$agent_verb intelligence from $target_name.",who,
                     target,environment(who));
      target->SetProperty("mage_bane",1);
      target->AddStatBonus("intelligence", -amt, dur);
      target->AddEnemy(who);
         who->SetProperty("mage_bane",1);
      who->AddStatBonus("intelligence", amt, dur);
      call_out(function(object caster, object castee) {
         if(caster) {
            message("system","%^BOLD%^GREEN%^You feel normal "
                    "again.%^RESET%^",caster);
            caster->RemoveStatBonus("intelligence");
         caster->RemoveProperty("mage_bane");
         }
         if(castee) {
            message("system","%^BOLD%^GREEN%^You feel normal "
                    "again.%^RESET%^",castee);
            castee->RemoveProperty("mage_bane");
            castee->RemoveStatBonus("intelligence");
         }
      }, dur, who, target);
      return 1;
   }
}
