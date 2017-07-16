#include <lib.h>
#include <domains.h>
inherit AVERATH_LIB;

varargs static void create(int x, int y) {
  ::create(0,-1);
  SetTown("Averath");
  SetShort("the Duke's Road");
  SetLong("The Duke's Road continues southward from the crossroads out "
     "of town and across the island. The road is paved with large stones, "
     "smoothed over the years from many the traveller. To the west, tall "
     "spires of the church can be seen, while off to the east is a rather "
     "residential looking area. North the bustling of the city can be "
     "heard, citizens and travellers coming and going from the neatly "
     "kept wooden buildings.");
  SetListen( ([
     "default" : "Faint sounds of the city's commerce linger in the air.",
     ]) );
  SetSmell( ([
     "default" : "Small wafts of incense delight the senses.",
     ]) );
  SetItems( ([
     "road" : "The Duke's Road is paved with large stones, and continues "
       "to the north and southward out of town.",
     ({"stone","stones"}) : "These large stones have been worn smooth over "
       "the years from the trampling of citizens and travellers alike.",
     ({"spire","spires"}) : "Tall spires of the church reach into the sky "
       "providing a beacon of sorts, leading the congregation to it's "
       "sanctuary.",
     ({"building","buildings"}) : "Small neatly kept wooden buildings lie "
       "to the north, housing the shops and taverns of the small town.",
     ]) );

  SetItemAdjectives( ([
     "stone" : ({"large","smooth"}),
     "spire" : ({"tall"}),
     "building" : ({"wooden","small"}),
     ]) );
}
