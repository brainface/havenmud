// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../soleil.h"

static void create() {
   room::create();
   SetTown("Soleil");
   SetClimate("indoors");
   
   SetAmbientLight(55);
   SetShort("warm bakery");
   SetLong("White curtains with blue stripes ruffle gently in a light "
           "breeze, and all the walls seem to glow slightly with a "
           "peaceful light.  A display case fills most of the room, "
           "and some storages boxes have been stuck beside it to one "
           "side.  A staircase leads down and out of the bakery, "
           "and it looks as if a board could be fit over the opening "
           "to the staircase to keep out bad weather.");
   SetItems( ([
                ({ "staircase opening","staircase","stairs","stair",
                   "opening","hole","small nitch","nitch" }) :
                   "Around the opening for the staircase is a "
                   "small nitch that a board could be places upon "
                   "to cover up the hole and make the floor safer and "
                   "the room more secure.  The staircase leads down "
                   "to the outside world.",
                ({ "storage boxes","storage box","boxes","box",
                   "labels","label" }) :
                   "Labels on the boxes mark them as being for "
                   "various things such as clothing, weapons, and "
                   "torches.",
                ({ "display case","case","display","bread","slices",
                   "slice","loaves","loaf","croissants","croissant",
                   "cinnamon rolls","cinnamon roll","roll","rolls",
                   "steaming mugs","steaming mug","mug","mugs","items",
                   "item","various items" }) :
                   "Various items fill the display case, all things "
                   "usually found in places like bakeries.  Some "
                   "bread, in slices and loaves, are set to one "
                   "side, and some croissants are nearby.  Cinnamon "
                   "rolls also have a spot.  Some steaming mugs "
                   "are also part of the display.",
                ({ "glowing walls","glowing wall","walls","wall" }) :
                   "A slight glow comes from the walls, adding light "
                   "and warmth to the room.",
                ({ "warm bakery","bakery","room" }) :
                   (: GetLong :),
                ({ "white curtains","white curtain","curtains","curtain",
                   "blue stripes","blue stripe","stripe","stripes" }) :
                   "The curtains shake slightly in the breeze, the "
                   "stripes coloring with their horizontal and vertical "
                   "paths.",
              ]) );
   SetExits( ([
                "down" : S_ROOM + "tree_c",
           ]) );
   SetObviousExits("down");
   SetInventory( ([
                    S_NPC + "baker_dulcae" : 1,
                    S_NPC + "gs_sorgan" : 1,
               ]) );
}

