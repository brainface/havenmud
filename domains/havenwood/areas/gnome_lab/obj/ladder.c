#include <lib.h>
#include <climb.h>
#include "../gnome_lab.h"
inherit LIB_DUMMY;
inherit LIB_CLIMB;
 
static void create() {
  dummy::create();
  SetKeyName("ladder");
  SetId( ({"ladder"}) );
  SetAdjectives( ({"long","wooden"}) );
  SetShort("a long wooden ladder");
  SetLong(
	  "This long wooden ladder look very sturdy, as it is strapped "
	  "to the tree. The ladder goes from the clearing to the "
	  "branch supporting someone's house.");
  SetClimb(G_ROOM + "clearing", CLIMB_DOWN);
  SetClimb(G_ROOM + "tree1", CLIMB_UP);
}
