/*    /daemon/services/channel.c
 *    from the Dead Souls LPC Library
 *    handles intermud channels using the Intermud 3 protocols
 *    created by Descartes of Borg 950625
 *    Version: @(#) channel.c 1.2@(#)
 *    Last modified: 96/12/14
 */

#define SERVICE_CHANNEL

#include <daemons.h>
#include <message_class.h>
inherit "/daemon/chat/censor";

string *IgnoredMuds = ({ "boarder" });
string *IgnoredPeople = ({  });


void eventReceiveChannelWhoReply(mixed array packet) {
    object ob;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( !(ob = find_player(packet[5])) ) return;
    packet[6] = (string)CHAT_D->GetLocalChannel(packet[6]);
    if( !sizeof(packet[7]) ) {
	    ob->eventPrint("No one is listening to " + packet[6] + " at " +  packet[2] + ".", MSG_SYSTEM);
	    return;
    }
    ob->eventPrint("Listening to " + packet[6] + " at " + packet[2] + ":" + implode(packet[7], "   "), MSG_SYSTEM);
}

void eventReceiveChannelWhoRequest(mixed array packet) {
    string array who;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    who = (string array)CHAT_D->GetChannelList(packet[6]);
    INTERMUD_D->eventWrite(({ "chan-who-reply", 5, mud_name(), 0, packet[2], packet[3], packet[6], who }));
}

void eventReceiveChannelUserRequest(mixed array packet) {
    object ob;
    string visname;
    int gender;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( !(ob = find_player(packet[6])) ) {
	    INTERMUD_D->eventWrite( ({ "error", 5, mud_name(), 0, packet[2], 0, "unk-user", packet[6] + " is not a valid " "player.", packet }) );
	    return;
    }
    visname = (string)ob->GetCapName();
    switch( (string)ob->GetGender() ) {
	    case "male": gender = 0; break;
      case "female": gender = 1; break;
      default: gender = 2; break;
    }
    INTERMUD_D->eventWrite( ({ "chan-user-reply", 5, mud_name(), 0,   packet[2], 0, packet[6], visname, gender }));
}

void eventReceiveChannelMessage(mixed array packet) {
    string msg = "Your mud name is too long.  Please change it.";
    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( packet[2] == mud_name() ) return;
    if (member_array(packet[2], IgnoredMuds) != -1) { packet[8] = "(" + packet[6]+ ") " + packet[8];packet[6] = "ignore"; }
    if (member_array(packet[7], IgnoredPeople) != -1) { packet[8] = "(" + packet[6]+ ") " + packet[8];packet[6] = "ignore"; }  
//    if (strlen(packet[2]) > 20) {  SERVICES_D->eventSendTell(packet[7], packet[2], msg);  packet[8] = "(" + packet[6]+ ") " + packet[8]; packet[6] = "ignore"; packet[2] = packet[2][0..20];}
    CHAT_D->eventSendChannel(packet[7] + "@" + packet[2], packet[6], packet[8]);
}

void eventReceiveChannelEmote(mixed array packet) {
    string msg = "Your mud name is too long.  Please change it.";
    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( packet[2] == mud_name() ) return;
    if( !packet[7] ) return;
    if (member_array(packet[2], IgnoredMuds) != -1) { packet[8] = "(" + packet[6]+ ") ";packet[6] = "ignore"; }
    if (member_array(packet[7], IgnoredPeople) != -1) { packet[8] = "(" + packet[6]+ ") " + packet[8];packet[6] = "ignore"; }        
//    if (strlen(packet[2]) > 20) { SERVICES_D->eventSendTell(packet[7], packet[2], msg); packet[8] = "(" + packet[6]+ ") "  + packet[8]; packet[6] = "ignore"; packet[2] = packet[2][0..20];}
    CHAT_D->eventSendChannel(packet[7] + "@" + packet[2], packet[6], packet[8], 1, 0, 0);
}

