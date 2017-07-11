/* A mountain path and tunnel to Tairi */
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create(int x, int y) {
  string n, s, e, w, ne, sw, nw, se;
  ::create(x, y);
  SetShort("along the Tairi Path");
  SetSmell( ([
    "default" : "The scents of the mountains waft lazily here."
    ]) );
  SetListen( ([
    "default" : "It is quiet with only the distant howl of the wind as "
                "noise.",
    ]) );
  if (x == -8) {
    SetLong(
      "The Tairi Path continues to the east and southwest from here, its "
      "cold and empty status reinforced with every footstep. No trees "
      "line the path, and anything that may have been of value to the "
      "town at one time seems to have been removed. Off to the west "
      "the peak of Mount Shatadru can be seen. A small crack in the ground "
      "seems to be large enough to enter."
      );
    SetItems( ([
      ({ "crack", "cave" }) : 
      	 "This crack appears to be some kind of cave.",
      ({ "path" }) : 
      	 (: GetLong :),
      ({ "shatadru", "mount", "peak" }) : 
      	 "The peak of Mount Shatadru is seen off in the west.",
      ({ "town", "tairi" }) :
      	 "The town of Tairi is east along the Tairi Path."
      ]) );
    SetItemAdjectives( ([
      "crack" : ({ "small" }),
      ]) );
    SetEnters( ([
      "crack" : TAIRI_AREAS "oni_cave/room/cave_1",
      ]) );
    sw = TAIRI_VIRTUAL "tairi_path/" + (x - 1) + "," + (y - 1);
    e = TAIRI_VIRTUAL "tairi_path/" + (x + 1) + "," + y;
  }
  if (x > -8) {
    SetLong(
      "The Tairi Path continues to the east and west from here, its "
      "cold and empty status reinforced with every footstep. No trees "
      "line the path, and anything that may have been of value to the "
      "town at one time seems to have been removed. Off to the west "
      "the peak of Mount Shatadru can be seen."
      );
    SetItems( ([
      ({ "path" }) : 
      	 (: GetLong :),
      ({ "shatadru", "mount", "peak" }) : 
      	 "The peak of Mount Shatadru is seen off in the west.",
      ({ "town", "tairi" }) :
      	 "The town of Tairi is east along the Tairi Path."
      ]) );
      
    w = TAIRI_VIRTUAL "tairi_path/" + (x - 1) + "," + y;
    e = TAIRI_VIRTUAL "tairi_path/" + (x + 1) + "," + y;
  }
  if (x == -16) {
    SetLong(
      "The Tairi Path continues to the northeast and west from here, its "
      "cold and empty status reinforced with every footstep. No trees "
      "line the path, and anything that may have been of value to the "
      "town at one time seems to have been removed. Off to the northwest "
      "the peak of Mount Shatadru can be seen."
      );
    SetItems( ([
      ({ "path" }) : 
      	 (: GetLong :),
      ({ "shatadru", "mount", "peak" }) : 
      	 "The peak of Mount Shatadru is seen off in the northwest.",
      ({ "town", "tairi" }) :
      	 "The town of Tairi is northeast along the Tairi Path."
      ]) );
    w = TAIRI_VIRTUAL "tairi_path/" + (x - 1) + "," + (y);
    ne = TAIRI_VIRTUAL "tairi_path/" + (x + 1) + "," + (y + 1);
  }
 
  if (x < -16) {
    SetLong(
      "The Tairi Path continues to the west and east from here, its "
      "cold and empty status reinforced with every footstep. No trees "
      "line the path, and anything that may have been of value to the "
      "town at one time seems to have been removed. Off to the north "
      "the peak of Mount Shatadru can be seen."
      );
    SetItems( ([
      ({ "path" }) : 
      	 (: GetLong :),
      ({ "shatadru", "mount", "peak" }) : 
      	 "The peak of Mount Shatadru is seen off in the north.",
      ({ "town", "tairi" }) :
      	 "The town of Tairi is east along the Tairi Path."
      ]) );
    w = TAIRI_VIRTUAL "tairi_path/" + (x - 1) + "," + y;
    e = TAIRI_VIRTUAL "tairi_path/" + (x + 1) + "," + y;
  }
  if (x > -16 && x < -8) {
    SetLong(
      "The Tairi Path continues to the southwest and northeast from here, its "
      "cold and empty status reinforced with every footstep. No trees "
      "line the path, and anything that may have been of value to the "
      "city at one time seems to have been removed. Off to the northwest "
      "the peak of Mount Shatadru can be seen."
      );
    SetItems( ([
      ({ "path" }) : 
      	 (: GetLong :),
      ({ "shatadru", "mount", "peak" }) : 
      	 "The peak of Mount Shatadru is seen off in the northwest.",
      ({ "town", "tairi" }) :
      	 "The town of Tairi is northeast along the Tairi Path."
      ]) );
    ne = TAIRI_VIRTUAL "tairi_path/" + (x + 1) + "," + (y + 1);
    sw = TAIRI_VIRTUAL "tairi_path/" + (x - 1) + "," + (y - 1);
  }
  if (x == 0 && y == 0) {
    SetLong(
      "Directly to the north, the Tairi Path "
      "enters the town of Tairi. The Tairi Path continues to the west, "
      "where it eventually curves southwest towards Mount Shatadru. The road "
      "is wind-swept and empty, devoid of vegetation. Far off to the north "
      "lies the coast of the ocean."
      );
    SetItems( ([
      ({ "path", "road" }) : 
      	 (: GetLong :),
      ({ "shatadru", "mount", "peak" }) : 
      	 "The peak of Mount Shatadru is seen off in the west.",
      ({ "town", "tairi" }) :
      	 "The town of Tairi can be seen north of here.",
      ({ "vegetation" }) :
      	 "The road is devoid of all vegetation.",
      ({ "ocean", "coast", "sea" }) :
      	 "The coast of Tairi collides with the Endless Sea, north of "
      	 "the town of Tairi.",
      ]) );
    n = TAIRI_TOWNS "tairi/room/path1";
    w = TAIRI_VIRTUAL "tairi_path/-1,0";
    e = 0;
  }
  if (x == -3 && y == 0) {
        s = TAIRI_AREAS "camp/room/entrance";
        SetLong("The Tairi Path continues to the east and west from here. To the south "
          "lies a cobblestone path leading into an encampment of some kind. Far to the "
          "west the spire of Mount Shatadru can be seen. The path itself is devoid "
          "of anything useful to the town, having been stripped of all wood and mined "
          "to near extinction.");
        SetItems( ([
          ({ "path", "tairi path" }) : 
      	     (: GetLong :),
      	  ({ "cobblestone path" }) :
      	  	 "Following the cobblestone path is an encampment.",
          ({ "shatadru", "mount", "peak" }) : 
      	     "The peak of Mount Shatadru is seen off in the west.",
          ({ "town", "tairi" }) :
      	     "The town of Tairi is east along the Tairi Path."
          ]) );
        }
  if (x == -20 && y == -8) {
    SetLong(
      "To the northwest lies the base of Mount Shatadru, its peak hidden among "
      "the clouds. A small path begins to wind up its surface, and the Tairi Path "
      "continues back to the east. The windswept road is devoid of vegetation "
      "here, and seems desolate and without any redeeming interesting value."
      );
    SetItems( ([
          ({ "path", "tairi path" }) : 
      	     (: GetLong :),
      	  ({ "small path" }) :
      	  	 "A small path starts from the base of Mount Shatadru.",
          ({ "shatadru", "mount", "peak", "cloud", "clouds" }) : 
      	     "The peak of Mount Shatadru is hidden by the clouds.",
          ({ "town", "tairi" }) :
      	     "The town of Tairi is east along the Tairi Path.",
      	  ({ "vegetation" }) :
      	     "The road is devoid of all vegetation.",
          ]) );
    e = TAIRI_VIRTUAL "tairi_path/-19,-8";
    w = 0;
    sw = TAIRI_AREAS "mountain/room/mtn1";
  }
  if (x == -8 && y == 0) {
    AddLong(" To the north lies a small Cherry Blossom Park.");
  	
    n = TAIRI_AREAS "copse/room/room1";
  }
  if (x == -9 && y == -1) {
     AddLong(" A small path going south leads to a shrine.");
    s = TAIRI_AREAS "shrine/room/room1";
  }

  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);
  if (ne) AddExit("northeast", ne);
  if (nw) AddExit("northwest", nw);
  if (sw) AddExit("southwest", sw);
  if (se) AddExit("southeast", se);
}
