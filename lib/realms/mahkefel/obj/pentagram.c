/* 
 * Having fun with door code, to see if something relatively non-door like could act like a door and also be convincing.
* It probably needs more hook-thingies to actually be convincing
 * Also, it keeps flies out of the greater immortal area.
 */
#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("south",
    ([ "id" : "pentagram", 
     "short": "a pentagram glowing with arcane energy on the floor",
     "long" : "a pentagram has been etched into the stone floor here, apparently to seal the way to the south. Though it cackles with arcane energy, it might be easily opened to disturb the magic powering it.",
     "lockable" : 1])
  );
  SetSide("north",
    ([ "id" : "pentagram", 
     "short": "a strange pentagram scrawled in the dirt",
     "long" : "an odd seal shaped like a pentagram is scrawled in the dirt here. Despite its simple appearance, it seems exterely difficult to look past it. Opening the pentagram might disturb its magic.",
     "lockable" : 0]) 
  );
  SetClosed(1);

}
