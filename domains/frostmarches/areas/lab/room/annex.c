#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

static void create()
{
  ::create();
  SetShort("an annex to the laboratory");
  SetLong("In a completely haphazard fashion, piles of books, chemicals, "
          "and herbs lie scattered around this room.  This large closet has "
          "seemingly been turned into a storage area.  This room was "
          "clearly added as an afterthought as it is not quite finished. "
          "The brick floor has not yet been covered with floorboards, and "
          "the walls are bare of shelves. As a result, the floor is "
          "crowded with items placed one on top of the other. The laboratory "
          "itself opens to the west.");
  SetSmell( ([
    "default" :
      "The musky odor of things long left untouched pervades the room."
  ]) );
  SetListen( ([
    "default" :
      "The stirring of little critters can be heard."
  ]) );
  SetClimate("indoors");
  SetItems( ([
    ({"various items","items","item","chemicals","chemical","herbs","herb",
      "herb","clutter"}) :
      "Various items that Teras uses in her experiments lie scattered "
      "across the floor.",
    ({"annex to the laboratory","annex to the lab","annex",
      "laboratory","lab","room","storage area","area","large closet",
      "closet"}) :
      (: GetLong() :),
    ({"bare walls","bare wall","walls","wall"}) :
      "The bare walls are made of red brick.",
    ({"red bricks","red brick","ordinary bricks","ordinary brick,",
      "bricks","brick","crowded brick floor","brick floor","crowded floor",
      "floor"}) :
      "The red bricks that comprise the floor and walls are just ordinary "
      "bricks.",
    ({"piles of books","pile of books","piles","pile","books","book",
      "diagrams","diagram"}) :
      "The books seem to be written in a foreign tongue.  From the "
      "diagrams, it seems they elaborate upon some scientific procedure.",
    ({ "main laboratory", "main lab" }) :
      "The laboratory continues to the south.",
  ]) );
  SetAmbientLight(36);
  SetExits( ([
    "west" : L_ROOM "/south_lab",
  ]) );
  SetInventory( ([
    L_NPC "/roach" : random(2) + 1,
    L_OBJ "/tome" : 1,
  ]) );
}
