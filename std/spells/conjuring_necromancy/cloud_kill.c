//
// The 'Cloud Kill' spell
// Continually kills someone via a surrounding cloud
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

void eventGas();

static void create() {
   spell::create();
   SetSpell("cloud kill");
   SetRules("","LIV");
   SetSpellType(SPELL_COMBAT);
   SetSkills( ([
          "conjuring"  : 30,
          "necromancy" : 30,
    ]) );
   SetAutoDamage(0);
   SetDamageType(GAS);
   SetMorality(-5);
   SetDifficulty(45);
   SetEnhanceSkills( ({ "poison magic" }) );
   SetHelp(
     "This spell creates a cloud of gas that will continuously "
     "choke the target for a certain amount of time. That time "
     "is dependant upon the caster's mastery of the spell. If "
     "no target is specified, the spell is targetted at your "
     "current enemy."
     );
}

int CanCast(object who, int level, string limb, object array targets) {
   object target = targets[0];

   if(target->GetProperty("cloud_kill")) {
      message("system", "A large cloud seems to already be surrounding "
              "that person.",who);
      return 0;
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object array targets) {
   int i = 0;
   int length = (level/10)+1;
   int chance = level + random((int)who->GetSkillLevel("necromancy"));
   chance += random((int)who->GetSkillLevel("conjuring"));
   chance += random(who->GetSkillLevel("poison magic"));
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
         send_messages("summon","$agent_name $agent_verb "
                       "a thick %^YELLOW%^BOLD%^"
                       "yellow cloud%^RESET%^ from thin "
                       "air.",who,target,environment(who));
         send_messages("","The cloud suddenly surrounds "
                       "$target_name and stays!",who,target,
                        environment(who));
         call_out( (: eventGas, who, level, target, length, i :), 0);
         target->AddEnemy(who);
         target->SetProperty("cloud_kill",1);
         return 1;
      }
   }
}

void eventGas(object who, int level, object target, int length, int i) {
   int damage = GetDamage(level)/3;
   if(!target) return 0;
   if (target->GetUndead()) {
    target->RemoveProperty("cloud_kill");
    target->eventPrint("The gas does not affect the undead.");
   return 0;
    }
   if (!who) {
     target->RemoveProperty("cloud_kill");
     target->eventPrint("The gas around you disperses.");
     return;
    }
   if(target && (i < length)) {
      send_messages("",
        "The %^YELLOW%^BOLD%^yellow cloud%^RESET%^ surrounding $target_name continues to choke " + capitalize(target->GetShort()) + ".",
          who, target, environment(target));
      target->eventForce("cough painfully");
      target->eventReceiveDamage(who, GAS, damage, GetAutoDamage(), 0);
      i++;
      call_out((: eventGas, who, level, target, length, i :), 20);
      return;
   } else if(target && (i >= length)) {
      target->RemoveProperty("cloud_kill");
      send_messages("",
        "The %^YELLOW%^BOLD%^yellow cloud%^RESET%^ surrounding " + capitalize(target->GetShort()) + " suddenly vanishes.",
          who, target, environment(target));
      return;
   }
}
