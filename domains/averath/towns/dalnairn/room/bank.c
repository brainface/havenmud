// Dalnairn
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../dalnairn.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetTown("Dalnairn");
  SetShort("in the bank of dalnairn");
  SetLong(
    "The bank of Dalnairn is a popular building in the city. As such, it has "
    "been decorated carefully. A soft red carpet covers most of the floor, "
    "with tall potted plants in the corners of the room. At the northern "
    "end there is a long counter where visitors conduct their business with "
    "the teller. Behind the counter is a huge iron vault where the money is "
    "kept."
  );
  SetItems( ([
  ({ "bank", "building" }) : (: GetLong :),
  ({ "carpet" }) : 
    "The red carpet covers most of the floor. It is soft, and comfortable to "
    "walk on.",
  ({ "plants", "pots" }) : 
    "These tall plants are situated in pots, placed in each corner of the "
    "bank.",
  ({ "corners" }) : 
    "There are potted plants in each of the corners here.",
  ({ "counter" }) : 
    "The counter is long, leaving adequate room for conducting business. ",
  ({ "vault" }) : 
    "The huge iron vault is locked. Despite numerous attempts, nobody has "
    "managed to break in to date.",
  ]) );
  SetItemAdjectives( ([
    "building" : ({ "popular" }),
    "carpet" : ({ "soft", "red" }),
    "plants" : ({ "tall", "potted" }),
    "counter" : ({ "long" }),
    "vault" : ({ "huge", "iron" }),    	
  ]) );
  SetInventory( ([
    DAL_NPC "wuach" : 1,
    DAL_NPC "guard" : 1,  
  ]) );
  SetListen( ([
    "default" : "It sounds like money is being counted here.",
  ]) );
  SetSmell( ([
    "default" : "The bank smells very clean.",
  ]) );
  SetExits( ([
    "out" : DAL_ROOM "road5",
  ]) );  
}
