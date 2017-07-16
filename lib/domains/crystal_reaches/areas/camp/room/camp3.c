
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy camp");
     SetDomain("Crystal Reaches");
     SetDayLong("Like a pile of gems mixed with "
           "grey sand, the gypsy camp catches "
           "attention.  "
           "A yellow wagon, a blue wagon, and a "
           "magenta wagon stand out.  "
           "A small tree shoot has started to grow "
           "in the shelter between the wagons.");
    SetNightLong("The light from the fire flickers like "
           "a candle in the wind "
           "causing the camp to appear as if it "
           "were a pile of sparkling gems held up to a "
           "light.  The firelight bounces off three"
           " wagons, one yellow, one magenta,  and one "
           "blue.  Shadows dance over a small "
           "tree shoot.");
    SetItems( ([
             ("camp") : (: GetLong :),
             ({ "patch", "ground"}) :
                   "The dark gray ground is dry and firm. ",
             ({ "swamp", "swampy land", "land", "mud",
                     "water"}):
                 "The swamp is mainly gray water thick "
                 "with mud.  Some areas are fairly solid "
                 "allowing for relatively safe travel.  Many "
                 "trees thrive in the moisture of the swamp."
                 "  Even on the clearest of days the swamp "
                 "seems to be overcast.  ",
         ({ "blue wagon", "wagon"}):
                "The wagon is painted a bold blue with "
                "purple trim.  The window is unadorned.  "
                "A door at the back provides the only "
                "means for entrance.  A shelf-like bench at "
                "the front offers a place for the driver to "
                "sit.",
         ({"purple trim", "trim"}) : "Purple trim lines the" 
                " edges of the wagon.  ",
        ({"window", "spot"}) : "The window allows "
               "people to look out of the wagon.  ",
        ({"door"}) : "The door is open. ",
        ({"bench"}) : "The bench is where the driver "
            "sits.  ",
         ({"magenta wagon","wagon"}) : "The magenta  "
               " wagon is edged in a sunny yellow.  "
               "A small ceramic dog sits in the "
               "window.   A door at the back provides the "
               "only means for entrance.  A shelf-like "
               "bench at the front provides a place for the "
               "driver to sit.  ",
         ({"dog"}) : "The small ceramic dog is finely "
               "crafted.  It sits in the window almost "
               "like it's guarding the wagon.  ",
         ({"yellow wagon", "wagon"}) : "The light "
               "yellow wagon has bright orange edging.  "
               "The window is the only dark spot on the "
               "whole wagon.  The bench for the driver is "
               "worn, but still a bright orange as is the "
               "door.",
        ({"bright orange edging", "orange edging",     
               "edging"}) : "Bright orange edging lines the"
                   " wagon. ",
        ("firelight") : "The firelight flickers like fireflies "
               "dancing in the wind.  ",
        ({"shadows", "shadow"}) : 
              "Dark shadows fall where the "
              "firelight can't reach.",
        ({"tree shoot", "tree", "shoot", "shelter"}) : 
                "The tree shoot looks like a stick "
               "with scrawny twigs for branches.",
             ]) );
    SetItemAdjectives( ([
                    "camp" : ({"gypsy"}),
                    "patch" : ({"large", "dry"}),
                    "tree shoot" : ({"small"}),
                    "shoot" : ({"small", "tree"}),
                    "mud" : ({"thick", "gray"}),
                    "water" : ({"gray"}),
                    "window" : ({"unadorned"}),
                    "bench" : ({"shelf-like", "bright orange",
                             "orange"}),
                    "dog" : ({"small", "ceramic", 
                          "small ceramic"}),
                    "spot" : ({"dark"}),
                    "door" : ({"bright orange", "orange"})
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
    SetInventory( ([ C_OBJ + "fire1" : 1,
                             C_NPC + "girl" : 1]) );
    SetExits( ([
                       "east" : C_ROOM + "camp2",
                       "north" : C_ROOM + "camp6",
                       "northeast" : C_ROOM + "camp5"
                  ]) );
    SetEnters( ([
             "yellow wagon" : C_ROOM + "wagon6",
             "blue wagon" : C_ROOM + "wagon7",
             "magenta wagon" : C_ROOM + "wagon8",
                 ]) );
}
