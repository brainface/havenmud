#include <lib.h>
inherit LIB_ROOM;
#include "ditmar.h"

static void create() {
   room::create();
   SetTown("Ditmar");
   SetClimate("indoors");
   SetAmbientLight(15);
   SetShort("Ditmar Library");
   SetLong("Stone shelves with strange books filling them are scattered "
           "haphazardly about the Ditmar Library.  There are other "
           "signs of life around the library, like the stone furniture "
           "set near the shelves to provide room to sit and rest while "
           "studying.  An opening to the south leads out.");
   SetItems( ([
                ({ "stone furniture","furniture","tables","table",
                   "chairs","chair","benches","bench" }) :
                   "The furniture has been worn smooth and shiny by "
                   "the great use that it has been put through over the "
                   "years.  Tables, chairs, and benches are put in "
                   "areas all over the library to allow room for all "
                   "to relax while enjoying the delicate stone books.",
                ({ "Ditmar Library","ditmar library","library",
                   "cave","ditmar" }) :
                   (: GetLong :),
                ({ "stone shelves","stone shelf","shelf","shelves",
                   "stone" }) :
                   "The shelves have been carefully fashioned from the "
                   "natural stone that is quite abudant in this "
                   "underground area.  Peculiar books have been carefully "
                   "set on the shelves, as well.  They look to be made "
                   "of stone, also.",
                ({ "strange books","book","books","stone" }) :
                   "The books are made of stone, just like the shelves and "
                   "furniture, but it is a very delicate stone that is "
                   "thin as paper.",
           ]) );
   SetItemAdjectives( ([
                         "shelves" : ({ "stone" }),
                         "books" : ({ "strange","peculiar","thin",
                                      "delicate","very delicate" }),
                         "opening" : ({ "south" }),
                         "furniture" : ({ "stone" }),
                    ]) );
   SetSmell( ([
                "default" : "While most libraries will smell of dust and "
                   "old musty books, this library is refreshing clean and "
                   "pure in its air.",
           ]) );
   SetExits( ([
                "south" : D_ROOM + "/cave_a",
           ]) );
   SetInventory( ([
                    D_NPC + "/sage" : 1,
                    D_NPC + "/div" : 1,
                    D_NPC + "/ench" : 1,
                    "/domains/haven/obj/spell_board" : 1,
               ]) );
}