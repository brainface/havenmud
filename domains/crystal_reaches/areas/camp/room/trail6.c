
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a trail");
     SetDomain("Crystal Reaches");
     SetDayLong("The deep ruts caused by wagon "
           "wheels crossing the swampy land are hardly "
           "visible.  The ground is fairly firm allowing "
           "for a straight and noticeably wider trail.  A "
           "very few soft spots remain, none large "
           "enough to be covered by the scrap boards.  "
           "The trees are much less dense indicating a "
           "large area of dry land.");
    SetNightLong("The mist has cleared for the most "
           "part as the ground has become firm and dry. "
           "The trail continues to be straight.  It is much "                      
           "wider because the trees have thinned out.  "
           "A light emanates from a clearing up ahead.  "  
           "The starlight bathes the swamp in pale light.");
    SetItems( ([
             ("trail") : (: GetLong :),
             ({ "ruts", "deep ruts", "rut"}) :
                   "The mud of the swamp has several "
                   "deep ruts caused by heavy wagons.  "
                   "However, they are not as deep in this "
                   "area. ",
	              ({ "swamp", "swampy land", "ground",
                          "land",  "mud"}):
                 "The swamp is mainly gray water thick "
                 "with mud.  Some areas are fairly solid "
                 "allowing for relatively safe travel.  Many "
                 "trees thrive in the moisture of the swamp."
                 "  Even on the clearest of days the swamp "
                 "seems to be overcast.  ",
         ({ "trees", "tree"}):
                "The trees are very broad.  The roots are "
                "visible above ground and branch out to "
                "give the tree more water and better "
                "support.  The branches are covered with "
                "dark green leaves as big as a human "
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
         ("path") : "The path is wider and dry. ",
         ("area") : "The dry area is too far away to see.",
         ("light") : "The flickering light might come "
                         "from a campfire.  ",
         ("mist"):
               "The thick mist makes it difficult to see "
               "the path and to judge distances. It gives "
               "an eerie quality to the swamp. ", 
        ({"spots", "puddles"}) :
              "Some areas of the trail are softer than "
              "others.  Half-dry puddles result in the "
              "soft mushy mud.  ",
         ({"starlight", "light"}):
              "The faint, beautiful light of the stars " 
              "reflects off the shiny gray mud of the "
              "swamp.  "
             ]) );
    SetItemAdjectives( ([
                    "ruts" : ({"deep"}),
                    "trail" : ({"firm", "straight", "wider"}),    
                    "path" : ({"straight", "narrow"}) ,
                    "area" : ({"large", "dry"}),
                    "water" : ({"gray"}),
                    "mud" : ({"thick", "gray", "shiny",
                               "soft", "mushy"}),
                    "spots" : ({"soft"}),
                    "light" : ({"pale"})              
                    ]) );
    SetSmell( ([
                "default" : "The smell of smoke is strong "
                                  "enough to block out the smell "
                                  "of decay."
              ]) );
    SetListen( ([
                "default" :  "A tambourine and singing drift"          
                                  " through the air."
             ]) );
    SetClimate("temperate");
    SetObviousExits("southeast, northwest");
    SetExits( ([
                       "northwest" :  C_ROOM + "camp2",
                       "southeast" : C_ROOM + "trail5"
                  ]) );
}
