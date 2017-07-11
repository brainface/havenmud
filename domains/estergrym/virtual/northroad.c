#include <lib.h>
#include <domains.h>
#include <std.h>
inherit LIB_ROOM;

void Setup(int, int);

static void create(int x, int y) {
  string n, s, e, w, ne, sw, nw, se;
  string lng, shrt;
  ::create();
  n = s = e = w = ne = se = nw = sw = 0;
  /* Basic Setup Stuff */
  lng = "The North Road continues, passing alongside the "
        "Estergrym Mountains to the east. Far to the west, "
        "the plains of Estergrym stretch out nearly to the "
        "horizon.";
  shrt = "the North Road";
  if (y >= 0 && y < 40 && y != 20) {
  	n = ESTERGRYM_VIRTUAL "northroad/" + x + "," + (y + 1);
  	lng += " The road continues off to the north from here.";
  	}
  if (y > 0 && y <= 40 && y != 21) {
  	s = ESTERGRYM_VIRTUAL "northroad/" + x + "," + (y - 1);
  	lng += " The road continues off to the south from here.";
  	}
  /* Specific Room Stuff */
  if (x == 0 && y == 0) {
  	s = HAVENWOOD_VIRTUAL "havenwoodroad/165,165";
  	lng += " Off to the south the road becomes the HavenWood road.";
  }
  if (y == 20) {
  	ne = ESTERGRYM_VIRTUAL "northroad/" + (x + 1) + "," + (y + 1);
  	lng += " The road continues to the northeast.";
  	e  = ESTERGRYM_VIRTUAL "grymxoria_road/0,0";
  	lng += " Another road seems to head off to the east through the "
  	       "mountains.";
        nw = ESTERGRYM_AREAS "tulu/room/path01";
        lng += " A thin path leads off to the northwest as it "
               "climbs towards a hill in the distance.";
  	}
  if (y == 21) {
  	sw = ESTERGRYM_VIRTUAL "northroad/" + (x - 1) + "," + (y - 1);
  	lng += " The road continues to the southwest.";
  	}
  if (y == 40) {
  	w = GUROV_VIRTUAL "gurovrd/40,0";
  	lng += " A path across the plains and into the lands of the Prince of Gurov lies "
  	       "to the west.";
  	}	
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);
  if (nw) AddExit("northwest", nw);
  if (ne) AddExit("northeast", ne);
  if (sw) AddExit("southwest", sw);
  if (se) AddExit("southeast", se);
  SetLong(lng);
  SetShort(shrt);
  Setup(x, y);
}
 
void Setup(int x, int y) {
	mapping inv = ([ ]);
	string smell = "", listen = "";
	mapping items = ([ ]);
	mapping itemadj = ([ ]);
	smell  = "A hazy fog wisps around from the mountains.";
	listen = "The silence is broken by the occasional howl of a wolf.";
	items += ([ ({ "mountain", "mountains" }) :
	               "The Estergrym Mountains are large, black spires that "
	               "rise into the sky like deranged, disfigured claws. Their "
	               "peaks stretch into the sky as if clasping for something." ]);
	itemadj += ([ "mountain" : ({ "estergrym" }) ]);
	items += ([ "fog" : "The fog is thin but disconcerting." ]);
	itemadj += ([ "fog" : ({ "hazy", }) ]);
        if (x == 0 && y == 20) inv += ([ ESTERGRYM_VIRTUAL "sign/northroad020" : 1 ]);
        if (x == 1 && y == 40) inv += ([ ESTERGRYM_VIRTUAL "sign/northroad140" : 1 ]);
	
	/* Set the values */
	SetItems(items);
	SetItemAdjectives(itemadj);
	SetInventory(inv);
	SetSmell("default", smell);
	SetListen("default", listen);
	return;
}
