
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
    SetAmbientLight(30); 
    SetShort("a trail");
    SetDomain("Crystal Reaches");
    SetDayLong("The ruts on the trail are not as deep. "
           " The ground is fairly firm here and the trees "
           "are further off to the side.  Thus, the trail is "
           "slightly wider and much straighter.  A few "
           "boards still cover soft areas.");
    SetNightLong("The thick mist still obscures the "
           "trail, but is as thick over the straighter, wider "
           "trail.  The trees are less threatening because "                      
           "they are further from the trail.  The starlight "           
           "bathes the swamp in pale light.  A dim "            
           "light can be seen up ahead. ");
    SetItems( ([
             ("trail") : (: GetLong :),
             ({ "ruts", "deep ruts", "rut"}) :
                   "The mud of the swamp has several "
                   "deep ruts caused by heavy wagons. ",
	              ({ "swamp", "swampy land", "ground",
                          "land",  "mud", "water", "areas", "area"}):
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
          ("light") : "The light is very dim.  The source "
                "is too far away to see.  ",
         ("starlight"):
              "The faint, beautiful light of the stars " 
              "reflects off the shiny gray mud of the "
              "swamp.  ",
          ("mist"):
               "The thick mist makes it difficult to see "
               "the path and to judge distances. It gives "
               "an eerie quality to the swamp. "
                   ]) );
    SetItemAdjectives( ([
                    "ruts" : ({"deep"}),
                    "trail" : ({"firm", "straight", "straighter",
                               "wider"}),  
                    "light" : ({"dim"}),
                    "mist" : ({"thick"}),
                    "ground" : ({"firm"}),
                    "mud" : ({"shiny", "gray", "thick"}),
                    "water" : ({"gray"}),
                    "areas" : ({"softer"}),             
                    ]) );
    SetSmell( ([
                "default" : "The stench of swamp decay "
                                  "is much weaker.  ",
              ]) );
    SetListen( ([
                "default" : "The rustling of tree branches"
                                  " can be heard along with faint"
                                  " music. ",
             ]) );
    SetClimate("temperate");
    SetInventory( ([ C_NPC + "dog2" : 2]) );
    SetObviousExits("southeast, northwest");
    SetExits( ([
                       "northwest" :  C_ROOM + "trail6",
                       "southeast" : C_ROOM + "trail4",
                  ]) );
}
