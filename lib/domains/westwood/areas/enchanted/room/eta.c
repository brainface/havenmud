// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../balz.h"
#define OUT "/domains/westwood/virtual/soleilroad/0,5"

void TreeWink();
void TreeClose();
string LookKnot();

static void create() {
   room::create();
   
   SetShort("a dark forest path");
   SetLong("One tall tree stands in the middle of the path here, almost "
           "blocking out the light.  Gnarled branches come out of it at "
           "odd angles, intertwined with branches from other trees.  "
           "Dark, ominous shadows spring up around the path.  Small "
           "gaps in the thick trees appear to the west "
           "and northwest.  The forest opens up to the east.");
   SetItems( ([
                ({ "tall tree","tree","old tree","bark","surface" }) :
                   "Scratched and ancient bark peels off this old "
                   "tree in hunks.  Strange knots and swirled designs "
                   "in the bark cover its surface.",
                ({ "forest path","path","pathway" }) :
                   "Huge soiled tree roots tangle the path, making "
                   "it easier to trip.",
                ({ "huge soiled tree roots","huge soiled tree root","root",
                   "huge soiled roots","huge soiled root","huge root",
                   "soiled root","soiled roots","roots","tree roots",
                   "huge tree roots","huge tree root","tree root",
                   "soiled tree root","soiled tree roots","huge roots" }) :
                   "The roots rip up the pathway and make it uneven.",
                ({ "gnarled branches","branches","gnarled branch",
                   "branch","trunks","trunk" }) :
                   "Thick branches extend from all the trunks, "
                   "deeply mixed together, creating an enclosed "
                   "atmosphere.",
                ({ "other trees","trees","other tree","tree",
                   "thick trees","bark","surface" }) :
                   "The other trees are just like the tall one "
                   "in the center of the path, but smaller and "
                   "younger by look and feel.",
                ({ "dark ominous shadows","dark shadows",
                   "ominous shadows","shadow","dark shadow","ominous shadow",
                   "dark ominous shadow" }) :
                   "The trees and darkness make the shadows large and "
                   "eerie, jumping up in strange, ghoulish shapes.",
                ({ "small gaps","gaps","gap","small gap" }) :
                   "The trees seem to part purposefully to make a "
                   "pathway to walk through to the northwest and "
		   "west.  The forest opens up to the east.",
                ({ "strange ghoulish shapes","ghoulish shapes","shape",
                   "strange shapes","shapes","strange ghoulish shape",
                   "strange shape","ghoulish shape" }) :
                   "The ominous shadows create peculiar, eerie "
                   "shapes that twist and move almost like smoke.",
                ({ "tree knot","knot" }) :
                   "Strange knots mix and meld on the tall tree's "
                   "surface.",
           ]) );
   SetListen( ([
                 "default" : "The leaves rustle softly above.",
            ]) );
   SetSmell( ([
		"default" : "The dank scent of decomposition wafts "
			"lightly through the area.",
	]) );
   SetExits( ([
                "east" : OUT,
                "west" : B_ROOM + "/etc",
                "northwest" : B_ROOM + "/ete",
           ]) );
   SetInventory( ([
                    B_NPC + "/owl" : random(3)+1,
               ]) );
   call_out( (: TreeWink :), 60);
}

void TreeWink() {
   message("other_action","One of the knots in the tall tree "
      "opens, revealing an eye.\nThe eye peers around slowly, "
      "taking in its surroundings.",
      this_object());
   call_out( (: TreeClose :),20);
}

void TreeClose() {
   message("other_action","The eye slowly closes, fading into "
      "the tree as just another snarl to the wood.",this_object());
   call_out( (: TreeWink :), 300);
}