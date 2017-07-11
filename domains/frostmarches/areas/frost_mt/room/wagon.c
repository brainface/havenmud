//
// An old wagon
// Created by Zaxan@Haven
// 23rd of November, 1997
//

#include <lib.h>
#include "path.h"

inherit LIB_ROOM;

static void create() {
	room::create();
	SetClimate("indoors");
	SetAmbientLight(40);
	SetShort("inside an old wagon");
	SetLong("This old wagon in the valley is completely ruined. "
		"Pictures of various explorers hang on the walls, while "
		"their skeletons lie on the ground. Empty jars of food "
		"and empty canteens sit on a nearby table, gathering "
		"cobwebs. A broken window in the eastern wall provides "
		"a view to the valley outside. Amazingly, and old lantern "
		"sitting on the floor is still burning dimly.");
	SetItems( ([ ({ "old wagon in the valley",
			"wagon in the valley",
			"old wagon", "wagon" }) : (: GetLong :),
		     ({ "pictures of various explorers",
			"picture", "pictures" }) : "These pictures of "
						   "now deceased explorers "
						   "hang all over the place "
						   "showing their past "
						   "accomplishments.",
		     ({ "thin cobweb", "thin cobwebs",
			"cobwebs", "cobweb" }) : "These thin cobwebs "
						 "cover everything in the "
						 "wagon almost completely.",
		     ({ "skeletons of many famous explorers",
			"skeletons", "skeleton" }) : "The skeletons of "
						     "many famous "
						     "explorers sit "
						     "decaying on the "
						     "floor in the bitter "
						     "cold.",
		     ({ "wooden floor", "wooden ground",
			"ground", "floor" }) : "This floor is made out of "
					       "now ruined wood. Many "
					       "skeletons are scattered "
					       "over it.",
		     ({ "empty canteen", "empty canteens",
			"canteens", "canteen" }) : "Now empty, they were "
						   "once supposed to hold "
						   "water.",
		     ({ "jar of foods", "jar of food",
			"jar", "jars" }) : "These jars don't even have a "
					   "crumb in them.",
		     ({ "old table",
			"table" }) : "This table sits in a small corner "
				     "Many canteens and jars sit on it, "
				     "gathering cobwebs.",
		     ({ "snowy valley",
			"valley" }) : "This snowy valley stretches far "
				      "out and away from the wagon. A "
				      "mine shaft can be seen on the other "
				      "side.",
		     ({ "mine shaft", "shaft" }) : "This dark mine shaft "
						   "drills deep into the "
						   "side of the valley.",
		     ({ "broken window", "window" }) : "This window "
						       "provides a way to "
						       "view the large "
						       "valley outside.",
		     ({ "old lantern", "lantern" }) : "This old lantern "
						      "is still slightly "
						      "burning, providing "
						      "a little light." ]));
	SetObviousExits("out");
	SetExits( ([ "out" : ROOM "/valley" ]) );
	SetInventory( ([ OBJ "/journal" : 1,
			 NPC "/explorer" : random(3)+1 ]) );
}
