
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy camp");
     SetDomain("Crystal Reaches");
     SetDayLong("The colorful collage of wagons "
           "continues to dominate the bland swamp.  "
           "A teal wagon and a purple wagon surround a "
           "small cooking fire.  An extra wheel rests "
           "against one of the wheels of the purple "
           "wagon.  ");
    SetNightLong("The flickering firelight "
           "casts shadows over purple wagon and "
           "the teal wagon.  An extra wheel "
           "rests against one of the wheels of the "
           "purple wagon. ");       
    SetItems( ([
             ("camp") : (: GetLong :),
             ({ "patch", "ground"}) :
                   "The dark gray ground is dry and firm. ",
             ({ "swamp", "swampy land", "land", "mud"}):
                 "The swamp is mainly gray water thick "
                 "with mud.  Some areas are fairly solid "
                 "allowing for relatively safe travel.  Many "
                 "trees thrive in the moisture of the swamp."
                 "  Even on the clearest of days the swamp "
                 "seems to be overcast.  ",
         ({"wheel"}) :  "The wheel looks like it "
                 "has never been used.  ",
         ({ "teal wagon", "wagon"}):
                "The wagon is painted teal with light "
                "purple trim.  A small flower pot sits on "
                "the ledge of the single window.  "
                "A door at the back provides the only "
                "means for entrance.  A shelf-like bench at "
                "front provides a place for the driver to sit. ",
       ({"light purple trim", "purple trim", "trim"}) : 
                "Light purple trim edges the wagon.  ",
       ({"pot", "ledge"}) : "The window ledge is wide "
             "enough to hold a small flower pot containing"
             " two purple flowers.  ",
       ({"window"}) : "The window allows people to "
             "look out the window. ",
       ({"door"}) : "The door is open. ",
       ({"bench"}) : "The driver sits on the bench. ",
       ({"purple wagon", "wagon"}) : "The purple "
               "wagon has bright white trim and "
               "shutters.  The back door is split in half "
               "allowing the bottom to be closed and the "
               "top to be open.  Beautiful music streams "
               "from the open top.  Music notes are "
               "painted on the bottom.  The bench for the "
               "driver is padded. ",
         ({"shutters", "shutter"}) :
              "The white shutters frame the "
              "window. ",
        ("white trim", "trim") : "The wagon looks like "
               "a frosted cake because of the white trim. ",
       ("music") : "The beautiful music sounds like it "
             "comes from a dulcimer. ",
       ({"notes", "note",  "squares", "square"}) : 
              "The music notes are "
              "simply squares of "
              "varying length.  Some are placed higher "
              "others. ",
        ("firelight") : "The firelight flickers like fireflies "
               "dancing in the wind.  ",
       ({"fire", "campfire"}) : "The fire is small and"
               " warm. "
             ]) );
    SetItemAdjectives( ([
                    "camp" : ({"gypsy"}),
                    "patch" : ({"large", "dry"}),
                    "fire" : ({"small", "cooking"}),
                    "swamp" : ({"bland"}),
                    "firelight" : ({"flickering"}), 
                    "pot" : ({"small", "flower"}),
                    "ledge" : ({"window"}),
                    "bench" : ({"shelf-like", "padded"}),
                    "notes" : ({"music", "musical"}),
                    "music" : ({"beautiful"}),
                    "wheel" : ({"extra"})             
                    ]) );
    SetSmell( ([
                "default" : "Various cooking fires fill the "
                                  "air with tantalizing scents."
              ]) );
    SetListen( ([
                "default" :  "The bustle of chores and work"
                                   " blends with the sounds of a "
                                   "tambourine and singing.  "
                                   "Beautiful dulcimer playing "
                                   "comes "
                                   "from the purple wagon.  ",
                "purple wagon" : "A beautiful song "
                                   "comes from the purple "
                                   "wagon. ",
                "music" : "The music is beautiful, "
                                "complicated, and haunting. ",
             ]) );
    SetClimate("temperate");
    SetInventory( ([ C_OBJ + "fire1" : 1]) );
    SetExits( ([
                       "east" :  C_ROOM + "camp5",
                       "southeast" : C_ROOM + "camp2",
                       "north" : C_ROOM + "camp9",
                       "northeast" : C_ROOM + "camp8",
                       "south" : C_ROOM + "camp3"
                  ]) );
    SetEnters( ([
             "teal wagon" : C_ROOM + "wagon12",
             "purple wagon" : C_ROOM + "wagon13"
                 ]) );
}
