


#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the center of Tai-Ri");
  SetExits( ([
    "east" : "path7",
    "west" : "path5",
    "north" : "path9",
    "south" : "path2",
    ]) );
  SetLong("Chrysanthemum Path and the Way of the Warrior cross "
          "here, resulting in a \"center of town\".  To the east "
          "lies the Taisoka Temple, while to the west is "
          "the funeral glade.  Further south is the exit back into "
          "the Tai mountain range, and north along the Way is the "
          "grand palace of the Daimyo.");
  SetItems( ([
    ({ "path", "road" }) :
          "The Chrysanthemum Path is dirt beaten which heads west "
          "towards the funeral glade and east towards the Temple of "
          "Taisoka.  The path has purple flowers growing along its edges.",
    ({ "way", "road" }) :
    			"The Way of the Warrior is a well travelled dirt road.  This "
    			"road heads north to the Daimyo's grand palace and heads south "
    			"out of Tairi and into the Tai Mountains.",
    ({ "center", "town", "tairi" }) :
    	    (: GetLong :),
    "glade" : "The funeral glade is west along the Chrysanthemum Path.",
    "temple" : "The Temple of Taisoka is east along the Chrysanthemum Path.", 
    "palace" : "The Grand Palace of the Daimyo is north along the Way of "
    	         "the Warrior.",
    ({ "mountain", "mountains", "exit", "range" }) :
    	    "The Tai mountain range is south along the Way of the Warrior.",
    ({ "flower", "flowers", "chrysanthemum", "chrysanthemums" }) :
            "The flowers are a lovely shade of purple.",
    ]) );
  SetInventory( ([
    TAI_RI_NPC "sam_guard" : random(4),
//    TAI_RI_NPC "citizen" : random(3),
    TAI_RI_OBJ "fountain" : 1,
    TAI_RI_NPC "controller" : 1,
    ]) );
  SetSmell( ([
    "default" : "The light scent of flowers fills the air.",
    "flower" :
         "The flowers have a faint but pleasant smell to them.",
    ]) );
  SetListen( ([
    "default" : "The splash of fountain water is the only "
                "sound to break the quiet.",
    ]) );
}
