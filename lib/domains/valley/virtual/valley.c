#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

void SetupExits(int, int);
void SetupDescription(int, int);
void GenerateEncounters(int, int);
void AddSpecialStuff(int, int);

static void create(int x, int y) {
  ::create();
  SetDomain("Valley");
  SetShort("along a road in the Valley");
  SetClimate("temperate");
  SetupExits(x, y);
  SetupDescription(x, y);
  GenerateEncounters(x, y);
  AddSpecialStuff(x, y);
}

void SetupExits(int x, int y) {
  string n, s, e, w, ne, sw;
  if (y == 0) {
    w = VALLEY_VIRTUAL "valley/" + (x - 1) + "," + y;
    e = VALLEY_VIRTUAL "valley/" + (x + 1) + "," + y;
  }
  if (x == 0) {
    n = VALLEY_VIRTUAL "valley/" + (x) + "," + (y + 1);
    s = VALLEY_VIRTUAL "valley/" + (x) + "," + (y - 1);
  }
  if (x == -10) {
    n = VALLEY_VIRTUAL "valley/" + (x) + "," + (y + 1);
    s = VALLEY_VIRTUAL "valley/" + (x) + "," + (y - 1);
  }
  if (x == y) {
    ne = VALLEY_VIRTUAL "valley/" + (x + 1) + "," + (y + 1);
    sw = VALLEY_VIRTUAL "valley/" + (x - 1) + "," + (y - 1);
  }
  if (x == 0 && y == 0) {
    s  = 0;
    sw = 0;
  }
  if (x == 0 && y == 45) {
    n = VALLEY_TOWNS "jidoor/room/maingate";
  }
  if (x == -20 && y == 0) {
    w = BARIA_VIRTUAL "jungle/10,8";
  }
  if (x == 20 && y == 0) {
    e = CRYSTAL_REACHES_VIRTUAL "glimmerdinroad/0,15";
  }
  if (x == 10 && y == 10) {
    ne = 0;
    e  = VALLEY_TOWNS "underland/room/gate";
  }
  if( n ) AddExit("north", n);
  if( s ) AddExit("south", s);
  if( e ) AddExit("east", e);
  if( w ) AddExit("west", w);
  if (ne) AddExit("northeast", ne);
  if (sw) AddExit("southwest", sw);
}

void SetupDescription(int x, int y) {
  string lng;
  lng =
    ("The Valley continues to spread out to the " + conjunction(GetExits(), "and") + " from here. "
     "The peaceful grassland of the Valley is broken up by occasional patches of rocky dirt, owing "
     "largely to spills from the Crystal Reaches which comprise the northern and eastern edges of the Valley."
    );
  AddItem("dirt",    "These patches of rocky dirt are caused by spills from the mountains.", ({ "rocky", "patch", "patches" }) );
  AddItem("valley",  "The Valley is this area in its fullness.");
  AddItem("reaches", "The Crystal Reaches rim the Valley, protecting it from weather.", ({ "crystal" }) );
  SetLong(lng);
  SetSmell("A cool breeze drifts down from the mountaintops.");
  SetListen("Distant birds chirp their happiness.");
}

void GenerateEncounters(int x, int y) {

}

void AddSpecialStuff(int x, int y) {
  if (x == 0 && y == 35) {
    AddExit("west", VALLEY_AREAS "mntside/room/start");
    AddLong(" A path leads west through a pine forest into the foothills of the Crystal Reaches from here.");
  }
  if (x == 0 && y == 40) {
    AddExit("east", VALLEY_AREAS "canyon/room/cliff_edge");
    AddLong(" To the east, a cliff drops away from the road into a deep chasm running beneath the mountains.");
  }
  if (x == 0 && y == 9) {
    AddExit("east", VALLEY_AREAS "jidoor_forest/room/courtyard01");
    AddLong(" A small path leads east into a small forest by a keep.");
  }
  if (x == 8 && y == 8) {
    AddExit("west", VALLEY_AREAS "jidoor_forest/room/path01");
    AddLong(" A small path leads west into a small forest by a keep.");
  }
  if (x == -20 && y == 0) {
    AddExit("north", VALLEY_AREAS "castle/room/realent");
    AddLong(" Directly to the north lies a castle.");
  }
  if (x == -10 && y == 0) {
    AddExit("south", VALLEY_AREAS "mansion/rooms/clearing4");
    AddLong(" A large manor house lies to the south.");
  }
  if (x == 10 && y == 0) {
    AddExit("north", VALLEY_AREAS "prasanna/room/caventr");
    AddLong(" To the north, a large cave opening gapes its dark heart to the world.");
  }
  if (x == -10 && y == 15) {
    AddExit("north", VALLEY_AREAS "shining/room/forest0");
    AddLong(" To the north, a small paved path leads into a pleasant forest.");
  }
}

