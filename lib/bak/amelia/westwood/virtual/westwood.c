#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;
#include "westwood.h"

static private int XPosition, YPosition;
static void SetupRoom(int, int);
int type = random(3);
int variety = random(150);
int Light();
int PreExit();
int XLine = random(30);
int YLine = random(30);

static void create(int x, int y) {
  string n, e, s, w;

  SetNoReplace(1);
  room::create();
  XPosition = x;
  YPosition = y;

/*  Setting Exits */

  if (x < 29) {
    e = "westwood/" + (x+1) + "," + y;
  }
  if (x > 0) {
    w = "westwood/" + (x-1) + "," + y;
  }
  if (y < 29) {
    n = "westwood/" + x + "," + (y+1);
  }
  if (y > 0) {
    s = "westwood/" + x + "," + (y-1);
  }

  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (w) AddExit("west", w);
  if (e) AddExit("east", e);
  if (n && e) AddExit("northeast", "westwood/" + (x+1) + "," + (y+1));
  if (n && w) AddExit("northwest", "westwood/" + (x-1) + "," + (y+1));
  if (s && w) AddExit("southwest", "westwood/" + (x-1) + "," + (y-1));
  if (s && e) AddExit("southeast", "westwood/" + (x+1) + "," + (y-1));

  if ( (x == 30) && (y == 0) ) RemoveExit("northeast");
/* SetShort and Obvious */

  SetDomain("WestWood");
  SetClimate("temperate");
  SetGoMessage("The forest is too dense to proceed in that direction.");
  SetupRoom(x, y);
  }

