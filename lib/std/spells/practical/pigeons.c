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
   SetSpell("carrier pigeon");
   SetGlobalSpell(1);
   SetSpellType(SPELL_OTHER);
   SetRules("STR");
   SetRequiredMagic(40);
   SetMagicCost(40, 10);
   SetMorality(0);
   SetDifficulty(10);
   SetRequiredStamina(30);
   SetStaminaCost(10, 20);
   SetSkills( ([ 
     "practical magic" : 160,
     ]) );
  SetHelp(
           "This spell enables the caster to send a message to "
           "a target via carrier pigeon. On a cast, the "
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
      int chance = lev;
      string tname = caster->GetName();
      int extramp = (sizeof(ppl)) *10;

      foreach(object target in ppl) 
      {
         if((chance < random(20) + 10) || !target)
         {
            message("my_action", "Your pigeon heading towards "+ target->GetName() + " got lost!", caster);
         } 
         else 
         {
            message("system", 
              "A carrier pigeon sent by %^RED%^BOLD%^" + tname + " %^RESET%^flies down and drops off a small note to you which reads: " +
              str+ "%^RESET%^\"", target);
            message("system", "%^RED%^BOLD%^You send a pigeon to "+target->GetName()+
                    " with a note reading: %^RESET%^\"%^CYAN%^BOLD%^" + str + "%^RESET%^\"", 
                    caster);
            write_file("/log/reports/telepathy", 
                       tname+ " sent " + capitalize(target->GetKeyName()) + " \""+str+"\" on " + ctime(time())+".\n");
            CHAT_D->eventSendChannel("Telepathy (Pigeon Powered)", "reports", 
                     capitalize(caster->GetKeyName()) + " sent " + 
                     capitalize(target->GetKeyName()) + ": " + str, 1);
         }
      }
      caster->AddMagicPoints(-extramp);
   }, who, level, targets);
}
