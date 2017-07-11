
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy wagon");
     SetDomain("Crystal Reaches");
     SetLong("This wagon is small but comfortable.  "
                 "A hammock is set up in one corner.  In "
                 "the other corner is a small table with a "
                 "single chair.  One large chest rests "
                 "along the wall directly across from the "
                 "window.  A half-completed wooden lyre "
                 "lies on the workbench next to the chest.");
     SetItems( ([
             ("wagon") : (: GetLong :),
             ({ "floor"}) :
                   "The floor is made of a light brown wood "
                   "and is clean except for a few wood "
                   "shavings. ",
             ("hammock"):
                 "The hammock is big enough for a large "
                 "man to sleep in.",
            ({ "chest"}):
                "The single chest is left unfinished.  The "
                "top is open revealing several tools used in "
                "instrument making. ", 
          ({"tools", "tool"}) :
                "The tools are used to make "
                "instruments. ",               
          ({"walls", "wall"}) : 
                "The walls are whitewashed. ",
          ({"table"}) : "The table is simple yet sturdy.  "
              "It is painted a soft brown.  ",
          ({"chairs", "chair"}) : 
              "The chairs are simple and sturdy.  "
               "They are painted to match the table. ",
        ("lyre"): "The lyre isn't finished yet.  The strings "
               "and bridge are missing.  The wood hasn't "
               "been stained yet.  It looks like it will be a "
               "beautiful instrument once finished.  ",
        ("workbench") : "The workbench is long and "
               "sturdy.  It is cleaned off allowing for plenty"
               " of work space. "
             ]) );
    SetItemAdjectives( ([
                    "lyre" : ({"wooden"}),
                    "tools" : ({"several"}) 
                    ]) );
    SetSmell( ([
                "default" : "The air is filled with the scent "
                                  "of fresh wood shavings. "
    
              ]) );
    SetListen( ([
                "default" :  "Beautiful music fills "
                                  "the wagon. ",
                "music" : "The music is so heart "
                               "wrenching, it could "
                               "bring tears to the most "
                               "careless listener. "
                                   ]) );
    SetInventory( ([ C_NPC + "man3" : 1]) );
    SetClimate("indoors");
    SetExits( ([
                       "out" : C_ROOM + "camp2"
                  ]) );
}
