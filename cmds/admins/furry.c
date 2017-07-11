#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

void eventFurry(object who, int cycle);

mixed cmd(string args) {
  string sWho;
  string sNumber;
  string *x;
  object oWho;
  int iNumber;

  x = explode(args, " ");
  if (sizeof(x) != 2) {
    return "furry who how_many";
    }

  sWho = x[0];
  sNumber = x[1];
  iNumber = to_int(x[1]);
  if (!iNumber) return "How many furries need to visit?";
  oWho = find_living(sWho);
  if (!oWho) return "Who do the furries need to visit?";
  call_out( (: eventFurry, oWho, iNumber :), random(6) + 1);
  return "Started the furry invasion.";
}

void eventFurry(object who, int cycle) {
  debug(identify(who) + " " + cycle + " more times");
  cycle--;
  if (!who) return;
    new("/realms/duuk/stuff/thing")->eventMoveLiving(environment(who), "$N comes rushing in.");
  if (cycle > 0) {
    call_out( (: eventFurry, who, cycle-- :), random(6) + 1);
   }
}
