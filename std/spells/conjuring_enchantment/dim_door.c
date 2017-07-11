//
// The 'dimension door' spell
// Sends someone into the lower planes
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;
#include <setup.h>


static void create() {
   spell::create();
   SetSpell("dimension door");
   SetSpellType(SPELL_OTHER);
   SetRules("", "LIV");
   SetSkills( ([
      "conjuring"   : 150,
      "enchantment" : 150,
      ]) );
   SetRequiredMagic(150);
   SetMagicCost(125,25);
   SetRequiredStamina(30);
   SetStaminaCost(25, 5);
   SetDifficulty(80);
   SetMorality(0);
   SetHelp(
           "Using this spell, the caster is able to rip a hole in "
           "dimensions, sending themself or their target "
           "into or out of the lower plane of existance."
           );
}

int CanCast(object who, int level, string limb, object array targets) {
   object target = targets[0];

   if(!playerp(target)) {
      message("system","This spell may only be directed at a player.", who);
      return 0;
   }
   if( (environment(who)->GetProperty("no teleport")) ||
       (environment(who)->GetProperty("no bump")) ) {
      message("system","A mystical force prevents your magic.",who);
      return 0;
   }
   if(target != who) {
      who->AddMagicPoints(-100);
   }
   if (target->GetLevel() < 5) {
      message("system", "You cannot target one so young!", who);
      return 0;
      }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object array targets) {
   object target = targets[0];
   int chance = level + random(who->GetSkillLevel("enchantment"));
   chance -= (target->GetLevel() * 5);

   if((chance <= 0) && (target != who)) {
      if(random(20) >= 10) {
         send_messages(({"falter","fumble","fire"}), "$agent_name "
                       "$agent_verb and $agent_verb the spell. Amazingly, "
                       "$agent_nominative $agent_verb it upon "
                       "$agent_reflexive.",who, target, environment(who));
         send_messages("","%^CYAN%^BOLD%^A huge vortex opens and swallows "
                       "$agent_name!%^RESET%^",who,0,environment(who));
         message("system","You lose all sense of direction as you tumble "
                 "through the voids of space and time.",who);
         call_out(function(object guy) {
            string blah;
            string env = base_name(environment(guy));

            if(sscanf(env, "/domains/planes/%s", blah)) {
               guy->eventMove(StartRooms[guy->GetTown()]);
            } else {
               guy->eventMove("/domains/planes/castles/first/entrance");
            }
            message("system","%^CYAN%^BOLD%^You stop tumbling. You feel as "
                    "if you're in a different plane of existance.",guy);
            guy->eventDescribeEnvironment();
         }, random(3)+5, who);
         message("system","%^RED%^You feel magically drained.%^RESET%^",who);
         who->AddMagicPoints(-(who->GetMagicPoints()));
         return 1;
      }
      send_messages("","A bright light flickers in the room for a split-second before suddenly vanishing.", 
                     ({ environment(target) }));
      return 1;
   } else {
      message("system","%^CYAN%^BOLD%^A huge vortex opens and you "
              "step inside!%^RESET%^",target);
      message("system","%^CYAN%^BOLD%^A huge vortex opens "
                    "and "+target->GetName()+" steps inside!%^RESET%^", 
                     environment(target), target);
      send_messages("","The vortex suddenly disappears into nothingness.",
                        ({ environment(target) }));
      message("system","You lose all sense of direction as you tumble "
              "through the voids of space and time.",target);
      call_out(function(object guy) {
         string blah;
         string env;

         if( !guy ) return 0;
         else env = base_name(environment(guy));

         if(sscanf(env, "/domains/planes/%s", blah)) {
            guy->eventMove(StartRooms[guy->GetTown()]);
         } else {
            guy->eventMove("/domains/planes/castles/first/entrance");
         }
         message("system","%^CYAN%^BOLD%^You stop tumbling. You feel as "
                 "if you're in a different plane of existance.",guy);
         guy->eventDescribeEnvironment();
      }, random(3)+5, target);
      return 1;
   }
}
