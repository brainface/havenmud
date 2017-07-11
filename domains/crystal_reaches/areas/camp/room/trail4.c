
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetAmbientLight(30);
     SetShort("a trail");
     SetDomain("Crystal Reaches");
     SetDayLong("Deep ruts caused by wagon wheels "
           "crossing the swampy land make the trail "
           "clear.  The ground is relatively firm here "
           "allowing for a straight path for awhile.  "
           "The swamp closes in again further down " 
           "forcing the path to the northwest once "
            "more.  The trees are off to the side of the "
           "road preferring the moist land over the dry "
           "trail.  ");
     SetNightLong("The thick mist still obscures the "
           "trail, but the trail is drier.  The mist is not as "
           "thick over the straighter trail.  The swamp "
           "closes in further down and the mist thickens, "
           "once more forcing the trail to the northwest.  "
           "The trees still seem to reach for unwary "
           "travelers, but are further from the trail.  The "  
           "starlight bathes the swamp in silvery light.  ");
    SetItems( ([
             ({"trail", "path"}) : (: GetLong :),
             ({ "ruts", "deep ruts", "rut"}) :
                   "The mud of the swamp has several "
                   "deep ruts caused by heavy wagons. ",
	              ({ "swamp", "swampy land", "ground",
                          "land",  "mud", "areas", "area"}):
                 "The swamp is mainly gray water thick "
                 "with mud.  Some areas are fairly solid "
                 "allowing for relatively safe travel.  Many "
                 "trees thrive in the moisture of the swamp."
                 "  Even on the clearest of days the swamp "
                 "seems to be overcast.  ",
         ({"moisture", "air"}): "The air is thick with "
                 "moisture.  ",
         ({ "trees", "tree"}):
                "The trees are very broad.  The roots are "
                "visible above ground and branch out to "
                "give the tree more water and better "
                "support.  The branches are covered with "
                "dark green leaves as big as a human's "
                "head.  Moss covers the silvery trunk. ",
         ("moss"): 
                "The moss is dark green and leafy.",
           ({"branches", "branch"}):
               "The branches are thick and strong. ",
           ({"trunk", "tree trunk"}): 
               "The tree trunk is thick and silvery.",
           ({"leaves", "leaf", "green leaves"}):
               "The huge leaves are dark green and "
               "round.  ",
           ({"roots", "root"}):
              "The roots grow above ground making "
              "the tree look like it has multiple legs. ",	   
         ("mist"):
               "The thick mist makes it difficult to see "
               "the path and to judge distances.  It gives "
               "an eerie quality to the swamp. ",
         ({"starlight", "light"}):
              "The faint, beautiful light of the stars " 
              "reflects off the shiny gray mud of the "
              "swamp.  "
    
               ]) );
    SetItemAdjectives( ([
                    "ruts" : ({"deep"}),
                    "trail" : ({"firm", "straight"}),
                    "mist" : ({"thick"}),
                    "leaves" : ({"green", "dark green"}),
                    "areas" : ({"softer"}),
                    "land" : ({"moist"}),
                    "trail" : ({"drier"}),
                    "path" : ({"straight"}),
                    "light" : ({"silvery"})                    
                    ]) );
    SetSmell( ([
                "default" : "The stench of swamp decay "
                                  "is much weaker.  ",
              ]) );
    SetListen( ([
                "default" : "The rustling of tree branches"
                                  " can be heard along with faint "
                                  "music. ",
             ]) );
    SetClimate("temperate");
    SetObviousExits("southwest, northwest");
    SetExits( ([
                       "northwest" :  C_ROOM + "trail5",
                       "southwest" : C_ROOM + "trail3",
                  ]) );
}
