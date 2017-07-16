/*    /daemon/chat.c
 * Original code Descartes@Nightmare/Dead Souls
 * Various modifications by Zaxan and Zeddicus
 * Recode and shatter into multiple files by Duuk
 */

#include <lib.h>
#include <pov.h>
#include <daemons.h>
#include <origin.h>
#include <message_class.h>
#include <save.h>
#include "include/chat.h"

inherit LIB_DAEMON;
inherit CHAT_D "/censor";
inherit CHAT_D "/members";
inherit CHAT_D "/history";
inherit CHAT_D "/brackets";

private mapping Channels;
private string *NoInvis = ({ "imm", "reports", "error", "intergossip",
                                    "intercre", "muse", "prayer", "admin",
                                    "arch", "emoted", "spirit", "souls",
                                    "twilight", "isport", "dc", "ds",
                                    "meta", "ooc" });
private string* UseOOCName = ({ "ooc", "non" });


static void create() {
  daemon::create();
  censor::create();
  members::create();
  history::create();
  brackets::create();
  SetNoClean(1);
  Channels = GetChannelMembers();
}

int cmdListChannel(string str) {
  string *who;
  string ch, mud;
  string msg;

    if (!str) return 0;
    if (sscanf(str, "%s@%s", ch, mud) == 2) {
      if (!Channels[ch]) return 0;
      if (member_array(this_player(), Channels[ch]) == -1) return 0;
      if (ch == (ch = GetRemoteChannel(ch))) return 0;
      if (!(mud = (string)INTERMUD_D->GetMudName(mud)))
      {
        this_player()->eventPrint(mud_name() + " is not aware of " 
          "such a place.", MSG_ERROR);
        return 1;
      }
      SERVICES_D->eventSendChannelWhoRequest(ch, mud);
      this_player()->eventPrint("Remote listing request sent.", MSG_SYSTEM);
      return 1;
    }
    else ch = str;
    if (!Channels[ch]) return 0;
    if (member_array(this_player(), Channels[str]) == -1) return 0;
    who = GetChannelList(str);
    msg = "Online: " + implode(who, "   ");
    this_player()->eventPrint(msg, MSG_SYSTEM);
    return 1;
}

