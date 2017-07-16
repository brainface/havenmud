#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("prasanna");
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("the throne room");
   SetLong("Embellished with silver inlaid upon white marble, the walls " 
           "of the throne room seem to catch every ray of light, and "
           "turn it into a gleam. Curious shapes and creatures are carved "
           "into the walls, most of which never have, or ever will be "
           "seen in this world. Wisps of ethereal energy filter through "
           "the floor and wind in and about the throne, as well as "
           "causing the silken draperies to billow a bit in a nonexistant "
           "wind. Behind the throne, to the north, lies a pair of thick "
           "steel doors. To the south likes a beautiful archway.");
   SetItems( ([ 
      ({ "curious shapes","curious shape" }) :
         "These shapes could possibly portray beings from another place, "
         "but it is impossible to tell from their abstract appearance.",
      ({ "creatures","creature" }) :
         "Carvings of strange creatures litter the walls, many of which "
         "look frightening beyond compare, others which look quite "
         "personable.",
      ({ "wisps of ethereal energy","wisps","wisp","energy" }) :
         "These small tendrils wrap around and embrace the throne, in an "
         "ill-fated attempt to pull the throne back to where ever they "
         "are coming from.",
      ({ "silken draperies","draperies","drapery" }) :
         "These flowing silk draperies look priceless.",
      ({ "thick steel doors","steel doors","steel door","doors","door" }) :
         "These doors are easily a foot thick, and look quite secure. "
         "They appear to be either keeping everyone out, or keeping "
         "something quite large in.",
      ({ "walls","wall" }) :
         "The walls of the throne room are carved from marble, with silver "
         "inlaid deeply to give graceful curves and beauty. ",
      ({ "floors","floor" }) :
         "The floors of the throne room are polished marble, naturally.",
      ({ "archway","arch" }) :
         "This scuplted archway winds around two pillars, and leads to "
         "the main hall of the palace.",
      ({ "throne" }) :
         "The throne is a crystal and ruby miracle, with a rather "
         "sinister look to it. Pure light seems to be born within "
         "the crystal, and amplified in the ruby.",
      ({ "throne room" }) :
         "The throne room is a work of divine art, and seems incapable "
         "of being built by mortal hands. ",
      ({ "main hall","hall" }) :
         "These steps stretch across the entire width of the palace "
         "foyer, yet only a small door leads into the building.",
      ({ "white marble","marble" }) :
         "The white marble that makes up a large portion of the palace "
         "looks as white as ivory, and as smooth and soft as silk.",
      ({ "silk tapestries","silk tapestry","tapestries","tapestry" }) :
         "These tapestries are easily fifty feet long and fifteen "
         "feet wide. They depict scenes that would appear to be the "
         "birth of the city. ",
      ({ "marble columns","columns" }) :
         "The columns are pure marble, carved by hand. The size and "
         "skill required are almost unimaginable.",
      ({ "palace" }) :
         "The palace of Maeralin is immaculate and beautiful. A warm "
         "breeze drifts through the estate, making it seem almost "
         "inviting.",
      ({ "doorway" }) :
         "These doorways lead to various parts of the palace. ",
      ({ "scenes","scene" }) :
         "The scenes on the various tapestries seem to show a brief history "
         "of the city, mages of various races coming together to create "
         "the city and it's surroundings, then sealing the tunnel to the "
         "city, and finally isolating the city from time itself.",
      ({ "gardens","garden" }) :
         "The gardens outside the palace are a vision of beauty, and are "
         "just barely visible out the doorway to the south. ",
   ]) );
   SetExits( ([ 
      "south" : PA_ROOM "/estatehall",
   ]) );  
   SetInventory( ([ PR_NPC + "/maeralin" : 1,
                    PR_NPC + "/royalguard" : 4, ]) );
}

