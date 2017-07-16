/* 5/03 Libitina / newbie area / wooded vale */

#include <lib.h>
#include <domains.h>
#include "../wood.h"
inherit LIB_ROOM;
int DomainCheck();

static void create() {
    ::create();
    SetShort("a small wooded vale");
    SetLong(
      "The corsican pine trees grow thicker here, making it next to "
      "impossible to continue eastward or westward. Thick, thorny underbrush "
      "creates a wall between the trees. The area seems lighter and "
      "more open to the north, welcoming even. Light dances on the trail "
      "to the south, almost happily."
    );
    SetItems( ([
        "trees" : "The trees grow taller and thicker to the west and east.",
        "underbrush" : "The plants here are thicker and bear sharp "
        "thorns.",
        "trail" : "The trail is narrow, and leads back to the south."
      ]) );
    SetSmell("default", 
      "The pine scent is nearly overwhelming."
    );
    SetListen("default", 
      "The forest seems quieter here."
    );
    SetExits( ([
        "south" : WOOD_ROOM "vale8",        
      ]) );
    AddExit("north", SOUTHERN_COAST_VIRTUAL "havenroad/1,0", (: DomainCheck :) );
    SetInventory( ([ WOOD_NPC "fox.c" : 1 ]) );
    SetDayLight(-5);
    AddWarmth(-10);
}

int DomainCheck() {
  if (!OPEN_SOUTHERN_COAST)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_SOUTHERN_COAST;  
}