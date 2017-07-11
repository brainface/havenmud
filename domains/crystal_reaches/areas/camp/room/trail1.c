
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
           "clear.  The trail twists "
           "and turns to stay on the firmer ground and "
           "several boards lay across softer areas where " 
           "firm ground is not easily found.  Large "
           "trees thrive in the swamp causing the trail "
           "to twist even more. ");
    SetNightLong("A thick mist rises up from the "
           "swamp, making the trail even more dangerous"
           " than during the day.  The trees seem to be "
           "reaching for unwary travelers.  The starlight "
           "bathes the swamp in silvery light.");
    SetItems( ([
             ({"trail", "path"}) : (: GetLong :),
             ({ "ruts", "rut"}) :
                   "The mud of the swamp has several "
                   "deep ruts caused by heavy wagons. ",
	              ({ "swamp", "swampy land", "areas", "area",          
                            "ground", "softer areas", "land",  "mud"}):
                 "The swamp is mainly gray water thick "
                 "with mud.  Some areas are fairly solid "
                 "allowing for relatively safe travel. Many "
                 "trees thrive in the moisture of the swamp."
                 "  Even on the clearest of days the swamp "
                 "seems to be overcast.  ",
              ({ "board", "boards", 
                   "scraps", "scrap"}):
                 "The boards vary in size.  They are "
                 "obviously scraps that served no other "
                 "purpose than to make the softer areas "
                 "of the swamp easier to traverse.  ",
             ({ "trees", "large trees", "tree"}):
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
            ("starlight"):
              "The faint, beautiful light of the stars " 
              "reflects off the shiny gray mud of the "
              "swamp.  "
             ]) );
    SetItemAdjectives( ([
                    "ruts" : ({"deep"}),
                    "boards" : ({"several"}),
                    "trees" : ({"large", "broad", "many"}),
                    "mist" : ({"thick"}),
                    "areas" : ({"softer"}),
                    "water" : ({"gray"})
                    ]) );
    SetSmell( ([
                "default" : "The stench of swamp decay "
                                  "fills the air.  ",
              ]) );
    SetListen( ([
                "default" : "The rustling of tree branches"
                                  " can be heard. ",
             ]) );
    SetInventory( ([ C_NPC + "dog2" : 1]) );
    SetClimate("temperate");
    SetExits( ([
                       "northeast" :  C_ROOM + "trail2",
         "south" : "/domains/crystal_reaches/virtual/llorykroad/5,0",
                  ]) );
}
