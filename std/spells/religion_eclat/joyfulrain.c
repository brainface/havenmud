//
// With code stolen from the cloud kill spell by Zaxan
// Amelia@Haven
// "joyful rain"--Heals good, kinda heals neutral, and hurts baddies.  Area effect.

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

void eventHealGood(object who, int level, object target, int length, int i);
void eventHealNeutral(object who, int level, object target, int length, int i);
void eventHarmEvil(object who, int level, object target, int length, int i);
void eventGeneralMessages(object who, int level, object target, int length, int i, string Room);

static void create() {
   spell::create();
   SetSpell("joyful rain");
   SetRules("");
   SetSpellType(SPELL_OTHER);
   SetMagicCost(250, 100);
   SetSkills( ([
          "natural magic" : 150,
           "enchantment" : 150,
    ]) );
   SetMorality(55);
   SetDifficulty(175);
   SetReligions("Eclat");
  SetHelp("One of the most powerful spells an Eclat follower can ever acquire, "
          "it allows them to summon forth joyous rain that will heal the good but "
          "harm the evil. The duration of the rain is dependent on knowledge "
          "of the caster.");
}

int CanCast(object who, int level, string limb, object array t) {
   if( (environment(who)->GetClimate() == "indoors") ||
       (environment(who)->GetClimate() == "underground") ){
      message("system","Your spell fizzles and refuses to work "
              "in these types of environmental settings.",who);
      return 0;
   }
   if(environment(who)->GetProperty("joyful_rain")) {
        who->eventPrint("A joyful rain is already falling here.");
        return 0;
   }
   if(who->GetMorality() < 500) {
        who->eventPrint("The blessing of the joyful rain eludes your skill, "
                "for your are not morally strong enough to handle the "
                "power.");
        return 0;
   }
   return spell::CanCast(who, level, limb, t);
}

int eventCast(object who, int level, mixed limb, object array t) {
   string Room;
   int i = 0;
   int length = (level/10)+1;
   int chance = level + random((int)who->GetSkillLevel("enchantment"));
   object *targets = filter(all_inventory(environment(who)), (: living($1) && noncreatorp($1) :) );
   Room = base_name(environment(who));

   if(chance < 40) {
      send_messages("blurt","$agent_name $agent_verb "
                    "out some words, but they don't make "
                    "any sense.",who,0,environment(who));
      return 1;
   }

   else {
      send_messages("look","$agent_name $agent_verb "
                    "up at the sky and swirling clouds begin to take form "
                    "in the area.",who,0,environment(who));
      find_object(Room)->SetProperty("joyful_rain",1);
      foreach(object targ in targets) {
                targ->SetProperty("joyful_rain",1);
                switch(targ->GetMorality()) {
                        case 200..2500:
                        call_out( (: eventHealGood, who, level, targ, length, i :), 10);
                        break;
                        case -200..199:
                        call_out( (: eventHealNeutral, who, level, targ, length, i :), 10);
                        break;
                        case -2500..-201:
                        call_out( (: eventHarmEvil, who, level, targ, length, i :), 10);
                        targ->AddEnemy(who);
                        break;
                }
      }
      call_out( (: eventGeneralMessages, who, level, targets, length, i, Room :), 10);
      return 1;
   }

}


void eventHarmEvil(object who, int level, object target, int length, int i) {
   int damage = (GetDamage(level));
   if(!target) return 0;

   if(!environment(target)->GetProperty("joyful_rain")) {
        target->RemoveProperty("joyful_rain");
        return;
   }
   if(target && (i < length)) {
     environment(target)->eventPrint("The rain %^RED%^burns%^RESET%^ "+
                  conjunction(target->GetName())+" skin as it falls on them.", target);
        target->eventPrint("Your skin begins to %^RED%^melt%^RESET%^ as the rain touches you.");
      target->eventReceiveDamage(0, ACID, damage, GetAutoDamage(), 0);
      i = i+1;
      call_out( (: eventHarmEvil, who, level, target, length, i :), 60);
      return;
   }
   target->RemoveProperty("joyful_rain");
   return;
}

void eventHealGood(object who, int level, object target, int length, int i) {
   int damage = GetHealing(level);
   if(!target) return 0;

   if(!environment(target)->GetProperty("joyful_rain")) {
        target->RemoveProperty("joyful_rain");
        return;
   }
   if(target && (i < length)) {
        environment(target)->eventPrint("The rain %^BOLD%^%^BLUE%^refreshes%^RESET%^ "+
                  conjunction(target->GetName())+" as it falls on their skin.", target);
        target->eventPrint("You feel %^BOLD%^%^BLUE%^refreshed%^RESET%^ as the rain touches you.");
      target->eventHealDamage(damage, 1);
      target->AddMagicPoints(100);
      i = i+1;
      call_out( (: eventHealGood, who, level, target, length, i :), 60);
      return;
   }
   target->RemoveProperty("joyful_rain");
   return;
}

void eventHealNeutral(object who, int level, object target, int length, int i) {
   int damage = GetHealing(level)/2;
   if(!target) return 0;

   if(!environment(target)->GetProperty("joyful_rain")) {
        target->RemoveProperty("joyful_rain");
        return;
   }
   if(target && (i < length)) {
      environment(target)->eventPrint("An expression of %^BLUE%^calmness%^RESET%^ overcomes "+
                  conjunction(target->GetName())+" as the rain touches them.", target);
        target->eventPrint("You feel %^BLUE%^calm%^RESET%^ as the rain touches you.");
            target->eventHealDamage(damage, 1);
      i = i+1;
      call_out( (: eventHealNeutral, who, level, target, length, i :), 60);
      return;
   }
   target->RemoveProperty("joyful_rain");
   return;
}

void eventGeneralMessages(object who, int level, object target, int length, int i, string Room) {
     object rainroom;
     rainroom = find_object(Room);
     if(i<length) {
                i++;
     message("joyrain", "The %^BOLD%^%^CYAN%^joyous rain%^RESET%^ continues to soak the area.", rainroom);
                foreach(object targ in all_inventory(rainroom)) {
                        if((living(targ)) && !targ->GetProperty("joyful_rain")) {
                                targ->SetProperty("joyful_rain",1);
                                switch(targ->GetMorality()) {
                        case 200..2500:
                        call_out( (: eventHealGood, who, level, targ, length, i :), 0);
                        break;
                        case -200..199:
                        call_out( (: eventHealNeutral, who, level, targ, length, i :), 0);
                        break;
                        case -2500..-201:
                        call_out( (: eventHarmEvil, who, level, targ, length, i :), 0);
                        targ->AddEnemy(who);
                        break;
                                }
                        }
                }
      call_out( (: eventGeneralMessages, who, level, target, length, i, Room :), 60);
                return;
        }
   message("joyrain", "The %^BOLD%^%^YELLOW%^joyful rain%^RESET%^ slowly dissipates, returning the "
        "weather to normal.", rainroom);
   rainroom->RemoveProperty("joyful_rain");
        return;
}

