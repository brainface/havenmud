#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(0,1,-1);
  SetLong("Dark and foreboding, the tunnel leads off to the south, and west. "
     "The curved walls of the tunnel are wet and slimy, and the ceiling "
     "is almost tall enough for an average human to stand upright. The "
     "thick, smelly muck covering the floor indicates that the tunnel is "
     "part of a sewer system. The tunnel is kept barely navigable by the "
     "small torches set into the walls.");
  SetItems( ([
     ({"wall","walls"}) : "These curved walls are made of a dark stone "
       "that is covered in some sort of slime from the flow of refuse.",
     ({"muck","floor"}) : "A small stream of muck passes through the center "
       "of the tunnel, flowing with the twists and turns of the sewers.",
     ({"torch","torches"}) : "These small wood torches give enough light "
       "to get a small glimpse of the next passage.",
     ]) );
  RemoveExit("east");
  RemoveExit("north");
   SetAmbientLight(26);
  SetInventory( ([
     AVERATH_NPC "whore" : 1,
   ]) );
}
