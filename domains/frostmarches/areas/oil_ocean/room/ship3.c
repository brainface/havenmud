//Illura@haven
//ship3
//Nov 2010
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../oil.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("inside the captain's cabin");
  SetLong(
    "This opulent cabin housed the ship's primary officer "
    "but is now all but ruined. The bed frame is warped, and "
    "the silk curtains stained and rent. Rugs on the floor "
    "are wet through with bilge, and the picture frames are "
    "cracked and yellowed. A few log books are strewn "
    "across the table in a disarray that speaks to despair."
  );
  SetExits( ([
    "east" : OIL_ROOM "/ship2"
  ]) );
  SetItems( ([
    ({"cabin"}) : "You are inside the cabin of a ship.",
    ({"bed", "frame", "curtains"}) : 
      "The bed was once piled high with velvet blankets and hung "
      "with silken curtains. No one would want to sleep in it now.",
    ({"rug", "rugs","rags"}) : 
      "You can't even make out the pattern in these filthy rags.",
    ({"bilge","water"}) : 
      "The amount of bilge seeping into the floor is really making "
      "you uncomfortable.",
    ({"pictures", "picture","frame", "frames"}) : 
      "All the pictures are yellowed with time and the glass in the "
      "frames is cracked and smashed. The pictures themselves are of "
      "smiling faces, of bygone days, and better places than this one.",
    ({"book", "books","journal","journals"}) : 
      "Every captain keeps journals, this one no less than any other. "
      "The volumes are all old and crusty.",
    ({"table"}) : 
      "The table is the only thing on this boat that seems sturdy."
  ]) );
  SetItemAdjectives( ([
    "cabin" : ({"opulent", "ruined"}),
    "curtains" : ({"silk"}),
    "book" : ({"log"})
  ]) );
  SetInventory( ([
    OIL_NPC + "captain" : 1,
  ]) );
  SetListen( ([
    "default" : "The ship creaks and groans.",
  ]) );
  SetSmell( ([
    "default" : "The stench is pretty powerful.",
  ]) );
}
