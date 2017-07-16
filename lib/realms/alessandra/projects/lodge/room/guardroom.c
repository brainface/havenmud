#include <lib.h>
#include <lib.h>
#include "../lodge.h"
inherit LIB_ROOM;

int CheckGuard();
static void create() {
  room::create();
  
  SetAmbientLight(13);
  SetClimate("indoors");  
  SetShort("a gloomy hallway");
  SetLong(
     "This room has very poor lighting. The torches on the wall "
     "need to be re-lit. A stream of light comes from the room before. "
     "This room seems to be frightfully silent. The sights of murky walls "
     "and floors can be made out in this room."
     );
  SetSmell( ([
     "default" : "The vague scent of soil can be smelled here.",
     ]) );
  SetListen( ([
     "default" : "The sound of shifting armour can be heard.",
     ]) );
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
  SetInventory( ([
     L_NPC + "xindara" : 1,
     L_NPC + "rztsual" : 1,
     ]) );
  AddExit("south", L_ROOM + "pit", (:CheckGuard:));
  SetExits( ([
     "up" : L_ROOM + "basement.c",
     ]) );
}


int CheckGuard() {
  object who = this_player();
  object guard1 = present("rztsual", this_object());
  object guard2 = present("xindara", this_object());
  
  if(creatorp(who)) return 1;
  if(!(guard1)&&(guard2)) return 1;
  if(this_player()==(guard1)&&(guard2)) return 1;
  if((guard1)&&(guard2)->GetParalyzed()) return 1;
  if((guard1)&&(guard2)->GetSleeping()) return 1;
  if(who->GetInvis()) return 1;
  if(!living(guard1)&&(guard2)) return 1; 
  message("", who->GetName() + " tries to go south. ",
     this_object());
  guard1->eventForce("say You cannot go in there, Heathen!");
  guard2->eventForce("say Stand back you worm!");
  return 0;
}



 
