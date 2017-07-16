// cremate
// a necromancy fire dot that really hurts undead
// also, i'm gonner copy cloudkill like 9000 times.
// -mahkefel
#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

void eventCremate();

static void create() {
   spell::create();
   SetSpell("cremate");
   SetRules("","LIV");
   SetSpellType(SPELL_COMBAT);
   SetSkills( ([
          "conjuring"  : 120,
          "necromancy" : 120,
    ]) );
   SetAutoDamage(0);
   SetDamageType(HEAT);
   SetDifficulty(45);
   SetEnhanceSkills( ({ "fire magic" }) );
   SetHelp(
    "A favorite of necromancers talented with fire who lose control "
    "of their minions, this spell ignites the flesh of an opponent and "
    "attempts to burn them to ash from outside in. It's particularly "
    "effective when used against the dry flesh of undead."
     );
}

int CanCast(object who, int level, string limb, object array targets) {
   object target = targets[0];

   if(target->GetProperty("cremate")) {
      message("system", "You're burning them as fast as you can!",who);
      return 0;
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object array targets) {
   int i = 0;
   int length = (level/10)+1;
   int chance = level + random((int)who->GetSkillLevel("necromancy"));
   chance += random((int)who->GetSkillLevel("conjuring"));
   chance += random(who->GetSkillLevel("fire magic"));
    if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
          }
   foreach(object target in targets) {
     if(chance < 40) {
        send_messages("snap",
          "$agent_name $agent_verb $agent_possessive fingers and points at "
          "$target_name, but nothing seems to happen.",
          who,target,environment(who));
        return 1;
     } else {
        send_messages("snap",
          "$agent_name $agent_verb $agent_possessive fingers and points at "
          "$target_name.",who,target,environment(who));
        send_messages("", "%^CYAN%^Eerie %^BLUE%^blue %^CYAN%^flames%^RESET%^ "
          "suddenly %^BOLD%^ignite%^RESET%^ around $target_name!%^",
          who,target, environment(who));
        call_out( (: eventCremate, who, level, target, length, i :), 0);
        target->AddEnemy(who);
        target->SetProperty("cremate",1);
        return 1;
      }
   }
}

void eventCremate(object who, int level, object target, int length, int i) {
   int damage = GetDamage(level)/3;
   int damageboost = 0;
   if(!target) return 0;
   if (!who) {
     target->RemoveProperty("cremate");
     target->eventPrint("The fire mercifully extinguishes.");
     return;
    }
   if(target && (i < length)) {
     if (target->GetUndead()) {
        send_messages("",
          "The %^BLUE%^blue%^RESET%^ %^CYAN%^flames%^RESET%^ blaze brightly, "
          "slowly %^BOLD%^cremating%^NORMAL%^ $target_possessive_noun rotten form!",
          who, target, environment(target));
        damage *= 2;
      } else {
        send_messages("",
          "The %^BLUE%^blue%^RESET%^ %^CYAN%^flames%^RESET%^ smolder around "
          "$target_name, scorching them painfully!",
          who, target, environment(target));
        damage *= 0.75;
      }
      
      damageboost = who->GetSkillLevel("fire magic") / (GetSpellLevel() * 2);
      if (damageboost > 3) damageboost = 3;
      damage += damage * damageboost;

      target->eventReceiveDamage(who, HEAT, damage, GetAutoDamage(), 0);
      i++;
      call_out((: eventCremate, who, level, target, length, i :), 20);
      return;
   } else if(target && (i >= length)) {
      target->RemoveProperty("cremate");
      send_messages("",
        "The %^BLUE%^blue%^ %^CYAN%^flames%^ around $target_name extinguish in a final puff of ash and smoke.",
        who, target, environment(target));
      return;
   }
}

