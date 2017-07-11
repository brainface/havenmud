
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy camp");
     SetDomain("Crystal Reaches");
     SetDayLong("The bonfire at the center of the "
           "camp seems like the sun shining through "
           "a rainbow.  Only one wagon is "
           "close to the fire.  Most of the area around "
           "the fire is cleared so that the gypsies can "
           "gather together in their free time.  ");
    SetNightLong("The bonfire bathes the center of the"
           " camp in a strong glow.  Sometimes gypsies "
           "gather around the fire, swapping stories,  "
           "laughing, singing, and dancing.  The firelight "
           "bounces off the only wagon nearby.  Most of "
           "the area is left open so the gypsies can "
           "gather.");
    SetItems( ([
             ("camp") : (: GetLong :),
             ({ "area", "ground"}) :
                   "The dark gray ground is packed tightly "
                   "from use.  ",
             ({ "swamp", "area", "swampy land", "land", 
                    "mud"}) :
                 "The swamp is mainly gray water thick "
                 "with mud.  Some areas are fairly solid "
                 "allowing for relatively safe travel.  Many "
                 "trees thrive in the moisture of the swamp."
                 "  Even on the clearest of days the swamp "
                 "seems to be overcast.  ",
         ({"wagon"}):
                "The wagon is painted the brightest yellow "
                "imaginable and edged in blood red.  It is "
                "larger than any of the other wagons.  "
                "Three windows with red drapes line the "
                "sides of the wagon. The bench for the "
                "driver is padded and covered by a small "
                "overhang. ",
        ({"windows", "window"}) :
                "The windows allow people to "
                "look out of the wagon. ",
         ({"drapes", "drape"}) :
                "The red drapes are thick and well "
                "made.  ",
        ({"bench", "overhang"}) : "The bench where the"
               " driver sits is comfortably padded.  A small"
               " overhang protects the driver from the rain.",
        ("firelight") : "The firelight flickers like fireflies "
               "dancing in the wind.  ",
       ({"gypsies", "gypsy"}) :
                "The gypsies are busy elsewhere. ",
       ({"bonfire", "glow"}) : "The bonfire is large and "
                    "bright.  It "
                    "gives off quite a bit of heat and is "
                    "tended all day and all night.  "
             ]) );
    SetItemAdjectives( ([
                    "camp" : ({"gypsy"}),
                    "patch" : ({"large", "dry"}),
                    "wagon" : ({"yellow"}),
                    "drapes" : ({"red"}),
                    "bench" : ({"padded"}),
                    "overhang" :({"small"})             
                    ]) );
    SetSmell( ([
                "default" : "Various cooking fires fill the "
                                  "air with tantalizing scents."
              ]) );
    SetListen( ([
                "default" :  "A cacophony of sounds fills "
                                   "the area.  The most prominent"
                                   " are singing, music and "
                                   "laughing."
             ]) );
    SetClimate("temperate");
    SetInventory( ([ C_OBJ + "fire2" : 1,
                              C_NPC + "dancer" : 1,
                              C_NPC + "drummer" : 1,
                              C_NPC + "man" : 1]) );
    SetExits( ([
                       "west" : C_ROOM + "camp6",
                       "north" : C_ROOM + "camp8",
                       "northwest" : C_ROOM + "camp9",
                       "northeast" : C_ROOM + "camp7",
                       "east" : C_ROOM + "camp4",
                       "southeast" : C_ROOM + "camp1",
                       "south" : C_ROOM + "camp2",
                       "southwest" : C_ROOM + "camp3"
                  ]) );
     SetEnters( ([
             "wagon" : C_ROOM + "wagon11",
                 ]) );

}