int cmdChannel(string verb, string str) {
  string msg, name, rc, target, targetkey, target_msg, who_msg;
  object ob = 0;
  int emote = 0;
  int use_oocname = 0;
  object *found = ({ });

  if ((verb == "time" || verb == "timeemote" || verb == "reboot" || verb == "rebootemote" ) && playerp(this_player())) return 0;
  if ((verb == "quest" || verb == "questemote") && playerp(this_player())) return 0;
  if (verb == "list") { return cmdListChannel(str); }
  if (verb == "test" || verb == "testemote") {
    "/daemon/newchat"->cmdChannel(verb, str);
    return 1;
  }
  if (!Channels[verb])  {
    if (sscanf(verb, "%semote", verb))    {
      string emote_cmd, remains;
      mixed array msg_data;
      int i;
    
      if (!Channels[verb]) return 0;
      rc = GetRemoteChannel(verb);
      sscanf(str, "%s %s", emote_cmd, remains);
      if (!emote_cmd)  {
        emote_cmd = str;
        remains = 0;
      }
      if (!remains) {
        msg_data = SOUL_D->GetChannelEmote(emote_cmd, "");
        if (!msg_data) str = "$N " + str;
      } else {
	    if (member_array(verb, UseOOCName) != -1) {
	      foreach(object user in users()) {
		      if (user->GetOOCName() && remains && !(user->GetInvis() > rank(this_player())))	{
		        if (lower_case(user->GetOOCName()) == lower_case(remains)) {
			       found += ({ user });
		        }
		      }
	      }
     }

	if (sizeof(found) == 1)
	{
	    use_oocname = 1; 
	    ob = found[0];
          
	    msg_data = SOUL_D->GetChannelEmote(emote_cmd, "LIV");
	    if (!msg_data)
	    {
		str = "$N " + str;
		target = 0;
	    }
	}
	else if (ob = find_living(target = convert_name(remains)))
        {
          msg_data = SOUL_D->GetChannelEmote(emote_cmd, "LIV");
          if (!msg_data)
          {
            str = "$N " + str;
            target = 0;
          }
        }
        else if (strsrch(target, "@") == -1 || rc == verb)
        {
          string array words = explode(remains, " ");

          target = "";
          for (i=0; i<sizeof(words); i++)
          {
            target += lower_case(words[i]);
            if (ob = find_living(target))
            {
              if (i < sizeof(words)-1) remains = implode(words[(i+1)..], " ");
              else remains = 0;
              msg_data = SOUL_D->GetChannelEmote(emote_cmd, "LIV STR", remains);
              break;
            }
          }
          if (!ob)
          {
            msg_data = SOUL_D->GetChannelEmote(emote_cmd, "STR",  remains);
            target = 0;
          }
          if (!msg_data)
          {
            str = "$N " + str;
            target = 0;
          }
        }
        else if (rc != verb)
        {
          string array words;

          i = strsrch(remains, "@", -1);
          if (i >= strlen(remains)-1)
          {
            msg_data = SOUL_D->GetChannelEmote(emote_cmd, "STR", remains);
            target = 0;
          }
          else
          {
            string mud;
            int test = 3;

            words = explode(remains[(i+1)..], " ");
            target = remains[0..i];
            remains = "";
            while (sizeof(words))
            {
              mud = implode(words, " ");
              mud = INTERMUD_D->GetMudName(lower_case(mud));
              if (mud)
              {
                target += mud;
                break;
              }
              if (remains == "") remains = words[<1];
              else remains = words[<1] + " " + remains;
              words = words[0..<2];
            }
            if (!mud)
            {
              msg_data = SOUL_D->GetChannelEmote(emote_cmd, "STR", remains);
              target = 0;
            }
            else
            {
              if (trim(remains) == "") msg_data = SOUL_D->GetChannelEmote(emote_cmd, "LIV");
              else msg_data = SOUL_D->GetChannelEmote(emote_cmd, "LIV STR", remains);
              if (!msg_data)
              {
                str = "$N " + str;
                target = 0;
              }
            }
          }
        }
      }
      if (msg_data)
      {
        string sgen = this_player()->GetGender();
        string tgen = 0;

        if (ob)
        {
	    if (use_oocname)
	    {
		target = ob->GetOOCName();
	    }
	    else
	    {
		target = ob->GetName();
	    }
	    tgen = ob->GetGender();
        }
        else if (target)
        {
          string user, mud;

          sscanf(target, "%s@%s", user, mud);
          targetkey = target;
          tgen = SERVICES_D->GetRemoteGender(user, mud);
          target = SERVICES_D->GetRemoteDisplayName(user, mud);
          if (!target) target = capitalize(targetkey);
        }
	who_msg = create_message(POV_SUBJECT, msg_data[0], msg_data[1],
	      "$N", sgen, "$O", tgen, msg_data[2]);
        str = create_message(POV_OBSERVER, msg_data[0], msg_data[1],
          "$N", sgen, "$O", tgen, msg_data[2]);
        if (target)
        {
          target_msg = create_message(POV_TARGET, msg_data[0],
            msg_data[1], "$N", sgen, "$O", tgen, msg_data[2]);
        }
      }
      emote = 1;
    }
    else return 0;
  }
  else rc = GetRemoteChannel(verb);
  if (member_array(this_player(), Channels[verb]) == -1) return 0;
  if (!str || str == "")
  {
    this_player()->SetBlocked(verb);
    return 1;
  }
  if ((int)this_player()->GetBlocked(verb))
  {
    if ((int)this_player()->GetBlocked("all"))
    {
      this_player()->eventPrint("You cannot chat while totally blocked.", MSG_ERROR);
      return 1;
    }
    this_player()->SetBlocked(verb);
  }
  if (member_array(verb, NoInvis) != -1) {
    name = capitalize(this_player()->GetKeyName());
  }
  else name = (string)this_player()->GetName();
  if (target_msg) target_msg = replace_string(target_msg, "$O's", "your");
  if (!(this_player()->GetViking()))
  eventSendChannel(name, verb, str, emote, target, target_msg, who_msg);
  else eventSendChannel(name, verb, viking(str), 0, target, target_msg, who_msg);
  if (rc != verb)
  {
    if (ob)
    {
      SERVICES_D->eventSendChannel(name, rc, str, emote, target, target_msg);
    }
    else
    {
      SERVICES_D->eventSendChannel(name, rc, str, emote, targetkey, target_msg);    
    }
  }
  return 1;
}

