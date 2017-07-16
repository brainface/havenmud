// Coded by Zeratul
// 1-26-2000
// Ninja tower tower4
#include <lib.h>
#include "../ninja.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetAmbientLight(35);
  SetClimate("indoors");
  SetShort("a training room");
  SetLong(
     "This room offshoots from the main part of the tower. The paper walls form "
     "around this room in a square shape. Training mats cover the floor, for this "
     "room is the training room where the ninjas train and spar with each other. "
     "The ceiling is higher here than the rest of the tower, as well as being "
     "the most well lit room in the tower. "
  );
  SetItems( ([
     ({"walls","tower","place"}) : (:GetLong:),
     ({"furnishings","items"}) : "Several colorful paintings and other art "
     "sculptures sit about in the far corners. They are on the walls as well as "
     "in all the corners, as they liven up the room and make it feel more at home.",
     ({"mats","training mats"}) : "Several well padded mats lie on the floor. "
     "They are used by the ninjas to soften blows to the ground from training "
     "and sparring. ",
  ]) );
  SetSmell( ([
     "default" : "The scent of incense is here. ",
  ]) );
  SetListen( ([
     "default" : "The sound of combat can be heard.",
  ]) );
  SetInventory( ([
     N_NPC "trainer" : 1,
     N_NPC "ninja_leader" : 1,
  // N_NPC + "ninja_trainer" : 1,
     N_NPC + "ninja3" : 4,

  ]) );
  SetExits( ([
     "west" : N_ROOM + "tower3",
  ]) );
  }
