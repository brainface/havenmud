
/*  shrine.c
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
  SetShort("a shrine");
  SetLong();
  SetSmell();
  SetListen();
  SetItems();
  SetItemAdjectives();
  SetEnters( ([
     "south" : CRYPT_ROOM + "garden",
     "down" : CRYPT_ROOM + "crypt1"
     ]) );
}