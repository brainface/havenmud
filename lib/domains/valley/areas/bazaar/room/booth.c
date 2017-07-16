  //* This is the ticket booth where players can buy a ticket for a ride or continue on to other parts of the bazaar. *//
#include <lib.h>
#include "../bazaar.h"
  inherit LIB_ROOM;

static void create (){
  ::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("the ticket booth");
  SetLong("Here is a hastily built booth where one could "
     "buy a ticket to one of the events at the bazaar. "
     "The rotten boards that make up the ticket booth "
     "look like they have been through one too many storms. "
     "To the north and south are some places to shop, "
     "while the games and rides appear to be further west.");
  SetSmell( ([
     "default" : "The smells of cooking meat and sawdust linger in the air."
  ]) );
  SetListen( ([
     "default" : "Loud laughter drifts in from the west."
  ]) );
  SetItems( ([
   ({ "booth" }) : "The boards that make up this booth are old and barely holding together.",
   ({ "board", "boards" }) : "These boards are old and falling apart. Termites fill the cracks of the wood.",
   ({ "games", "rides", "games and rides" }) : "They are further west.",
   ({ "termite", "termites" }) : "The termites are eating away at the boards.",
   ({ "crack", "cracks" }) : "They are filled with termites.",
  ]) );
  SetItemAdjectives( ([
     "board" : ({ "old", "rotten" }),
   "booth" : ({ "hastily built", "ticket" }),
  ]) );
  SetExits( ([
    "north" : BAZAAR_ROOM "flowers",
     "west" : BAZAAR_ROOM "juggle",
    "south" : BAZAAR_ROOM "acc",
     "east" : BAZAAR_ROOM "entrance",
  ]) );
  SetInventory( ([ BAZAAR_NPC + "zoe" : 1, ]) );
}
