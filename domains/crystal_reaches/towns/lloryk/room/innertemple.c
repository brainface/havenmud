#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() 
{
  room::create();
  SetClimate("indoors");
  SetTown("Lloryk");
  SetShort("the Inner Temple");
  SetLong("Within the Inner Temple of Eclat there is little "
          "doubt about the spartan nature of the religion.  Little "
          "in the way of furnishings fills a room designed as little "
          "more than a safe place to contemplate the expansion of the "
          "faith through action."
     );
  SetSmell( ([
    "default" : "The room has the scent of fresh cut flowers.",
    ]) );
  SetProperty("no magic", 1);
  SetProperty("no attack", 1);
  SetListen( ([
    "default" : "Light music plays magically from the ceiling.",
    ]) );
  SetAmbientLight(50);
  SetExits( ([ 
    "west" : LLORYK + "room/church",
     ]) );
  SetNewsgroups( ({ "religion.eclat" }) );
  SetInventory( ([ 
    ]) );
}

