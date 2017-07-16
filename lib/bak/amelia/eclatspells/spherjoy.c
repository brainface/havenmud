/*  /spells/religion_eclat/sphere_of_joy.c
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
   SetSpell("sphere of joy");
   SetRules("","LIV");
   SetSpellType(SPELL_DEFENSE);
   SetSkills( ([
                 "faith" : 50,
                 "enchantment" : 50,
            ]) );
   SetMagicCost(90,60);
   SetRequiredMagic(150);
   SetStaminaCost(20,20);
   SetRequiredStamina(40);
   SetDifficulty(65);
   SetHelp("Syntax:  <cast sphere of joy>\n"
           "         <cast sphere of joy on LIVING>\n\n"
           "This defense spell conjures a sphere of tangible joy "
           "to surround the living creature named, or the caster "
           "if nothing is specified.  It will block attacks against "
           "the protected.");
}

int eventCast(object who, int level, string race, object array targets) {
   class MagicProtection prot;
   object target = targets[0];
   int prot_level, skill;

   skill = ((who->GetSkillLevel("faith")) + (who->GetStatLevel("wisdom")));
   prot_level = (random(skill)*2 + level);

   prot = new(class MagicProtection);
   prot->name = "sphere of joy";
   prot->bits = ALL_DAMAGE;
   prot->caster = who;
   prot->absorb = 4*prot_level;
   prot->args = level;
   prot->hit = (: hitCallback :);
   prot->end = (: endCallback :);
   if(target->AddMagicProtection(prot)) {
      if(target == who) {
         send_messages("","A sphere of joy coalesces around "
                          "$agent_possessive_noun body, protecting "
                          "$agent_objective.",who,0,environment(who));
      }
      else {
         send_messages("cause","$agent_name $agent_verb a sphere of joy "
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
   send_messages("hit","The joyous sphere around $agent_name bends "
                 "slighty, absorbing damage into it, as "
                 "$target_name $target_verb it.",who,
                 agent,environment(who));
   return x;
}

void endCallback(object who) {
   if(who) {
      send_messages("","The sphere of joy protecting $agent_name "
                       "disappears.",who,0,environment(who));
   }
}