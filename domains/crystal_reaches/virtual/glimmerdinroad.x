//
// Virtual Roads - Glimmerdin Road
// Created by Ranquest
// 6th February 1999
//
// Notes:
// GR linked to G city on Feb. 7 by Duhoc
// Link to Heyam removed at (-7,22)
// Link to "/areas/mistik/rooms/tm1" removed at (-7,22)
// Changed to reflect banishment of Haun
//

#include <lib.h>
#include <domains.h>
#include <std.h>
#define SALTUS_OPEN 0
inherit LIB_ROOM;

static private int XPosition, YPosition;

varargs static void create(int x, int y) {
  string n, s, e, w, nw, se, ne;
  mapping items, inv, itemadj;
  string str;

  room::create();
  inv = ([]);
  XPosition = x;
  YPosition = y;

  SetShort("Glimmerdin Road");
  SetClimate("temperate");
  SetDomain("Crystal Reaches");

  str = 
    "This road leads south to Lloryk Shire, which in turn curves "
    "east to Haven, city of Duuktsaryth the Lord of Balance and Order.  "
    "To the north and west, the road meets its namesake, the dwarven "
    "stronghold of Glimmerdin. To the north and east lie the Crystal "
    "Reaches, the longest mountain range of Kailie. Its peaks rise "
    "into the heavens and are perpetually covered in clouds and snow.";
  items = ([
    ({"glimmerdin road", "road" }) :
      "The road is cobblestoned, and seems as old as Kailie"
      " itself. A few hardy travellers often use it in the"
      " hope of seeing Haven town, and every so often, an"
      " elf will venture out of his home on some important"
      " errand.",
    ({ "reaches", "crystal reaches", "mountains" }) :
      "The Crystal Reaches are an old, long mountain range whose "
      "peaks are covered in snow and clouds.",
    ]);
  itemadj = ([
    ]);

  if( y >= 0 && y < 15)
    n = CRYSTAL_REACHES_VIRTUAL + "glimmerdinroad/" + x + "," + (y+1);
  if( y > 1 && y <= 15)
    s = CRYSTAL_REACHES_VIRTUAL + "glimmerdinroad/" + x + "," + (y-1);
  else if ( x == 0 && y == 1)
    s = CRYSTAL_REACHES_TOWNS + "lloryk/room/northgate";
  if( x < -7 && x >= -12 )
    e = CRYSTAL_REACHES_VIRTUAL + "glimmerdinroad/" + (x+1) + "," + y;

  if( x <= -7 && x > -12 )
    w = CRYSTAL_REACHES_VIRTUAL + "glimmerdinroad/" + (x-1) + "," + y;
  if ( x > -7 && x <= 0 && y >= 15 )
    nw = CRYSTAL_REACHES_VIRTUAL + "glimmerdinroad/" + (x-1) + "," + (y+1);
  if ( x >= -7 && y <= 22 && x < 0 )
    se = CRYSTAL_REACHES_VIRTUAL + "glimmerdinroad/" + (x+1) + "," + (y-1);
  if ( x == -11 && y == 22 ) {
    str += " To the north stands the entrance to a cave.";
    items += ([ "cave" : "The cave stands like a gaping hole in the world."]);
    }
  if ( x == -12 && y == 22 ) {
    s = CRYSTAL_REACHES_AREAS + "mines/rooms/start";
    n = CRYSTAL_REACHES_TOWNS + "glimmerdin/room/outside_gate";
    }
  if ( x == -2 && y == 17 ) {
  e = CRYSTAL_REACHES_AREAS + "ungkh/room/road01";
    str += " To the east lies the primitive city of Ungkh.";
    }
  if ( x == -8 && y == 22 ) {
    n = CRYSTAL_REACHES_AREAS + "aelithol/rooms/entrance";
    }
  if ( x == 0 && y ==15 )
    w = VALLEY_VIRTUAL + "valleyrd/-1,0";

  SetLong(str);
  SetItems(items);
  SetItemAdjectives(itemadj);
  SetInventory(inv);

  if( n ) AddExit("north", n);
  if( s ) AddExit("south", s);
  if( e ) AddExit("east", e);
  if( w ) AddExit("west", w);
  if( nw ) AddExit("northwest", nw);
  if( se ) AddExit("southeast", se);
  if( ne ) AddExit("northeast", ne);
  if( x == -11 && y == 22) {
    AddEnter("cave", CRYSTAL_REACHES_AREAS + "caverns/level_1/entrance");
    SetSmell( ([
      "default" : "An odd scent comes from the cave.",
      ]) );
    SetListen( ([
      "default" : "Something is making noise in the cave.",
      ]) );
    }
    if (random(100) > 90)
      inv += ([ STD_NPC + "traveller" : 1 ]);
    if (random(100) > 95)
      inv += ([STD_NPC + "minstrel" : 1 ]);
    if (random(100) > 97)
      inv += ([STD_NPC + "monk" : 1]);

}
