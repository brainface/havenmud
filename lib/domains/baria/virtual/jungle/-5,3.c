/*                                                                   */

#include <lib.h>

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("tropical");
  SetShort("outside a dark pyramid");
  SetLong("Here, a dark pyramid towers the sky. It is made of a dark "
          "stone that looks very old. Strange energies are felt "
          "close to it. There's a large hole that looks like the "
          "entrance, it is very dark inside."
         );
  SetItems( ([ 
               ({"pyramid"}) : "A huge pyramid stands here.",
               ({"hole"}) : "It looks like the entrance of the "
                            "pyramid.",
               ({"stone"}) : "A very old and dark type of stone."
           ]) );
  SetDomain("Baria");
  SetItemAdjectives( ([
                       "stone" : ({"old","dark","and"}),
                       "hole" : ({"dark","large"}),
                       "pyramid" : ({"dark","huge"})
                   ]) );
  SetExits( ([
              "east" : "/domains/baria/virtual/jungle/-4,3",
              "west" : "/domains/baria/virtual/jungle/-6,3",
              "north" : "/domains/baria/virtual/jungle/-5,4",
              "south" : "/domains/baria/virtual/jungle/-5,2",
              "southwest" : "/domains/baria/virtual/jungle/-6,2",
              "southeast" : "/domains/baria/virtual/jungle/-4,2",
              "northwest" : "/domains/baria/virtual/jungle/-6,4",
              "northeast" : "/domains/baria/virtual/jungle/-4,4"
           ]) );
  SetEnters( ([
               ({"hole","pyramid"}) : "/domains/baria/areas/pyramid/room/entrance"
           ]) );
}


