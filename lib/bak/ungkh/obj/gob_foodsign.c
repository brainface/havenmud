/* EnjilCode */


#include "../ungkh.h"
#include <lib.h>

inherit LIB_ITEM;

static void create() {
  item::create();

  SetKeyName("sign");
  SetShort("a small sign");

  SetId( ({"sign"}) );
  SetAdjectives( ({ "small","wooden" }) );

  SetLong("The sign has been pegged into the ground.  It is made of wood.");

  SetMaterial( ({"wood"}) );
  SetPreventGet("You can't take the sign.");
  SetRead("Gorkshank's Food Store \nWest --> Gobskork's General Store.");

}
