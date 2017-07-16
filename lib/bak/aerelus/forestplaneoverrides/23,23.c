// Virtual override for the forest maze quest
#include <lib.h>
#include <domains.h>
#include "../../planes.h"
inherit DIR_VIRT + "forest.c";

static void create() {
  string dir;
  int rx, ry;
  
  dir = "north";
  rx = 23;
  ry = 23;
  
  forest::create(rx,ry);
  SetItems( ([
     "hedge" : "A towering hedge stretches upwards, blocking passage to "
     	  "the " + dir,                   
   ]) );
  SetLong(GetLong() + " There is a towering hedge here which blocks passage "
    "to the " + dir);         
  SetProperty("lower plane",1);
  RemoveExit(dir);
 }
