#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_DAEMON;

mapping Docks = ([
SOUTHERN_COAST_TOWNS  "haven/room/wharf"  : ({  0, 1  }),
CRYSTAL_REACHES_TOWNS "lloryk/room/wharf" : ({ -88, 7  }),
CRYSTAL_REACHES_TOWNS "karak/room/rd7"    : ({ -68, -1 }),
CRYSTAL_REACHES_TOWNS "gwonish/room/rd8"  : ({ -93, -1 }),
TAIRI_TOWNS           "tairi/room/path11" : ({ 150, -51  }),
AVERATH_TOWNS         "averath/room/wharf": ({ 0, -101 }),
PENINSULA_TOWNS       "sanctum/room/docks": ({ -32, -11 }),
PENINSULA_TOWNS       "sanctum/room/rd05" : ({ -25, -7 }),
HAVENWOOD_AREAS       "wood/rooms/beach15": ({ 11, 38 }),
HAVENWOOD_AREAS       "wood/rooms/beach14": ({ 11, 37 }),
HAVENWOOD_AREAS       "wood/rooms/beach13": ({ 11, 36 }),
HAVENWOOD_AREAS       "wood/rooms/beach12": ({ 11, 35 }),
HAVENWOOD_AREAS       "wood/rooms/beach11": ({ 10, 34 }),
HAVENWOOD_AREAS       "wood/rooms/beach10": ({ 9, 34 }),
HAVENWOOD_TOWNS       "parva/room/docks1" : ({  29, 46 }),
GUROV_TOWNS           "gurov/room/bay1"   : ({ -51, 109 }),
GUROV_TOWNS           "gurov/room/bay4"   : ({ -50, 109 }),
GUROV_TOWNS           "gurov/room/bay7"   : ({ -49, 109 }),
GUROV_TOWNS           "gurov/room/bay3"   : ({ -51, 111 }),
GUROV_TOWNS           "gurov/room/bay5"   : ({ -50, 110 }),
GUROV_TOWNS           "gurov/room/bay2"   : ({ -51, 110 }),
FROSTMARCHES_TOWNS    "keryth/room/wharf" : ({ -152, 93 }),
DOMAIN_ISLANDS        "assassin/room/bay" : ({ 111, -299 }),
BARIA_TOWNS           "baria/room/path12" : ({ -150, 1 }),
XANDRIA_VIRTUAL       "river/-1,0"        : ({ -1, -501}),
ISLANDS_AREAS         "monkey/room/port"  : ({ -150, -19 }),
SOUTHERN_COAST_AREAS  "meadow/rooms/meadow13" : ({ -19, 1 }),  
SOUTHERN_COAST_AREAS  "meadow/rooms/meadow12" : ({ -20, 1 }), 
SOUTHERN_COAST_AREAS  "meadow/rooms/meadow11" : ({ -21, 1 }), 
SOUTHERN_COAST_AREAS  "acove/rooms/cove3"     : ({ -12, 2 }),
 ]);

mapping Towns = ([
"haven"   : SOUTHERN_COAST_TOWNS  "haven/room/wharf"  ,
"lloryk"  : CRYSTAL_REACHES_TOWNS "lloryk/room/wharf" ,
"tairi"   : TAIRI_TOWNS           "tairi/room/path11" ,
"averath" : AVERATH_TOWNS         "averath/room/wharf",
"sanctum" : PENINSULA_TOWNS       "sanctum/room/docks" ,
"parva"   : HAVENWOOD_TOWNS       "parva/room/docks1" ,
"gurov"   : GUROV_TOWNS           "gurov/room/bay5"   ,
"karak"   : CRYSTAL_REACHES_TOWNS "karak/room/rd7"   ,
"gwonish" : CRYSTAL_REACHES_TOWNS "gwonish/room/gw01"   ,
"keryth"  : FROSTMARCHES_TOWNS    "keryth/room/wharf" ,
"lisht"   : XANDRIA_VIRTUAL       "river/-1,0"       ,
"assassin": DOMAIN_ISLANDS        "assassin/room/bay" ,
"baria"   : BARIA_TOWNS           "baria/room/path12" ,
]);


int *GetCoordinates(string room) {
  mixed *tmp = ({ });
  string *averath = ({ });
  int x, y, z;
  
  if (Docks[room]) {
    tmp = Docks[room];
    return tmp;
  }
  tmp = explode(room, "/");
  if (sizeof(tmp) != 5) {
    debug("Called for a room to coordinate translation of " + room + " by " + identify(previous_object(-1)));
    return ({ });
    }
  if (tmp[1] == "xandria") {
     averath = explode(tmp[4], ",");
     x = to_int(averath[0]);
     y = to_int(averath[1]);
     tmp = ({ x, (y - 1501) });
     return tmp;
     }
  
  if (tmp[3] != "ocean") {
    debug("Called for a room to coordinate translation of " + room + " by " + identify(previous_object(-1)));
    return ({ });
  }
  tmp = explode(tmp[4], ",");
  foreach(mixed s in tmp) { tmp -= ({ s }); s = to_int(s); tmp += ({ s }); }
  return tmp;
}
  

string GetTownDock(string town) {
  if (!Towns[town]) return 0;
  return Towns[town];
}

string GetTowns() {
  return conjunction(keys(Towns), "and");
}

string *GetTownArray() { return keys(Towns); }
  
