// Crown of Flames
//   Sets some fool's head on fire.
//   Basically copy of Zaxan's cloudkill
// Created by Mahkefel@Haven
//
// This spell has "less" damage and duration than
//   cloudkill because it damages the head every time.
//   
#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

void eventCrown();

static void create() {
   spell::create();
   SetSpell("crown of flames");
   SetRules("","LIV");
   SetSpellType(SPELL_COMBAT);
   SetSkills( ([
          "conjuring"  : 250,
          "evokation" : 250,
    ]) );
   SetAutoDamage(0);
   SetDamageType(HEAT);
   SetMorality(-5);
   SetDifficulty(45);
   SetEnhanceSkills( ({ "fire magic" }) );
   SetHelp(
     "With this vicious spell, the caster conjurers a ring of "
     "flames to cling to the target's head in a cruel mockery "
     "of a crown."
   );
}

int CanCast(object who, int level, string limb, object array targets) {
   object target = targets[0];

   if(target->GetProperty("crown_of_flames")) {
      message("system", "That person has already been crowned with flames",
        who);
      return 0;
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object array targets) {
   int i = 0;
   int length = (level/30)+1;
   int chance = level + random((int)who->GetSkillLevel("evokation"));
   chance += random((int)who->GetSkillLevel("conjuring"));
   chance += random(who->GetSkillLevel("fire magic"));
    if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
          }
   foreach(object target in targets) {
      if(chance < 40) {
         send_messages("blurt","$agent_name $agent_verb "
           "out some words, but they don't make "
           "any sense.",who,target,environment(who));
         return 1;
      } else {
         send_messages("wrap","$agent_name $agent_verb "
           "a thin %^RED%^BOLD%^sheet of flames%^RESET%^ "
           "around $target_possessive_noun head.",
           who,target,environment(who));
         send_messages("","The flames ignite "
           "$target_possessive_noun brow!",
           who,target,
           environment(who));
         call_out( (: eventCrown, who, level, target, length, i :), 0);
         target->AddEnemy(who);
         target->SetProperty("crown_of_flames",1);
         return 1;
      }
   }
}

void eventCrown(object who, int level, object target, int length, int i) {
   int damage = GetDamage(level)/9;
   if(!target) return 0;
   if (!target->GetLimb("head")) {
     target->RemoveProperty("crown_of_flames");
     target->eventPrint("That creature has no head!.");
     return 0;
   }
   if (!who) {
     target->RemoveProperty("crown_of_flames");
     target->eventPrint("The fire crowning you finally extinguishes.");
     return;
   }
   if(target && (i < length)) {
      send_messages("",
        "The %^RED%^BOLD%^scorching flames%^RESET%^ surrounding "
        "$target_possessive_noun head continue to sear "
        "$target_objective.",
        who, target, environment(target));
      target->eventForce("emote screams in agony.");
      target->eventReceiveDamage(who, HEAT, damage, 0, "head");
      i++;
      call_out((: eventCrown, who, level, target, length, i :), 20);
      return;
   } else if(target && (i >= length)) {
      target->RemoveProperty("crown_of_flames");
      send_messages("",
        "The %^RED%^BOLD%^scorching flames%^RESET%^ surrounding " +
        "$target_possessive_noun head sputter out.",
        who, target, environment(target));
      return;
   }
}

