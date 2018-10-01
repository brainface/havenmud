
/*  room17.c
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
  SetShort("a guard tower");
  SetLong();
  SetSmell();
  SetListen();
  SetItems();
  SetItemAdjectives();
  SetEnters( ([
     "down" : CRYPT_ROOM + "room13"
     ]) );
}