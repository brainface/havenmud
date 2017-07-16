// Title: Durgoroth Town
// File: road09.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1997
// Abstract: East-west road inside the town of Durgoroth
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("east west road in Durgoroth");
	SetDayLong("This road continues to the east towards the wall of the "
		"fortress, and to the west towards the center of the town. "
		"To the north stands the Durgoroth post office, and to the south "
		"the Durgoroth bank. To the northeast is the large columned "
     "building of the Durgoroth Library.  To the southeast is a small house.");
	SetNightLong("This road continues into the darkness to the east and "
		"west. To the north stands the Durgoroth post office, and to the "
		"south the Durgoroth bank. The the northeast looms the large "
                  "columned structure that houses the Durgoroth library.  "
          "A small house stands to the southeast.");
	SetObviousExits("east, west");
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
		({"Durgoroth library", "library", "columned building",
		"columned structure" }) : "The large ornate stone edifice "
			"houses the knowledge of the town, as well as a few "
			"carefully guarded tomes from the previous inhabitants "
			"of the fortress. It is also the place from which "
			"many of the town's scholars do buisiness.",
		]) );
 AddItem(({"small house", "house"}), "It is a small house ");
	SetExits( ([
		"east" : D_ROOM+"/road10",
		"west" : D_ROOM+"/road08",
		]) );
	SetEnters( ([
		"post office" : D_ROOM+"/p_office",
		"bank" : D_ROOM+"/bank",
		]) );
	}
