#include <lib.h>
#include "../lodge.h"
inherit LIB_ROOM;

 static void create() {
   room::create();
  SetShort("a musty staircase");
  SetDayLong("These stairs are very fragile-looking. The wood is "
         "decaying and some of the stairs have eroded away from the "
        "staircase completely. A small door is made out at the top "
        "of these stairs. It is the entrance to the annex. Looking back, "
         "the stairs seem to have faded if it were not for the tiny bit of "
         "sunlight and candles from below, they would not be able to be seen.");
  SetNightLong("These stairs are very fragile-looking. The wood is "
         "decaying and some of the stairs have eroded away from the "
        "staircase completely. A small door is made out at the top "
        "of these stairs. It is the entrance to the annex. Looking back, "
         "the stairs seem to have disappeared and become one with the "
         "darkness.");
   SetAmbientLight(13);
   SetClimate("indoors");
   SetItems( ([
         ({"room","staircase"}) : (:GetLong:),
         ({"stair","stairs"}) : "These stairs are old and crusty.  They are "
         "breaking off and becoming nothing but decaying wood.  They "
         "can not support much weight so it would be a good idea to not"
         "linger on them for long.",
        ({"annex"}) : "The lodge annex is on the other side of the door.",
   ]) );
   SetItemAdjectives( ([
         "stairs" : ({"old","crusty"}),
   ]) );
  SetDoor("annex", L_ROOM + "annexdoor.c");
  SetEnters( ([ "annex" : L_ROOM + "annex" ]) );
   SetExits( ([
         "down" : L_ROOM + "hallway.c",
   ]) );
   SetSmell( ([
         "default" : "It smells of dust in here.",
   ]) );
   SetListen( ([
         "default" : "The sound of creeking stairs bring attention to the ears.", 
   ]) );
 }
