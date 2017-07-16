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

int GetOOCChannel(string channel);

private mapping Channels;
private string *NoInvis = ({ "imm", "reports", "error", "intergossip",
                                    "intercre", "muse", "prayer", "admin",
                                    "arch", "emoted", "spirit", "souls",
                                    "twilight",
                                    "meta", "ooc" });
private string* UseOOCName = ({ "ooc", "non", "test" });


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
      if (!(mud = (string)INTERMUD_D->GetMudName(mud)))      {
        this_player()->eventPrint("Haven is not aware of such a place.", MSG_ERROR);
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

string *GetChannelList(string ch) {
  string *ret;
  object who;
  string list;
  int i;
  if (file_name(previous_object()) == SERVICES_D) ch = GetLocalChannel(ch);
 // else if (origin() != ORIGIN_LOCAL) return ({ });
  if (!Channels[ch]) return ({ });
  ret = ({ });
  foreach (who in Channels[ch])  {
   if (!who || (int)who->GetWhoInvis() || ((int)who->GetInvis() > rank(this_player())) || 
               (int)who->GetBlocked(ch)) continue;
    if (GetOOCChannel(ch)) ret += ({ who->GetOOCName() });
    else ret += ({ (string)who->GetName() });
  }
  return ret;
}

string GetLocalChannel(string ch) {
  switch (ch)  {
    case "imud_code":
      return "intercre";
    case "imud_gossip":
      return "intergossip";
  }
  return ch;
}

int GetOOCChannel(string channel) {
  if (member_array(channel, UseOOCName) != -1) return 1;
  return 0;
}

string GetRemoteChannel(string ch) {
  switch (ch)  {
    case "intercre": 
      return "imud_code";
    case "intergossip":
      return "imud_gossip";
  }
  return ch;
}

string *GetChannels() { return copy(keys(Channels)); }

string GetTarget(string channel, string args) {
  int ooc_flag;
  if (member_array(channel, UseOOCName) != -1) ooc_flag = 1;
  return "";
}

int eventResolveEmote(object who_ob, string channel, string str) {
  string *tmp = explode(str, " ");
  string adverb;
  string target;
  string emote;
  string message, targetmessage, whomessage;
  mixed *ChannelEmote;
  string who;
  
  if (GetOOCChannel(channel)) who = capitalize(who_ob->GetOOCName());
    else who = capitalize(who_ob->GetName());
  emote = tmp[0];
  if (member_array(emote, SOUL_D->GetEmotes()) != -1) {
    if (sizeof(tmp) == 1) { 
      ChannelEmote = SOUL_D->GetChannelEmote(emote, "");
      message = create_message(POV_OBSERVER, ChannelEmote[0], ChannelEmote[1], who, who_ob->GetGender(), 0, 0, ChannelEmote[2]);
      eventSendChannel(who, channel, message, 1);
      return 1;
    }
    if (sizeof(tmp) == 2) {
      if (member_array(tmp[1], ADVERBS_D->GetAdverbs()) != -1) {
        adverb = tmp[1];
        ChannelEmote = SOUL_D->GetChannelEmote(emote, "STR", tmp[1]);
        message = create_message(POV_OBSERVER, ChannelEmote[0], ChannelEmote[1], who, who_ob->GetGender(), 0, 0, ChannelEmote[2]);
        eventSendChannel(who, channel, message, 1);
        return 1;
      }
    }
  }
  message = who + " " + str;
  eventSendChannel(who, channel, message, 1);
  return 1;
}    

int cmdChannel(string verb, string str) {
  string channel, who, msg, target, targmsg, whomsg;
  string *tmp;
  int emote;
  object targ_ob, who_ob = this_player();
  
  if (!Channels[verb]) {
    sscanf(verb, "%semote", verb);
    if (!Channels[verb]) { return 0; }
    emote = 1; 
  }
  if (emote) {
    eventResolveEmote(who_ob, verb, str);
    return 1;
  }
  if (GetOOCChannel(verb)) who = capitalize(who_ob->GetOOCName());
    else who = capitalize(who_ob->GetName());
  eventSendChannel(who, verb, str);
  return 1;
}

varargs void eventSendChannel(string who, string ch, string msg, int emote, string target, string targmsg, string whomsg) {
  object *listeners;
  string rc;
  
  if (file_name(previous_object()) == SERVICES_D) {
    ch = GetLocalChannel(ch);
    if (emote) msg = replace_string(msg, "$N", who);
  }
  
  if (emote) {
    msg = AddBrackets(ch) + " " + msg;
  } else {
    msg = who + " " + AddBrackets(ch) + " " + msg;
  }
  rc = GetRemoteChannel(ch);
  if (rc != ch) {
    SERVICES_D->eventSendChannel(who, rc, msg, emote, target, targmsg);
    return;
  }
  listeners = filter(Channels[ch], (: $1 && !((int)$1->GetBlocked($(ch))) :));
  foreach(object listener in listeners) {
    listener->eventPrint(msg, MSG_SYSTEM);
  } 
}