#include <lib.h>
#include "ditmar.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Ditmar");
   SetClimate("indoors");
   SetAmbientLight(5);
   SetShort("faith hall");
   SetLong("A few small candles flicker complacently in little nooks in the walls, "
           "but they do not serve to illuminate the room so much as to make the "
           "mica in the walls glitter.  A few half-finished ice and rock sculptures are "
           "scattered around the room.  The exit is to the north.");
   SetItems( ([
                ({ "faith hall","hall","room" }) :
                   (: GetLong :),
                ({ "small candles","candles","candle" }) :
                   "The candles are small, black, wax candles.  They are stuck in "
                   "little nooks in the walls to keep them from spreading too much "
                   "light.",
                ({ "little nooks","nooks","nook" }) :
                   "The nooks are little dents in the walls that hold the black "
                   "candles.  They keep the light from spreading too far or illuminating "
                   "too much.",
                ({ "mica in walls","mica","walls","walls","rock" }) :
                   "Mica is a type of rock that general appears as little flecks in other "
                   "types of rock.  This room has been hollowed out of rock that contains "
                   "mica, and the candles in the walls were designed to make it "
                   "glitter.",
                ({ "half-finished sculptures","sculptures","sculpture","ice","rock" }) :
                   "Scattered around the faith hall are the attempts of some of the "
                   "faithful to create sculptures of beauty that are worthy to be "
                   "put in the actual Temple of Worship.  The ones here have yet to "
                   "be finished.",
           ]) );
   SetItemAdjectives( ([
                         "nooks" : ({ "little" }),
                         "candles" : ({ "small","black","wax" }),
                         "sculptures" : ({ "ice","rock","half-finished","ice and rock" }),
                    ]) );
   SetExits( ([
                "north" : D_ROOM + "/church",
           ]) );
   SetInventory( ([
                    D_OBJ + "/board_f" : 1,
               ]) );
}

int CanRecieve() {
   if(immortalp(this_player())) return 1;
   if(this_player()->GetReligion() != "Marn") return 0;
   send_messages("","%^PURPLE%^Welcome.%^RESET%^",this_object(),0,this_player());
}