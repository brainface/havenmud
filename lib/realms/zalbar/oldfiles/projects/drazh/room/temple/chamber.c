// by Dahaka
// Aug 2004

#include <lib.h>
#include <domains.h>
#include "../../drazh.h"

inherit LIB_ROOM;


static void create() {
  room::create();
  SetTown("Drazh");
  SetClimate("underground");
  SetAmbientLight(10);
  SetShort("Chamber of the Thirteen");
  SetLong(
	   "Dark and oppressive, the dimensions of the cold stone circular "
	   "room are impossible to make out in the gloom, obscured in the "
	   "shadows. In the exact center of the room is a giant circle "
	   "embellished with the symbols of Melchezidek. Surrounding the circle, "
	   "there are thirteen thrones set at equal distances from one another. "
	   "The most elaborate and largest of the thrones is the thirteenth, "
	   "at the apex of the circle, opposite the door and raised on "
	   "dais. ");
  SetItems( ([
     ({"thrones" }) :
     "The largest throne is a twisted jagged monstrosity sprouting twisted "
     "and jagged ornate spires and the symbol of the Melchezidek hangs above "
     "it. The remaining thrones are smaller and less ornate, and above them "
     "hang their banners identifying the throne's occupant.",
     ({"small thrones","small throne"}) :
     "These thrones are smaller and less ornate than the larger one, and "
     "above each small throne hangs their banners identifying the throne's "
     "occupant.",
     ({"large throne","largest thron"}) :
     "The largest throne is a twisted jagged monstrosity sprouting twisted "
     "and jagged ornate spires and the symbol of the Melchezidek hangs above "
     "it. ",
     ({"room","chamber"}) : (: GetLong :),
     ({"shadow","shadows","dark"}) :
     "The shadows cling to the walls and ceiling to obscure the dimensions "
     "of the room.",
     
     ]) );
  SetItemAdjectives( ([
    
	  ]) );
  SetListen( ([
     "default" : 
     "Silence fills the room.",
     ]) );
  SetSmell( ([
     "default" : 
     "The stench of blood fills the air.",
     ]) );
  SetInventory( ([
	  V_NPC + "mayor" : 1,
	 ]) );
  SetExits( ([
	 "east" : V_ROOM + "temple/landing",
     ]) );

}