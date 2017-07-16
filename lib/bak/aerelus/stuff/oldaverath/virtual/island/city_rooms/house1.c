#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("indoors");
  SetShort("a small house");
  SetLong("This small one room house contains all the necessities for "
     "a small family to live happily. In one corner a small table and "
     "chairs sit while on the other side a few small beds are curtained "
     "off from the rest of the room. A small round braided rug covers "
     "some of the dusty floor.");
  SetListen( ([
     "default" : "Sounds of a small child crying fill the room.",
     ]) );
  SetSmell( ([
     "default" : "This place smells dirty and musty.",
     ]) );
  SetItems( ([
     ({"table"}) : "This small wooden table is cluttered with dirty dishes "
       "from breakfast and probably dinner from the night before.",
     ({"chair","chairs"}) : "Small wooden chairs sit near the table, "
       "a small wooden doll rests on one of them.",
     ({"curtain"}) : "Though not exactly a curtain, this long piece of "
       "what used to be bedding, serves as a makeshift wall to close "
       "off the beds from the rest of the room.",
     ({"bed","beds"}) : "These beds are small and build with wooden frames, "
       "which hold feathered bedding for cushioning. They were obviously "
       "hastily made and the blankets are a bit worn and dirty.",
     ({"rug","floor"}) : "A small braided rug, made of mutlicolored fabrics "
       "covers only a small portion of the dusty floor.",
     ]) );
  SetItemAdjectives( ([
     "table" : ({"small","wooden"}),
     "chair" : ({"small","wooden"}),
     "bed" : ({"small"}),
     "rug" : ({"small","braided"}),
     ]) );
    SetExits( ([
     "out" : AVERATH_ISLAND "1,1,0",
     ]) );
SetInventory( ([ 
     AVERATH_NPC "woman" : 1,
     AVERATH_NPC "man" : 1,
     AVERATH_NPC "child" : 1,
     ]) );
    SetDoor("out", AVERATH_OBJ + "door1");
}
