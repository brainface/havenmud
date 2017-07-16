#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <message_class.h>
#include <music.h>
#include <daemons.h>

inherit LIB_SONG;

static void create() 
{
   song::create();
   SetSong("projecting voice");
   SetGlobalSong(1);
   SetSongType(SONG_OTHER);
   SetRules("STR");
   SetMagicCost(50, 25);
   SetDifficulty(10);
   SetStaminaCost(10, 20);
   SetSkills( ([ "vocal music" : 7 ]) );
  SetHelp(
           ".");
}

int CanSing(object who, int level, mixed limb, object *targets) 
{
   int i, maxi = sizeof(targets);

   for(i=0;i<maxi;i++) 
   {
      if(creatorp(targets[i]))
      {
         message("system","Sing it to whom?", who);
         return 0;
      }
   }
   return song::CanSing(who, level, limb, targets);
}

int eventSing(object who, int level, mixed limb, object array targets) 
{
   if(sizeof(targets) == 0) 
   {
      message("system", "Sing it to whom?", who);
      return 0;
   }
   who->eventPrint("Enter a message to send to " +  
                    conjunction(targets->GetName()) + ": ", MSG_EDIT);
   input_to(function(string str, object singer, int lev, object array ppl) 
   {
      int chance = lev + random((int)singer->GetSkillLevel("vocal music"));
      string tname = singer->GetName();
      int extramp = (sizeof(ppl)) *10;

      foreach(object target in ppl) 
      {
         if((chance < random(20) + 10) || !target)
         {
            message("my_action", "Your communicating wind intended for "+
                     target->GetName() + " fails.", singer);
         } 
         else 
         {
            message("system", "%^BLUE%^BOLD%^You hear " + tname + "'s "
                    "voice on the wind saying : %^RESET%^\"%^BOLD%^CYAN%^"+
                     str+ "%^RESET%^\"", target);
            message("system", "%^BLUE%^BOLD%^You send "+target->GetName()+
                    ": %^RESET%^\"%^CYAN%^BOLD%^" + str + "%^RESET%^\"", 
                    singer);
            write_file("/log/reports/telepathy", tname+ " sent " +
                       capitalize(target->GetKeyName()) + " \""+str+"\" on " +
                       ctime(time())+".\n");
            CHAT_D->eventSendChannel("Telepathy", "reports", 
                     capitalize(singer->GetKeyName()) + " sent " + 
                     capitalize(target->GetKeyName()) + ": " + str, 1);
         }
      }
      singer->AddMagicPoints(-extramp);
   }, who, level, targets);
}
