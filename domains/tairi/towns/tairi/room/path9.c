#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the Way of the Warrior");
  SetExits( ([
    "north" : "path10",
    "south" : "path6",
    ]) );
  SetLong("The path leads north and south from here. "
          "To the north is the palace of the Daimyo of "
          "Tairi, while to the south is the center of "
          "town. Directly to the east is a large building "
          "which seems to be a shop of some kind, while to "
          "the west is the home of the local moneylender.");
  SetItems( ([
    ({ "shop", "building" }) : 
    	    "The shop is a large building with reinforced wooden walls.",
    ({ "home", "bank" }) : 
    	    "The moneylender's home is what amounts to a bank for Tairi.",
    ({ "path", "road" }) :
    	    "This dirt beaten road travels north towards the Grand Palace "
    	    "of the Daimyo and south back to the center of Tairi.",
    ({ "palace" }) :
    	    "The Grand Palace of the Daiymo sits north of here along the Way "
    	    "of the Warrior.",
    ({ "center", "town", "tairi" }) :
    	    "The town center of Tairi is southward along the Way of the "
    	    "Warrior",
    ({ "wall", "walls" }) :
    	    "The walls of the shop are wooden and reinforced.",  
    ]) );
  SetItemAdjectives( ([
    "home"   : ({ "moneylender", "moneylender's", "moneylenders" }),
    "shop"   : ({ "large" }),
    "wall"   : ({ "wooden", "reinforced" }), 
    "palace" : ({ "grand", "daiymo" }),
    "center" : ({ "town", "tairi" }),
        
    ]) );
  SetEnters( ([
    "home" : TAI_RI_ROOM "bank",
    "shop" : TAI_RI_ROOM "shop",
    ]) );
  SetInventory( ([
    ]) );
  SetSmell( ([
    "default" : "The scent of flowers is more faint here.",
    ]) );
  SetListen( ([
    "default" : "The muffled sounds of city life echo into the air.",
    ]) );
}

