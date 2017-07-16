#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("a small house");
  SetLong("Filled with old rickety furniture, this house seems fairly "
     "cluttered. A farily small bed is in one corner with a stand next to "
     "it, and the kitchen table and chairs are neatly cleaned. A large "
     "rug covers the mostly swept floor, and a comfortable, if not old, "
     "looking chair sits in a corner next to a pile of books and papers.");
  SetListen( ([
     "default" : "Sounds of humming fill the air.",
     ]) );
  SetSmell( ([
     "default" : "A faint breeze of flowers fills the air.",
     ]) );
  SetItems( ([
     ({"furniture"}) : "Various old wooden chairs, tables, and other "
       "furniture clutters this small home.",
     ({"bed"}) : "This old bed looks as if it's about to fall apart at "
       "any moment. Although it's neatly made, with feathered pillows "
       "all in place the linens seem very worn with age and patched "
       "from previous tears.",
     ({"stand"}) : "This small wood stand rests near the bed and holds "
       "a wash basin, various combs and a small sliver of some soap.",
     ({"chair","chairs"}) : "Little chairs sit around the table, all "
       "neat and clean. Though obviously worn and old, they are kept "
       "as tidy as possible. A larger chair sits in the corner and is "
       "covered with feather padded cushions, which have been patched "
       "multiple times over the years.",
     ({"table"}) : "This old wood table has seen better days, but is kept "
       "tidy and as clean as possible. Repaired several times, it probably "
       "won't last much longer, but it's been a good table.",
     ({"rug"}) : "A large rug which covers most of the almost swept floor "
        "and looks as if it hasn't moved from this spot in years. Made of "
       "multi-colored fabric, most of the color is dull and hard to "
       "make out.",
     ]) );
  SetItemAdjectives( ([
     "furniture" : ({"old","rickety"}),
     "bed" : ({"old","small","wood"}),
     "stand" : ({"small","wood"}),
     "chair" : ({"little","wood"}),
     "table" : ({"old","wood"}),
     "rug" : ({"large","multi-colored"}),
     ]) );
    SetExits( ([
     "out" : AVERATH_ISLAND "-1,1,0",
     ]) );
  SetInventory( ([
     AVERATH_NPC "woman" : 1,
     AVERATH_NPC "man" : 1,
     ]) );
  SetDoor("out", AVERATH_OBJ + "door2");
}
