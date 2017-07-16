#include <lib.h>
inherit LIB_ROOM;
#include "sdm.h"

static void create() {
   room::create();
   SetShort("a pasture");
   SetLong("Cow pies litter this fertile pasture.  Healthy green grass "
           "is another prominent aspect, as well as the beautiful "
           "yellow flowers that grow everywhere.  Rocks are scattered "
           "about haphazardly, and the world turns to hills off in the "
           "nearby area.  Far off to the south, the Ruined Sea can be "
           "seen.  One can go to more pasture to the north and east "
           "from here.");
   SetItems( ([
                ({ "ruined sea","sea" }) :
                   "The Ruined Sea to the south is desolate and dreary.",
                ({ "distant hills","hills","distant hill","hill" }) :
                   "The hill is apparently a popular motif for this "
                   "general little area, as many surround it.",
                ({ "haphazardly scattered rocks","haphazardly scattered rock",
                   "rock","rocks","scattered rock","scattered rocks" }) :
                   "The rocks are strewn about the field, not by "
                   "some malevelant being that wishes to make it difficult "
                   "to prepare the land for things like farming, but "
                   "but general nature.",
                ({ "cow pies","cow pie","pie","pies" }) :
                   "Some are dry, and some more damp, but all aren't "
                   "the most pleasant thing to be closely examining.",
                ({ "fertile pasture","pasture" }) : (: GetLong :),
                ({ "healthy green grass","healthy grass","green grass",
                   "grass" }) ;
                   "The grass grows all over the pasture, and looks "
                   "slightly nibbled on.",
                ({ "beautiful yellow flowers","yellow flowers",
                   "beautiful flowers","beautiful yellow flower",
                   "beautiful flower","yellow flower","flower",
                   "flowers","buttercups","buttercup","dainty flowers",
                   "dainty flower" }) :
                   "The dainty flowers look like buttercups.",
           ]) );
   SetObviousExits("north, west");
   SetExits( ([
                "west" : SDM_ROOM + "/pasturec",
                "north" : SDM_ROOM + "/pasturea",
           ]) );
}