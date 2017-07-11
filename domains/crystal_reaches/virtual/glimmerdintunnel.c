#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

void SetupExits(int, int);

static void create(int x, int y) {
  ::create();
  SetShort("in a tunnel under the Crystal Reaches");
  SetClimate("underground");
  SetWarmth(30);
  SetLong(
    "This winding tunnel leads from Glimmerdin to the Underland. "
    "The smooth rock and impacted earth on the walls of the tunnel "
    "lends credence to the idea that this tunnel may have been "
    "well travelled in days long past."
    );
  SetSmell("A vaguely musty smell hangs in the stale air.");
  SetListen("The tunnel is quiet from lack of use.");
  SetupExits(x, y);
}

void SetupExits(int x, int y) {
  string n, s, w, e, ne, sw, nw, se;
  
  if (x == y) {
    ne = CRYSTAL_REACHES_VIRTUAL "glimmerdintunnel/" + (x + 1) + "," + (y + 1);
    sw = CRYSTAL_REACHES_VIRTUAL "glimmerdintunnel/" + (x - 1) + "," + (y - 1);
    }
  if (y == 10) {
    e = CRYSTAL_REACHES_VIRTUAL "glimmerdintunnel/" + (x + 1) + "," + (y);
    w = CRYSTAL_REACHES_VIRTUAL "glimmerdintunnel/" + (x - 1) + "," + (y);
    }
  if (x == 10 && y == 10) {
    w = 0;
    ne = 0;
    }
  if (x == 0 && y == 0) {
    w = VALLEY_AREAS "mount_trog/room/tunnel11";
    sw = 0;
    }
  if (x == 30 && y == 10) {
    e = CRYSTAL_REACHES_TOWNS "glimmerdin/room/holding";
    }
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east",  e);
  if (w) AddExit("west",  w);
  if (ne) AddExit("northeast", ne);
  if (nw) AddExit("northwest", nw);
  if (se) AddExit("southeast", se);
  if (sw) AddExit("southwest", sw);
}