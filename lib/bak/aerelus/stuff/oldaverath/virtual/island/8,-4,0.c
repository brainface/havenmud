//Lilavae
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("a bright part of the forest");
   SetDayLong("Shining rays of sunlight focus on the soft carpet of "
	      "gold and green leaves.  Surrounded by saplings, this small "
              "part of the forest glows with the sunlight.  A large grey "
	      "rock lays underneath the largest tree.  The rock has been "
              "carved by the elements into a throne-like shape.  A path "
	      "lined with small lilac flowers runs in all four cardinal "
	      "directions. ");
   SetNightLong("The saplings that surround this small section of the "
                "forest shine in the moonlight.  The entire area is "
                "sharply etched in silver.  A cloud of lilac flowers "
		"blooms at the edge of the small path that runs through "
		"the clearing.  A throne-shaped rock throws dark shadows "
		"against the trunks of the surrounding trees. ");
   SetItems( ([
	      ({ "part","forest","section","area","clearing" }) :
		 (: GetLong :),
	      ({ "rays","sunlight","sun" }) :
		 "Golden sunlight streams through the leaves of the "
		 "surrounding saplings, playing across the long grassy "
		 "forest floor. ",
	      ({ "carpet","leaves" }) :
		 "Lovely warm hues of gold and green lay pooled along the "
		 "ground as fallen leaves.  Each leaf bursts with soft "
		 "shining color. ",
	      ({ "saplings","trees" }) :
		 "The miniature trees that surround this clearing come "
		 "in two distinctly different varieties.  Most of the "
		 "saplings are topped with long strands of light green "
                 "leaves, while others carry brightly coloured leaves of  "
		 "red and gold. ",
	      ({ "rock","throne","shape" }) :
		 "This unusual rock stands proudly underneath the largest "
		 "sapling in the clearing.  Shaped by the fierce elements, "
                 "this unusual rock looks exactly like a royal "
		 "throne. ",
	      ({ "tree" }) : 
		 "This massive tree is like a giant among dwarves. Much "
		 "higher than the surrounding saplings, the large tree "
		 "reaches toward the sky with thick, gnarled branches. ",
	      ({ "path" }) : 
		 "This small dirt path runs to the north, south, east, and "
		 "west.  It is unremarkable, except for the lovely purple "
		 "flowers that line it. ",
	      ({ "lilac","lilacs","flower","flowers","cloud","edge" }) : 
		 "Dainty looking, these lilac flowers are delicately "
		 "tinged a soft purple color.  Small and unobtrusive, they "
		 "line the dirt path that cuts through the clearing. ",
	      ({ "moonlight","silver" }) : 
		 "Thick beams of moonlight illuminate the entire clearing "
                 "and outline every shape here with thick lines of " 
                 "silver. ", 
	      ({ "shadows","trunks" }) : 
                 "Creating a lovely contrast of silver and black, the "
		 "shadows thrown upon the trunks of the trees seem warm, "
		 "and vibrant, rather than ominous. ",
           ]) );
   SetItemAdjectives( ([
                         "rays" : ({ "shining" }),
                         "carpet" : ({ "soft" }),
                         "leaves" : ({ "gold","green" }),
                         "part" : ({ "small" }),
                         "rock" : ({ "grey","large","shaped","throne",
                                     "throne-like" }),
                         "tree" : ({ "largest" }),
                         "path" : ({ "lined","small" }),
                         "flowers" : ({ "lilac","small","blooming" }),
                         "section" : ({ "small" }),
                         "area" : ({ "entire" }),
                         "shadows" : ({ "dark" }),
                         "trees" : ({ "surrounding" }),
                    ]) );
   SetListen( ([
                 "default" : "The only sound is the rustling of the "
			     "leaves underfoot. ",
            ]) );
   SetSmell( ([
                "default" : "Fresh air wafts through the clearing. ",
           ]) );
   SetExits( ([
                "north" : AVERATH_ISLAND + "8,-3,0",
                "south" : AVERATH_ISLAND + "8,-5,0",
                "west" : AVERATH_ISLAND + "7,-4,0",
                "east" : AVERATH_ISLAND + "9,-4,0",
           ]) );
}
