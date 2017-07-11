
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy camp");
     SetDomain("Crystal Reaches");
     SetDayLong("Bright colors continue to dazzle the "
           "mind.  A turquoise wagon and a red wagon "
           "assault the eyes with clashing color.  "
           "A bench rests between the wagons providing "
           "a nice place to rest. ");
    SetNightLong("The firelight reveals a red "
           "wagon and a turquoise one that does not "
           "compliment the red wagon.  "
           "A bench between the wagons is revealed "
           "by the dancing firelight.");
    SetItems( ([
             ("camp") : (: GetLong :),
             ({"colors", "color"}) :
                 "The wagon is very colorful. ",
             ({ "patch", "ground"}) :
                   "The dark gray ground is dry and firm. ",
             ({ "swamp", "swampy land", "land", "mud"}):
                 "The swamp is mainly gray water thick "
                 "with mud.  Some areas are fairly solid "
                 "allowing for relatively safe travel.  Many "
                 "trees thrive in the moisture of the swamp."
                 "  Even on the clearest of days the swamp "
                 "seems to be overcast.  ",
         ({ "turquoise wagon", "wagon"}):
                "The wagon is painted turquoise with "
                "white trim.  A small flower pot sits on "
                "the ledge of the single window.  A"
                "door at the back provides the only means"
                "for entrance.  A shelf-like bench at the "
                "front provides a place for the driver to sit. ",
        ({"white trim", "trim"}) : "White trim runs "
               "along the edges of the wagon.  ",
        ({"pot", "ledge"}) : "The window ledge is wide "
              "enough to hold a small flower pot "
              "containing a single red wildflower. ",
        ({"wildflower", "flower"}) : "The red flower is "
              "beautiful and delicate.",
       ({"door"}) : "The door is open.",
       ({"red wagon", "wagon"}) : "The brick red "
               "wagon has hideous mustard trim and "
               "shutters.  The back door is split in half "
               "allowing the bottom to be closed and the "
               "top to be open.  The bench for the driver is "
               "padded. ",
         ({"hideous mustard trim", "hideous trim",  
              "trim",}) : "The mustard trim is absolutely "
                     "hideous.  It looks like the wagon was "
                     "dipped in vomit. ",
        ({"bench"}) : "The bench is made of pine slats "
              "and is "
              "very light weight.  It is well worn and a "
              "perfect place to rest. ",
        ({"slats", "slat"}) :
             "The slats are about an inch thick "
             "and are made from pine. ",
        ("firelight") : "The firelight flickers like fireflies "
               "dancing in the wind.  "
             ]) );
    SetItemAdjectives( ([
                    "camp" : ({"gypsy"}),
                    "patch" : ({"large", "dry"}),
                    "slats" : ({"pine"}), 
                    "firelight" : ({"dancing"}),
                     "ground" : ({"dark", "gray", "dry" , 
                            "firm"}),
                   "wildflower" : ({"single", "red"}),
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
                                   "tambourine and singing."
             ]) );
    SetClimate("temperate");
    SetInventory( ([ C_OBJ + "fire1" : 1]) );
    SetExits( ([
                       "west" :  C_ROOM + "camp5",
                       "southwest" : C_ROOM + "camp2",
                       "north" : C_ROOM + "camp7",
                       "northwest" : C_ROOM + "camp8",
                       "south" : C_ROOM + "camp1"
                  ]) );
    SetEnters( ([
             "turquoise wagon" : C_ROOM + "wagon9",
             "red wagon" : C_ROOM + "wagon10"
                 ]) );


}
