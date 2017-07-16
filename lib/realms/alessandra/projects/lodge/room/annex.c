#include <lib.h>
#include "../lodge.h"
inherit LIB_ROOM;

static void create() {
room::create();   
  
  SetAmbientLight(20);
  SetClimate("indoors");
  SetShort("an annex");
  SetLong(
     "This annex shows no sign of activity. Bright lighting from "
     "outside beams into this room. Broken floorboards are covered "
     "with crushed bones. A cold chill rushes into the room through a "
     "broken window. Below the window lies an interesting looking chest. "
     "Through the door, a staircase can be seen."
     );
  SetSmell( ([
     "default" : "This room smells old and dusty.",
     ]) );
  SetListen( ([
     "default" : "The sounds of whipping winds is present.",
     ]) );
  SetItems( ([ 
     ({"annex","room", "attic"}) : (:GetLong:),
     ({"staircase"}) : "Through the door is a big dark staircase out of the annex.",
     ({"boards","floor","floorboard","floorboards"}) : "The wood on these "
       "boards are decayed and broken.  They do not look like they have been "
       "walked on for awhile.  These boards do not look very sturdy, they probably "
       "can  not hold much weight.",
     ({"window"}) : "The glass from this window has been knocked out.  It "
       "seems to be knocked out forcefully  by someone trying to escape a "
       "danger.  A cold chill sweeps in from this window.",
     ({"bones"}) : "These are the remains of someone who was not fortunate "
       "to get out of the room. They are crushed as if they have been stomped "
       "on.  It does not look good.",
     ]) );
  SetItemAdjectives( ([
     "boards" : ({"broken","decayed"}),
     "chest" : ({"big","hollow"}),
     "bones" : ({"crushed"}), 
     ]) );
  SetInventory( ([
     ]) );
  SetDoor( "out" , L_OBJ + "annexdoor.c" );
  SetExits( ([
     "out" : L_ROOM + "staircase.c"
     ]) );

}
