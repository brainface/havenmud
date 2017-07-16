// Title: Durgoroth Town
// File: road10.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1997
// Abstract: East end of the east-west road inside the town of Durgoroth
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("near the east wall of Durgoroth");
	SetDayLong("This road ends at the edge of the eastern wall here, but "
		"continues into to town to the west. A small stair leads from the "
		"edge of the road up to the top of the wall. To the northwest is "
		"the Durgoroth post office, and to the southwest the Durgoroth "
		"bank. To the north stands the large columned structure of the "
		"Durgoroth library. Its dark gray stone contrasting against "
"the sparkling snow of the mountain above.  A small house stands to the south.");
	SetNightLong("This road ends at the edge of the eastern wall here, "
		"but continues off into the darkness to the west. A small "
		"stair leads from the edge of the road up to the top of "
		"the wall. To the northeast is the Durgoroth post office, "
		"and to the southeast the Durgoroth Bank. To the north stands "
		"the massive black form of the Durgoroth library. A faint "
"light coming from its shaded windows.  A small house stands to the south.");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
		"road" : "The cobblestone road runs from the east wall "
			"through the center of the town, to the west wall.",
		({"durgoroth post office", "post office", "office" }) :
			"The small stone building houses the post office "
			"of the town, where its citizens can send and "
			"recieve mail.",
		({"durgoroth bank", "bank" }) : "The large imposing stone "
			"building houses the Durgoroth bank, where the "
			"citizens of the town can deposit and exchange their "
			"coins.",
		({"durgoroth library", "library", "columned building",
		"columned structure" }) : "The large ornate stone edifice "
			"houses the knowledge of the town, as well as a few "
			"carefully guarded tomes from the previous inhabitants "
			"of the fortress. It is also the place from which "
			"many of the town's scholars do buisiness. The "
			"building is made of gray stone blocks, with a large "
			"colonade running up its front.",
		({"eastern wall", "wall"}) : "The massive walls of ancient, "
			"weather worn black stone surround the town.",
		({"small stair", "stair", "staircase" }) : "A small, worn, stair "
			"of cut stone blocks leads up from the edge of the road to "
			"the top of the wall.",
		"mountain" : "The mountain looms above, the upper pinnicles "
			"covered with deep snow.",
		]) );
             AddItem(({"small house", "house"}), "It is a small house ");
	SetExits( ([
		"west" : D_ROOM+"/road09",
		"up" : D_ROOM+"/wall14",
		]) );
	SetEnters( ([
		"library" : D_ROOM+"/library",
          "house" : D_ROOM + "/p_house_3",
       "small house" : D_ROOM+"/p_house_3",
		]) );
	}
