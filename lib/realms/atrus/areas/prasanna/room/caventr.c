#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
  SetDomain("Valley");
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("entry to a deep cavern");
   SetLong("The walls of this cavern are smooth, save a few unearthly "
           "crystals jutting out at odd angles, gleaming with their own inner "
           "light. The glow casts shadows in every direction, accompanied by "
           "the sound of more crystals shattering underfoot. To the east the "
           "cavern continues at a slight incline, and a small stream trickles "
           "past.");
   SetItems( ([ 
      ({ "tiny crystals", "crystals","crystal" }) :
         "These are small crystals with an unearthly, mysterious glow. ",
      ({ "shadow","shadows" }) :
          "Shadows are formed all over the cave by the glowing crystals "
          "and give the area an eerie feeling.",
      ({ "walls", "wall" }) : 
         "The walls are smooth as if carved out long, long ago. ",
      ({ "small stream", "stream" }) : 
         "This is a tiny stream, not even enough water to get a decent "
         "drink.", 
      ({ "water","drink" }) :
         "There isn't even enough water here to get a drink.",   ]) );
   SetExits( ([ 
      "north" : PR_ROOM "/cint", 
      "out" : "/realms/tassadar/workroom", 
      //"out" : "/domains/valley/virtual/valleyrd/-9,0",
   ]) );
}
