// Proximo@Via Imperialis
// 05/29/2003

#include <lib.h>
#include "../sulumus.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
/*
  SetDomain("mountains");
*/
  SetAmbientLight(30);
  SetShort("inside the Currency Exchange Tent");
  SetLong(
     "This very large canvas tent is the center point of the Sulumus Trading Post's "
     "economy. This makeshift bank is unusual in design from the other tents in the "
     "trading post, as the structure of the tent has been reinforced, as well as "
     "a safe within a bronze cage. The bank teller's desk sits near to the safe, "
      "as to allow easy access. A series of small candles have been lit in place "
     "of the firepit. "
  );
  SetItems( ([
     ({"tent","canvas"}) :
     "The material that this tent is composed of is that of tightly-wrapped canvas "
     "stretched over a wooden frame. This allows for a weather proof structure, "
     "able to withstand many types of weather. ",
     ({ "candles","firepit" }) : 
     "An assortment of dozens of candles have been lit in place of the firepit "
     "in the center of the room. While candlelight isn't as bright as a bon-fire, it "
     "provides more controlled and less hazardous lighting for maintaining currency. ",
     ({"desk"}) :
     "This wood desk was designed for the use of someone who handles currency. "
     "Special copper lock drawers keep money safe and secure, while with the use "
     "of a key can be access by the teller as needed. ",
  ]) );
  SetItemAdjectives( ([
  ]) );
  SetInventory( ([
     S_NPC + "standing_guard" : 1,
     S_NPC + "teller" : 1,
  ]) );
  SetEnters( ([
  ]) );
  SetSmell( ([
     "default" : "The air smells of coins and candles. ",
  ]) );
  SetListen( ([
     "default" : "The heavy traffic of daily use resounds here.",
  ]) );
  SetExits( ([
     "out" : S_ROOM + "sulumus5",
  ]) );
}
