#include <lib.h>
#include <lib.h>
#include "../lodge.h"
inherit LIB_ROOM;

int CheckGuard();
static void create() {
  room::create();
  SetShort("a gloomy hallway");
  SetDayLong("This room has very poor lighting. The torches on the wall "
        "need to be re-lit. A stream of light comes from the room before. "
       "This room seems to be frightfully silent. The sights of murky walls "
        "and floors can be made out in this room.");
   SetNightLong("This room has very poor lighting. The torches on the wall "
        "need to be re-lit. There is no other light source in here. This "
       "room seems to be frightfully silent. The sights of murky walls "
        "and floors can be made out in this room.");
  SetAmbientLight(13);
  SetClimate("indoors");  
  SetItems( ([
        ({"room","entrance","entryway","entry"}) : (:GetLong:),
        ({"torch","torches"}) :  "These torches look like they have been "
        "burning for sometime.  They are made out of decaying bones and"
        "they barely light the room.",
        ({"floor","wall","walls"}) : "By the look of these, this room is definatley "   
        "underground. These are made out of dirt and it is starting to crumble.  "
        "It leaves a muddy soil on the floor.",
  ]) );
  SetItemAdjectives( ([
     "wall" : ({"crumble"}),
  ]) );
  SetExits( ([
      "up" : L_ROOM + "basement.c",
  ]) );
  AddExit("south", L_ROOM + "pit");
  SetInventory( ([
  L_NPC + "xindara" : 1,
  L_NPC + "rztsual" : 1,
  ]) );
  SetSmell( ([
        "default" : "The vague scent of soil can be smelled here.",
  ]) );
  SetListen( ([
      "default" : "The sound of shifting armour can be heard.",
  ]) );
}

int CheckGuard() {
  object who = this_player();
/*
  object nosferatu = present("guardroom_blocker", this_object()); 
  if (!nosferatu) return 1;
  if(nosferatu->GetParalyzed()) return 1;
*/
  if(creatorp(who)) return 1;
  if(who->GetRace() !="nosferatu") {
    message("system", "A mystic force prevents you.",
  this_object());
/*
  nosferatu->eventForce("!say You're not allowed to go in there!");
  nosferatu->eventForce("attack" + this_player()->GetKeyName());
*/
  return 0;
}
  return 1;
}
