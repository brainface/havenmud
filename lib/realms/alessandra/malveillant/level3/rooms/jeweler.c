//  Jeweler for Marketplace  
//  Alessandra 2009

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetAmbientLight(20);
  SetClimate("indoors");
  SetShort("malveillant Jeweler");
  SetLong(
     "Display cases framed in glass line either side of this shop, filled "
     "with handsomely crafted jewelry. The floor and walls are covered in a "
     "rich, dark wood that seems flawless. Spotless windows are framed by "
     "beautiful gold curtains that hang down nearly to the floor. There is "
     "a small room to the south and an exit back out onto the market pathway."
     );
  SetListen( ([
     "default" : "Faint sounds of bartering filter in from the market.",
     ]) );
  SetSmell( ([
     "default" : "The air smells faintly of metal and polish.",
     ]) );
  SetItems( ([
     ({"shop", "store", "room"}) : (:GetLong:),
     ({"case", "display", "display case"}) :
     	 "Handcrafted from wood, these cases are framed in glass to protect "
     	 "the jewelry from dirty fingers.",
     ({"jewelry", "jewels"}) :
     	 "Nardus carries the finest jewelry in Malveillant, if a little "
     	 "expensive. They are displayed carefully within the wood and glass "
     	 "cases lining the walls.",
     ({"curtain", "curtains"}) :
     	 "The curtains are made from a gold velvet, probably just as expensive "
     	 "as the jewelry Nardus sells.",
     ({"window", "windows"}) :
     	 "The spotless windows are framed by beautiful gold curtains.",
     ({"floor", "ground"}) :
     	 "The floor is made of the same dark wood as the walls and is kept "
     	 "extremely well-polished.",
     ({"wall", "walls"}) :
     	 "The walls have been covered in a rich dark wood, the same as the "
     	 "floors. The wood is flawless and polished to a deep shine.",
     ({"glass"}) : 
     	 "The glass surrounding the cases is sparkling.",
     ]) );  
  SetItemAdjectives( ([
     "case" : ({"wood", "wooden", "handcrafted", "framed"}),
     "glass" : ({"sparkling"}),
     "curtain" : ({"gold", "velvet"}),
     "window" : ({"framed"}),
     "floor" : ({"well", "polished", "wood"}),
     "wall" :({"covered", "wood", "polished"}),
     ]) );
  SetInventory( ([
     MAL_NPC3 + "nardus" : 1,
     ]) );
  SetExits( ([
     "out" : MAL_ROOMS3 + "market4",
     "south" : MAL_ROOMS3 + "merch",
     ]) );



}

