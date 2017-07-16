// Added an item for storeroom, since it was in the long
// Laoise, Sept 2004

#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("a small shop");
  SetLong("Long shelves line the walls of this tiny shop, displaying a "
     "variety of wares. The proprietor stands behind a small counter ready "
     "to help all who enter. The wood walls are decorated with paintings "
     "of all types of flowers, and the tops of the shelves have many "
     "flower arrangements. A small door leads back to a storeroom, the only "
     "other exit being back out to the Crossroads.");
  SetListen( ([
     "default" : "The only sounds are the occasional clinking of coins.",
     ]) );
  SetSmell( ([
     "default" : "The smell of fresh flowers lingers in the air.",
     ]) );
  SetItems( ([
     ({"shelf","shelves"}) : "These long wood shelves are neatly dusted and "
       "wares are placed all in order across them. Between the breaks in "
       "shelving hang the most beautiful pictures.",
     ({"wall","walls"}) : "The wood walls are painted a pale blue and are "
       "lined with shelves containing her wares. Paintings of lovely "
       "colorful flowers decorate the walls, and small curtained windows "
       "let the sun through to light the shop.",
     ({"ware","wares"}) : "You should ask the shopkeeper to see them.",
     ({"picture","pictures","painting","paintings"}) : "These lovely "
       "framed paintings portray a variety of brightly colored flowers.",
     "counter" : "This white-washed counter is where all the transactions "
       "take place. All neat and tidy there is a small pad of paper and "
       "a pencil that rest just above a drawer.",
    ({ "door", "storeroom", "room" }) : "This small door appears to lead to "
    "a back storeroom. The door is closed and barred and appears not "
    "to be for general access.",
     ]) );
  SetItemAdjectives( ([
     "shelf" : ({"long","wood"}),
     "wall" : ({"wood","blue"}),
     "counter" : ({"small"}),
    "door" : ({ "small", "store", "closed", "barred" }),
     ]) );
  SetExits( ([
     "out" : AVERATH_ISLAND "0,0,0",
     ]) );
  SetInventory( ([
    AVERATH_NPC "shopkeep" : 1,
    ]) );
}
