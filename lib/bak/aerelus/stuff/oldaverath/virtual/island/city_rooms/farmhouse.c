// This is a farmhouse for a farmer leader NPC
// gehnna@havenmud 05/30/01

#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create(){
  room::create();

  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("a farm house");
  SetLong("This small room is quite cluttered. Farming tools are hanging "
     "all along the walls. Hanging from the ceiling are fresh cheeses, "
     "strands of garlic, and a large ham. A loaf of fresh bread "
     "and a bowl of homemade butter sit atop a roughly hewn table. "
     "Several hay bales are stacked along the walls and around "
     "the table for seating. One wall contains a bay window from "
     "which some fields are visible.  A wooden ladder leads up "
     "to a loft."),
  SetListen( ([
     "default" : "You hear the rustling of hay and creaking floorboards.",
  ]) );
  SetSmell( ([
     "default" : "It smells like fresh food and hay here.",
  ]) );
  SetItems( ([
     ({"tools"}) : "There are rakes, hoes, pitchforks, and a scythe hanging "
     "from the walls. They are in good condition but clearly used often.",
     ({"ceiling"}) : "There are cheeses, garlic, and a large ham hanging "
     "here.",
     ({"cheese","cheeses"}) : "They are covered with an airy cheesecloth.",
     ({"garlic"}) : "The strands of garlic are partially dried.",
     ({"ham"}) : "The juicy ham looks very tasty.",
     ({"bread","loaf"}) : "The edges of the loaf are a golden brown.",
     ({"butter","bowl"}) : "This reddish glass bowl is chipped in a few "
     "places and it contains a mound of freshly churned white butter.",
     ({"table"}) : "It is rough but sturdy.",
     ({"bales","hay"}) : "The bales of hay are scattered around the room "
     "for seating purposes. They are tied tightly together with twine.",
     ({"window"}) : "The large window covers almost an entire wall, providing "
      "sunlight during the day and a view of the fields.",
     ({"field","fields"}) : "The fields are filled with healthy growing "
      "crops.",
     ({"ladder"}) : "It is a handmade wooden ladder leading up to a loft.",
     ({"loft"}) : "The contents of the loft cannot be seen from here.",
  ]) );
  SetItemAdjectives( ([
     "tools" : ({"farming"}),
      "cheese" : ({"fresh"}),
     "garlic" : ({"strands of"}),
      "ham" : ({"large"}),
     "bread" : ({"loaf of","fresh"}),
     "butter" : ({"homemade"}),
     "table" : ({"roughly hewn"}),
     "bales" : ({"hay","several"}),
     "window" : ({"bay"}),
     "ladder" : ({"wooden"}),
  ]) );
  SetExits( ([
     "out" : AVERATH_ISLAND "0,5,0",
     "up" : AVERATH_CITY "farmloft",
  ]) );
  SetInventory( ([
  ]) );
}
