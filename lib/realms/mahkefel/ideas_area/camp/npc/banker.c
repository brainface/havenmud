#include <lib.h>
#include <std.h>
#include "../camp.h"

inherit LIB_TELLER;

static void create() {
    ::create();

    //descriptions
    SetKeyName("Laihdelm");
    SetId( ({ "laihdelm","hoarder" }) );
    SetShort("laihdelm the hoarder");
    SetLong(
      "This fearful soul seems to be shivering from more than cold. "
      "Nervous eyes scan the walls and peer through the doorway "
      "constantly. His black fur seems frozen to his hide, and his "
      "tail is wrapped around his leg."
    );
    SetGender("male");

    //vital statistics
    SetClass("merchant");
    SetLevel(20);
    SetRace("goden");

    //miscellaneous
    SetAction(5, ({
      "!say Just... let me hold your coins. A bit. I'll give them back.",
      "!say I'll keep your money safe. In the ice.",
      "!say Let me... just let me look at wealth.",
      "!say Very safe. Your gold is very safe in the ice. Thieves here are too "
        "tired to dig.",
      "!emote looks around nervously.",
      "!emote slowly digs a hole in the ice, and drops a few coins in.",
    }) );
    
    SetInventory( ([
      STD_OBJ "digging/shovel" : "wield shovel",
    ]) );
}

