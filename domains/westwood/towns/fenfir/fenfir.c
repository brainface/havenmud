#include <lib.h>
#include <domains.h>
#include "fenfir.h"
inherit LIB_ROOM;

static private int XPosition, YPosition;
void eventNoise();
int chance1 = (50 + random(75));

static void create(int x, int y) 
{
  string *tmp = ({ });
  string n, e, s, w;

  SetNoReplace(1);
  room::create();
  XPosition = x;
  YPosition = y;

 /*  Setting Exits */

  if (x > -8)
  {
    w = "fenfir/" + (x-1) + "," + y;
  }
  if (x < 0) 
  {
    e = "fenfir/" + (x+1) + "," + y;
  }
  if (y < 4) 
  {
    n = "fenfir/" + x + "," + (y+1);
  }
  if (y > 0) 
  {
    s = "fenfir/" + x + "," + (y-1);
  }

  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (w) AddExit("west", w);
  if (e) AddExit("east", e);
  if (n && e) AddExit("northeast", "fenfir/" + (x+1) + "," + (y+1));
  if (n && w) AddExit("northwest", "fenfir/" + (x-1) + "," + (y+1));
  if (s && w) AddExit("southwest", "fenfir/" + (x-1) + "," + (y-1));
  if (s && e) AddExit("southeast", "fenfir/" + (x+1) + "," + (y-1));

  if ( (x == 0) && (y == 0) )
  {
    RemoveExit("north");
    RemoveExit("east");
    AddExit("south", T_ROOM + "link");
  }
  if ( (x == -1) && (y == 1) )
  {
    RemoveExit("north");
    RemoveExit("east");
    RemoveExit("northeast");
  }
  if ( (x == -2) && (y == 2) )
  {
    RemoveExit("north");
    RemoveExit("east");
    RemoveExit("northeast");
  }
  if ( (x == -3) && (y == 1) )
  {
    AddExit("up", T_ROOM + "misctree");
  }
  if ( (x == -3) && (y == 3) )
  {
    RemoveExit("north");
    RemoveExit("east");
    RemoveExit("northeast");
  }
  if ( (x == -4) && (y == 4) )
  {
    RemoveExit("east");
  }
  if ( (x == -4) && (y == 0) )
  {
    RemoveExit("west");
  }
  if ( (x == -4) && (y == 2) )
  {
    AddExit("up", T_ROOM + "foodtree");
  }
  if ( (x == -5) && (y == 1) )
  {
    RemoveExit("south");
    RemoveExit("west");
    RemoveExit("southwest");
  }
  if ( (x == -5) && (y == 3) )
  {
    AddExit("up",T_ROOM + "drinktree");
  }
  if ( (x == -6) && (y == 2) )
  {
    RemoveExit("south");
    RemoveExit("west");
    RemoveExit("southwest");
  }
  if ( (x == -7) && (y == 3) )
  {
    RemoveExit("south");
    RemoveExit("west");
    RemoveExit("southwest");
  }
  if ( (x == -8) && (y == 4) )
  {
    RemoveExit("south");
  }
  if ( (x == -4) && (y == 1) )
  {
    RemoveExit("southwest");
  }
  if ( (x == -5) && (y == 2) )
  {
    RemoveExit("southwest");
  }
  if ( (x == -6) && (y == 3) )
  {
    RemoveExit("southwest");
  }
  if ( (x == -7) && (y == 4) )
  {
    RemoveExit("southwest");
  }
  if ( (x == -4) && (y == 3) )
  {
    RemoveExit("northwest");
  }
  if ( (x == -3) && (y == 2) )
  {
    RemoveExit("northwest");
  }
  if ( (x == -2) && (y == 1) )
  {
    RemoveExit("northwest");
  }
  if ( (x == -1) && (y == 0) )
  {
    RemoveExit("northwest");
  }

  SetTown("Fenfir Forest");
  SetShort("a small forest");
  SetLong("This is a small forest of fenfir trees.  It is nestled "
    "in a crack in the spine of the mounains, similiar to a small "
    "valley.  The towering mountains surround the forest on all "
    "sides making it impossible to leave here except through a "
    "small pass in the southeastern corner of the forest.");
  SetItems( ([
    ({"tree","trees","fenfir"}) : "The fenfir trees are common to "
      "the regions of the WestWood.  They are tall and have broad "
      "branches and leaves.  The bark on the trunk of the trees is "
      "a pale white color while the leaves are a light shade of "
      "green.  Most of the branches for the trees are too far up "
      "to grasp and climb.",
    ({"forest"}) : (: GetLong() :),
    ({"mountain","mountains","spine"}) : "The mountains in this "
      "region are known as the Frostmarches.  They stand tall as "
      "the silent guardians to this hidden region.",
    ({"valley"}) : "This valley lies nestled in a crack in the "
      "spine of the mountains.  It isnt large enough to support "
      "too life.",
    ({"pass"}) : "To the southeast of the forest lies a gap in "
      "mountains, allowing some access to this hidden forest.",
    ({"up"}) : "The only thing up is the tree tops.",
  ]) );
  SetItemAdjectives( ([
    "forest" : ({"small"}),
    "tree" : ({"fenfir"}),
    "valley" : ({"small"}),
    "mountain" : ({"towering"}),
    "pass" : ({"small"}),
  ]) );    
  SetClimate("sub-artic");
  SetSmell( ([
    "default" : "The light airy scent of fenfir fills the air.",
  ]) );
  SetListen( ([
    "default" : "The forest is silent.",
  ]) );
  
  foreach(string ex in GetExits()) 
  {
   tmp += ({ ex });
  }
  tmp = implode(tmp, ", ");
  SetObviousExits(tmp);
  call_out( (: eventNoise :), chance1 );
}

void eventNoise() 
{
  int chance2 = (50 + random(75));
  int rand = random(3);

  if (rand == 0)
  {
    message("other_action","A soft fluttering of wings can be "
      "heard overhead.",this_object());
    call_out( (: eventNoise :), chance2);
    return;
  }
  else if (rand == 1)
  {
    message("other_action","A soft glittery powder sprinkles "
      "down from overhead.",this_object());
    call_out( (: eventNoise :), chance2);
    return;
  }
  else
  {
    message("other_action","A soft breeze passes by your ear."
      "",this_object());
    call_out( (: eventNoise :), chance2);
    return;
  }
}
