
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy camp");
     SetDomain("Crystal Reaches");
     SetDayLong("Like a rainbow breaking through "
           "storm clouds, the gypsy camp pierces the "
           "stark grayness of the swamp.  A myriad of "  
           "colors beams forth from the wagons.  Very "
           "few of the wagons are painted the same color."
           "  A pink wagon, a purple "
           "wagon, and a green wagon stand sentry "
           "against the bleak swamp.  A small fire for "
           "cooking burns warmly. ");
    SetNightLong("The light from the fire flickers like "
           "sunlight through the rustling leaves of a dense"
           " forest causing the camp to appear as if it "
           "were a pile of sparkling gems held up to a "
           "dazzling light.  The firelight reveals three "
           "wagons, one pink, one green and "
           "purple.  The haunting"
           " darkness of the swamp closes in from the "
           "south. ");
    SetItems( ([
             ("camp") : (: GetLong :),
             ({"fire", "campfire"}): "The fire is small and "
                "warm.  ",
             ({ "patch", "ground"}) :
                   "The dark gray ground is dry and firm. ",
             ({ "swamp", "swampy land", "land", "mud"}):
                 "The swamp is mainly gray water thick "
                 "with mud.  Some areas are fairly solid "
                 "allowing for relatively safe travel.  Many "
                 "trees thrive in the moisture of the swamp."
                 "  Even on the clearest of days the swamp "
                 "seems to be overcast.  ",
         ({ "pink wagon", "wagon"}):
                "The wagon is painted a warm pink with "
                "white trim.  A small flower box hangs just "
                "below the ledge of the single window.  "
                "A door at the back provides the only "
                "means for entrance.  A shelf-like bench at "
                "the front offers a place for the driver to "
                "sit.",
     ({"white trim", "trim"}) : "The white trim goes "
               "around the edges of the wagon.  ",
     ({"box", "ledge"}) : "The flower box rests under "
             "the window ledge.  The flower box contains "
             "small white flowers.  ",
      ({"door"}) : "The door is propped open.",
     ({"bench", "seat"}): "The bench is where the "
              "driver sits. ",
      ({"green wagon", "wagon"}) : "The emerald "
               "green wagon has thick purple edging.  The "
               "only window is undecorated.  The door at "
               "the back has two parts so the top could be "
               "open and the bottom closed.  The bench for"
               "the driver is padded.",
        ({"thick purple edging", "purple edging", 
            "thick edging", "edging"}) : "Thick purple "
            "edging runs along the edges of the wagon. ",
        ({"window"}) : "The window allows people to " 
            "look out of the wagon.",
        ({"purple wagon", "wagon"}) : "The deep purple"
               " wagon has delicate pale blue edging.  The "
               "window has small shutters in the same "
               "shade of  blue.  "
               " A pale blue door at the back provides the "
               "only entrance.  The driver's seat is also pale"
               " blue.",
        ({"delicate pale blue edging", "pale blue edging",
            "delicate edging", "blue edging"}) : "The "
           "delicate pale blue edging makes the wagon "  
           "like it has lace on its edges. ",
        ({"shutters", "shutter"}) :  
               "The small, pale blue shutters "
               "frame the window.  They are open.  ",
        ("firelight") : "The firelight flickers like fireflies "
               "dancing in the wind.  "
             ]) );
    SetItemAdjectives( ([
                    "camp" : ({"gypsy"}),
                    "swamp" : ({"bleak"}),
                    "patch" : ({"large", "dry"}),
                    "fire" : ({"small", "warm", "cooking"}),
                    "box" : ({"small", "flower", 
                        "small flower box"}),
                    "ledge" : ({"window"}),
                    "bench" : ({"padded"}),
                    "window" : ({"single", "undecorated"}),
                    "door" : ({"pale blue", "blue"}),
                    "seat" : ({"pale blue", "blue"}),
                    "shutters" : ({"pale blue", "blue", 
                         "small"}),              
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
                       "west" :  C_ROOM + "camp3",
                       "southeast" : C_ROOM + "trail6",
                       "north" : C_ROOM + "camp5",
                       "east" : C_ROOM + "camp1",
                       "northwest" : C_ROOM + "camp6",
                       "northeast" : C_ROOM + "camp4"
                  ]) );
    SetEnters( ([
             "purple wagon" : C_ROOM + "wagon3",
             "green wagon" : C_ROOM + "wagon4",
             "pink wagon" : C_ROOM + "wagon5",
                 ]) );

}
