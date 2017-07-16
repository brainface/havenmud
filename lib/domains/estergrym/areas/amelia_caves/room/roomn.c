// Amelia@Haven

#include <lib.h>
#include <std.h>
inherit LIB_FISHING;
#include "../cave.h"
 
static void create() {
   fishing::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("a dry ledge");
   SetLong("The bridge has taken you across to a small ledge, where "
           "one can sit and fish.  There is a door in the rock "
           "to the south.");
   SetItems( ([
                ({ "stepping stone bridge","bridge" }) :
                   "The bridge is more like a path of "
                   "stones going from one end of the creek to the "
                   "other.",
                ({ "bridged creek","creek" }) :
                   "The little stream is full of strange "
                   "shapes which are most likely fish.",
                ({ "strange shapes","shapes","shape",
                   "strange shape" }) :
                   "The shapes are deffinitely some strange fish.",
                ({ "strange fish","fish" }) :
                   "The little fish have no eyes, instead, "
                   "there are strange bumps where the eyes should "
                   "have been.",
                ({ "creek water","water" }) :
                   "The water floats by in a liquid-like manner.",
                ({ "strange bumps","bumps","eyes","eye","bump","strange bump" }) :
                   "The bumps are just spots on "
                   "the fish that would be eyes, if they needed "
                   "eyes, but this cave is so dark, they would be "
                   "useless.",
                ({ "stepping stones","stones","stone","stepping stone" }) :
                   "The solid stones are firmly placed in "
                   "the ground.",
                ({ "cave ground","ground" }) :
                   "The ground is of stones and rock.",
                ({ "ground rock","rock" }) :
                   "The rock is dark and gray.",
                ({ "fishing ledge","ledge" }) :
                   "The ledge is made of the same dark gray "
                   "stone that everything else around here is made "
                   "of.  It is not very large, but in the southern "
                   "wall there is a door.",
                ({ "southern door","door" }) :
                   "The door of a dark wood is already "
                   "partially open, it wouldn't take much to walk "
                   "through.",
                ({ "southern wall","wall" }) :
                   "There is a door in the southern wall.",
           ]) );
   SetListen( ([
                 "default" : "The water rushes past noisily."
            ]) );
   SetExits( ([
                "east" : C_ROOM + "roomo",
           ]) );
   SetEnters( ([
                 "door" : C_ROOM + "roomp",
            ]) );
   SetInventory( ([
      STD_FISH "pole" : 1,
               ]) );
   SetSpeed(5);
   SetFish( ([ C_NPC + "fish" : 100 ]) );
   SetChance(25);
   SetMaxFishing(12);
}
