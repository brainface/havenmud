//   Alessandra 2009
//   Clothier for Marketplace  

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetAmbientLight(20);
  SetClimate("indoors");
  SetShort("an elegant boutique");
  SetLong(
     "Intricately carved wooden racks hold the finest in upscale clothing, "
     "for the citizens of Malveillant, who wouldn't be caught dead in last "
     "season's fashions. Sheer curtains line the windows, and are held open "
     "with tassled sashes. Large, comfortable chairs rest on either side of "
     "the back counter, covered in a deep burgundy velvet. A stairway on the "
     "left side of the boutique climbs upwards, towards the hat shop."
     );
  SetListen( ([
     "default" : "The rustling of clothing being tried on can be heard.",
     ]) );
  SetSmell( ([
     "default" : "The room smells slightly of roses.",
     ]) );
  SetItems( ([
     ({"shop", "store", "room", "boutique"}) : (:GetLong:),
     ({"rack", "racks"}) :
     	 "Handcrafted from wood, these clothing racks have been carved with "
     	 "intricate designs.",
     ({"clothing", "clothes"}) :
     	 "Mari Laviste only carries the latest in fashion. Her clothing is "
     	 "beautifully made, and on occasion you can purchase a one of a kind.",
     ({"curtain", "curtains"}) :
     	 "Rose colored, sheer curtains drape gracefully from the windows. Deep "
     	 "burgundy sashes have been used to tie them open.",
     ({"window", "windows"}) :
     	 "The windows are lined with beautiful sheer curtains.",
     ({"sash", "sashes"}) :
     	 "Deep burgundy in color, these tassled sashes tie the sheer curtains "
     	 "open.",
     ({"chair", "chairs"}) :
     	 "Large and comfortable looking, these chairs are covered in a dark "
     	 "burgundy velvet. They sit on either side of the counter, welcoming "
     	 "guests to sit and relax while shopping.",
     ({"counter"}) :
     	 "The counter is very tidy.",
     ({"stairs", "stairway"}) :
     	 "A narrow stairway that climbs up to the hat shop on the second floor "
     	 "of the boutique.",
     ({"floor", "ground"}) :
     	 "The floor is kept very tidy.",
     ({"wall", "walls"}) : 
     	 "The walls are painted a pale rose color.",
     ]) );  
  SetItemAdjectives( ([
     "rack" : ({"wood", "wooden", "carved", "handcrafted"}),
     "clothing" : ({"upscale", "beautiful"}),
     "curtain" : ({"sheer", "rose"}),
     "sash" : ({"tassled", "burgundy"}),
     "chair" : ({"large", "comfortable", "velvet", "burgundy"}),
     "counter" :({"tidy"}),
     "stairs" : ({"narrow"}),
     "floor" : ({"tidy"}),
     "wall" : ({"painted"}),
     ]) );
  SetInventory( ([
     MAL_NPC3 + "laviste" : 1,
     ]) );
  SetExits( ([
     "out" : MAL_ROOMS3 + "market3",
     "up" : MAL_ROOMS3 + "hat_shop",
     ]) );



}

