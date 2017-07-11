#include <lib.h>
#include "../rome.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(45);
   SetShort("the Diseased Room of the Faithful");
   SetProperty("no conjuring", 1);
   SetProperty("no attack", 1);
   SetProperty("no teleport", 1);
  SetProperty("no magic", 1);
   SetProperty("no steal", 1);
   SetNewsgroups( ({ "magic.ideas", "religion.thorian" }) );
   SetExits( ([
      "west" : "thorian_temple",
   ]) );
   SetLong("This is a quiet room for use by faithful followers of "
           "the Decayed One. This place is holy to those who follow him and "
           "is under his protection. The room is filled with various chairs and "
           "sofas for rest. A large fireplace lies embedded in the eastern "
           "wall heating the room.");
   SetItems( ([
      ({ "sofa", "chair", "sofas", "chairs", "furnishing", "furnishings" }) :
         "The furnishings are basic and functional which one would except "
         "to be used by clergy.",
      ({ "fireplace" }) : 
         "The fireplace is idle, yet looks ready at a moments notice "
         "to burst into flames.",
      ({ "wall" }) :
         "The eastern wall of this room contains a very large fireplace.",
   ]) );
   SetItemAdjectives( ([
      "furnishing" : ({ "basic", "functional", "comfortable",
                        "upholstered" }),
      "fireplace" : ({ "idle", "large" }),
      "wall" : ({ "east", "eastern" }),
   ]) );
   SetInventory( ([
   ]) );
   SetSmell( ([
      "default" : "The smell of rotting and decayed flesh fills the small room.",
    ]) );
   SetListen( ([
      "default" : "The sound of the crackling fire is the only sound in the room.",
   ]) );
}
