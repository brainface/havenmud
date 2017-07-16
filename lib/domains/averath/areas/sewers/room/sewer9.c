// Averath Sewers
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../sewers.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("indoors");
  SetShort("in the Averath sewer system");
  SetLong(
    "The primitive living area extends here, at the end of the tunnel system. "
    "This area is not quite as well lit as the other part of the area, but "
    "the light coming from the west keeps it from being in complete darkness. "
    "There is a large iron grate in the floor here, alongside piles of refuse "
    "from the inhabitants of the sewers. "    
  );
  SetItems( ([
  ({ "sewer", "system", "tunnel", "area" }) : (: GetLong :),  
  ({ "network", "tunnels", "tunnel" }) : "The network of tunnels that make up "
    "the sewer system seem like they were built a long time ago.",  
  ({ "stream", "center" }) : "The stream is blocked further to the west, "
    "allowing people to live in this part of the tunnel system.",  
  ({ "walkways" }) : "The stone walkways lie on either side of where the "
    "stream would usually be, providing access to city workers, should the "
    "need arise. ",
  ({ "grate" }) : "This large iron grate would allow the sewage stream to "
    "flow down to what appears to be a system of caves, if the stream was "
    "still running through here. Some of the bars appear bent.",
  ({ "bars" }) : "The bars on the grate have been bent, allowing most normal "
    "sized people access to the caves below.",
  ({ "piles", "refuse" }) : "Refuse from the living area to the west has "
    "piled up here over the years. Empty bottles, fruit peel and other such "
    "items have been thrown in this direction to be forgotten about.",  
  ]) );
  SetItemAdjectives( ([
    "system" : ({ "sewer" }),    
    "stream" : ({ "filthy" }),
    "walkways" : ({ "stone" }),
    "grate" : ({ "large", "iron" }),
    "refuse" : ({ "piles", "of" }),    
  ]) );
  SetInventory( ([    
    SEWERS_NPC "rat" : 3,
    SEWERS_NPC "bandit2" : 1,
  ]) );
  SetListen( ([
    "default" : "The sound of the trickling stream is faint here.",
  ]) );
  SetSmell( ([
    "default" : "The sewer smells horrible.",    
  ]) );
  SetExits( ([  
    "west" : SEWERS_ROOM "sewer8",    
  ]) );
  SetEnters( ([
    "grate" : SEWERS_ROOM "sewer10",
  ]) );
}