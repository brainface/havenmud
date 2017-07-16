// Virtual override for the forest maze quest
#include <lib.h>
#include <domains.h>
#include "../../planes.h"
inherit DIR_VIRT + "forest.c";
#include DIR_VIRT + "/maze/maze.h";

static void create() {
  string dir;
  int rx, ry;  
  
  rx = 20;
  ry = 20;
  
  forest::create(rx,ry);
  SetItems( ([
     "hedge" : "The towering hedge opens up to the south here, leading to "
     	  "what appears to be a dense hedge maze.",
   ]) );
  SetLong(GetLong() + " There is a towering hedge here which blocks passage "
    "to the " + dir);         
  SetProperty("lower plane",1);
  SetListen( ([
    "default" : "The faint sound of giggling can be heard to the south,",
  ]) );
  RemoveExit("south");
  AddExit("south", MAZE + "6,0");
 }
