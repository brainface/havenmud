/*  /spells/religion_eclat/sphere_happiness.c
 *  Protection spell for the Eclat religion.
 *  Coded by Amelia@Haven
 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <magic_protection.h>
inherit LIB_SPELL;

int hitCallback(object who, object agent, int x, class MagicProtection cl);
void endCallback(object who);

static void create() {
   spell::create();
   SetSpell("sphere of happiness");
   SetRules("","LIV");
   SetSpellType(SPELL_DEFENSE);
   SetSkills( ([
                 "faith" : 20,
                 "enchantment" : 20,
            ]) );
   SetMagicCost(30,15);
   SetRequiredMagic(45);
   SetStaminaCost(10,10);
   SetRequiredStamina(20);
   SetDifficulty(35);
   SetHelp("Syntax:  <cast sphere of happiness>\n"
           "         <cast sphere of happiness on LIVING>\n\n"
           "This defense spell conjures a sphere of tangible happiness "
           "to surround the living creature named, or the caster "
           "if nothing is specified.  It will block attacks against "
           "the protected.");
}

int eventCast(object who, int level, string race, object array targets) {
   class MagicProtection prot;
   object target = targets[0];
   int prot_level, skill;

   skill = ((who->GetSkillLevel("faith")) + (who->GetStatLevel("wisdom")));
   prot_level = (random(skill) + level);

   prot = new(class MagicProtection);
   prot->name = "sphere of happiness";
   prot->bits = ALL_DAMAGE;
   prot->caster = who;
   prot->absorb = 2*prot_level;
   prot->args = level;
   prot->hit = (: hitCallback :);
   prot->end = (: endCallback :);
   if(target->AddMagicProtection(prot)) {
      if(target == who) {
         send_messages("","A sphere of happiness coalesces around "
                          "$agent_possessive_noun body, protecting "
                          "$agent_objective.",who,0,environment(who));
      }
      else {
         send_messages("cause","$agent_name $agent_verb a sphere of happiness "
                               "to coalesce around $target_possessive_noun "
                               "body, protecting $target_objective.",
                               who, target, environment(target));
      }
   }
   else {
      message("my_action","The spell fails.",who);
   }
   return 1;
}

int hitCallback(object who, object agent, int x, class MagicProtection cl) {
   string str;
   object Caster = cl->caster;
   if( (int)agent->GetUndead()) return 0;
   str = (string)agent->GetName() || (string)agent->GetShort();
   if(who == Caster) {
      who->eventTrainSkill("enchantment",cl->args,x,1);
   }
   else if(Caster && playerp(who) && Caster!=who) {
      Caster->eventTrainSkill("enchantment",cl->args,0,1);
   }
   send_messages("hit","The sphere of happiness around $agent_name bends "
                 "slighty, absorbing damage into it, as "
                 "$target_name $target_verb it.",who,
                 agent,environment(who));
   return x;
}

void endCallback(object who) {
   if(who) {
      send_messages("","The sphere of happiness protecting $agent_name "
                       "disappears.",who,0,environment(who));
   }
}