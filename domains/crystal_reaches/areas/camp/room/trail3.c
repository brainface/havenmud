
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetAmbientLight(30);
     SetShort("a trail");
     SetDomain("Crystal Reaches");
     SetDayLong("The deep ruts continue to twist "
           "and turn to stay on the firmer ground.  "
           "Several boards lay across softer areas where " 
           "firm ground is not easily found.  An immense "
           "boulder forces the trail to turn northeast.  Large "
           "trees shelter the boulder.");
SetNightLong("A thick mist rises up from the "
           "swamp, making the trail even more dangerous"
           " than during the day.  The starlight "
           "bathes the swamp in silvery light and reflects "
           "off an immense boulder sheltered by the large "
           "trees.  The boulder forces "
           "the trail to turn northeast.");
    SetItems( ([
             ("trail") : (: GetLong :),
             ({ "ruts", "deep ruts","rut"}) :
                   "The mud of the swamp has several "
                   "deep ruts caused by heavy wagons. ",
              ({ "swamp", "swampy land", "ground",
                     "land",  "mud", "areas"}):
                 "The swamp is mainly gray water thick "
                 "with mud.  Some areas are fairly solid "
                 "allowing for relatively safe travel.  Many "
                 "trees thrive in the moisture of the swamp."
                 "  Even on the clearest of days the swamp "
                 "seems to be overcast.  ",
              ({ "board", "several boards", "boards"}):
                 "The boards vary in size.  They are "
                 "obviously scraps that served no other "
                 "purpose than to make the softer areas "
                 "of the swamp easier to traverse.  ",
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
           ("boulder") : "The immense boulder is too big "
                "to go over.  It has a slightly purple cast to "
                "it where it is not covered by the thick gray "
                "mud of the swamp.  ",
         ("mist"):
               "The thick mist makes it difficult to see "
               "the path and to judge distances. It gives "
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
                    "boulder" : ({"immense", "large"}),
                    "areas" : ({"softer"}),
                    "leaves" : ({"green", "dark green"}),
                    "mud" : ({"thick", "gray", "thick gray"})
                    ]) );
    SetSmell( ([
                "default" : "The stench of swamp decay "
                                  "fills the air.  ",
              ]) );
    SetListen( ([
                "default" : "The rustling of tree branches"
                                  " can be heard. ",
             ]) );
    SetClimate("temperate");
    SetObviousExits("southeast, northeast");
    SetExits( ([
                       "northeast" :  C_ROOM + "trail4",
                       "southeast" : C_ROOM + "trail2",
                  ]) );
}
