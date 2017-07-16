
/*  room1.c
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
     "east" : CRYPT_ROOM + "fronthall",
     "north" : CRYPT_ROOM + "room2",
     "southwest" : CRYPT_ROOM + "room13"
     ]) );
}