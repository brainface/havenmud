#include <lib.h>
#include <daemons.h>

mixed cmd(string u) {
  object *livs = livings();
  
  foreach(object l in livs) {
    if (!environment(l) && clonep(l)) {
      l->eventMoveLiving("/std/room/workroom");
      CHAT_D->eventSendChannel("clean", "error", identify(l) + " was cleaned (no env)");
      l->eventDie(this_player());
      }
    }
  return 1;
}