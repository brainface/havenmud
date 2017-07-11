#include <lib.h>
inherit LIB_DAEMON;

private mapping ChannelMembers;

static void create() {
  ::create();
  SetNoClean(1);
  ChannelMembers = ([ ]);
  foreach (object user in users())  {
    string *chans;
    string channel;

    if (!(chans = (string *)user->GetChannels())) continue;
    foreach (channel in chans) {
      if (!ChannelMembers[channel]) ChannelMembers[channel] = ({ });
      ChannelMembers[channel] = distinct_array(ChannelMembers[channel] + ({ user }));
      }
    }
}

string *eventRegisterMember(string *chans) {
  string *tmp;
  object ob;
  string channel;

  if (!living(ob = previous_object())) return ({ });
  if(ob->GetProperty("assumed")) { ob = ob->GetProperty("assumed");  }
  tmp = ({ });
  foreach (channel in chans)  {
    /* just check out for secure channels */
    switch (channel) {
      case "admin":
        if (!adminp(ob)) break;
      case "meta":
        if (!metap(ob)) break;
      case "arch": case "intercre": case "allnotify":
        if (!assistp(ob)) break;
      case "muse":
      case "souls":
      case "intergossip": case "dc":
      case "fs": case "ds": case "ibsg":
        if (ob->GetName()!= "Salius" && ob->GetName() != "Sinistrad" && !musep(ob)) break;
      case "imm": case "prayer": case "error":
      case "reports":
        if (!creatorp(ob)) break;

      default:
        if (!ChannelMembers[channel]) ChannelMembers[channel] = ({ });
        ChannelMembers[channel] = distinct_array(ChannelMembers[channel] + ({ ob }));
        tmp += ({ channel });
    }
  }
  return tmp;
}

string *eventRemoveMember(string *chans) {
  object ob;
  string channel;

  if (!living(ob = previous_object())) return({ });
  foreach (channel in chans)  {
    if (!ChannelMembers[channel]) continue;
    else ChannelMembers[channel] -= ({ ob });
    if (!sizeof(ChannelMembers[channel])) map_delete(ChannelMembers, channel);
  }
  return chans;
}

mapping GetChannelMembers() { return ChannelMembers; }


