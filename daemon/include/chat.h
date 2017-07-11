#ifndef __CHAT_H__
#define __CHAT_H__

static void create();
string *eventRegisterMember(string *chans);
string *eventRemoveMember(string *chans);
int cmdChannel(string verb, string str);
varargs void eventSendChannel(string who, string ch, string msg, int emote,
			      string target, string targmsg, string whomsg, int use_oocname);
string *GetChannelList(string ch);
string GetLocalChannel(string ch);
string GetRemoteChannel(string ch);
string AddBrackets(string ch);
private void AddHistory(string ch, string str);
mixed *GetHistory(string ch);
string* GetBadWords();
string* GetCensored();
string* AddBadWord(mixed str);
string* AddCensored(mixed str);
string* RemoveBadWord(mixed str);
string* RemoveCensored(mixed str);
string doCensor(string str);

#endif /* __CHAT_H__ */
