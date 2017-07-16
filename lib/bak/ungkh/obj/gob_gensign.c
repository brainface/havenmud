/* EnjilCode */


#include "../ungkh.h"
#include <lib.h>

inherit LIB_ITEM;

static void create() {
  item::create();

  SetKeyName("sign");
  SetShort("a hanging sign");

  SetId( ({"sign"}) );
  SetAdjectives( ({ "hanging" }) );

  SetLong("The sign hangs from the doorway.  It is made of wood.");

  SetMaterial( ({"wood"}) );
  SetPreventGet("A magical ward prevent you from getting the sign.");
  SetRead("Gobskork's General Store.");

}
