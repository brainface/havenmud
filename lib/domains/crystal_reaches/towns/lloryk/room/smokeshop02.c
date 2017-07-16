
#include <lib.h>
#include "../path.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("a small lounge");
  SetLong(
    "This small lounge sits off the main shop.  Arranged around the room are various chairs and "
    "tables designed for the relaxation and comfort of the patrons of the Emporium. The wooden "
    "floor is obviously well maintained, with a highly polished shine to all of the wood surfaces. "
    "A rectangular rug sits beneath the main table here. Along the north wall, a window looks out "
    "over the majestic farmland of the Shire."
    );
  SetExits( ([
    "east" : LLORYK "room/smokeshop01",   
    ]) );
  SetInventory(([ 
    LLORYK "obj/smoke/chair" : 2,
    ]));
  SetAmbientLight(30);
  SetSmell( ([
    "default" : "Strong clouds of smoke linger about.",
    ]) );
  SetListen( ([
    "default" : "Light wind from the window drafts in."
     ]) );
  SetItems( ([
     "lounge"    : "This lounge has been decorated with a neutral "
                   "brown and white theme.",
     "rug"       : "It is rectangular in shape and rests under the "
                   "table in the center of the room.",
     "window"    : "The window displays farmlands outside.",
     "farmlands" : "Rows and rows of growing plants.",
     "wall"      : "One wall has a window built into it.",
     "walls"     : "The walls make a square shaped room, the west "
                   "wall has a window displaying the farmlands.",
    ({ "floor", "wooden floor", "polished wooden floor" }) : "The "
                  "wooden floor has been built to reach the "
                  "four walls. A rug rests in the center of the "
                  "floor underneath the wooden table.",
    ({ "table","wooden table" }) : "It stands on the rug in the "
                  "center of the lounge slightly raised for "
                  "guests to rest their drinks on.", 
    ({ "curtain", "brown curtain" }) : "A brown curtain has been "
                  "slightly pulled aside to display the farmlands "
                  "of Lloryk.",
              ]) );
  }
