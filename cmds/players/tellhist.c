#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd()
{
  object who = this_player();
  string *output = ({ });
  mixed *list = who->GetTellHist();

  foreach (mixed *item in list)
  {
    mixed *ts = localtime(item[0]);
    string str;
    str = sprintf("%02d/%02d/%d %02d:%02d:%02d %s[%03d]%s %s",
      ts[4]+1, ts[3], ts[5], ts[2], ts[1], ts[0], "%^BOLD%^RED%^",
      member_array(item, list)+1, "%^RESET%^", item[1]);
    output += ({ str });
  }
  who->eventPage(output);
  return 1;
}

string GetHelp()
{
  return  "Syntax: tellhist\n\n"
          "Shows tells you have sent and received.";
}
