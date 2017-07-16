#include <lib.h>
inherit LIB_DAEMON;

mapping Distance = ([
"averath"        : ({  0, -5 }),
"baria"          : ({ -5,  0 }),
"crystal_reaches": ({ -2,  0 }),
"estergrym"      : ({  1,  2 }),
"frostmarches"   : ({ -5,  5 }),
"gurov"          : ({ -3,  5 }),
"havenwood"      : ({  1,  1 }),
"islands"        : ({  5,  5 }),
"innersea"       : ({  20,  20 }),
"peninsula"     : ({ -2, -1 }),
"southern_coast" : ({  0,  0 }),
"tairi"          : ({ 30, 30 }),
"valley"         : ({ -4,  1 }),
"westwood"       : ({ -1,  1 }),
"xandria"        : ({  0, -50 }),
"yozrath"        : ({ -3,  3 }),
 ]);

static void create() {
  ::create();
}


int GetDistance(string A, string B) {
  int xd, yd;
  A = lower_case(replace_string(A, " ", "_"));
  B = lower_case(replace_string(B, " ", "_"));

  if (A == "planes" || B == "planes") return 100;
  if (!sizeof(Distance[A])) return -1;
  if (!sizeof(Distance[B])) return -1;
  xd = absolute_value(Distance[A][0] - Distance[B][0]);
  yd = absolute_value(Distance[A][1] - Distance[B][1]);
  return xd + yd;
}
