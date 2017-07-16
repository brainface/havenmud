/*   Portia  1-9-99
     A study room.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small study");
  SetClimate("indoors");
SetAmbientLight(20);
  SetExits( ([
    "northeast" : MAL_ROOMS3 + "entranceway",
    "southwest" : MAL_ROOMS3 + "hall5",
    ]) );
  SetListen( ([
    "default" : "Only a soft murmuring can be heard.",
    ]) );
  SetSmell( ([
    "default" : "The room smells of potions and incense.",
    ]) );
  SetInventory( ([
    MAL_NPC3 + "student3" : 1,     
    MAL_NPC3 + "student4" : 1,     
    ]) );
  SetLong("This small study seems to be the most "
    "popular place for the young magicians to practice. "
    "Many books line the small shelves and are scattered about "
    "the tables. A large fireplace sits within the outward of the "
    "two curved obsidian walls. As it crackles it emits all of the "
    "light in the room. Along the inside curved wall is a small window "
    "overlooking the round courtyard of the Ring of Magic.");
  SetItems( ([
    ({"study"}) : (:GetLong:),
    ({"book", "books"}) : "The books are scattered everywhere.",
    ({"shelves", "shelf"}) : "The small shelves hold many books.",
    ({"tables", "table"}) : "The tables look like they are quite old.",
    ({"fireplace"}) : "The fireplace emits all of the light.",
    ({"walls", "wall"}) : "The walls curve here to create a rounded "
          "building.",
    ({"building"}) : "The building is circular in nature.",
    ({"window"}) : "The window overlooks the courtyard.",
    ({"courtyard"}) : "The circular courtyard is centered around the "
          "staircase.",
    ({"staircase"}) : "The huge staircase is in the courtyard.",
    ]) );
  SetItemAdjectives( ([
    "study" : ({"small"}),
    "book" : ({"scattered"}),
    "shelves" : ({"small"}),
    "tables" : ({"old"}),
    "fireplace" : ({"large"}),
    "walls" : ({"obsidian", "curved"}),
    "building" : "rounded",
    "window" : "small",
     "courtyard" : "circular",
    "staircase" : "huge",
    ]) );
  }
