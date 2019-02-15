/* Barn11.c
 * A barn
 * 
 *
 */

#include <lib.h>
#include "../francis.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetDomain("Havenwood");
  SetShort("A drafty barn");
  SetLong("Seems barny");

  SetItems( ([ ]) );

  SetListen( ([
    "default" : "Someone is snoring to wake the dead.",
  ]) );

  SetSmell( ([
    "default" : "Piles of fresh hay and old wood scent the air.",
  ]) );
  SetExits( ([
      "north" : FRANCIS_ROOM "fence12",
      "east"  : FRANCIS_ROOM "inn21",
      "south" : FRANCIS_ROOM "clearing10",
      "west"  : FRANCIS_ROOM "forest01"
  ]) );

}
