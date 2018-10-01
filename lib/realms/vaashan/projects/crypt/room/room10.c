
/*  room10.c
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
  SetShort("a guard station");
  SetLong();
  SetSmell();
  SetListen();
  SetItems();
  SetItemAdjectives();
  SetEnters( ([
     "up" : CRYPT_ROOM + "room14",
     "northwest" : CRYPT_ROOM + "room9",
     "down" : CRYPT_ROOM + "crypt7"
     ]) );
  SetDoor("down", CRYPT_ROOM + "trap_door");     
}