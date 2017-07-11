// Title: Durgoroth Town
// File: durgorothroad.c
// Author: Tim Morris aka Morgoth@Haven
// Date: June 1998
//
// Abstract: Virtual road leading from the frostmarch road to
//                      the town of Durgoroth
//
// Revision History: 
//

#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static int XPosition, YPosition;
static void SetupRoom(int x, int y);

static void create(int x, int y) {
        string *tmp = ({ });
        string nw, se;
        string e, w;
        string n, s;
        SetNoReplace(1);
        room::create();
        XPosition = x;
        YPosition = y;

        if (y == 0) {
                se = FROSTMARCHES_VIRTUAL+"frostmarchrd/0,18";
                }
        else if(y <= 10) {
                se = "durgorothroad/" + (x+1) + "," + (y-1);
                }
        if (y < 10) {
                nw = "durgorothroad/" + (x-1) + "," + (y+1);
                }
        if (y == 15) {
                n = FROSTMARCHES_AREAS+"outpost/room/south_gate";
                }
        else if (y > 9) {
                n = "durgorothroad/" + (x) + "," + (y+1);
                }
        if (y > 10) {
                s = "durgorothroad/" + (x) + "," + (y-1);
                }
  if (y == 12) e = FROSTMARCHES_AREAS "lodge/room/outside1";
        if (n) AddExit("north", n);
        if (s) AddExit("south", s);
      if (e) AddExit("east", e);
        if (nw) AddExit("northwest", nw);
        if (se) AddExit("southeast", se);
        foreach(string ex in GetExits() ) {
                tmp += ({ ex });
                }
        tmp = implode(tmp, ", ");
        SetObviousExits(tmp);
        SetShort("a winding road climbing up into the Frostmarches");
        SetClimate("arctic");
        SetDomain("FrostMarches");
        SetupRoom(x, y);
        }

static void SetupRoom(int x, int y) {
        string long;
        mapping items = ([ ]), inv = ([ ]);
        long = "The narrow winding road climbs up into the Frostmarches "
                "from the valley below. To the south the valley can be seen "
                "running from east to west along the southern spur of the "
                "Frostmarches. The road continues on up into the mountains "
                "above to the north, and down into the valley below to "
                "the south.";
        if (y == 15) {
                long += " The town of Durgoroth can be seen to the north.";
                }
        SetLong(long);
        SetItems(items);
        SetInventory(inv);
        }

