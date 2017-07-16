//
// Summary: tunnel connecting draconians' and Kysanth's lair
// Created by: Rhakz@Haven -- Angel Cazares
// For Baria
// Date: 31/01/99
//
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static int XPosition, YPosition;
static void SetupRoom(int x, int y);

static void create(int x, int y) {
    string n, s, e, w;
    SetNoReplace(1);
    room::create();
    XPosition = x;
    YPosition = y;

    if (y < 15) {
        n = "tunnel/" + (x) + "," + (y+1);
            }
    if (y > 0) {
        s = "tunnel/" + (x) + "," + (y-1);
    }
    if (y == 5 && x == 0) {
        e = "tunnel/1,5";
        n = 0;
    }
    if (y == 5 && x == 1) {
        w = "tunnel/0,5";
        s = 0;
    }
    if (y == 11 && x == 1) {
        e = "tunnel/2,11";
        n = 0;
    }
    if (y == 11 && x == 2) {
        w = "tunnel/1,11";
        s = 0;
    }
    if (n) AddExit("north", n);
    if (w) AddExit("west", w);
    if (e) AddExit("east", e);
    if (s) AddExit("south", s);
    SetShort("a dark and hot tunnel");
    SetClimate("underground");
    SetupRoom(x, y);
}

static void SetupRoom(int x, int y) {
  string long;
  mapping items = ([ ]), inv = ([ ]), itemadj = ([ ]);
  long = "The dark and hot tunnel runs endlessly to the north. "
         "The walls are very smooth and they contain some "
         "carvings and strange markings. "
         "Torches hang from the walls in an attempt to dimly "
         "illuminate the passage."; 
  items = ([
            ({"tunnel","passage"}) : (: GetLong :),
            ({"wall","walls"}) : 
              "The walls have been perfectly cut out from the "
              "ground, making them very smooth. There are some "
              "carvings and markings on them. They also hold "
              "several lit torches.",
            ({"carvings","carving","markings","marking"}) :
              "These strange figures of dragons are marked on "
              "the walls' surface. They seem to be religion-"
              "related.",
            ({"torch","torches"}) :
              "Several lit torches hang from the walls, dimly "
              "enlightening the tunnel.",
            ({"floor","ground"}) :
              "The ground is very smooth and dry."
  ]);
  itemadj = ([
              "wall" : ({"smooth","marked","carved"}),
              "carvings" : ({"strange"}),
              "torch" : ({"lit"}),
              "floor" : ({"smooth","dry"})
  ]);
  if ( (x == 0 && y == 5) || (x == 1 && y == 11) ) {
    long += "The tunnel turns east in here.";
  }
  SetLong(long);
  SetItems(items);
  SetInventory(inv);
  SetItemAdjectives(itemadj);
}
