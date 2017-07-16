#include <lib.h>
#include <domains.h>
#include "vimp.h"
#define ROME  PENINSULA_TOWNS "sanctum/room/vi01"
inherit LIB_ROOM;

int Y, X;

void Setup();

static void create(int x, int y) {
  string n, s, e, w, ne, se, sw, nw;
  ::create();
  SetShort("along the Via Imperialis");
  Y = y; X = x;
  n = s = e = w = ne = se = sw = nw = 0;
  if (Y > 6 && Y <= 20) {
  	if (x >= 0) {
  		if ( Y != 20) ne = VIMP_VIRTUAL + (X + 1) + "," + (Y + 1);
  		sw = VIMP_VIRTUAL + (X - 1) + "," + (Y - 1);
  	}
  	if (x <= 0) {
  		if (Y != 20) nw = VIMP_VIRTUAL + (X - 1) + "," + (Y + 1);
  		se = VIMP_VIRTUAL + (X + 1) + "," + (Y - 1);
  	}
  }
  if (Y == 6) {
  	  ne = VIMP_VIRTUAL + (X + 1) + "," + (Y + 1);
  	  nw = VIMP_VIRTUAL + (X - 1) + "," + (Y + 1);
  	  s = VIMP_VIRTUAL + (X) + "," + (Y - 1);
  	}
  if (Y < 6) {
  	s = VIMP_VIRTUAL + (X) + "," + (Y - 1);
  	n = VIMP_VIRTUAL + (X) + "," + (Y + 1);
  
  }
  if (Y == 0 && X == 0) {
  	s = ROME;
  }
  if (Y == 20 && X == -14) {
    nw = SOUTHERN_COAST_VIRTUAL "havenroad/0,0";
  }
  if (n) { AddExit("north", n); }
  if (s) { AddExit("south", s); }
  if (e) { AddExit("east", e); }
  if (w) { AddExit("west", w); }
  if (ne) { AddExit("northeast", ne); }
  if (nw) { AddExit("northwest", nw); }
  if (sw) { AddExit("southwest", sw); }
  if (se) { AddExit("southeast", se); }
  Setup();
}

void Setup() {
	SetLong("The Via Imperialis continues to the " +
	         conjunction(GetExits(), "and") + " from here. "
	        "The smoothly paved road is a marvel of modern engineering. Various trees "
	        "line the path, making the road a scenic, if somewhat dangerous, path. "
	        "Scattered along the road are various former campsites and occasional "
	        "signs of previous human passage.");
	SetItems( ([
	  ({ "tree", "trees" }) : "The trees here are few and far between, but tend to be "
	                          "oaks and other hardwoods.",
    ]) );	                          
	SetClimate("temperate");
	SetSmell( ([
	  "default" : "The roadway smells of empty plains and plentiful trees.",
	  ]) );
	SetListen( ([
	  "default" : "The path is quiet except for the noise of birds and animals.",
	  ]) );
}