void SetupRoom(int x, int y) {
  string long;
  string short;
  mapping items = ([ ]);

  if (type == 0) {
    long = "This is an area inside the WestWood.  Surrounding the area "
      "are lots of trees.  It appears that it would be very easy "
      "to get lost here as there are not paths that stand out.  The "
      "canopy of the forest covers the sky partially.";
    short = "an area inside the WestWood";
    items = ([
      ({"area","westwood"}) : (:GetLong:),
      ({"tree","trees","forest"}) : "The trees stand very tall in the forest.  "
        "Most of them appear to be evergreens and have the pine "
        "needles associated with those types of trees.",
      ({"path"}) : "There are not any noticeable paths along here.",
      ({"sky","canopy"}) : (:Light:)
    ]);
    SetSmell( ([
      "default" : "The woods smell of pine needles and the outdoors.",
    ]) );
    SetListen( ([
      "default" : "The forest is oddly quiet here.",
    ]) );
  }
  else if(type == 1) {
    long = "This is an area inside the WestWood.  It appears to be a "
      "small clearing amidst the gigantic forest.  There are multiple "
      "entries back into the forest from here.  Overhead, one can get "
      "a glimpse of the sky.";
    short = "a clearing inside the WestWood";
    items = ([
      ({"area","westwood","opening"}) : (:GetLong:),
      ({"forest"}) : "The trees stand very tall in the forest.  "
        "Most of them appear to be evergreens and have the pine "
        "needles associated with those types of trees.",
      ({"entry","entries"}) : "All along the perimeter of the clearing "
        "are entries back into the forest.",
    ]);
    SetSmell( ([
      "default" : "The smell of smoke from a campfire persists here.",
    ]) );
    SetListen( ([
      "default" : "The forest is oddly quiet here.",
    ]) );
  }
  else if(type == 2) {
    long = "This is an area inside the WestWood.  Mixed amidst the trees "
      "are lots of small scrub bushes.  They make moving around difficult "
      "but it is still possible to find a way around.  The "
      "canopy of the forest covers the sky partially.";
    short = "an area inside the WestWood";
 items = ([
    ({ "cloud", "clouds" }) : "These clouds are wispy hints of a southern "
                              "sky that seem infinately out of reach.",
    ]);
    items = ([
      ({"area","westwood"}) : (:GetLong:),
      ({"tree","trees","forest"}) : "The trees stand very tall in the forest.  "
        "Most of them appear to be evergreens and have the pine "
        "needles associated with those types of trees.",
      ({"bush","bushes"}) : "Scattered all along the floor of the forest "
        "are small scrub bushes that make moving around difficult.  "
        "It is still possible to move around here.",
      ({"sky","canopy"}) : (:Light:)
    ]);
    SetSmell( ([
      "default" : "The smell of smoke from a campfire persists here.",
    ]) );
    SetListen( ([
      "default" : "Birds chirp and sing their little song off in the distance.",
    ]) );
   }
  if (variety == 0) {
    long += "  The ground is blackened here from an old camp fire.";
   }
  else if(variety == 25) {
    SetInventory( ([ 
      W_NPC + "muezzin" : 1,
    ]) );
   }
  else if(variety == 50) {
    SetInventory( ([
      W_NPC + "halfling" : 1,
    ]) );
   }
  else if(variety == 75) {
    SetInventory( ([
      W_NPC + "gelfling" : 1,
    ]) );
   }
  else if(variety == 1) {
    SetInventory( ([ 
      W_NPC + "bear" : random(2)+1,
    ]) );
   }
   else if(variety == 11) {
     SetInventory( ([
                      W_NPC + "knight" : 1,
                 ]) );
   }
  else if(variety == 2) {
    SetInventory( ([ 
      W_NPC + "blue_jay" : 1,
    ]) );
   }
  else if(variety == 3) {
    SetInventory( ([ 
      W_NPC + "butterfly" : 1,
    ]) );
   }
  else if(variety == 4) {
    SetInventory( ([ 
      W_NPC + "deer" : random(3)+1,
    ]) );
   }
  else if(variety == 5) {
    SetInventory( ([ 
      W_NPC + "deermouse" : random(4)+1,
    ]) );
   }
  else if(variety == 6) {
    SetInventory( ([ 
      W_NPC + "rabbit" : random(2)+1,
    ]) );
   }
  else if(variety == 7) {
    SetInventory( ([ 
      W_NPC + "raven" : 1,
    ]) );
   }
  else if(variety == 8) {
    SetInventory( ([ 
      W_NPC + "robin" : 1,
    ]) );
   }
  else if(variety == 9) {
    SetInventory( ([ 
      W_NPC + "tarantula" : 1,
    ]) );
   }
  else if(variety == 10) {
    SetInventory( ([ 
      W_NPC + "wolf" : random(5)+1,
    ]) );
   }
  else if(variety == 99) {
    SetInventory( ([ 
      "/domains/westwood/virtual/npc/protect" : 1,
    ]) );
   }
  if ((x == 0) && (y == 0) ) {
    long += "  There appears to be a small dirt path leading northeast "
      "from here while Soleil Road leads southwest.";
    short = "a break in the WestWood";
    AddExit("southwest","/domains/westwood/virtual/soleilroad/20,20",(:PreExit:));
    SetObviousExits("north, northeast, east, southwest");
    items = ([
      ({ "path" }) : "There is a small dirt path from here leading northeast "
        "while Soleil road leads southwest.",
    ]);
   }
  if ((x == 0) && (y == 6) ) {
    long += "  The forest grows dense to the northeast.";
    RemoveExit("northeast");
    SetObviousExits("north, south, east, southeast");
   }
  if ((x == 0) && (y == 7) ) {
    long += "  The forest grows dense to the east.";
    RemoveExit("east");
    SetObviousExits("north, south, northeast, southeast");
   }
  if ((x == 0) && (y == 8) ) {
    long += "  The forest grows dense to the southeast.";
    RemoveExit("southeast");
    SetObviousExits("north, south, east, northeast");
   }
  if ((x == 0) && (y == 11) ) {
    long += "  The forest grows dense to the north.";
    RemoveExit("north");
    SetObviousExits("south, east, northeast, southeast");
   }
  if ((x == 0) && (y == 18) ) {
    long += "  The forest grows dense to the south.";
    RemoveExit("south");
    SetObviousExits("north, east, northeast, southeast");
   }
  if ((x == 0) && (y == 29) ) {
    long += "  The forest opens into a mountain trail to the northwest and "
      "a path seems to lead southeast.  A pass opens into the mountains "
      "and leads to the west, trailing up into the mountains.";
    short = "a break in the WestWood";
    AddExit("northwest","/domains/westwood/areas/hiker/room/trailhead");
    AddExit("west","/domains/westwood/virtual/transit/97,6");
    items = ([
      ({ "path","trail" }) : "A small dirt path is worn into the ground "
        "here leading southeast while a small trail enters into the mountains "
        "mountains to the northwest and west.",
    ]);
   }
  if ((x == 1) && (y == 1) ) {
    long += "  There appears to be a path leading north and southwest "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and southwest.",
    ]);
   }
  if ((x == 1) && (y == 2) ) {
    long += "  There appears to be a path leading north and south "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and south.",
    ]);
   }
  if ((x == 1) && (y == 3) ) {
    long += "  There appears to be a path leading east and south "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "east and south.",
    ]);
   }
  if ((x == 1) && (y == 5) ) {
    long += "  The forest grows dense to the northeast.";
    RemoveExit("northeast");
    SetObviousExits("north, south, east, west, northwest, "
      "southeast, southwest");
   }
  if ((x == 1) && (y == 6) ) {
    long += "  The forest grows dense to the north, east, and northeast.";
    RemoveExit("northeast");
    RemoveExit("north");
    RemoveExit("east");
    SetObviousExits("south, west, northwest, southeast, southwest");
   }
  if ((x == 1) && (y == 8) ) {
    long += "  The forest grows dense to the south, east, and southeast.";
    RemoveExit("southeast");
    RemoveExit("south");
    RemoveExit("east");
    SetObviousExits("north, west, northwest, northeast, southwest");
   }
  if ((x == 1) && (y == 9) ) {
    long += "  The forest grows dense to the southeast.";
    RemoveExit("southeast");
    SetObviousExits("north, south, east, west, northwest, northeast, "
      "southwest");
   }
  if ((x == 1) && (y == 11) ) {
    long += "  The forest grows dense to the northwest.";
    RemoveExit("northwest");
    SetObviousExits("north, south, east, west, northeast, "
      "southwest, southeast");
   }
  if ((x == 1) && (y == 12) ) {
    long += "  The forest grows dense to the west, north, and northwest.";
    RemoveExit("northwest");
    RemoveExit("north");
    RemoveExit("west");
    SetObviousExits("south, east, northeast, southwest, southeast");
   }
  if ((x == 1) && (y == 17) ) {
    long += "  The forest grows dense to the south, west, southwest, "
      "and southeast.";
    RemoveExit("southwest");
    RemoveExit("southeast");
    RemoveExit("south");
    RemoveExit("west");
    SetObviousExits("north, east, northeast, northwest");
   }
  if ((x == 1) && (y == 18) ) {
    long += "  The forest grows dense to the southwest.";
    RemoveExit("southwest");
    SetObviousExits("north, south, east, west, northeast, northwest, "
      "southeast");
   }
  if ((x == 1) && (y == 28) ) {
    long += "  There appears to be a path leading northwest and southeast "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "northwest and southeast.",
    ]);
   }
  if ((x == 2) && (y == 3) ) {
    long += "  There appears to be a path leading west and east "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and east.",
    ]);
   }
  if ((x == 2) && (y == 4) ) {
    long += "  The forest grows dense to the northeast.";
    RemoveExit("northeast");
    SetObviousExits("north, south, east, west, northwest, "
      "southeast, southwest");
   }
  if ((x == 2) && (y == 5) ) {
    long += "  The forest grows dense to the north, east, and northeast.";
    RemoveExit("northeast");
    RemoveExit("north");
    RemoveExit("east");
    SetObviousExits("south, west, northwest, southeast, southwest");
   }
  if ((x == 2) && (y == 9) ) {
    long += "  The forest grows dense to the south, east, and southeast.";
    RemoveExit("southeast");
    RemoveExit("south");
    RemoveExit("east");
    SetObviousExits("north, west, northwest, northeast, southwest");
   }
  if ((x == 2) && (y == 10) ) {
    long += "  The forest grows dense to the southeast.";
    RemoveExit("southeast");
    SetObviousExits("north, south, east, west, northwest, northeast, "
      "southwest");
   }
  if ((x == 2) && (y == 12) ) {
    long += "  The forest grows dense to the northwest.";
    RemoveExit("northwest");
    SetObviousExits("north, south, east, west, northeast, "
      "southwest, southeast");
   }
  if ((x == 2) && (y == 13) ) {
    long += "  The forest grows dense to the north, west, and northwest.";
    RemoveExit("northwest");
    RemoveExit("north");
    RemoveExit("west");
    SetObviousExits("south, east, northeast, southwest, southeast");
   }
  if ((x == 2) && (y == 17) ) {
    long += "  The forest grows dense to the south and southwest.";
    RemoveExit("southwest");
    RemoveExit("south");
    SetObviousExits("north, east, west, northeast, northwest, southeast");
   }
  if ((x == 2) && (y == 27) ) {
    long += "  There appears to be a path leading northwest and east "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "northwest and east.",
    ]);
   }
  if ((x == 3) && (y == 3) ) {
    long += "  There appears to be a path leading east and west "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "east and west.",
    ]);
   }
  if ((x == 3) && (y == 4) ) {
    long += "  The forest grows dense to the north and northeast.";
    RemoveExit("northeast");
    RemoveExit("north");
    SetObviousExits("south, east, west, northwest, southwest, southeast");
   }
  if ((x == 3) && (y == 10) ) {
    long += "  The forest grows dense to the south, east, and southeast.";
    RemoveExit("southeast");
    RemoveExit("south");
    RemoveExit("east");
    SetObviousExits("north, west, northwest, northeast, southwest");
   }
  if ((x == 3) && (y == 11) ) {
    long += "  The forest grows dense to the southeast.";
    RemoveExit("southeast");
    SetObviousExits("north, south, east, west, northwest, northeast, "
      "southwest");
   }
  if ((x == 3) && (y == 13) ) {
    long += "  The forest grows dense to the northwest.";
    RemoveExit("northwest");
    SetObviousExits("north, south, east, west, northeast, "
      "southwest, southeast");
   }
  if ((x == 3) && (y == 14) ) {
    long += "  The forest grows dense to the north, west, northeast and "
      "northwest.";
    RemoveExit("northwest");
    RemoveExit("northeast");
    RemoveExit("north");
    RemoveExit("west");
    SetObviousExits("south, east, southwest, southeast");
   }
  if ((x == 3) && (y == 16) ) {
    long += "  The forest grows dense to the south, west, and southwest.";
    RemoveExit("southwest");
    RemoveExit("south");
    RemoveExit("west");
    SetObviousExits("north, east, northeast, northwest, southeast");
   }
  if ((x == 3) && (y == 17) ) {
    long += "  The forest grows dense to the southwest.";
    RemoveExit("southwest");
    SetObviousExits("north, south, east, west, northeast, northwest, "
      "southeast");
   }
  if ((x == 3) && (y == 27) ) {
    long += "  There appears to be a path leading west and east "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and east.",
    ]);
   }
  if ((x == 4) && (y == 3) ) {
    long += "  There appears to be a path leading west and east "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and east.",
    ]);
   }
  if ((x == 4) && (y == 4) ) {
    long += "  The forest grows dense to the north, northwest, and northeast.";
    RemoveExit("north");
    RemoveExit("northeast");
    RemoveExit("northwest");
    SetObviousExits("south, east, west, southwest, southeast");
   }
  if ((x == 4) && (y == 11) ) {
    long += "  The forest grows dense to the south.";
    RemoveExit("south");
    SetObviousExits("north, east, west, northwest, northeast, "
      "southwest, southeast");
   }
  if ((x == 4) && (y == 14) ) {
    long += "  The forest grows dense to the northwest and north.";
    RemoveExit("northwest");
    RemoveExit("north");
    SetObviousExits("south, east, west, northeast, southwest, southeast");
   }
  if ((x == 4) && (y == 16) ) {
    long += "  The forest grows dense to the south and southwest.";
    RemoveExit("southwest");
    RemoveExit("south");
    SetObviousExits("north, east, west, northeast, southeast");
   }
  if ((x == 4) && (y == 27) ) {
    long += "  There appears to be a path leading west and east "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and east.",
    ]);
   }
  if ((x == 5) && (y == 3) ) {
    long += "  There appears to be a path leading west and east "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and east.",
    ]);
   }
  if ((x == 5) && (y == 4) ) {
    long += "  The forest grows dense to the north and northwest.";
    RemoveExit("north");
    RemoveExit("northwest");
    SetObviousExits("south, east, west, northeast, southwest, southeast");
   }
  if ((x == 5) && (y == 10) ) {
    long += "  The forest grows dense to the south, southwest, and west.";
    RemoveExit("southwest");
    RemoveExit("south");
    RemoveExit("west");
    SetObviousExits("north, east, northwest, northeast, southeast");
   }
  if ((x == 5) && (y == 11) ) {
    long += "  The forest grows dense to the southwest.";
    RemoveExit("southwest");
    SetObviousExits("north, south, east, west, northwest, northeast, "
      "southeast");
   }
  if ((x == 5) && (y == 15) ) {
    long += "  The forest opens west into a valley leading into the depths "
      "of the mountains.  There appears to be a path leading east.";
    AddExit("northwest","/domains/westwood/areas/dunedain_forest/room/forest1");
    short = "a break in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "east and a valley opens up to to the west.",
    ]);
    }
  if ((x == 5) && (y == 27) ) {
    long += "  There appears to be a path leading west and southeast "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and southeast.",
    ]);
   }
  if ((x == 6) && (y == 3) ) {
    long += "  There appears to be a path leading west and east "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and east.",
    ]);
   }
  if ((x == 6) && (y == 4) ) {
    long += "  The forest grows dense to the northwest.";
    RemoveExit("northwest");
    SetObviousExits("north, south, east, west, northeast, "
      "southwest, southeast");
   }
  if ((x == 6) && (y == 5) ) {
    long += "  The forest grows dense to the west, northwest, and north.";
    RemoveExit("west");
    RemoveExit("north");
    RemoveExit("northwest");
    SetObviousExits("south, east, northeast, southwest, southeast");
   }
  if ((x == 6) && (y == 9) ) {
    long += "  The forest grows dense to the south, southwest, and west.";
    RemoveExit("southwest");
    RemoveExit("south");
    RemoveExit("west");
    SetObviousExits("north, east, northwest, northeast, southeast");
   }
  if ((x == 6) && (y == 10) ) {
    long += "  The forest grows dense to the southwest.";
    RemoveExit("southwest");
    SetObviousExits("north, south, east, west, northwest, northeast, "
      "southeast");
   }
  if ((x == 6) && (y == 15) ) {
    long += "  There appears to be a path leading west and east "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and east.",
    ]);
   }
  if ((x == 6) && (y == 26) ) {
    long += "  There appears to be a path leading northwest and southeast "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "northwest and southeast.",
    ]);
   }
  if ((x == 7) && (y == 3) ) {
    long += "  There appears to be a path leading west and east "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and east.",
    ]);
   }
  if ((x == 7) && (y == 5) ) {
    long += "  The forest grows dense to the north, northwest, and northeast.";
    RemoveExit("north");
    RemoveExit("northwest");
    RemoveExit("northeast");
    SetObviousExits("south, east, west, southwest, southeast");
   }
  if ((x == 7) && (y == 7) ) {
    long += "  The forest grows dense to the northwest, west, southwest, "
      "south, and southeast.";
    RemoveExit("northwest");
    RemoveExit("west");
    RemoveExit("southwest");
    RemoveExit("south");
    RemoveExit("southeast");
    SetObviousExits("north, east, northeast");
   }
  if ((x == 7) && (y == 15) ) {
    long += "  There appears to be a path leading west and southeast "
      "from here.";
    short = "a path in the WestWood";
   }
  if ((x == 7) && (y == 24) ) {
    long += "  There appears to be a path leading north and east "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and east.",
    ]);
   }
  if ((x == 7) && (y == 25) ) {
    long += "  There appears to be a path leading northwest and south "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "northwest and south.",
    ]);
   }
  if ((x == 8) && (y == 3) ) {
    long += "  There appears to be a path leading west and east "
      "from here.";
    short = "a path in the WestWood";
   }
  if ((x == 8) && (y == 5) ) {
    long += "  The forest grows dense to the north and northwest.";
    RemoveExit("north");
    RemoveExit("northwest");
    SetObviousExits("south, east, west, northeast, southwest, southeast");
   }
  if ((x == 8) && (y == 7) ) {
    long += "  The forest grows dense to the south and southwest.";
    RemoveExit("south");
    RemoveExit("southwest");
    SetObviousExits("north, east, west, northwest, northeast, southeast");
   }
  if ((x == 8) && (y == 14) ) {
    long += "  There appears to be a path leading northwest and "
      "southeast from here.";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "northwest and southeast.",
    ]);
   }
  if ((x == 8) && (y == 24) ) {
    long += "  There appears to be a path leading west and east "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and east.",
    ]);
   }
  if ((x == 9) && (y == 3) ) {
    long += "  There appears to be a path leading west and north "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and north.",
    ]);
   }
  if ((x == 9) && (y == 4) ) {
    long += "  There appears to be a path leading north and south "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and south.",
    ]);
   }
  if ((x == 9) && (y == 5) ) {
    long += "  There appears to be a path leading north and south "
      "from here.  The forest grows dense to the northwest.";
    RemoveExit("northwest");
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and south.",
    ]);
   }
  if ((x == 9) && (y == 6) ) {
    long += "  There appears to be a path leading north and south "
      "from here and a log seems to have fallen to the west, "
      "blocking a small path.";
    AddExit("west","/domains/westwood/areas/goblin_camp/room/camp_road_01");
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and south.",
      ({ "log" }) : "A rotten log blocks a path to the west.  It appears that "
        "one could still go that way.",
    ]);
   }
  if ((x == 9) && (y == 7) ) {
    long += "  There appears to be a path leading north and south "
      "from here.  The forest grows dense to the southwest.";
    RemoveExit("southwest");
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and south.",
    ]);
   }
  if ((x == 9) && (y == 8) ) {
    long += "  There appears to be a path leading northeast and south "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "northeast and south.",
    ]);
   }
  if ((x == 9) && (y == 12) ) {
    long += "  There appears to be a path leading north and southeast "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and southeast.",
    ]);
   }
  if ((x == 9) && (y == 13) ) {
    long += "  There appears to be a path leading northwest and south "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "northwest and south.",
    ]);
   }
  if ((x == 9) && (y == 24) ) {
    long += "  There appears to be a path leading west and east "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and east.",
    ]);
   }
  if ((x == 10) && (y == 9) ) {
    long += "  There appears to be a path leading northeast, "
      "and southwest from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "northeast and northwest.",
    ]);
   }
  if ((x == 10) && (y == 11) ) {
    long += "  There appears to be a path leading northwest and "
      "southeast from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "northwest and southeast.",
    ]);
   }
  if ((x == 10) && (y == 24) ) {
    long += "  There appears to be a path leading west and east "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and east.",
    ]);
   }
  if ((x == 10) && (y == 25) ) {
    long += "  The forest grows dense to the northeast.";
    RemoveExit("northeast");
    SetObviousExits("north, south, east, west, northwest, "
      "southeast, southwest");
   }
  if ((x == 10) && (y == 26) ) {
    long += "  The forest grows dense to the northeast and east.";
    RemoveExit("northeast");
    RemoveExit("east");
    SetObviousExits("north, south, west, northwest, southeast, southwest");
   }
  if ((x == 10) && (y == 27) ) {
    long += "  The forest grows dense to the east and southeast.";
    RemoveExit("east");
    RemoveExit("southeast");
    SetObviousExits("north, south, west, northwest, northeast, southwest");
   }
  if ((x == 10) && (y == 28) ) {
    long += "  The forest grows dense to the southeast.";
    RemoveExit("southeast");
    SetObviousExits("north, south, east, west, northwest, northeast, "
      "southwest");
   }
  if ((x == 11) && (y == 10) ) {
    long += "  There appears to be a path leading east, southwest, "
      "and northwest from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "east and southwest.",
    ]);
   }
  if ((x == 11) && (y == 21) ) {
    long += "  There appears to be a path leading north and southeast "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and southeast.",
    ]);
   }
  if ((x == 11) && (y == 22) ) {
    long += "  There appears to be a path leading north and south "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and south.",
    ]);
   }
  if ((x == 11) && (y == 23) ) {
    long += "  There appears to be a path leading north and south "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and south.",
    ]);
   }
  if ((x == 11) && (y == 24) ) {
    long += "  There appears to be a path leading west and south "
      "from here.  To the northeast lies a monastery.";
    short = "a path in the WestWood";
    AddExit("northeast","/domains/westwood/areas/monastery/room/ent");
   }
  if ((x == 11) && (y == 25) ) {
    long += "  The forest grows dense to the north, east, and northeast.";
    RemoveExit("northeast");
    RemoveExit("north");
    RemoveExit("east");
    SetObviousExits("south, west, northwest, southeast, southwest");
   }
  if ((x == 11) && (y == 28) ) {
    long += "  The forest grows dense to the south and southeast.";
    RemoveExit("southeast");
    RemoveExit("south");
    SetObviousExits("north, east, west, northwest, northeast, southwest");
   }
  if ((x == 12) && (y == 10) ) {
    long += "  There appears to be a path leading east and west "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "east and west.",
    ]);
   }
  if ((x == 12) && (y == 20) ) {
    long += "  There appears to be a path leading northwest and southeast "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "northwest and southeast.",
    ]);
   }
  if ((x == 12) && (y == 24) ) {
    long += "  The forest grows dense to the north.";
    RemoveExit("north");
    SetObviousExits("south, east, west, northwest, northeast, "
      "southeast, southwest");
   }
  if ((x == 12) && (y == 28) ) {
    long += "  The forest grows dense to the south, southeast, and southwest.";
    RemoveExit("south");
    RemoveExit("southeast");
    RemoveExit("southwest");
    SetObviousExits("north, east, west, northwest, northeast");
   }
  if ((x == 13) && (y == 8) ) {
    long += "  There appears to be a path leading north and east "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and east.",
    ]);
   }
  if ((x == 13) && (y == 9) ) {
    long += "  There appears to be a path leading north and south "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and south.",
    ]);
   }
  if ((x == 13) && (y == 10) ) {
    long += "  There appears to be a path leading west and south "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and south.",
    ]);
   }
  if ((x == 13) && (y == 19) ) {
    long += "  There appears to be a path leading northwest and east "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "northwest and east.",
    ]);
   }
  if ((x == 13) && (y == 24) ) {
    long += "  The forest grows dense to the northwest.";
    RemoveExit("northwest");
    SetObviousExits("north, south, east, west, northeast, "
      "southeast, southwest");
   }
  if ((x == 13) && (y == 25) ) {
    long += "  The forest grows dense to the northwest, north, and west.";
    RemoveExit("northwest");
    RemoveExit("north");
    RemoveExit("west");
    SetObviousExits("south, east, northeast, southeast, southwest");
   }
  if ((x == 13) && (y == 28) ) {
    long += "  The forest grows dense to the southwest, south, southeast, "
      "and east.";
    RemoveExit("southwest");
    RemoveExit("south");
    RemoveExit("southeast");
    RemoveExit("east");
    SetObviousExits("north, west, northwest, northeast");
   }
  if ((x == 13) && (y == 29) ) {
    long += "  The forest grows dense to the southeast.";
    RemoveExit("southeast");
    SetObviousExits("south, east, west, southwest");
   }
  if ((x == 14) && (y == 8) ) {
        long += "  There appears to be a path leading east and west "
                "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "east and west.",
    ]);
   }
  if ((x == 14) && (y == 17) ) {
    long += "  The hospital sits to the northeast.";
    RemoveExit("northeast");
    SetObviousExits("north, south, west, east, northwest, southwest, southeast");
    items = ([
      ({ "hospital" }) : "The Eclat Hospital lies to the northeast.  It is a "
        "small building and houses the sick and those here to help them.  It "
        "painted in a light green colour and blends into the forest a little.",
    ]);
   }
  if ((x == 14) && (y == 18) ) {
    long += "  The hospital sits to the east.";
    RemoveExit("east");
    SetObviousExits("north, south, west, northeast, northwest, southwest, southeast");
    items = ([
      ({ "hospital" }) : "The Eclat Hospital lies to the east.  It is a "
        "small building and houses the sick and those here to help them.  It "
        "painted in a light green colour and blends into the forest a little.",

    ]);
   }
  if ((x == 14) && (y == 19) ) {
    long += "  There appears to be a path leading west and east "
      "from here.  The Eclat Hospital sits to the southeast.";
    RemoveExit("southeast");
    SetObviousExits("north, south, west, east, northeast, northwest, southwest");
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and east.",
      ({ "hospital" }) : "The Eclat Hospital lies to the southeast.  It is a "
        "small building and houses the sick and those here to help them.  It "
        "painted in a light green colour and blends into the forest a little.",

    ]);
   }
  if ((x == 14) && (y == 25) ) {
    long += "  The forest grows dense to the northwest.";
    RemoveExit("northwest");
    SetObviousExits("north, south, east, west, northeast, "
      "southeast, southwest");
   }
  if ((x == 14) && (y == 26) ) {
    long += "  The forest grows dense to the west and northwest.";
    RemoveExit("northwest");
    RemoveExit("west");
    SetObviousExits("north, south, east, northeast, southeast, southwest");
   }
  if ((x == 14) && (y == 27) ) {
    long += "  The forest grows dense to the west, northwest, north, and "
      "northeast.";
    RemoveExit("northwest");
    RemoveExit("west");
    RemoveExit("north");
    RemoveExit("northeast");
    SetObviousExits("south, east, southeast, southwest");
   }
  if ((x == 14) && (y == 29) ) {
    long += "  The forest grows dense to the south, southeast, and east.";
    RemoveExit("south");
    RemoveExit("southeast");
    RemoveExit("east");
    SetObviousExits("west, southwest");
   }
  if ((x == 15) && (y == 8) ) {
    long += "  There appears to be a path leading east and west "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "east and west.",
    ]);
   }
  if ((x == 15) && (y == 15) ) {
    long += "  The hospital sits to the northeast.";
    RemoveExit("northeast");
    SetObviousExits("north, south, west, east, northwest, "
      "southwest, southeast");
    items = ([
      ({ "hospital" }) : "The Eclat Hospital lies to the northeast.  It is a "
        "small building and houses the sick and those here to help them.  It "
        "painted in a light green colour and blends into the forest a little.",
    ]);
   }
  if ((x == 15) && (y == 16) ) {
    long += "  The hospital sits to the northeast and east.";
    RemoveExit("northeast");
    RemoveExit("east");
    SetObviousExits("north, south, west, northwest, southwest, southeast");
    items = ([
      ({ "hospital" }) : "The Eclat Hospital lies to the northeast and east.  "
        "It is a small building and houses the sick and those here to help them.  "
        "  It painted in a light green colour and blends into the forest a little.",
    ]);
   }
  if ((x == 15) && (y == 17) ) {
    long += "  The hospital sits to the north, east, southeast and northeast.";
    RemoveExit("northeast");
    RemoveExit("north");
    RemoveExit("east");
    RemoveExit("southeast");
    SetObviousExits("south, west, northwest, southwest");
    items = ([
      ({ "hospital" }) : "The Eclat Hospital lies to the north, east, southeast, "
        "and northeast.  It is a small building and houses the sick and those "
        "here to help them.  It painted in a light green colour and blends into "
        "the forest a little.",
    ]);
   }
  if ((x == 15) && (y == 19) ) {
    long += "  There appears to be a path leading west and east "
      "from here.  The Eclat Hospital sits to the south, and southeast.";
    RemoveExit("southeast");
    RemoveExit("south");
    SetObviousExits("north, west, east, northeast, northwest, southwest");
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and east.",
      ({ "hospital" }) : "The Eclat Hospital lies to the south and southeast.  "
        "It is a small building and houses the sick and those here to help them."
        "  It painted in a light green colour and blends into the forest a little.",
    ]);
   }
  if ((x == 15) && (y == 27) ) {
    long += "  The forest grows dense to the northwest, north, and northeast.";
    RemoveExit("northwest");
    RemoveExit("north");
    RemoveExit("northeast");
    SetObviousExits("south, east, west, southeast, southwest");
   }
  if ((x == 16) && (y == 8) ) {
    long += "  There appears to be a path leading east and west "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "east and west.",
    ]);
   }
  if ((x == 16) && (y == 12) ) {
    long += "  The forest slopes uphill to the northeast.";
    RemoveExit("northeast");
    SetObviousExits("north, south, east, west, southeast, southwest");
   }
  if ((x == 16) && (y == 13) ) {
    long += "  The forest slopes uphill to the northeast and east.";
    RemoveExit("northeast");
    RemoveExit("east");
    SetObviousExits("north, south, west, southeast, southwest");
   }
  if ((x == 16) && (y == 14) ) {
    long += "  The forest slopes uphill to the east and southeast.";
    RemoveExit("east");
    RemoveExit("southeast");
    SetObviousExits("north, south, west, northeast, southwest");
   }
  if ((x == 16) && (y == 15) ) {
    long += "  The forest slopes uphill to the southeast and the Soleil "
      "Hospital lies to the north and northeast.";
    RemoveExit("southeast");
    RemoveExit("north");
    RemoveExit("northeast");
    SetObviousExits("south, east, west, southwest");
    items = ([
      ({ "hospital" }) : "The Eclat Hospital lies to the north and northeast.  "
        "It is a small building and houses the sick and those here to help them."
        "  It painted in a light green colour and blends into the forest a little.",
    ]);
   }
  if ((x == 16) && (y == 19) ) {
    long += "  There appears to be a path leading west and east "
      "from here.  The Eclat Hospital sits to the south, southeast,  "
      "and southwest.";
    RemoveExit("southwest");
    RemoveExit("southeast");
    RemoveExit("south");
    SetObviousExits("north, west, east, northeast, northwest");
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and east.",
      ({ "hospital" }) : "The Eclat Hospital lies to the south and southeast.  "
        "It is a small building and houses the sick and those here to help them."
        "  It painted in a light green colour and blends into the forest a little.",
    ]);
   }
  if ((x == 16) && (y == 27) ) {
    long += "  The forest grows dense to the northwest and north.";
    RemoveExit("northwest");
    RemoveExit("north");
    SetObviousExits("south, east, west, northeast, southeast, southwest");
   }
  if ((x == 17) && (y == 8) ) {
    long += "  There appears to be a path leading east and west "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "east and west.",
    ]);
   }
  if ((x == 17) && (y == 12) ) {
        long += "  The forest slopes uphill to the north.";
        RemoveExit("north");
        SetObviousExits("south, east, west, northeast, southeast, southwest");
   }
  if ((x == 17) && (y == 15) ) {
    long += "  The forest slopes uphill to the east, south, and southeast.  "
      "The hospital sits to the north and northwest.";
    RemoveExit("east");
    RemoveExit("south");
    RemoveExit("southeast");
    RemoveExit("north");
    RemoveExit("northwest");
    SetObviousExits("west, northeast, southwest");
    items = ([
      ({ "hospital" }) : "The Eclat Hospital lies to the east, south, and "
        "southeast.  It is a small building and houses the sick and those here "
        "to help them.  It painted in a light green colour and blends into "
        "the forest a little.",
    ]);
   }
  if ((x == 17) && (y == 16) ) {
    long += "  The forest slopes uphill to the southeast.";
    RemoveExit("southeast");
    SetObviousExits("north, south, east, west, northeast, "
      "southwest");
   }
  if ((x == 17) && (y == 19) ) {
    long += "  There appears to be a path leading west and southeast "
      "from here.  The Eclat Hospital sits to the south and southwest.";
    RemoveExit("southwest");

    RemoveExit("south");
    SetObviousExits("north, west, east, northeast, northwest, southeast");
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and southeast.",
      ({ "hospital" }) : "The Eclat Hospital lies to the south and southwest.  "
        "It is a small building and houses the sick and those here to help them."
        "  It painted in a light green colour and blends into the forest a little.",
    ]);
   }
  if ((x == 17) && (y == 27) ) {
    long += "  The forest grows dense to the northwest.";
    RemoveExit("northwest");
    SetObviousExits("north, south, east, west, northeast, "
      "southeast, southwest");
   }
  if ((x == 17) && (y == 28) ) {
    long += "  The forest grows dense to the northwest and west.";
    RemoveExit("northwest");
    RemoveExit("west");
    SetObviousExits("north, south, east, northeast, southeast, southwest");
   }
  if ((x == 17) && (y == 29) ) {
    long += "  The forest grows dense to the west and southwest.";
    RemoveExit("west");
    RemoveExit("southwest");
    SetObviousExits("south, east, southeast");
   }
  if ((x == 18) && (y == 8) ) {
    long += "  There appears to be a path leading north and west "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and west.",
    ]);
   }
  if ((x == 18) && (y == 9) ) {
    long += "  There appears to be a path leading north and south "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and south.",

    ]);
   }
  if ((x == 18) && (y == 10) ) {
    long += "  There appears to be a path leading north and south "
      "from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and south.",
    ]);
   }
  if ((x == 18) && (y == 11) ) {
    long += "  There appears to be a path leading north and south from here.";
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and south.",
    ]);
   }
  if ((x == 18) && (y == 12) ) {
    long += "  The forest slopes uphill to the northwest and northeast.  "
      "There appears to be a path leading south and east from here.";
    RemoveExit("northwest");
    RemoveExit("northeast");
    SetObviousExits("north, south, east, west, southeast, southwest");
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "south and east.",
    ]);
   }
  if ((x == 18) && (y == 13) ) {
    long += "  The forest slopes uphill to the north, northwest, east, "
      "and west.";
    RemoveExit("northwest");
    RemoveExit("north");
    RemoveExit("east");
    RemoveExit("west");
    SetObviousExits("south, northeast, southeast, southwest");
   }
  if ((x == 18) && (y == 15) ) {
    long += "  The forest slopes uphill to the southwest and south.  A "
      "path seems to end here, leading southeast only.  It also appears "
      "that there is a way up into the trees.";
    AddExit("up","/domains/westwood/towns/soleil/room/gate");
    RemoveExit("southwest");
    RemoveExit("south");
    RemoveExit("north");
    RemoveExit("northeast");
    RemoveExit("northwest");
    RemoveExit("west");
    RemoveExit("east");
    SetObviousExits("southeast");
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "southeast and a small ladder is nailed to the tree leading up.",
    ]);
   }
  if ((x == 18) && (y == 16) ) {
    long += "  The forest slopes uphill to the south while the "
      "hospital sits to the west, north, and northwest.";
    RemoveExit("south");
    RemoveExit("north");  
    RemoveExit("west");  
    RemoveExit("northwest");  
    SetObviousExits("east, northeast, southeast, southwest");
    items = ([
      ({ "hospital" }) : "The Eclat Hospital lies to the west, north, and "
        "northwest.  It is a small building and houses the sick and those here "
        "to help them.  It painted in a light green colour and blends into the "
        "forest a little.",
    ]);
   }
  if ((x == 18) && (y == 18) ) {
    long += "  There appears to be a path leading northwest and southeast "

      "from here.  The hospital sits to the southwest, west, and south.";
    RemoveExit("southwest");
    RemoveExit("south");
    RemoveExit("west");
    SetObviousExits("north, east, northeast, northwest, southeast");
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "northwest and southeast.",
      ({ "hospital" }) : "The Eclat Hospital lies to the west, south, and "
        "southwest.  It is a small building and houses the sick and those here "
        "to help them.  It painted in a light green colour and blends into the "
        "forest a little.",
    ]);
   }
  if ((x == 18) && (y == 19) ) {
    long += "  The hospital sits to the southwest.";
    RemoveExit("southwest");
    SetObviousExits("north, south, west, east, northeast, northwest, southeast");
    items = ([
      ({ "hospital" }) : "The Eclat Hospital lies to the southwest.  It is a "
        "small building and houses the sick and those here to help them.  It "
        "painted in a light green colour and blends into the forest a little.",
    ]);
   }
  if ((x == 19) && (y == 12) ) {
    long += "  The forest slopes uphill to the north.  There appears "
      "to be a path leading northeast and west from here.";
    RemoveExit("north");
    SetObviousExits("south, east, west, northeast, northwest, "
      "southeast, southwest");
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "west and northeast.",
    ]);
   }
  if ((x == 19) && (y == 14) ) {
    long += "  The forest slopes uphill to the south and west.  There "
      "also appears to be a path leading north, northwest and southeast "
      "from here.";
    RemoveExit("south");
    RemoveExit("west");
    SetObviousExits("north, east, northeast, northwest, "
      "southeast, southwest");
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north, northwest, and southeast.",
    ]);
   }
  if ((x == 19) && (y == 15) ) {
    long += "  The forest slopes uphill to the west.  There appears to "
      "be a path leading north and south from here.";
    RemoveExit("west");
    SetObviousExits("north, south, east, northeast, "
      "southeast, southwest");
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and south.",
    ]);
   }
  if ((x == 19) && (y == 16) ) {
    long += "  The forest slopes uphill to the southwest.  To the "
      "northwest stands the Soleil hospital.  A path leads north and south "
      "from here.";
    RemoveExit("southwest");
    RemoveExit("northwest");
    SetObviousExits("north, south, east, west, northeast, southeast");
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "north and south.",
      ({ "hospital" }) : "The Eclat Hospital lies to the west.  It is a "
        "small building and houses the sick and those here to help them.  It "
        "painted in a light green colour and blends into the forest a little.",
    ]);
   }
  if ((x == 19) && (y == 17) ) {
    long += "  There appears to be a path leading northwest and south "
      "from here while the entrance to the hospital sit to the west.";
    AddExit("west","/domains/westwood/areas/hospital/room/start");
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "northwest and south.",
      ({ "hospital" }) : "The Eclat Hospital lies to the west.  It is a "
        "small building and houses the sick and those here to help them.  It "
        "painted in a light green colour and blends into the forest a little.",
    ]);
   }
  if ((x == 19) && (y == 18) ) {
    long += "  The hospital sits to the southwest.";
    RemoveExit("southwest");
    SetObviousExits("north, south, east, west, northeast, northwest, southeast");
    items = ([
      ({ "hospital" }) : "The Eclat Hospital lies to the southwest.  It is a "
        "small building and houses the sick and those here to help them.  It "
        "painted in a light green colour and blends into the forest a little.",
    ]);
   }
  if ((x == 20) && (y == 13) ) {
    long += "  The forest slopes uphill to the west.  There also appears "
      "to be a path leading southwest and northwest from here.";
    RemoveExit("west");
    SetObviousExits("north, south, east, northeast, northwest, "
      "southeast, southwest");
    short = "a path in the WestWood";
    items = ([
      ({ "path" }) : "A small dirt path is worn into the ground here leading "
        "southwest and northwest.",
    ]);
   }
  if ((x == 20) && (y == 12) ) {

    long += "  The forest slopes uphill to the northwest.";
    RemoveExit("northwest");
    SetObviousExits("north, south, east, west, northeast, "
      "southeast, southwest");
   }
  if ((x == 20) && (y == 14) ) {
    long += "  The forest slopes uphill to the southwest.";
    RemoveExit("southwest");
    SetObviousExits("north, south, east, west, northeast, "
      "southeast");
   }
/*  Rook's lair commented out  
  if ((x == 26) && (y == 25) ) {
    long += "  A small sinkhole is in the ground here..";
    SetInventory( ([ R_OBJ + "rope1" : 1 ]) );
   }
*/

  SetLong(long);
  SetShort(short);
  SetItems(items);
 }


int Light() {
  if(query_night()){
    message("look_sky_mesg","It is dark and the canopy blocking the "
      "is barely visible.",
    this_player());
    return 1;
   }
  else{
    message("look_sky_mesg","The canopy of trees blocks the most of "
      "sunlight from reaching the ground.",
    this_player());
    SetAmbientLight(15);
    return 0;
   }
}

int PreExit() {
   if(this_player()->GetProperty("noleave")) return 0;
   return 1;
}
