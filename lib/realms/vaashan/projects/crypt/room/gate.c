
/*  gate.c
 *  The gate room to the desert crypt.
 *  Vaashan@Haven 9/14/09
 */
#include <lib.h>
#include "../crypt.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  //SetAmbientLight();
  SetClimate("arid");
  SetShort("within the outer wall");
  SetLong();
  SetSmell( ([
    "default" : "The desert air is remarkably clean and crisp.",
    ]) );
  SetListen();
  SetItems();
  SetItemAdjectives();
  SetEnters( ([
     "out" : CRYPT_ROOM + "entrance",
     "north" : CRYPT_ROOM + "fronthall"
     ]) );
}