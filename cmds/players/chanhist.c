#include <lib.h>
#include <daemons.h>

#define DEFAULT_CHAN  "ooc"
#define DEFAULT_START 20

inherit LIB_DAEMON;

int cmd(string arg)
{
  object who = this_player();
  string *output = ({ });
  mixed *list;
  mapping opts = ([ ]);

  if (arg && !sizeof(opts = getopts(arg, ({ "-c", "-s", "-e", "-t" })))) opts["-c"] = arg;
  if (!opts["-c"]) opts["-c"]= DEFAULT_CHAN;
  if (!opts["-s"] = to_int(opts["-s"])) opts["-s"] = DEFAULT_START;
  if (!opts["-e"] = to_int(opts["-e"])) opts["-e"] = 0;

  if (!(list = CHAT_D->GetHistory(opts["-c"])))
  {
    who->eventPrint("History not available.");
    return 1;
  }

  foreach (mixed *arr in list[(sizeof(list)-opts["-s"])..(sizeof(list)-opts["-e"]-1)])
  {
    mixed *ts = localtime(arr[0]);
    string str;
    if (!opts["-t"]) str = sprintf("%02d/%02d %02d:%02d:%02d %s[%03d]%s %s",
      ts[4]+1, ts[3], ts[2], ts[1], ts[0], "%^BOLD%^RED%^",
      member_array(arr, list)+1, "%^RESET%^", arr[1]);
    else str = sprintf("%s[%03d]%s %s", "%^BOLD%^RED%^",
      member_array(arr, list)+1, "%^RESET%^", arr[1]);
    output += ({ str });
  }
  who->eventPage(output);
  return 1;
}

string GetHelp()
{
  return  "Syntax: <chanhist [channel]>\n"
          "        <chanhist [-cx] [-sx] [-ex] [-t]>\n\n"
          "Shows you the history of a channel.  Arguments can be either "
          "simply the name of a channel, as in \"chanhist gossip\" or a list "
          "of options as in \"chanhist -cgossip -s50 -e20 -t\".\n\n"

          "  -c%^BLUE%^BOLD%^x%^RESET%^  Selects the channel where "
            "%^BLUE%^BOLD%^x%^RESET%^ is a name like \"gossip\".  Default is "
            "ooc.\n\n"

          "  -s%^BLUE%^BOLD%^x%^RESET%^  Start %^BLUE%^BOLD%^x%^RESET%^ "
            "number of messages before the most current.  Default is 20.\n\n"

          "  -e%^BLUE%^BOLD%^x%^RESET%^  End %^BLUE%^BOLD%^x%^RESET%^ number "
            "of messages before the most current.  Default is 0, obviously "
            "meaning that the last message is included.\n\n"

          "  -t   Do not display timestamp.\n";
}
