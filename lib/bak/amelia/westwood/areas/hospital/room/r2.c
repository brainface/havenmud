#include <lib.h>
inherit LIB_ROOM;
#include "../hospital.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(45);
   SetShort("in the hospital");
   SetLong("Pristine white beds are set in neat rows throughout the room "
          "with small tables next to them for holding the few necessities "
          "the occupants own.  A ramp against the northern wall "
          "leads upwards into another section of the hospital, and "
          "beneath the ramp are white cabinets used for holding "
          "supplies.  The wall to the south has an open doorway in "
          "it, but there is no wall to the west, leaving open passage.");
   SetItems( ([
                ({ "pristine white beds","beds","bed","neat rows",
                   "neat row","rows","row" }) :
                   "The beds have been freshly cleaned just this morning, "
                   "but some have already been slightly soiled by their "
                   "occupants.  The nurses will probably attend to that "
                   "quickly.  There is a small table next to each bed.",
                ({ "eclat hospital","room","hospital" }) :
                   (: GetLong :),
                ({ "small tables","table","tables","items",
                   "item","necessities","necessity" }) :
                   "The tables, just like the floor, ceiling, walls, beds "
                   "and everything else, are a clean white that almost "
                   "shines.  A few items lay on most of the tables, but "
                   "they are medical items, like medicines and antidotes.",
                ({ "white ramp","ramp" }) :
                   "The ramp has the gentlest slope imaginable, and "
                   "takes its sweet time in making it to the second floor "
                   "of the hospital.  It is white, like all else in "
                   "here.",
                ({ "white cabinets","cabinets",
                   "cabinet" }) :
                   "The cabinets are set beneath the ramp, as it was the " 
                   "most convenient place that wouldn't hold a bed "
                   "well.  They are all closed and locked securly.",
                ({ "white walls","walls","wall","ceiling",
                   "floor" }) :
                   "There are walls to the north, east, and south, leaving "
                   "the west open as a continuation of this room.  "
                   "The ceiling and floor are white, just as the walls, "
                   "with little of interest to them.  The wall to the "
                   "south has an open doorway in it.",
                ({ "open doorway","doorway","door" }) :
                   "A doorway leads into a brighter area to the south.",
           ]) );
   SetItemAdjectives( ([
                         "open doorway" : ({ "open" }),
                         "white walls" : ({ "white","clean" }),
                         "white cabinets" : ({ "white","clean" }),
                         "white ramp" : ({ "white","clean" }),
                         "small tables" : ({ "white","clean" }),
                         "pristine white beds" : ({ "pristine","white",
                                                    "clean","neat" }),
                    ]) );
   SetListen( ([
                 "default" : "Some muffled groans come from above.",
            ]) );
   SetSmell( ([
                "default" : "The room smells of a hospital full of "
                   "many, many patients.",
           ]) );
   SetExits( ([
                "south" : H_ROOM + "waiting",
                "west"  : H_ROOM + "r1",
                "up"    : H_ROOM + "up1",
           ]) );
   SetInventory( ([
                    H_NPC + "doc_a"    : 1,
                    H_NPC + "patient"  : 2,
                    H_NPC + "patientg" : random(2),
               ]) );
}
