/*  A cmd to renounce religions */
#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;
inherit LIB_HELP;
string *SupportedCommands = ({ "faith", "religion", "guild",
                             });

mixed cmd(string args) {
  object who = this_player();

  if (creatorp(who)) return "Cute, but 'No'.";
  if (member_array(args, SupportedCommands) == -1) {
   return ("Renounce " + conjunction(SupportedCommands, "or") + "?");
   }
  switch(args) {
     case "faith" : case "religion":
  if (who->GetSkillLevel("faith") || who->GetClass() == "mystic" ||
    who->GetClass() == "druid" || who->GetClass() == "contemplator" ) {
     who->RemoveClass();
     }
  unguarded( (: log_file, "players/faith",
    who->GetCapName() + " has forsaken the faith of " +
    who->GetReligion() + ".\n" + ctime(time()) + "\n" :) );
  CHAT_D->eventSendChannel(who->GetCapName(), "prayer",
    who->GetCapName() + " has renounced " + who->GetReligion() +
    " and become agnostic.", 1);
  send_messages("renounce", 
      "$agent_name $agent_verb $agent_possessive religion.",
      who, 0, environment(who));
  who->SetReligion("agnostic", "agnostic");
     break;
    case "guild":
if( who->GetGuild() == 0 ) return "You are not a member of any guild.";
     if(present(who->GetGuild() + "_guild_object", who) ){
     if(present(who->GetGuild() + "_guild_object", who)->GetLeader()  ==
        who->GetKeyName() ) return "Leaders cannot renounce that easy.";
      present(who->GetGuild() + "_guild_object", who)->eventDestruct();
     }
      who->RemoveChannel(who->GetGuild());
      who->SetGuild();
      send_messages("betray",
        "$agent_name $agent_verb $agent_possessive guild ties.",
        who, 0, environment(who) );
      break;
    }
  return 1;
  }

string GetHelp(string u) {
  return ("Syntax:      \"renounce <religion, faith, guild>\" \n\n"
          "Breaks ties with a given argument.  \n"
        "Mystics, and any class with faith as a skill (e.g. clerics) "
        "that chose to renounce their religion or their faith "
        "will be reset to level 0, and lose all of their skills. Because "
        "renoucing their religion/faith means betraying their calling, "
        "these players will be removed from their class, with no "
        "return of the development points that they spent to join."
  );
  }
