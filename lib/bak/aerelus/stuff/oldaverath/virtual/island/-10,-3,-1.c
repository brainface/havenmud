#include <lib.h>
#include <domains.h>
#include "../undead.h"
inherit AVERATH_LIB;

varargs static void create(int x, int y, int z) {
  ::create(-10,-3,-1);
  SetShort("a tunnel into the island");
  SetClimate("underground");
  SetAmbientLight(5);
  SetLong(
     "The walls of the tunnel have been carved crudly out of the ground. Water "
     "drips down these walls, slowly forming a puddle on the bottom of the tunnel. "
     "The ground appears unstable, as the dirt has been made loose and muddy from "
     "all the water running upon it. The tunnel runs up back onto the shores of "
     "Averath, and leads down into a dark cavern. "
  );
  SetItems( ([
     ({ "tunnel","passage" }) : (: GetLong :),
     ({ "walls","water" }) : "Water slowly drips down these walls as the ground "
     "above slowly absorbs the seawater being rushed ashore. ",
     ({ "ground","mud","floor" }) : "The ground has become unstable from all the "
     "water being dripped into it, making it a muddy mess. ",
  ]) );
  SetItemAdjectives( ([
     "tunnel" : ({ "poor" }),
     "walls" : ({ "crude" }),
     "ground" : ({ "muddy" }),
  ]) );
  SetListen( ([
     "default" : "A deep echo can be heard from the rumbling of the ocean. ",
  ]) );
  SetSmell( ([
     "default" : "The air smells damp and salty. ",
  ]) );
  SetInventory( ([
  ]) );
  SetExits( ([
     "up" : AVERATH_ISLAND + "-10,-3,0",
     "down" : AVERATH_ISLAND + "-10,-3,-2",
  ]) );
  }
