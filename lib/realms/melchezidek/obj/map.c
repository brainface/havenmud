#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("map");
  SetId( ({ "map" }) );
  SetAdjectives( ({ "treasure", "old" }) );
  SetShort("an old treasure map");
  SetLong("This is an old and dirty treasure map. Perhaps"
          " you should <read> it.");
  SetRead( "default",
    "  _______________________________________________________    \n"
    " /                                                    /  \\   \n"
    "|                                                    |    |  \n"
    "|                                                    |    |  \n"
    " \\____________________________________________________\\__/   \n"
    " |                                                     |  \n"
    " |                                                     |     \n"
    " |                                                     |     \n"
    " |The Treasure    ______________________ (Parva)       |     \n"
    " |               /                                     |     \n"
    " |              /                                      |     \n"
    " |     X|      /                                       |     \n"
    " |      |     /                                        |     \n"
    " |      |    /       |                                 |     \n"
    " |      |   / _______  (The HavenWood)                 |     \n"
    " |      |  / /       |                                 |     \n"     
    " |      \\-/-                                           |     \n"
    " |       /                                             |     \n"
    " |      /                                              |     \n"
    " |     /                                               |     \n"
    " |    /                                                |     \n"
    " |   /                                                 |     \n"
    " |  /                                                  |     \n"
    " | /                                                   |     \n"
    " |                                                     |     \n"
    " /~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/~~\\  \n"
    "|                                                     |    | \n"
    "|                                                     |    | \n"
    " \\_____________________________________________________\\__/  \n"
    );
   SetMass(1);
 } 
