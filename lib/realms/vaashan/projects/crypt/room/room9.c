
/*  room9.c
 *  
 *  Vaashan@Haven 9/14/09
 */
#include <lib.h>
#include "../crypt.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetAmbientLight(30);
  SetClimate("indoors");
  SetShort("a hallway");
  SetLong();
  SetSmell();
  SetListen();
  SetItems();
  SetItemAdjectives();
  SetEnters( ([
     "north" : CRYPT_ROOM + "room8",
     "west" : CRYPT_ROOM + "fronthall",
     "southeast" : CRYPT_ROOM + "room10"
     ]) );
}