// Coded by Zeratul 
// 1-23-2000
// Ninja tower tower1
#include <lib.h>
#include "../ninja.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetAmbientLight(35);
  SetClimate("indoors");
  SetShort("inside a large tower");
  SetLong(
     "This tower is a large structure that stands over the land. Its size is "
     "larger than most buildings in the town, other than the Palace of Tai-so-ka. "
     "The outside is made up of brick, while the inside is made up of paper "
     "walls with decorative furnishings. Stairs lead to the upper parts of the "
     "tower, where ninjas stand guard over this place. "
  );
  SetItems( ([
     ({"walls","tower","place"}) : (:GetLong:),
     ({"furnishings","items"}) : "Several colorful paintings and other art "
    "sculptures sit about the place. They are on the walls as well as standing "
     "in corners as they liven the room up and make it feel more at home. ",
     ({"flowers"}) : "Several flower pots lay about the room which bloom here "
     "and liven the room up as they fill it with a pleasant scent. ",
  ]) );
  SetItemAdjectives( ([
     "place" : ({"big"}),
     "furnishings" : ({"decorative","colorful"}),
     "flowers" : ({"pleasant"}),
  ]) );
  SetSmell( ([
     "default" : "The scent of flowers is mixed with incense here.",
  ]) );
  SetListen( ([
     "default" : "The tower is peaceful and quiet.",
  ]) );
  SetInventory( ([
     N_NPC + "ninja1" : 2,
  ]) );
  SetExits( ([
     "up" : N_ROOM + "tower2",
     "out" : N_ROOM + "n_path9",
     "west" : N_ROOM "shop",
  ]) );
  }
