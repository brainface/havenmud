
/*  room11.c
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
     "up" : CRYPT_ROOM + "room15",
     "southwest" : CRYPT_ROOM + "room6"
     ]) );
}