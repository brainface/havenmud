#include <lib.h>
#include <climb.h>
#include "../path.h"

inherit LIB_ROOM;


static void create()
{
  room::create();
  SetClimate("outdoors");
  SetShort("at the base of a cliff");
  SetLong( "A gigantic cliff towers over you." );

  SetItems( ([ 
               ({"root","roots"}) : "The roots stick out of the cliff at odd "
                     "intervals.",
               "earth" : "In spite of it being dirt the earth seems quite "
                         "sturdy."]) );

  SetSmell( ([ "default" : "The rotten smell of the nearby swamp nearly "
                           "overpowers you."]) );
  SetListen( ([ "default" : "It is very quiet, except for the chirping of a "
                            "cricket."]) );
  SetInventory( ([ GWONISH + "room/cliffob1" : 1 ]) );

}


