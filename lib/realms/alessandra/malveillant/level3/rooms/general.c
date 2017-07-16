//  Portia  12-11-98
//  The general store version 2.0
//  Updated by Alessandra 2009


#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
 
  SetAmbientLight(20);
  SetClimate("indoors");
  SetShort("malveillant general store");
  SetLong(
     "This is the general store of Malveillant. It has been owned by Tom "
     "Rifalia and his family since the time of the GodsWar. Newly dusted "
     "shelves are neatly lined with the goods most desired by the citizens "
     "of Malveillant. Crisp red linen curtains drape in the sparkling clean "
     "windows of the shop, and a matching hand woven rug covers the tidy "
     "floor."
     );
  SetListen( ([
     "default" : "The dull chatter of shoppers fills the air.",
     ]) );
  SetSmell( ([
     "default" : "There is an overwhelming scent of leather and linens.",
     ]) );
  SetItems( ([
     ({"store", "shop", "room"}) : (:GetLong:),
     ({"shelf", "shelves"}) : 
     	 "Carved wooden shelves line the walls and are stocked with various "
     	 "goods.",
     ({"wall", "walls"}) : 
     	 "The walls are painted a bright yellow and are lined with wooden shelves.",
     ({"curtain", "curtains"}) :
     	 "These linen curtains look freshly pressed and are a bold red, "
     	 "They contrast nicely with the yellow walls.",
     ({"window", "windows"}) :
     	 "Like everything else in the store, these windows shine as though "
     	 "freshly washed. Cheerful curtains drape casually from the windows.",
     ({"rug"}) :
     	 "This exquisite hand woven rug covers the center of the floor. Several "
     	 "shades of red are woven to form different patterns in the rug.",
     ({"floor", "ground"}) :
     	 "The floor is kept very tidy and is covered mostly by a beautiful rug.",
     ({"goods"}) :
     	 "Almost anything imaginable can be purchased in Tom's shop. He stocks "
     	 "only the best quality goods.",
     ]) );
  SetItemAdjectives( ([
     "shelf" : ({"carved", "wood", "wooden", "stocked", "dusted"}),
     "wall" : ({"painted", "yellow", "lined"}),
     "curtain" : ({"linen", "red", "pressed", "crisp", "cheerful"}),
     "window" : ({"clean", "sparkling", "washed"}),
     "rug" : ({"woven", "exquisite", "beautiful", "red"}),
     "floor" : ({"tidy"}),
     "goods" : ({"desired", "quality"}),
     ]) );
  SetInventory( ([
     MAL_NPC3 + "tom" : 1,
     ]) );
  SetExits( ([
     "out" : MAL_ROOMS3 + "market1",
     ]) );

}

