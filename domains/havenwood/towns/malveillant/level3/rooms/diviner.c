/*   Portia  1-9-99
    The diviner's study.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a diviner's workroom");
  SetClimate("underground");
SetAmbientLight(20);
  SetExits( ([
    "northwest" : MAL_ROOMS3 + "hall4",
    "southeast" : MAL_ROOMS3 + "hall3",
    ]) );
  SetInventory( ([
    MAL_NPC3 + "student3" : 1,//
    ]) );
  SetListen( ([
    "default" : "Soft chanting can be heard clearly.",
    ]) );
  SetSmell( ([
    "default" : "The scent of magic is in the air.",
    ]) );
  SetLong("This is a fairly dull room. The books are all in order, "
    "and the shelves are clean. A large torch sits on the curved "
    "wall and a small window overlooks the courtyard. There seem to "
    "be some rocks on the ground and they look like they may be "
    "in some sort of particular order. One most likely wouldn't want "
    "to move them.");
  SetItems( ([
    ({"room"}) : (:GetLong:),
    ({"walls", "wall"}) : "The curves walls are made of obsidian.",
    ({"books", "book", "shelves", "shelf"}) : "The shelves and books "
        "are all neat and tidy.",
    ({"window"}) : "The window overlooks the courtyard.",
    ({"torch"}) : "The torch is rather large.",
    ({"rocks", "rock"}) : "The rocks seem to be in a particular order.",
    ]) );
  SetItemAdjectives( ([
    "room" : ({"dull"}),
    "walls" : ({"curved", "obsidian"}),
    "torch" : ({"large"}),
    "books" : "clean", 
    ]) );
  }
