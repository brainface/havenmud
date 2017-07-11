// SetInventory bladedancer was commented out because
// /realms/duuktsaryth isn't there to call
// Laoise 6/22/04
// commented out bladedancer and barkeep - weren't updating
// Davantalus 20040731
// Once again commented out blade dancer for combat style revamp
//  -Melchezidek 8/09/08
#include "../inn.h"
#include <lib.h>
#include <std.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("The Morning Star Inn");
  SetAmbientLight(35);
  SetLong("The main room of the Morning Star Inn is crowded with tables and "
          "sparsely populated with drunken idiots.  Along the bar is a row of "
          "currently unoccupied stools, and on the wall behind it there are "
          "several shelves on which lie various items.  A hallway to the "
          "north leads to the rooms.");
  SetClimate("indoors");
  SetItems( ([ 
                "wall" : "The wall holds up several shelves.",
             ({ "several shelves", "shelves", "shelf", "various items",
                "items", "item" }) :
                "On the shelves are many items needed to run the bar for a "
                "time.",
             ({ "tabletops", "tabletop", "plank", "planks" }) :
                "Several of the tabletops have been spilled on and might be "
                "quite dirty if they hadn't been given a dark stain.",
             ({ "table legs", "table leg", "legs", "leg" }) :
                "The legs of the tables are each about four feet high.  One "
                "of the legs on the closest table appears to have been once "
                "pulled off and glued back on.  There is obviously a bit of "
                "blood and hair on it.",
             ({ "blood and hair", "hair and blood", "hair", "blood" }) :
                "The hair and blood are stuck to the side of a table leg as "
                "someone was once hit repeatedly over the head with it.",
             ({ "tables", "table" }) :
                "The tables are dark stained to hide spills and built very "
                "basically.  The tabletops are made of three planks, each "
                "three feet long and one foot wide, and the legs bring the "
                "tables to four feet high.  One of the legs seems to have "
                "something strange about it.",
             ({ "drunken idiots", "drunken idiot", "idiots", "idiot" }) :
                "These idiots are exactly what one would expect to see of "
                "drunken idiots...unclean and obnoxious.",
             ({ "tall wooden bar stools", "tall stools", "row of stools",
                "wooden bar stools", "bar stools", "row", "stool",
                "stools", "circular seats", "seats" }) :
                "These are tall wooden bar stools, about four feet high "
                "with circular seats.",
             ({ "long wooden bar", "wooden bar", "long bar", "bar" }) :
                "The bar extends from one wall almost to the other, leaving "
                "just enough room for the barkeep to get in and out.",
             ({ "hallway", "hall" }) :
                "This is a hallway that leads north to the rooms."
             ]) );
SetSmell( ([ 
           "default" : "The smell of drunkenness is prevalent here."
           ]) );
SetInventory( ([
     //        STD_NPC "bladedancer" : 1,
               I_NPC + "/jord" : 1,
               I_NPC + "/alcoholic" : random(3)+1
               ]) );
SetNewsgroups( ({ "player.general" }) );
SetObviousExits("north, out");
SetExits( ([
           "north" : I_ROOM + "/hall1",
           "out" : I_ROOM + "/entrance"
           ]) );
}
