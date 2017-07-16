#include <lib.h>
inherit LIB_ROOM;
#include "sdm.h"

static void create() {
   room::create();
   SetShort("the farm yard");
   SetLong("Stubby grass grows all over the yard, and grain has been "
           "scattered among it.  A fence stretches out to the north, "
           "where the gate lies open, allowing travel in and out of "
           "the yard.  To the west is a muddy looking pen, to the east "
           "is a small barn.  To the south a cozy house lies.");
   SetItems( ([
                ({ "stubby grass","grass" }) :
                   "The grass is short and green, and tiny specks of "
                   "grain have been scattered among it.",
                ({ "tiny specks of grain","tiny speck of grain",
                   "tiny speck","tiny specks","grain","grain",
                   "speck of grain","specks of grain","scattered grain" }) :
                   "The grain has been scattered among the stubby "
                   "grass that covers the farm's yard.",
                ({ "north fence","fence" }) :
                   "The fence is old and worn, the weather having "
                   "gnawed away at it slowly over the years.  There is "
                   "an open gate in it.",
                ({ "open gate","gate" }) :
                   "The gate is identical to the fence, weathered and "
                   "worn.",
                ({ "muddy looking pen","muddy pen","pen","pig pen" }) :
                   "The pen looks strong and can be entered by going "
                   "west.",
                ({ "farm yard","yard","farm's yard" }) :
                   (: GetLong :),
                ({ "small barn","barn" }) :
                   "The barn is old and rickety, but looks large enough "
                   "to have a hay loft and maybe a pen or two for holding "
                   "animals.",
                ({ "cozy house","house" }) :
                   "The house is small, but is open and waiting to be "
                   "explored.",
           ]) );
   SetSmell( ([
                "default" : "The smells of droppings reach you.",
           ]) );
   SetListen( ([
                 "default" : "Animals make noises nearby.",
            ]) );
   SetExits( ([
                "east" : SDM_ROOM + "/barn",
                "west" : SDM_ROOM + "/pigpen",
                "south" : SDM_ROOM + "/living",
           ]) );
   SetObviousExits("east, west, south");
   SetInventory( ([
                    SDM_NPC + "/chick" : random(2)+3,
                    SDM_NPC + "/chicken" : random(2)+1,
               ]) );
}