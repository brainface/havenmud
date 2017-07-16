#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("a western passage off the Great Hall");
	SetClimate("underground"); SetWarmth(45);
  SetProperty("no teleport",1);
  SetProperty("no conjuring",1);	
	SetExits( ([
	  "east" : G_ROOM "gh_north",
	  ]) );
	SetSmell( ([
	  "default" : "The smell of good dwarven cooking comes from the inn.",
	  ]) );
	SetListen( ([
	  "default" : "Music comes from the hall to the north.",
	  ]) );
	SetLong(
	  "The Great Hall lies to the east, but here the passage is slightly "
	  "smaller and less filled. The walls of the passage are still smooth, "
	  "but without the polished shine that the Great Hall offers. Lying in "
	  "the northern wall is the Glimmerdin Orchestral Hall, the center of "
	  "dwarven music. Built into the western wall is a cozy looking inn."
	  );
	SetItems( ([
	  ({ "wall", "walls" }) : 
	    "The walls are smooth stone without the polish of the Great Hall.",
	  ({ "hall" }) :
	    "The Glimmerdin Orchestral Hall is home to musical talent.",
	  ({ "inn" }) :
	    "The inn seems small but friendly.",
	  ]) );
	SetItemAdjectives( ([
	  "wall" : ({ "smooth", "stone" }),
	  "hall" : ({ "music", "orchestral", "glimmerdin" }),
	  "inn"  : ({ "cozy", "looking", "small", "friendly", }),
	  ]) );
	SetEnters( ([
	  "inn"  : G_ROOM "inn",
	  "hall" : G_ROOM "music_hall",
	  ]) );
	SetInventory( ([
	  ]) );
}