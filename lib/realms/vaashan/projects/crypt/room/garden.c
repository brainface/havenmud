
/*  garden.c
 *  
 *  Vaashan@Haven 9/14/09
 */
#include <lib.h>
#include "../crypt.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("temperate");
  SetShort("a garden");
  SetLong();
  SetSmell();
  SetListen();
  SetItems();
  SetItemAdjectives();
  SetEnters( ([
     "south" : CRYPT_ROOM + "fronthall",
     "north" : CRYPT_ROOM + "shrine"
     ]) );
}