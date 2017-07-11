#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(35);
   SetShort("the nursery");
   SetLong("Two low beds with railings sit against the west wall, each "
           "with snuggly blankets neatly inside.  Beneath each is a small "
           "rug.  A brightly painted chest resides in the southeast "
           "corner, and a rocking chair is up against the north wall.  "
           "A couple small tapestries dcorate each wall with bright "
           "images like calm oceans and brown-eyed does.  A door leads out "
           "in the east wall.");
   SetItems( ([
                ({ "rocking chair","chair","north wall","wall",
                   "wooden chair", }) :
                   "The wooden chair is made on rockers, so that "
                   "one can rock back and forth in it.",
                ({ "brightly painted chest","painted chest","chest",
                   "southeast corner","corner" }) :
                   "The chest is secure in the southeast corner of the "
                   "room, colored with the basic primary colors:  "
                   "Red, blue, and yellow decorate the various parts of "
                   "the chest.",
                ({ "small rugs","rug","rugs","small rug","red rug",
                   "dark blue rug","blue rug" }) :
                   "The rugs match the colors of the beds they sit under, "
                   "only are a darker shade:  Under the pink bed is "
                   "a red rug, and under the baby blue bed is a dark "
                   "blue rug.",
                ({ "low beds with railings","low bed with railing",
                   "beds with railings","bed with railing","bed","beds",
                   "low bed","low beds","railings","railing","corner",
                   "blue blankets","blue blanket","pink blanket",
                   "pink blankets","blanket","blankets","west wall",
                   "wall","snuggly blankets","snuggly blanket","pink bed",
                   "baby blue bed","blue bed" }) :
                   "The beds are fairly close to the ground, but still "
                   "have railings posted on the edge to prevent falling.  "
                   "Each has its own corner, one in the northwest and the "
                   "other in the southwest.  Simple blue and pink blankets "
                   "are neatly made on the beds, quite fuzzy and warm "
                   "in appearance.  There is a rug under each.",
                ({ "nursery","room" }) :
                   (: GetLong :),
                ({ "small tapestries","small tapestry","tapestries",
                   "tapestry" }) :
                   "Each of the tapestries has something different "
                   "on it, and each wall has tapestries.  On the east "
                   "wall, there is a tapestry on the north and south, "
                   "while there is only one in the center of the "
                   "west wall.  The north and south walls both have "
                   "tapestries on the east and west areas, but the "
                   "south wall also has one in the middle.",
                ({ "south tapestries","south tapestry","tapestries",
                   "tapestry","south wall","wall","unicorn","bunny",
                   "field mouse","mouse" }) :
                   "Three tapestries are hung on the south wall; all "
                   "are of animals:  One is a bunny, another of a "
                   "field mouse, and the center one of a unicorn.",
                ({ "east tapestries","east tapestry","tapestry",
                   "tapestries","east wall","wall","beautiful doe",
                   "doe","brown eyes","eyes","eye","brown eye","forest",
                   "swans","swan","blue lake","lake" }) :
                   "One of the tapestries, to the north side of the "
                   "door, has a beautiful doe in it with lovely brown "
                   "eyes, standing and staring out from the edge of "
                   "a forest.  The other one, on the south side, "
                   "are some swans swimming in a blue lake.",
                ({ "north tapestries","north tapestry","north wall",
                   "tapestry","tapestries","sun","ocean","forest",
                   "evergreen forest","small evergreen forest",
                   "small forest","wall","calm ocean" }) :
                   "The one to the west side has a simple image of "
                   "the ocean, with a sun bearing down upon it; the "
                   "eastern one on the north wall is of a small "
                   "evergreen forest.",
                ({ "west tapestries","west tapestry","tapestry","tapestry",
                   "west wall","girl","boy","tree","apple","apple tree",
                   "large tree","leaves","leaf","wall" }) :
                   "The more northern of the two tapestries on the west "
                   "wall is of a girl sitting under a tree eating an "
                   "apple (it's probably an apple tree).  The southern "
                   "one is of a boy dangling from some large tree that "
                   "is covered with leaves.",
           ]) );
   SetExits( ([
                "east"  : VC_ROOM + "/llroom2",
           ]) );
   SetInventory( ([
                    VC_NPC + "/boy" : 1,
                    VC_NPC + "/girl" : 1,
                    VC_NPC + "/nanny" : 1,
               ]) );
}
