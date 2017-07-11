//
// The 'Cloud Kill' spell
// Continually kills someone via a surrounding cloud
// Created by Zaxan@Haven
//
// copycopycopy
/// mahkefel

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

void eventGas();

static void create() {
   spell::create();
   SetSpell("burnt offering");
   SetRules("","LIV");
   SetSpellType(SPELL_COMBAT);
   SetSkills( ([
          "faith"  : 40,
          "evokation" : 40,
    ]) );
   SetAutoDamage(0);
   SetDamageType(HEAT);
   SetReligions("Anteky");
   SetMorality(-5);
   SetDifficulty(45);
   SetEnhanceSkills( ({ "fire magic" }) );
   SetHelp(
     "This spell creates an offering, pleasing unto the sight "
     "of the lord."
     );
}

int CanCast(object who, int level, string limb, object array targets) {
   object target = targets[0];
   if( target->GetProperty("burnt_offering") ) {
      message("system", "The One God already greatly appreciates "
        "your offering. Keep up the good work!", who);
      return 0;
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object array targets) {
   int i = 0;
   int length = (level/10)+1;
   int chance = level + random((int)who->GetSkillLevel("necromancy"));
   int id = 0;
   chance += random((int)who->GetSkillLevel("faith"));
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
         send_messages("call","$agent_name $agent_verb "
                       "down a %^BOLD%^RED%^tongue of flame%^RESET%^ from the "
                       "empty skies!",who,target,environment(who));
         send_messages("","The %^BOLD%^RED%^flame%^RESET%^ envelops "
                       "$target_name in fire and smoke!",who,target,
                        environment(who));
         target->AddEnemy(who);
         target->SetProperty("burnt_offering",1);
         id = target->AddShortSuffix("%^BOLD%^RED%^(all aflame!)%^RESET%^");
         call_out( (: eventGas, who, level, target, length, i, id :), 0);
         return 1;
      }
   }
}

void eventGas(object who, int level, object target, int length, int i, int id) {
   int damage = GetDamage(level)/3;
   if(!target) return 0;
   if (!who) {
     target->RemoveProperty("burnt_offering");
     target->eventPrint("The choking flame around you disperses.");
     return;
    }
   if(target && (i < length)) {
      send_messages("",
        "The %^RED%^BOLD%^tongue of flame%^RESET%^ enveloping $target_name "
        "continues to scorch " + capitalize(target->GetShort()) + ".",
          who, target, environment(target));
      target->eventForce("wail");
      target->eventReceiveDamage(who, HEAT, damage, GetAutoDamage(), 0);
      i++;
      call_out((: eventGas, who, level, target, length, i :), 20);
      return;
   } else if(target && (i >= length)) {
      target->RemoveProperty("burnt_offering");
      target->RemoveShortSuffix(id);
      send_messages("",
        "The %^RED%^BOLD%^tongue of flame%^RESET%^ enveloping " + 
        capitalize(target->GetShort()) + " snuffs out.",
          who, target, environment(target));
      return;
   }
}

