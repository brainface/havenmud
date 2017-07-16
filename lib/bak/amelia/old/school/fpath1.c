/* Angel:  Paradigm
   Date:  8/29/97   */

#include <lib.h>
#include "/realms/paradigm/path.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetDayLight(50);
  SetNightLight(20);
  SetClimate("outdoors");
  SetShort("a forest path");
  SetDayLong("Light flickers through the canopy above onto the "
             "shadowed path before you.  The trees, brush and weeds "
             "obscure your vision in nearly all directions. ");
  SetNightLong("You are barely able to see the path in front of you,"
               " but can definitely feel the foliage brush your body"
               ".");
  SetItems( ([ ({"shadowed path","dirt path","forest path","path","dirt"}) :
                     (: GetLong :),
         ({"flickering lights","flickering light","lights","light"}) :
                     "The lights streaming from the canopy are "
                     "mesmerizing as they play on the path before "
                     "you.   ",
         ({"canopy","trees","tree"}): "The canopy of leaves from "
                     "the trees keeps most light from reaching the "
                     "path.  ",
         ({"weed","bush","weeds","brush","bushes","foliage"}) : "The "
                     "foliage of the area tries to overtake the "
                     "path.  ",
          ({"canopy leaves","leaf","branch","branches","leaves"}) : "They "
                     "are too high and they are hard to see without proper "
                     "lighting.  "]) );
  SetExits( ([ "north" : TWR + "fpath2.c",
               "south" : "/realms/paradigm/workroom.c"]) );
  SetListen( ([ "default" : "A strange chittering sound seems to come"
                            " from the branches high above you.  "]) );
  SetObviousExits("north,south");
  SetInventory( (["/std/npc/r/robin.c" : random(3)]));
}
/* Approved by Balishae on Tue Sep 16 10:01:53 1997. */
