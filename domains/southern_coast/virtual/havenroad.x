//
// Haven road
// created by Ranquest
// 4th Feb 1999
//
// Notes : if (x == -20) needs to be linked n to Westwood.
//


#include <lib.h>
#include <domains.h>
#include <std.h>
#include "/domains/southern_coast/towns/haven/haven.h"
inherit LIB_ROOM;

static int XPosition, YPosition;
static void SetupRoom(int x, int y);

static void create(int x, int y) {
     string e, w, sw, ne, se, s, n;
    SetNoReplace(1);
    room::create();
    XPosition = x;
    YPosition = y;

    if (x == -36) {
     s = CRYSTAL_REACHES_TOWNS + "karak/room/rd1";
     sw = CRYSTAL_REACHES_VIRTUAL + "llorykroad/15,0";
      }
    if (x > -36) {
  	    w = SOUTHERN_COAST_VIRTUAL + "havenroad/" + (x-1) + "," + (y);
      }
  if (x < 22) {
    e = "havenroad/" + (x+1) + "," + (y);
    if (x == -32) {
      s = SOUTHERN_COAST_TOWNS + "kresh/room/m_1";
      }
    if (x == 0) {
      ne = HAVENWOOD_VIRTUAL + "havenwoodroad/126,126";
      se = PENINSULA_VIRTUAL + "vimp/-14,20";
      }
    if (x == 1) {
    s  = PENINSULA_AREAS "wood/room/vale9";
    }
    if (x == 11) {
      s = SOUTHERN_COAST_AREAS "meadow/rooms/path1";
      }
    if (x == 20) {
      s = SOUTHERN_COAST_AREAS "acove/rooms/cove1";
      }
    }
  if (x == 22) {
    e = SOUTHERN_COAST_TOWNS + "haven/room/out_rd2";
    s = SOUTHERN_COAST_AREAS + "camp/room/entrance";
    }
    if (s) AddExit("south", s);
    if (w) AddExit("west", w);
    if (ne) AddExit("northeast", ne);
    if (se) AddExit("southeast", se);
    if (n) AddExit("north", n);
    if (sw) AddExit("southwest", sw);
    if (e) AddExit("east", e);
    if (s) AddExit("south", s);
    SetShort("a road from Haven to the Crystal Reaches");
    SetClimate("temperate");
    SetDomain("Southern Coast");
    SetupRoom(x, y);
}

static void SetupRoom(int x, int y) {
    string long;
    mapping items = ([ ]), itemadj = ([ ]), inv = ([ ]);
    long = "This cobblestone road seems to run endlessly from east to"
      " west. To the west lie the Crystal Reaches, including the"
      " primitive city of Ungkh, and beyond to Jidoor, fabled"
      " city of splendour. To the east is the self-proclaimed"
      " greatest city on Kailie, Haven, ruled by Duuktsaryth"
      " the Lord of Order with an iron grip.";
    items = ([
      ({"reaches","range"}) :
        "The sparkling mountain range of the Crystal Reaches"
        " lies far to the east, the distance belying the massive"
        " size of its mountains.",
      ({"ungkh","city"}) :
        "Ungkh is a city famed for the primitive peoples that"
        " call it home. It is chiefly a mix of orcs, gnolls,"
        " goblins and ogres, who have banded together in"
        " numbers for protection against the more advanced"
        " races.",
      ({"jidoor","city"}) :
        "Jidoor, the city of splendours, is famed for the beauty"
        " of the buildings and for the advancements in magic"
        " that it has brought. The city is chiefly inhabited"
        " by sprites, and guarded by the Jidoormages.",
      ({"haven","city","town"}) :
        "Haven is regarded by most as the hub of Kailie, and"
        " foremost amongst the cities both in age and power."
        " It's deity, Duuktsaryth the Lord of Order, rules"
        " the town with an iron grip, and encourages its people"
        " to be insular and haughty, believing themselves to"
        " be the superior beings of Kailie. Haven is chiefly"
        " inhabited by elves, half-elves and humans.",
      ]);
    itemadj = ([
      "reaches" : ({"crystal","mountain","sparkling"}),
      "ungkh" : ({"primitive","city of"}),
      "jidoor" : ({"fabled","city of","splendours"}),
      "haven" : ({"town","city of"}),
      ]);
      if (x > 19) {
        items += ([
          "road" : "Haven town can be seen in the distance to the"
            " west, while to the east Haven road stretches endlessly"
            " into the distance",
          ]);
        }
      if (x < -29) {
        items += ([
          "road" : "Haven road ends in a bend to the southwest,"
            " merging into Balzor road, some way the west. To the"
            " east, Haven road continues without end.",
          ]);
        }
        else {
        items += ([
          "road" : "Haven road seems to stretch endlessly into the"
            "distance to the east and west.",
          ]);
          }
    itemadj += ([
      "road" : ({"cobblestone","endless"}),
      ]);

  if (random(100) > 90) inv += ([ STD_NPC + "traveller" : 1 ]);
  if (random(100) > 96) inv += ([ H_NPC   + "blunt_wander" : 1 ]);
  if (random(100) > 96) inv += ([ STD_NPC + "minstrel" : 1 ]);
  if (random(100) > 97) inv += ([ STD_NPC + "monk" : 1]);
  if (random(100) < 3)  inv += ([ STD_NPC + "pig" : 1 ]);
  if (x < -12) if (random(100) < 5) inv += ([ SOUTHERN_COAST_TOWNS "kresh/npc/little" : 1 ]);

    SetLong(long);
    SetItems(items);
    SetInventory(inv);
    SetItemAdjectives(itemadj);
}
