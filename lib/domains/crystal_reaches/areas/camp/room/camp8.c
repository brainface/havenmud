
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy camp");
     SetDomain("Crystal Reaches");
     SetDayLong("The black wagon stands out in the "
            "brightly colored camp.  The rich royal blue "
             "of the only other wagon nearby adds to the "
             "uniqueness of the black wagon.  The usual "          
             "cook fire lies between the two wagons.  ");
    SetNightLong("A black wagon is difficult to see "
             "despite the flickering light provided by the "
             "cook fire.  A rich royal blue wagon glitters "
             "brilliantly next to the black wagon. ");
    SetItems( ([
             ("camp") : (: GetLong :),
             ({"fire", "campfire"}) : "The fire is small and "
                 "warm.",
             ({ "patch", "ground"}) :
                   "The dark gray ground is dry and firm. ",
             ({ "swamp", "swampy land", "land", "mud"}):
                 "The swamp is mainly gray water thick "
                 "with mud.  Some areas are fairly solid "
                 "allowing for relatively safe travel.  Many "
                 "trees thrive in the moisture of the swamp."
                 "  Even on the clearest of days the swamp "
                 "seems to be overcast.  ",
         ({ "royal blue wagon", "blue wagon", 
                  "wagon"}):
                "The wagon is royal blue with dark "
                "purple trim.  A small flower box rests "
                "below the single window.  "
                "A door at the back provides the only "
                "means for entrance.  A shelf-like bench at "
                "front provides a place for the driver to sit. ",
        ({"dark purple trim", "purple trim", "trim"}) : 
               "The wagon is edged in dark purple trim. ",
       ({"box"}) :  "The small flower box has a few "
               "white daisies. ",
        ({"daisies", "daisy"}) : 
              "The white daises are small "
              "and delicate.",
       ({"window"}) : "The window allows people "
              "to look out of the wagon.",
        ({"door"}) : "The door is propped open.",
       ({"bench"}) : "The bench is where the "
              "driver sits. ",
        ({"black wagon", "wagon"}) : "The black "
               "wagon has blood red trim and "
               "shutters.  The back door is split in half "
               "allowing the bottom to be closed and the "
               "top to be open.  "
               "A blood red crescent moon painted on the "
               "top.  The top and bottom fit well together "
               "not letting a single crack of light in when "
               "closed.  The bench for the driver is "
               "padded.",
        ({"blood red trim", "red trim", "trim"}) : "The "
               "wagon looks like it has blood along the "
                "edges because of the color of the trim. ",
        ({"light", "firelight"}) : "The firelight flickers "
               "like fireflies dancing in the wind.  "
             ]) );
    SetItemAdjectives( ([
                    "camp" : ({"gypsy", "brightly colored"}),
                    "patch" : ({"large", "dry"}),
                    "box" : ({"small flower", "small",  
                            "flower"}), 
                    "daisies" :  ({"white"}),
                    "window" : ({"single"}),
                    "bench" : ({"shelf-like", "padded"}),
                    "door" : ({"back"})             
                    ]) );
    SetSmell( ([
                "default" : "Various cooking fires fill the "
                                  "air with tantalizing scents."
              ]) );
    SetListen( ([
                "default" :  "The bustle of chores and work"
                                   " blends with the sounds of a "
                                   "tambourine and singing.  "
             ]) );
    SetClimate("temperate");
    SetInventory( ([ C_OBJ + "fire1" : 1]) );
    SetExits( ([
                       "west" :  C_ROOM + "camp9",
                       "southwest" : C_ROOM + "camp6",
                       "east" : C_ROOM + "camp7",
                       "southeast" : C_ROOM + "camp4",
                       "south" : C_ROOM + "camp5"
                  ]) );
    SetEnters( ([
             "blue wagon" : C_ROOM + "wagon15",
             "black wagon" : C_ROOM + "wagon16"
                 ]) );

}

