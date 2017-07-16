#include <lib.h>
#include <std.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a shady glade");
  SetExits( ([
    "southeast" : "path3",
    "east"      : "path5",
    ]) );
  SetSmell( ([
    "default" : "The gentle scent of flowers softly flows here.",
    ]) );
  SetListen( ([
    "default" : "The glade is quiet and calm.",
    ]) );
  SetLong("The glade is a quiet spot for contemplation.  It is used "
          "in the town as a place for funerals and other solemn "
          "events.  At the center of the glade is a small bier "
          "set for the next to pass into the realm of the dead.  " 
          "There are two paths leaving the glade; one which heads east "
          "towards the center of Tairi and the other heads southeast "
          "towards the Tai mountain range.");
  SetItems( ([
    ({ "glade", "spot", "place", "event", "events", "funeral", 
    	 "funerals" }) : 
    	       (: GetLong :),
    "bier" : "This is a small rock table upon which a corpse "
             "would be placed prior to cremation.",
    ({ "center", "town"}) : 
    	       "The town of Tairi is off to the east.",
    ({ "mountain", "mountains", "range"}) :
             "The Tai mountain range protects the peace of this glade.",
    ({ "path", "paths" }) :
    	       "There are two paths that leave from the glade. The "
    	       "Chrysanthemum Path which heads east towards the "
    	       "center of Tairi and a small dirt path heading southeast "
    	       "on the outskirts of town."
    ]) );
  SetItemAdjectives( ([
    "bier"   : ({ "small", "rock" }),
    "center" : ({ "town", "tairi" }),
    "range"  : ({ "mountain", "tai" }),
    "path"   : ({ "chrysanthemum", "small", "dirt" }),
    
    ]) );
  SetInventory( ([
    STD_OBJ "reztotem" : 1,
  ]) );
}


    



