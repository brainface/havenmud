#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("a nice little house");
  SetLong("Fairly good sized, this house is immaculately kept. Two beds "
     "stand in the northern corner, made up perfectly, with a nightstand "
     "in between them. Four curtained windows allow the sun to spill into "
     "the room in the day and allow ample moonlight at night. A neat "
     "little kitchen sits across from the beds, with a table and two chairs. "
     "The table is spotless and holds a beautiful vase of flowers. Towards "
     "the door is obviously the entertaining area, as it holds a rather "
     "comfortable looking couch, draped in the finest fabrics.");
  SetListen( ([
     "default" : "The soft hum of birds singing fills the room.",
     ]) );
  SetSmell( ([
     "default" : "Sweet fragrances of flowers linger here.",
     ]) );
  SetItems( ([
     
     ({"nightstand","stand"}) : "This small nightstand rests between "
     "the two beds, holding a large candle and a wash basin on it. It's "
     "wood is polished to shine.",
     ({"kitchen"}) : "This part of the house is kept sparkling clean, as "
     "the rest of the house is. A small table and chairs sit in place "
     "perfectly, a little vase with flowers giving it decoration.",
     ({"bed","beds"}) : "One a bit larger than the other, these wooden "
       "beds are neatly made with beautifully colored linens.",
     ({"window","windows"}) : "Sheer fabric makes the delicate curtains "
     "that cover the windows, allowing plenty of sunlight in during the "
     "day. There is one window on each wall, making the whole house "
     "light up.",
     ({"wall","walls"}) : "The walls are a bright yellow, and pretty "
     "flower patterns speckle them.",
     ({"floor"}) : "The floor sparkles and is probably scrubbed by hand "
     "twice a day to keep it that way.",
     ({"couch"}) : "This comfortable looking couch is draped in rich "
     "looking fabrics, and stuffed with feathers to make it quite "
     "relaxing.",
     ({"table"}) : "The table is wood, and probably very old, but is "
     "immaculately kept. It shines with a great luster.",
     ({"chair","chairs"}) : "These small wood chairs match the table perfectly.",
     ({"door"}) : "The door seems to be propped open always to let the "
     "air in.",
     ]) );
  SetItemAdjectives( ([
     "nightstand" : ({"small"}),
     "kitchen" : ({"little"}),
     "bed" : ({"wooden"}),
     "window" : ({"curtained"}),
     "couch" : ({"comfortable"}),
     "table" : ({"wood"}),
     "chair" : ({"small","wood"}),
     ]) );
  SetExits( ([
     "out" : AVERATH_ISLAND "1,-1,0",
     ]) );
  SetInventory( ([
     AVERATH_NPC "woman" : 1,
     AVERATH_NPC "child" : 1,
     ]) );
}
