#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd(string who)
{
  if (!metap(this_player())) return "Meta+";
  if(!who) return notify_fail("Locate whom?\n");
  SERVICES_D->eventSendLocateRequest(who);
  message("info", "Locate query sent.", this_player());
  return 1;
}
