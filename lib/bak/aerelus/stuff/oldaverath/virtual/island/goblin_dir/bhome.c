#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("indoors");
  SetAmbientLight(0);
  SetShort("an old maintenance room");
  SetLong("This now abandoned room used to serve as a maintenance room "
     "for the sewers. Near empty shelves line the eastern wall, and large "
     "wooden barrels are stacked along the other. The room smells of dirt "
     "and human waste, and in the dark corner you can make out what "
     "appears to be bedding. Scattered trash and a few ashes from previous "
     "fires, lead to the conclusion that a family of beggars now occupy "
     "this room.");
  SetListen( ([ 
     "default" : "The scratching of rodents echos through the room."
     ]) );
  SetSmell( ([
     "default" : "The smell of dirt and human waste is overpowering."
     ]) );
  SetItems( ([
     ({"shelf","shelves"}) : "These old wooden shelves are near collapsing, "
       "and are covered in a thick layer of dust. Small empty boxes are "
       "scattered across the shelves.",
     ({"barrel","barrels"}) : "The wooden barrels contents are unknown "
       "as the writing on them is faded and can no longer be read. They "
       "are stacked a few high and line one of the walls.",
     ({"bedding"}) : "Old rags and blankets lie in heaps on the floor, "
       "making a bedding of sorts for the vagrants that live here.",
     ({"trash","floor"}) : "The floor is covered in dirt and trash from "
       "the rooms current occupants. Some of the trash looks like it's "
       "been dragged in from the sewer tunnels.",
     ({"ash","ashes"}) : "These ashes are the remains of a few small "
       "fires.",
     ]) );
  SetItemAdjectives( ([
     "shelf" : ({"empty","wooden","old"}),
     "barrel" : ({"wooden","stacked"}),
     ]) );
  SetExits( ([
     "out" : AVERATH_UNDERGROUND "-1,1,-2",
     ]) );
  SetInventory( ([
     AVERATH_OBJ "torch" : 1,
     ]) );
}
