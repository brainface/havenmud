//
// Virtual Roads - Lloryk road
// Coded by Ranquest
// 5th February 1999
//

#include <lib.h>
#include <domains.h>

inherit LIB_ROOM;
static private int XPosition, YPosition;
static void SetLongAndItems();

varargs static void create(int x, int y) {
  string n, s, e, w, ne;
  mapping inv, items;
  string str;
  room::create();
  XPosition = x;
  YPosition = y;
  SetShort("Lloryk Road");
  SetClimate("temperate");
  SetDomain("Crystal Reaches");

  inv = ([]);
  str = "The Lloryk road is an offshoot of the Imperial Road "
        "which leads from east to west across the main continent "
        "of Kailie. Further to the west, the road curves north and "
        "leads through the Shire, while off to the east it curves "
        "around the Crystal Reaches and heads off towards Haven Town. "
        "The road is a wide lane, well travelled by many races.";
  items = ([
    ({"lloryk","town"}) : 
             "The Lloryk Shire is the home to the peaceful halfling race.",
    "road" : "Lloryk road is quite long, and runs straight from east to west.",
    "haven" :"Haven is considered by most to be the capital city of"
             " Kailie. It is most famed for the insularity and"
             " xenophobia of its people.",
    "glimmerdin" :
      "Glimmerdin road is the road which leads to Glimmerdin,"
      " home to the dwarves.",
  ]);

  if (x == 15) {
    ne = SOUTHERN_COAST_VIRTUAL + "havenroad/-36,0";
    str += " The road turns to the northeast on to"
      " Haven road.";
    }
     if(x == 5 )
     {
          n = CRYSTAL_REACHES_AREAS + "camp/room/trail1";
          str += " To the north lies a path through the swamp.";
     }
  if (x < 15) {
    e = CRYSTAL_REACHES_VIRTUAL + "llorykroad/" + (x+1) + "," + y;
    }
  if (x == 0) {
    w = CRYSTAL_REACHES_TOWNS + "lloryk/room/outside_sgate";
    }
  if (x > 0) {
    w = CRYSTAL_REACHES_VIRTUAL + "llorykroad/" + (x-1) + "," + y;
    }
  if( n ) AddExit("north", n);
  if( ne ) AddExit("northeast", ne);
  if( s ) AddExit("south", s);
  if( e ) AddExit("east", e);
  if( w ) AddExit("west", w);

  SetLong(str);
  SetItems(items);
  SetInventory(inv);
  SetSmell( ([
    "default" : "The smell of the Ruined Sea wafts from the south.",
    ]) );
}
