
/*Cabin Room Added by Aless so that
  stairs in cabin_foyer made sense
*/

#include <lib.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetDomain("Estergrym");
  SetClimate("indoors");
  SetShort("A cabin room");
  SetLong("This upper floor of the cabin serves as the sleeping area "
     "with a wooden double bed against the far wall and a smaller bed "
     "opposite it. A small chest of drawers sits under the window and "
     "holds a small lantern and various sundries. The window shutters "
     "are open, letting the faded hanging curtains flutter with the "
     "breeze. The stairs lead back down to the main floor. "
     );
  SetListen( ([
     "default" : "Soft rustling can be heard.",
     ]) );
  SetSmell( ([
     "default" : "The air smells of evergreen wood.",
     ]) );
  SetItems( ([
     ({"stair", "stairs"}) : "The wooden stairs are made of the same "
       "evergreen wood that the rest of the cabin has been built from. "
       "They lead down to the first level within the cabin.",
     ({"shutter", "shutters"}) : "Wooden shutters frame the windows and "
       "open to offer fresh air from outdoors and natural light.", 
     ({"window", "windows"}) : "These windows look out from the cabin and "
       "provide a pleasant breeze from outside. Faded curtains hang over "
       "them, diffusing the light from outside.",
     ({"walls","wall"}) : "The walls are made of a sturdy, evergreen wood "
       "that looks strong enough to protect well from the outside elements. "
       "Small shuttered windows in the walls allow for light and fresh air.",
     ({"ceiling"}) : "The ceiling could use a little broom-work. A small "
       "floating cobweb spins in the breeze, glinting from the light "
       "spilling in the windows.",
     ({"floor", "ground"}) : "The wooden floor is worn in spots from foot "
       "traffic.",
     ({"bed", "beds"}) : "Wooden frames surround both beds, hand-carved and "
       "nicked in places from time and use. Multi-colored quilts cover both "
       "beds.",
     ({"cobweb"}) : "Small strands of web dangle from the ceiling, spinning "
       "and floating in the breeze. The light from the windows make it glint "
       "softly.",
     ({"lantern"}) : "A small metal lantern rests here, crudely made and currently "
       "extinguished.",
     ({"chest", "chest of drawers"}) : "This small, wooden chest of drawers are "
       "well worn from the years. The detailed woodwork is nearly faded from time "
       "and use.",
     ({"sundries"}) : "Miscellaneous knick-knacks are scattered about the top of "
       "the chest of drawers. Nothing important to note.",
     ({"quilt", "quilts"}) : "Multi-colored patches of cloth have been stitched "
       "together and, in places, hand tied to make these quilts.",
     ({"frame", "frames"}) : "The wooden frame of the bed has been hand carved "
       "and is marred with small nicks and dents from age and use.",
     ({"curtain", "curtains"}) : "The cloth from these curtains is nearly "
       "threadbare. Faded from the sun, the original color cannot be distinguished "
       "any longer.",
     ]) );
  SetAmbientLight(30);
  SetItemAdjectives( ([
     "stair" : ({"wood","wooden", "evergreen"}),
     "wall" : ({"sturdy", "strong", "wooden", "wood"}),
     "ceiling" : ({"wood"}),
     "shutter" : ({"wood", "wooden", "open"}),
     "window" : ({"wood", "wooden", "open", "shuttered"}),
     "curtain" : ({"faded", "cloth",}),
     "floor" : ({"wood", "wooden", "worn"}),
     "cobweb" : ({"small", "glinting", "spinning"}),
     "bed" : ({"wood", "wooden", "double", "small", "smaller"}),
     "chest" : ({"small", "wood", "wooden", "worn"}),
     "lantern" : ({"small", "metal"}),
     "sundries" : ({"various"}),
     "quilt" : ({"cloth", "multi-colored"}),
     "frame" : ({"wood", "wooden"}),
     "curtain" : ({"hanging", "faded", "threadbare"}),  
     ]) );
  SetInventory( ([
     LAKE_NPC + "/garion" : 1,
     ]) );
  SetDoor("out", LAKE_OBJ + "/cabin_door");
  SetExits( ([
     "down" : LAKE_ROOM + "/cabin_foyer",
     ]) );
}
