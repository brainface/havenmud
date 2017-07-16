


#include <lib.h>
#include "../shrine.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the sanctuary in the Shrine of Ancients");
  SetLong("The sanctuary is decorated with mild"
          " red paint. The smooth walls appear to"
          " have been treated with a resin of sorts"
          " to give them a slight shine. The floor"
          " is made of a hard wood that has been"
          " polished enough to provide a clear"
          " reflection. In the middle of the room"
          " there is a small altar upon which a"
          " lotus bowl and an incense burner rest."
          " Under the altar is a small circular"
          " rug. The antechamber can be reached"
          " through a door in the north wall.");
  SetItems( ([
          ({ "rug" }) :
          "The rug is very beautiful. It has a"
          " geometrical pattern sewn into it"
          " with silver thread.",
          ({ "wall", "walls" }) :
          "The walls are very smooth with a slight"
          " shine.",
          ({ "floor" }) :
          "The floor is made of a hard wood that"
          " has been polished enough to provide"
          " a clear reflection.",
          ({ "door", "antechamber" }) :
          "The antechamber can be reached through"
          " a door in the north wall.",
          ({ "altar", "bowl", "burner" }) :
          "The altar is small and adorned with"

          " a small lotus shaped bowl and an"
          " incense burner.",
          ]) );
  SetItemAdjectives( ([
          "rug"   : ({ "cloth", "ornate" }),
          "wall"  : ({ "smooth", "shiny" }),
          "floor" : ({ "wood", "hard", "polished" }),
          "door"  : ({ "north" }),
          "altar" : ({ "small" }),
          "bowl"  : ({ "lotus", "small" }),
          ]) );                 
  SetSmell( ([
          "default" : "The smell of burning incense lingers.",
       ]) );
  SetExits( ([
           "north" : SHRINE_ROOM "antechamber",
        ]) );
  SetInventory( ([
           SHRINE_NPC "mirogu" : 1,
        ]) );
  SetProperty("no attack", 1);
  SetProperty("no magic", 1);
}
