#include <lib.h>
inherit LIB_DAEMON;
object who;

mixed cmd(string name) {
  who = this_player();
  if (!name) { who->eventPrint("Fucking funny."); return 1; }
  resolve(name, "eventCallBack");
  return 1;
  }

void eventCallBack(string address, string resolved, int key) {
  who->eventPrint("IP: " + resolved);
  who->eventPrint("ADDY: " + address);
  return;
  }
