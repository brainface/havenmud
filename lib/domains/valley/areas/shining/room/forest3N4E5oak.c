/* Shinning Forest Room 3N4E5Oak
 * Created by Ohtar
 */
#include <lib.h>
#include "../sf.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("Inside a large oak tree");
  SetLong(
    "The inside of the oak tree is not very well decorated. There "
    "is a small beat up table with two broken chairs against the "
    "back wall. In the back corner there is a small chest. Against "
    "one wall is a small dusty looking bed. Everything in the room "
    "appears to be made of some sort of wood. The only possible exit "
    "is out into the forest. ");

SetItems( ([
     ({ "room" }) : 
    "The inside of the oak tree is not very well decorated. There "
    "is a small beat up table with two broken chairs against the "
    "back wall. In the back corner there is a small chest. Against "
    "one wall is a small dusty looking bed. Everything in the room "
    "appears to be made of some sort of wood. The only possible exit "
    "is out into the forest. ",
     ({ "bed", "small bed" }) : 
                "The bed is rather small. It is made with several "
                "blankets and pillows. Everything on the bed looks "
                "very dusty and dirty. ",
     ({ "wall", "back wall" }) : 
                "The wall was smoothly carved from the inside of "
                "the tree. ",
     ({ "walls" }) : 
                "The walls were smoothly carved from the inside of "
                "the tree. ",
     ({ "table", "small table" }) : 
                "The small table is oddly designed. It has only "
                "three legs holding it up. It is made of solid oak "
                "wood and covered with a clear finish. However there "
                "are many scratches and chunks missing from the finish. ",
     ({ "chair", "chairs" }) : 
                "The two chairs are made of wood. Both chairs are "
                "missing Several pieces of wood from the back rests. "
                "The legs also appear to be splintering. ",
  ]) );


SetListen( ([ "default" : "The sounds of leaves blowing can be heard "
                          "here.",   
  ]) );
SetSmell( ([ "default" : "The overpowering smell of flowers floats in "
                         "the air.",
  ]) );
SetInventory( ([
        SF_NPC + "/prince" : 1,
        SF_OBJ + "/chest" : 1,
        SF_NPC + "/garis"  : 1,
  ]) );

SetExits( ([
    "out" : SF_ROOM "forest3N4E4",      
  ]) ) ;
}
