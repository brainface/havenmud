/* Stabby Lynn's */

#include <lib.h>
#include <std.h>
#include <dirs.h>
#include <domains.h>
#include <rooms.h>
#include "../stab_bar.h"

inherit LIB_ROOM; 
inherit LIB_TOUCH;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(25);
  SetShort("inside the fucking bar");
  SetLong(
    "wow its a fucking bar.."
  );
  SetItems( ([
    ({ "bar" }) : "yep. its a bar alright.",
	]) );
  SetItemAdjectives( ([
    "bar" : ({ "fucking" }),
  ]) );
  if(query_night()) {
    SetInventory( ([
 //     SB_NPC "NPCHERE" : random(3) +1,
    ]) );
  } else {
    SetInventory( ([
    ]) );
  }
  SetListen( ([
    "default" : "sounds like a frucking bar.",
    ]) );
  SetSmell( ([
    "default" : "smells like a fucking bar.",
    ]) );
  SetTouch( ([
  "default" : "it feels like a fucking bar.",
    "bar" : "by god it really is a bar.",
    ]) );
  SetExits( ([
    "out" : "/realms/torak/workroom",
    ]) );
}
