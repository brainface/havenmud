#include <lib.h>
#include <music.h>
#include <damage_types.h>

inherit LIB_SONG;

void eventAria(object who, int level, object target, int length, int i);
void eventGeneralMessages(object who, int level, object target, int length, int i);

static void create() {
   song::create();
   SetSong("melody of war");
   SetRules("");
   SetSongType(SONG_OTHER);
   SetMagicCost(250, 200);
   SetSkills( ([
          "vocal music" : 200,
          "instrumental music" : 200,
    ]) );
   SetMorality(55);
   SetDifficulty(175);
   SetHelp("The bard sings a beautiful harmony about wars long ago, about the "
           "courage and bravery of the soldiers. The melody inspires the bard "
           "and their followers to preform better in battle.");
}

int CanSing(object who, int level, string limb, object array t) {
 if(who->GetProperty("grpsong")) {
        who->eventPrint("You are already singing a group affecting song.");
        return 0;
   }
   if(who->GetProperty("melofwar")) {
        who->eventPrint("You are already listening to the melody of war.");
        return 0;
   }
   return song::CanSing(who, level, limb, t);
}

int eventSing(object who, int level, mixed limb, object array t) {
   int amt;
   object *targets;
   int i = 0;
   int length = (level/10)+1;
   int chance = level + random((int)who->GetSkillLevel("vocal music"));

   amt = (level + who->GetSkillLevel("vocal music") + 
          who->GetSkillLevel("instrumental music"))/15;
   targets = ({ who }) + who->GetFollowers();

   if(chance < 40) {
      send_messages("attempt","$agent_name $agent_verb "
                    "to sing but cannot get any words "
                    "out.",who,0,environment(who));
      return 1;
   }

   else {
      send_messages("begin","$agent_name $agent_verb to sing a beautiful "
                    "harmony about fallen warriors and their brave acts.",
                    who,0,environment(who));
      foreach(object targ in (targets + ({ who }))) {
        targ->SetProperty("melofwar",1);
        targ->SetProperty("grpsong",1);      
        targ->AddStatBonus("agility", amt);
        targ->AddStatBonus("coordination", amt);
        call_out( (: eventAria, who, level, targ, length, i :), 10);
      }
      call_out( (: eventGeneralMessages, who, level, targets, length, i :), 10);
      return 1;
   }

}

void eventAria(object who, int level, object target, int length, int i) {
   if(!target) return 0;

   if(target != who && target->GetLeader() != who) {
        target->RemoveProperty("melofwar");
        target->RemoveProperty("grpsong");     
        target->RemoveStatBonus("agility");
        target->RemoveStatBonus("coordination");
        target->eventPrint("You stop listening to the %^BOLD%^%^RED%^melody of "
                           "war%^RESET%^.");
        return;
   }
   
   if(target->GetLeader(who) && (i < length)) {
      target->eventPrint("You feel your %^BOLD%^%^RED%^blood%^RESET%^ race "
   	                      "as you listen to the melody.");
   	  i++;
   	  call_out( (: eventAria, who, level, target, length, i :), 60);
   	  return;
   	}
   
   return;
}

void eventGeneralMessages(object who, int level, object target, int length, int i) {
   int amt;
   object *targets;
   if (!who) return;
   targets = who->GetFollowers() - ({ target });
   amt = (level + who->GetSkillLevel("vocal music") +
      who->GetSkillLevel("instrumental music"))/15;
      
   if(i<length) {
   	 
      i++;
      send_messages("continue","$agent_name $agent_verb to sing the beautiful "
                    "melody of war.",who,0,environment(who));
               
      foreach(object targ in (targets + ({ who }))) {
          if((living(targ)) && !targ->GetProperty("melofwar") &&
              !targ->GetProperty("grpsong")) {
                     targ->SetProperty("melofwar");
                     targ->SetProperty("grpsong");
                     targ->AddStatBonus("agility", amt);
                     targ->AddStatBonus("coordination", amt);
                     call_out( (: eventAria, who, level, targ, length, i :), 0);
                     }
              }
      call_out( (: eventGeneralMessages, who, level, targets, length, i :), 60);
      return;
      }
   foreach(object targ in (targets + ({ who }))) {
      targ->RemoveProperty("melofwar");
      targ->RemoveProperty("grpsong");
      targ->RemoveStatBonus("agility");
      targ->RemoveStatBonus("coordination");
      }
   message("song", "The %^BOLD%^%^RED%^melody of war%^RESET%^ slowly comes to "
           "an end.", environment(who));
 
        return;
}

