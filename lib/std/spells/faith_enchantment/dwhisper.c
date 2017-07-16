//
// The 'telepathy' spell for faith users
// Allows players to talk to eachother
// Created by Thoin@Haven
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <message_class.h>
#include <daemons.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("divine whisper");
   SetGlobalSpell(1);
   SetSpellType(SPELL_OTHER);
   SetRules("STR");
   SetRequiredMagic(75);
   SetMagicCost(50, 25);
   SetMorality(0);
   SetDifficulty(10);
   SetRequiredStamina(30);
   SetStaminaCost(10, 20);
   SetSkills( ([ "faith" : 7,
                "enchantment" : 7 ]) );
  SetHelp(
           "This spell enables the caster to send a message to "
           "the target. Multiple targets are allowed however it will "
           "increase in cost.");
}

int CanCast(object who, int level, mixed limb, object *targets) {
   int i, maxi = sizeof(targets);

   for(i=0;i<maxi;i++) {
      if(creatorp(targets[i])){
         message("system","Cast it on whom?", who);
         return 0;
      }
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object array targets) {
   if(sizeof(targets) == 0) {
      message("system", "Cast it on whom?", who);
      return 0;
   }
   who->eventPrint("Enter a message to whisper to " +  
                    conjunction(targets->GetName()) + ": ", MSG_EDIT);
   input_to(function(string str, object caster, int lev, object array ppl) {
      int chance = lev + random((int)caster->GetSkillLevel("enchantment"));
      string tname = caster->GetName();
      int extramp = (sizeof(ppl)) *10;

      foreach(object target in ppl) {
         if((chance < random(20) + 10) || !target){
            message("my_action", "Your attempt to communicate with "+
                     target->GetName() + " fails.", caster);
         } 
         else {
            message("system", "%^RED%^BOLD%^" + tname + " whispers "
                    "into your mind, %^RESET%^\"%^BOLD%^CYAN%^"+
                     str+ "%^RESET%^\"", target);
            message("system", "%^RED%^BOLD%^You whisper, \""
                    "%^CYAN%^BOLD%^" + str + "%^RESET%^%^BOLD%^%^RED%^\" into "+target->GetName()+
                    "'s mind.%^RESET%^", 
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

