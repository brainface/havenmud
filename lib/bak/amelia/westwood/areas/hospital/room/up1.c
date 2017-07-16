#include <lib.h>
inherit LIB_ROOM;
#include "../hospital.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(50);
   SetShort("on the upper floor of a hospital");
   SetLong("Windows look out onto a forest world of trees and "
           "fresh air.  Inside the hospital, however, the world "
           "is clean and sterile; the beds and walls and tables and "
           "cabinets all gleam with white cleanliness.  The room "
           "continues a ways to the west, and a gentle ramp "
           "goes down to the first floor.");
   SetItems( ([
                ({ "eclat hospital","world","room","upper floor",
                   "floor" }) :
                   (: GetLong :),
                ({ "forest world","trees","tree","world","window",
                   "windows" }) :
                   "The forest world is alive and growing, flourishing "
                   "in the fresh air.  The windows themselves are "
                   "plain and simple, rectangular in shape and designed "
                   "to merely give a glance of the outer world, instead "
                   "of edifying the beauty of the hospital.",
                ({ "rows of clean white beds","beds","bed","rows",
                   "row" }) :
                   "The beds are organized in neat rows that leave "
                   "plenty of space for other things.  There are "
                   "tables between each bed, with one per bed, and "
                   "cabinets set up all over.  There are many attached "
                   "to the walls and others under the beds, as well.",
                ({ "white cabinets","cabinets","cabinet" }) : 
                   "The cabinets are everywhere, under the beds and "
                   "on the walls and in spare spaces in the room.  "
                   "None are open, but all look like they are used "
                   "often.",
                ({ "clean tables","tables","table" }) :
                   "There is one table for each of the beds.  They are "
                   "pretty small, but tend to be kept neat and orderly.",
                ({ "gentle ramp","ramp","first floor","floor" }) :
                   "The ramp slopes down towards the first floor gently, "
                   "allowing for easy access between the levels.",
           ]) );
   SetItemAdjectives( ([
                         "eclat hospital" : ({ "clean","sterile","white",
                                               "eclat" }),
                         "forest world" : ({ "forest","green","fresh" }),
                         "beds" : ({ "white","clean","neat","rows of",
                                     "row of","organized" }), 
                         "walls" : ({ "white","clean" }),
                         "tables" : ({ "white","clean","small" }),
                         "cabinets" : ({ "white","clean" }),
                         "ramp" : ({ "gentle","white" }),
                    ]) );
   SetListen( ([
                 "default" : "The world outside is noisy and lively, "
                    "but inside, it is quiet except for a few "
                    "groans from below.",
            ]) );
   SetSmell( ([
                "default" : "The hospital smells clean and sterile.",
           ]) );
   SetExits( ([
                "down" : H_ROOM + "r2",
                "west" : H_ROOM + "up2",
           ]) );
   SetInventory( ([
                    H_NPC + "patient" : 4,
                    H_NPC + "doc_a" : 2,
               ]) );
}
