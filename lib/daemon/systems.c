#include <lib.h>
inherit LIB_DAEMON;

mapping Systems = ([
"Cerbala"     :   ({   0,   0,   0 }),
"Sol"   :   ({   1,   0,   0 }),
]);

mapping WarpZones = ([
"Sol"     :   ({  "-10",   "0",   "0" }),
"Cerbala"   :   ({    "0",   "0",   "0" }),
]);

int GetDistance(string system1, string system2) {
  int x = 0;
  if (!Systems[system1] || !Systems[system2]) return -1;
  x += WarpZones[system2][0] - WarpZones[system1][0];
  x += WarpZones[system2][1] - WarpZones[system1][1];
  x += WarpZones[system2][2] - WarpZones[system1][2];
  return x;
}

string GetWarpZone(string system) {
  string x = capitalize(system);
  int *y   = WarpZones[x];
  if (!sizeof(y)) return "null";
  return "/systems/" + lower_case(x) + "/virtual/space/" + implode(y, ",");
}
