//Selket@Haven
//2006
#include <lib.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("the Bedroom at the Blue Lotus Inn");
   SetExits( ([
      "down" : "inn",
   ]) );
   SetClimate("indoors");
   SetAmbientLight(30);
   SetLong("This is a small, yet common bedroom at the Blue Lotus "
           "Inn of Lisht. The noise of the city and downstairs is "
           "nicely muffled, and the cots are soft and springy. A "
           "comfortable place to sleep in peace.");
   SetProperty("no attack",1);
   SetProperty("no bump", 1);
   SetProperty("no magic", 1);
   SetItems( ([
      ({ "inn" }) :
         "This room is part of the Blue Lotus Inn." ,
      ({ "cot", "cots" }) :
         "The cots are large enough for anyone to sleep on.",
   ]) );
   SetItemAdjectives( ([ 
      "bedroom" : ({ "rupert's" }),
      "cot" : ({ "springy", "soft" }),
   ]) );
  SetSmell("The smell is soporific.");
  SetListen("The silence is soporific.");
}
