//
// The 'telepathy' spell
// Allows players to talk to eachother
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <message_class.h>
#include <daemons.h>

inherit LIB_SPELL;

static void create() 
{
   spell::create();
   SetSpell("telepathy");
   SetGlobalSpell(1);
   SetSpellType(SPELL_OTHER);
   SetRules("STR");
   SetRequiredMagic(75);
   SetMagicCost(50, 25);
   SetMorality(0);
   SetDifficulty(10);
   SetRequiredStamina(30);
   SetStaminaCost(10, 20);
   SetSkills( ([ "conjuring" : 7,
                "enchantment" : 7 ]) );
  SetHelp(
           "This spell enables the caster to send a message into "
           "the minds of their targets. On a cast, the "
           "caster will be prompted for a message to send. Multiple "
           "targets are specified by using a space between each "
           "name. A single target may be specified. "
           "The cost of this spell depends on the amount "
           "of targets specified.");
}

int CanCast(object who, int level, mixed limb, object *targets) 
{
   int i, maxi = sizeof(targets);

   for(i=0;i<maxi;i++) 
   {
      if(creatorp(targets[i]))
      {
         message("system","Cast it on whom?", who);
         return 0;
      }
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object array targets) 
{
   if(sizeof(targets) == 0) 
   {
      message("system", "Cast it on whom?", who);
      return 0;
   }
   who->eventPrint("Enter a message to send to " +  
                    conjunction(targets->GetName()) + ": ", MSG_EDIT);
   input_to(function(string str, object caster, int lev, object array ppl) 
   {
      int chance = lev + random((int)caster->GetSkillLevel("enchantment"));
      string tname = caster->GetName();
      int extramp = (sizeof(ppl)) *10;

      foreach(object target in ppl) 
      {
         if((chance < random(20) + 10) || !target)
         {
            message("my_action", "Your attempt to communicate with "+
                     target->GetName() + " fails.", caster);
         } 
         else 
         {
            message("system", "%^RED%^BOLD%^" + tname + " enters "
                    "your mind and says: %^RESET%^\"%^BOLD%^CYAN%^"+
                     str+ "%^RESET%^\"", target);
            message("system", "%^RED%^BOLD%^You send "+target->GetName()+
                    ": %^RESET%^\"%^CYAN%^BOLD%^" + str + "%^RESET%^\"", 
                    caster);
            if (userp(target)) {
              write_file("/log/reports/telepathy", tname+ " sent " + capitalize(target->GetKeyName()) + " \""+str+"\" on " + ctime(time())+".\n");
              CHAT_D->eventSendChannel("Telepathy", "reports", capitalize(caster->GetKeyName()) + " sent " + capitalize(target->GetKeyName()) + ": " + str, 1);
            }
         }
      }
      caster->AddMagicPoints(-extramp);
   }, who, level, targets);
}
