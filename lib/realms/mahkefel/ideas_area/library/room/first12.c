/* Arcanith Library first
 * outside courtyard, surrounded by rubble
 * 
 */
#include <lib.h>                   

// mikes includes dir
#include "../arc_library.h" 

// must be in all rooms
inherit LIB_ROOM;      

// true if winged or lamrani
int checkFlying();

static void create() {
  // get it started   
  ::create();     

  SetClimate("indoors");
  SetAmbientLight(30); // I hope this is dark?
  SetShort("an empty courtyard");           
  SetLong(
    "This is an empty courtyard, surrounded by the walls of abandoned "
    "buildings. A hole in the wall to the west leads to a dark closet. "
    "A balcony hangs overhead."
  );                                                                          

  SetListen( ([
    "default" : "A bird whistles nearby.",
  ]) );

  SetSmell( ([
    "default" : "The moldy scent of stagnant water hangs in the air.",
  ]) );

  SetInventory( ([
    ARC_LIBRARY_NPC "dust_mephit" : random(3),
    ARC_LIBRARY_NPC "wind_mephit" : random(3)+1,
  ]) );

  SetExits( ([
    "north" : ARC_LIBRARY_ROOM "first11",
    "west" : ARC_LIBRARY_ROOM "first02",
  ]) );

  SetDoor("north",ARC_LIBRARY_OBJ "door_courtyard");
  
  AddExit( "up",  ARC_LIBRARY_ROOM "second12", (: checkFlying :) ); 
}

// You can reach the next level by flying upward from here.
// There's no real point to this.
int checkFlying() {

  object who = this_player();
  if (creatorp(who) ) {
    who->eventPrint("You walk up the walls. Cheater.");
    return 1;
  }

  if (who->GetRace() == "lamrani") {
    send_messages( "levitate",
      "$agent_name $agent_verb upward effortlessly.",
      who, 0, this_object()
    );
    return 1;
  }

  if ( who->GetLimb("right wing") && who->GetLimb("left wing") ) {
    send_messages( "soar",
      "$agent_name $agent_verb upward.",
      who, 0, this_object()
    );
    return 1;
  }

  eventPrint("You see no easy way to reach the balcony from here.");
  return 0;
}