varargs void eventSendChannel(string who, string ch, string msg, int emote,
string target, string targmsg, string whomsg)
{
  object wob;

  if (file_name(previous_object()) == SERVICES_D)
  {
    ch = GetLocalChannel(ch);
    if (emote) msg = replace_string(msg, "$N", who);
  }

  if (!Channels[ch]) return;

  if (member_array(ch, Censored) != -1) msg = doCensor(msg);

  wob = find_player(convert_name(who));
  if (member_array(ch, UseOOCName) != -1 && wob)
  {
      who = wob->GetOOCName();
  }

  if (emote)
  {
    object *obs;
    object ob;
    string this_msg, tmp;
    int len;

    if (member_array(ch, UseOOCName) != -1)
    {
	foreach (object user in users())
	{
	    if (user->GetOOCName() == target)
	    {
		ob = user;
		break;
	    }
	}
    }
    else
    {
	if (target && ob = find_player(convert_name(target)))
	{
	    target = (string)ob->GetName();
	}
    }

    this_msg = AddBrackets(ch)+" ";
    msg = replace_string(msg, "$N", who);
    if(!whomsg) whomsg = msg;
    if (target)
    {
      targmsg = replace_string(targmsg, "$N", who);
      targmsg = capitalize(replace_string(targmsg, "$O", "you"));
      if(target == who || (wob && convert_name(target) == convert_name(wob->GetKeyName())))
      {
	 whomsg = capitalize(replace_string(whomsg, "$O", "yourself"));
	 msg = replace_string(msg, "$O", reflexive(wob));	 
      }
      else
      {
	 whomsg = capitalize(replace_string(whomsg, "$O", target));
	 msg = replace_string(msg, "$O", target);
      }
    }
    /* Allow possession */
    if(msg[0..(strlen(who)+2)] == who+" 's") msg = msg[0..(strlen(who)-1)]+msg[strlen(who)+1..];
    obs = filter(Channels[ch], (: $1 && !((int)$1->GetBlocked($(ch))) :));
    if(wob) obs -= ({ wob });
    tmp = this_msg + msg;
    AddHistory(ch, tmp);
    foreach (object listener in obs)
    {
      if (listener == ob) continue;
      listener->eventPrint(tmp, MSG_CONV);
    }
    if (member_array(ob, obs) != -1)
    {
      if (ob && !((int)ob->GetBlocked(ch)))
      {
        tmp = this_msg + targmsg;
        ob->eventPrint(tmp, MSG_CONV);
      }
    }
    if(wob)
    {
       tmp = this_msg + whomsg;
       if (member_array(ch, wob->GetChannels()) != -1)
       wob->eventPrint(tmp, MSG_CONV);
    }
  }
  else
  {
    object *obs;

    msg = who + " " + AddBrackets(ch) + " " + msg;
    obs = filter(Channels[ch], (: $1 && !((int)$1->GetBlocked($(ch))) :));
    obs->eventPrint(msg, MSG_CONV);
    AddHistory(ch, msg);
  }
}

string *GetChannelList(string ch)
{
  string *ret;
  object who;
  string list;
  int i;
if (ch == "test") {
  return "/daemon/newchat"->GetChannelList(ch);
}
  if (file_name(previous_object()) == SERVICES_D) ch = GetLocalChannel(ch);
  else if (origin() != ORIGIN_LOCAL) return ({ });
  if (!Channels[ch]) return ({ });
  ret = ({ });
  foreach (who in Channels[ch])
  {
   if (!who || (int)who->GetWhoInvis() || (int)who->GetInvis() || (int)who->GetBlocked(ch)) continue;
    if (member_array(ch, UseOOCName) != -1) ret += ({ who->GetOOCName() });
      else ret += ({ (string)who->GetName() });
  }
  return ret;
}

string GetLocalChannel(string ch)
{
  switch (ch)
  {
   case "imud_code":
      return "intercre";
   case "imud_gossip":
      return "intergossip";
   case "dead_souls":
      return "ds";
   case "havenlib":
      return "hl";
   case "free_speech":
     return "fs";
   case "dchat":
      return "dc";
   case "url":
      return "iurl";
   case "sport":
      return "isport";
   case "inews":
      return "nws";
   case "bsg":
    return "ibsg";
   
        
  }
  return ch;
}

string GetRemoteChannel(string ch)
{
  switch (ch)  {
    case "fs":
     return "free_speech";
    case "intercre": 
     return "imud_code";
    case "intergossip":
     return "imud_gossip";
    case "ds":
     return "dead_souls";
    case "hl":
     return "havenlib";
    case "dc":
     return "dchat";
    case "isport":
     return "sport";
    case "nws":
     return "inews";
    case "iurl":
      return "url";
    case "ibsg":
     return "bsg";
  }
  return ch;
}

string *GetChannels() { return copy(keys(Channels)); }