void eventReceiveChannelTargettedEmote(mixed array packet) {
    string target;
    string msg = "Your mud name is too long.  Please change it.";
    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( packet[2] == mud_name() ) return;
    if (member_array(packet[2], IgnoredMuds) != -1)  packet[6] = "ignore";
    if (member_array(packet[11], IgnoredPeople) != -1) { packet[8] = "(" + packet[6]+ ") " + packet[8];packet[6] = "ignore"; }  
    if( packet[7] != mud_name() ) target = packet[12] + "@" + packet[7];
    else target = packet[12];
//    if (strlen(packet[2]) > 20) { SERVICES_D->eventSendTell(packet[7], packet[2], msg); packet[6] = "ignore"; packet[2] = packet[2][0..20];}      
    CHAT_D->eventSendChannel(packet[11] + "@" + packet[2], packet[6], packet[9], 1, target, packet[10]);
}

varargs void eventSendChannel(string who, string ch, string msg, int emote,
			      string target, string targmsg) {
    mixed array packet;
    string targpl, where;  // targpl is target keyname
    if (member_array(ch, Censored) != -1) {
      msg = doCensor(msg);
    }
    if (who != "Duuk")
    msg = strip_colours(msg);

    if( emote ) {
	if( target && targmsg ) {
	    if( sscanf(target, "%s@%s", targpl, where) != 2 ) {
		targpl = convert_name(target);
		where = mud_name();
	    }
	    else {
		target = SERVICES_D->GetRemoteDisplayName(targpl, where);
		if( !target ) target = capitalize(targpl);
	    }
	    packet = ({ "channel-t", 5, mud_name(), convert_name(who), 0, 0,
			ch, where, targpl, msg, targmsg, who, target });
	}
	else packet = ({ "channel-e", 5, mud_name(), convert_name(who), 0, 0,
			 ch, who, msg });
    }
    else packet = ({ "channel-m", 5, mud_name(), convert_name(who), 0, 0, ch, 
		     who, msg });
    INTERMUD_D->eventWrite(packet);
}

void eventSendChannelWhoRequest(string channel, string mud) {
    string pl;

    pl = (string)this_player(1)->GetKeyName();
    INTERMUD_D->eventWrite(({ "chan-who-req", 5, mud_name(), pl, mud, 0,
			      channel }));
}

void eventRegisterChannels(mapping list) {
    mixed array val;
    string channel, ns;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    ns = (string)INTERMUD_D->GetNameserver();
    foreach(channel, val in list) {
	if( !val ) continue;
	if( channel == (string)CHAT_D->GetLocalChannel(channel) ) {
	    INTERMUD_D->eventWrite(({ "channel-listen", 5, mud_name(), 0, ns, 
				      0, channel, 0 }));
	}
	else INTERMUD_D->eventWrite(({ "channel-listen", 5, mud_name(), 0, ns,
				       0, channel, 1 }));
    }
}

int eventAdministerChannel(string channel, string array additions,
			   string array subs) {
    if( !((int)master()->valid_apply( ({}) )) ) return 0;
    if( member_array(channel, (string array)INTERMUD_D->GetChannels()) == -1 )
      return 0;
    INTERMUD_D->eventWrite(({ "channel-admin", 5, mud_name(),
			      (string)this_player(1)->GetKeyName(),
			      (string)INTERMUD_D->GetNameserver(),
			      0, channel, additions, subs }));
    return 1;
}

int AddChannel(string channel, int privee) {
    if( !((int)master()->valid_apply( ({}) )) ) return 0;
    if( member_array(channel, (string array)INTERMUD_D->GetChannels()) != -1 )
      return 0;
    INTERMUD_D->eventWrite(({ "channel-add", 5, mud_name(), 
			      (string)this_player(1)->GetKeyName(),
			      (string)INTERMUD_D->GetNameserver(), 0,
			      channel, privee }));
    return 1;
}

int RemoveChannel(string channel) {
    if( !((int)master()->valid_apply( ({}) )) ) return 0;
    if( member_array(channel, (string array)INTERMUD_D->GetChannels()) == -1 )
      return 0;
    INTERMUD_D->eventWrite(({ "channel-remove", 5, mud_name(),
			      (string)this_player(1)->GetKeyName(),
			      (string)INTERMUD_D->GetNameserver(), 0,
			       channel }));
    return 1;
}
