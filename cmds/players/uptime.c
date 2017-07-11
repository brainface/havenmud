/*    /cmds/player/uptime.c
 *    Rewritten by Zedd.  October 27, 2001.
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string unused) {
  string str;
  int* x = time_units(uptime());

  str = mud_name() + " has been up for %^ORANGE%^";
  if (x[0]) str += sprintf("%dw ", x[0]);
  if (x[1]) str += sprintf("%dd ", x[1]);
  if (x[2]) str += sprintf("%dh ", x[2]);
  if (x[3]) str += sprintf("%dm ", x[3]);
  if (x[4]) str += sprintf("%ds", x[4]);
  str += "%^RESET%^, since " + ctime(time()-uptime()) + ".";
  return str;
}

string GetHelp() {
  return "Syntax: uptime\n\nReports how long Haven has been up.";
}
