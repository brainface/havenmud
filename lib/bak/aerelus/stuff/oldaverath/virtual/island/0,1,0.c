#include <lib.h>
#include <domains.h>
inherit AVERATH_LIB;

varargs static void create(int x, int y) {
  ::create(0,1);
  SetTown("Averath");
  SetShort("outside the Duke's Keep");
  SetLong("The Duke's Keep poses as an overwhelming shadow on this end "
     "of the Road. The Dukes' Road continues south back into the center of "
     "Averath, the busier section of town. On either side, the road branches "
     "off into small residential areas, that seem like toys under the loom "
     "of the keep.");
  SetListen( ([
     "default" : "The noise of the city is faint here.",
     ]) );
  SetSmell( ([
     "default" : "The air turns stagnate and musty here.",
     ]) );
  SetItems( ([
     "keep" : "Made of gigantic stone blocks, the keep seems to overwhelm "
       "this part of the Duke's Road. Quite old and only slightly well kept, "
       "mothers generally keep their children as far from the property as "
       "possible.",
     ({"road"}) : "The Duke's Road is paved with large stones, and "
       "continues south back to the crossroads and north out of town.",
     ({"stone","stones"}) : "These large stones have been worn smooth over "
       "the years from the trampling of citizens and travellers alike.",
     ]) );
  SetItemAdjectives( ([
     "stone" : ({"large","smooth"}),
     "road" : ({"paved"}),
     "keep" : ({"old","overwhelming"}),
     ]) );
     SetEnters( ([ "keep" : AVERATH_CITY + "keep1" ]) );
}
