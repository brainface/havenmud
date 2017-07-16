#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetTown("Lloryk");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetShort("inside the village meeting hall");
  SetLong("The hall is a small structure, designed as a wide open hall with "
          "room only to stand.  At the front of the hall is a large podium "
          "from which the Prime Minister speaks at public gatherings. Around "
          "the room, red banners of the Eclat religion adorn the walls in a "
          "highly celibratory fashion."
          );
  SetItems( ([ 
    ({ "podium" }) : "The podium is a stately wooden structure with a "
                     "red banner draped over it.",
    ({ "banner", "banners" }) : "The banners are plain, deep red with no "
                                "markings or insignia on them at all.",
    ]) );              
  SetExits( ([ 
    "out" : LLORYK "room/uh5",
    ]) );
  SetInventory( ([ 
    LLORYK + "npc/filban" : 1,
    ]) );          
  SetSmell( ([ 
    "default" : "The smells of stale sweat taint the air from "
                "poor ventilation.",
    ]) );
  SetListen( ([
    "default" : "The acoustics in this hall are excellent.",
    ]) );
  SetNewsgroups( ({ "town.lloryk" }) );
}
