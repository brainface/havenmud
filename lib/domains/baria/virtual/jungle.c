/*  The Barian Jungle */
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static private int XPosition, YPosition;
static void SetLongAndItems();

static void create(int x, int y) {
  string *tmp = ({ });
  string n,s,e,w;
  SetNoReplace(1);
  room::create();
  XPosition = x;
  YPosition = y;

/*  Setting Exits */

  if (x < 10) {
    e = "jungle/" + (x+1) + "," + y;
  }
  if (x > -10) {
    w = "jungle/" + (x-1) + "," + y;
  }
  if (y > -10) {
    s = "jungle/" + x + "," + (y-1);
  }
  if (y < 10) {
    n = "jungle/" + x + "," + (y+1);
  }
  if ((y == 10) && ( x == -10) ) {
    n = "/domains/frostmarches/virtual/frostmarchrd/0,-10";
  }
  if ((x == -10) && (y == -10)) {
     s = "/domains/baria/towns/baria/room/path1";
  }
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);

/*  SetShort and SetObviousExits */

  SetShort("in a sweltering jungle");
  SetClimate("tropical");
  SetDomain("Baria");
  foreach(string ex in GetExits()) {
    tmp += ({ ex });
  }
  tmp = implode(tmp, ", ");
  SetObviousExits(tmp);
  SetLongAndItems();
  // a solitary road sign
  if (x == -10 && y == 8 ) AddInventory(BARIA_VIRTUAL "junglen10p8", 1);


}

static void SetLongAndItems() {
  mapping inv = ([ ]), items = ([ ]);
  string daylong, nightlong;

/*  Make a default Long */

  daylong = "The jungle is filled with towering trees and exotic foliage, "
            "which block the sun almost completely. The ground is covered "
            "with vines and dry remains of plants. The greenness of the "
            "jungle stretches out in all directions.";

  nightlong = "The dark jungle is covered with shadows of trees and foliage "
              "that filter the faint moonlight. The ground would seem like  "
              "a dark void if it wasn't for the few rays of pale light. Only "
              "darkness can be seen around.";

/*  Make default items based on the above long */

  items = ([
       ({ "tree", "trees" }) : "The trees are normal palm and other "
                               "tropical varieties.",
       ({ "vine", "vines" }) : "The vines are normal dead plants that "
                               "fell from the trees above.",
          ]);


/*  Make a default inventory, if it needs one */

  if (!random(15)) {
    inv["/domains/baria/areas/jungle/native"] = (random(2) + 1);
  }
  if (!random(20)) {
    inv["/domains/baria/areas/jungle/native_sword"] = 1;
  }
  if (!random(8)) {
    inv["/std/npc/monkey"] = 1;
  }
  if (!random(8)) {
    inv["/std/npc/tarantula"] = 1;
  }

  SetInventory(inv);
  SetDayLong(daylong);
  SetNightLong(nightlong);
  SetItems(items);
  SetListen( ([ "default" : "There's an incessant sound of moving leaves." ]) );
  SetSmell( ([ "default" : "The smell of the trees and plants is refreshing." ]) );
}

