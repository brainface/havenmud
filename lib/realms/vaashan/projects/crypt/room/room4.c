
/*  room4.c
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
     "south" : CRYPT_ROOM + "room3",
     "east" : CRYPT_ROOM + "room5",
     "northwest" : CRYPT_ROOM + "room12"
     ]) );
}