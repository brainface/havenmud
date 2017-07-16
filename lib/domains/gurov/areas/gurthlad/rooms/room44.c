#include <lib.h>
inherit LIB_ROOM;
#include "../gurthlad.h"

static void create()  {
  room::create();
  
  SetClimate("indoors");
  SetShort("inside a large tent");
  SetLong("A large, hastily erected, cabin style tent. The canvas walls "
          "and ceiling let in a little light, allowing the interior of the tent to be "
          "seen. There are four bedrolls on the ground. Next to each bedroll "
          "is a standard issue frame pack containing personal effects.");
  SetObviousExits("out");
  SetExits( ([
          "out" : G_ROOMS + "/room38"]) );
  SetItems( ([
          ({ "tent", "cabin style tent" }) : "A large cabin style tent. Its walls "
          "and ceiling are made out of worn canvas.",
          ({ "canvas", "wall", "walls", "ceiling" }) : "The tent is made out of "
          "worn and patched canvas.",
          ({ "bedroll", "bedrolls" }) : "There are four bedrolls spread out on "
          "the ground of the tent. They are made out of wool and look very "
          "warm, as well as very heavy.",
          ({ "pack", "packs", "frame pack", "frame packs" }) : "Standard issue "
          "canvas packs with wooden frames. They contain the personal items "
          "of the owners, none of which are of any particular interest."]) );
  SetSmell( ([
          "default" :  "There is a smell of wood smoke."]) );
  SetInventory( ([
          G_NPC + "/human_explr" : 2]) );
  }
