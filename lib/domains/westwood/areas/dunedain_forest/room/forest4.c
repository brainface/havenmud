/*   Added SetItemsAdjectices and cleaned up SetItems
     Zalbar 8-08
 */


#include <lib.h>
#include "../forest.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetDomain("Estergrym");
    SetClimate("temperate");
    SetShort("at the end of the woods");
    SetLong(
      "Only a few small trees are scattered here and there and the grass "
      "is much sparser here than it is to the east.  Further to the east "
      "the trees and greenery come together to form a dense forest.  To "
      "the west, a large mountain looms.  Dark crevices can be made out "
      "on the sides of the mountain.  The path curves northwest towards "
      "the mountain and east towards the forest.");
    SetListen( ([ "default" : "All is strangely silent here."]) );
    SetItems( ([
	    "path" :  (: GetLong() :),
	    ({ "trees","tree","forest","greenery" }) :
	    "The trees and grass are quite sparse here, but get denser "
	    "further to the east.",
	    ({"mountain", "crevices","shelter" }) :
	    "A large mountain stands to the west.  Crevices that may "
	    "be used as shelter jut into it."
      ]) );
    SetItemAdjectives( ([
      "path"     : ({"winding","forest","small"}),
      "trees"    : ({"small","scattered","dense"}),
      "mountain" : ({"large","looming"}),
      "crevice"  : ({"dark"}),
      ]) );
    SetExits( ([
	    "northwest" : F_ROOM "forest5",
	    "east"      : F_ROOM "forest3",
      ]) );

}