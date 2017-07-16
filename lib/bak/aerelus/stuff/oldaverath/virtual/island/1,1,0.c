#include <lib.h>
#include <domains.h>
inherit AVERATH_LIB;

varargs static void create(int x, int y) {
    ::create(1,1);
  SetTown("Averath");
    SetShort("a residential area");
    SetLong("The Averath River runs through here, heading off to the southwest "
      "from the northeast. A small house sits near the the river on the "
      "southeast side, a small wooden bridge crossing the river to join up "
      "with the Duke's Road to the west. The yard is a bit run down and "
      "some laundry hangs on lines close to the rivers edge.");
    SetListen( ([
	"default" : "The sounds of water bubbling are loud here.",
      ]) );
    SetSmell( ([
	"default" : "The air is filled with the smell earth and the river.",
      ]) );
    SetItems( ([
	({"river"}) : "The Averath River starts to the northeast and heads "
	"southwest, its blue waters shine in the light.",
	({"bridge"}) : "This wooden bridge spans the Averath River.",
	({"house"}) : "This is a small wooden house, that sits near the river. "
	"Slightly run down, it looks as though it's had repairs several "
	"times on the roof.",
	({"yard","ground"}) : "Grass grows bright green near the edge of the "
	"river but the rest of the yard hasn't been kept well, a few dying "
	"flowers line the sides of the house. Some childrens toys clutter "
	"the front near the door.",
	({"laundry","line","lines"}) : "Various childrens clothing and "
	"what appear to be other various linens hang on a rope which is "
	"tied to the tops of sticks which are placed firmly in the ground.",
      ]) );
    SetEnters( ([ "house" : AVERATH_CITY "house1" ]) );
  SetItemAdjectives( ([
     "bridge" : ({"wooden"}),
     "house" : ({"small","wooden"}),
     "yard" : ({"run down"}),
     ]) );
  SetDoor("house", AVERATH_OBJ + "door1");
}
