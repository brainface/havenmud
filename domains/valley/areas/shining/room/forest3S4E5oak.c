/* Shinning Forest Room 3S4E5Oak
 * Created by Ohtar
 */
#include <lib.h>
#include "../sf.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoor");
  SetShort("Inside a large oak tree");
  SetLong(
    "The inside of the oak tree is very well decorated. There is a small table with two chairs. "
    "In one corner is a small rocking chair with a warm blanket sitting on it. In another "
    "corner is a small chest. Against the back wall is a small bed. Everything in the room "
    "appears to be made of some sort of wood. The only possible exit is out into the forest. ");

SetItems( ([
     ({ "room" }) : 
    "The inside of the oak tree is very well decorated. There is a small table with two chairs. "
    "In one corner is a small rocking chair with a warm blanket sitting on it. In another "
    "corner is a small chest. Against the back wall is a small bed. Everything in the room "
    "appears to be made of some sort of wood. The only possible exit is out into the forest. ",
     ({ "bed", "small bed" }) : 
                  "The bed is rather small. It is made with several blankets and pillows. ",
     ({ "wall", "back wall" }) : 
                  "The wall was smoothly carved from the inside of the tree. ",
     ({ "walls" }) : 
                  "The walls were smoothly carved from the inside of the tree. ",
     ({ "chair", "rocking chair", "rocker"}) : 
                  "The chair is made of wood. It is very smooth and covered with a clear"
                  "finish. There is a small blanket sitting on it. ",
     ({"blanket", "warm blanket"}) : 
                  "The  blanket is made of a textile material. It is very colorful and appears "
                  "to be very warm. ",
     ({ "table", "small table" }) : 
                  "The small table is oddly designed. It has only three legs holding it up. "
                  "It is made of solid oak wood and covered with a clean finish. ",
     ({ "chest", "small chest" }) : 
                  "The small chest is made up of wood. It does however have a metal lock "

                  "to keep anything inside secured. ",
     ({ "chair", "chairs" }) : 
                  "The two chairs are made of wood. They appear to be just normal chairs. ",
  ]) );


SetListen( ([ "default" : "The sounds of leaves blowing can be heard here.",   
  ]) );
SetSmell( ([ "default" : "The overpowering smell of flowers floats in the air.",

  ]) );
SetInventory( ([
        SF_NPC + "/princess" : 1,
        SF_OBJ + "pchest" : 1,
  ]) );

SetExits( ([
    "out" : SF_ROOM "forest3S4E4",      
  ]) ) ;
}

