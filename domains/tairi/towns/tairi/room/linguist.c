#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetShort("inside a small house");
  SetAmbientLight(40);
  SetExits( ([
    "out" : "path10",
    ]) );
  SetLong("This house is a small but well furnished home of "
          "someone who obviously has wealth and taste. The thin "
          "paper walls of the house are lightly dyed, giving the "
          "room a slightly bluish tint. The floor is evenly polished "
          "hardwood which, given the lack of hardwoods in this area, "
          "must have cost a fortune. There is a comfortable looking "
          "sleeping mat against the far wall.");
  SetItems( ([
    ({ "house" ,"home" }) :
    	 (: GetLong :),
    ({ "wall", "walls" }) : 
    	 "The walls are a light shade of blue.",
    ({ "mat" }) : 
    	 "The sleeping mat is a soft down filled cushion.",
    ({ "floor" }) : 
    	 "The floor is a polished hardwood.",
    ]) );
  SetItemAdjectives( ([
    "house" : ({ "furnished", "small" }),
    "wall"  : ({ "thin", "paper", "dyed", "blue" }),
    "mat"   : ({ "comfortable", "looking", "sleeping" }),
    "floor" : ({ "polished" }),  
    ]) );
  SetInventory( ([
    TAI_RI_NPC "linguist" : 1,
    ]) );
  SetSmell( ([
     "default" : "The scent of flowers from outside permeates the air.",
  ]) );
  SetListen( ([
    "default" : "The room is quiet and peaceful.",
  ]) );
}
