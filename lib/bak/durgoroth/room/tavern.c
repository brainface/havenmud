// Title: Durgoroth Town
// File: tavern.c
// Author: Arika@Haven
// Date: February 1999
//
// Abstract:   The Raunchy Goblin Tavern in Durgoroth
//
// Revision History: 
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
     room::create();
     SetShort("the Raunchy Goblin Tavern");
     SetDayLong("The tavern is rather empty during the day.  There "
                        "are a few tables, but most of them have chairs sat "
                        "upon them.  The few patrons of this bar have taken "
                        "to lots of heavy drinking at the old bar on the south "
                        "wall.  Many bottles of liquor line the wall behind the "
                        "bar.  The only light that spills into this place somehow "
                        "manage to find their way in through all of the dust on "
                        "on the narrow windows high up on the wall.");
     SetNightLong("This is the place to be at night.  Most of the tables are "
                           "full and the bar is equally as full.  On the wall behind "
                           "the bar sets a stash of liquor.  The tavern is rather dark, "
                           "but a small amount of light is supplied by gas lanterns "
                           "hanging on the walls.");
     SetObviousExits("out");
     SetClimate("indoors");
     SetAmbientLight(35);

     SetItems( ([
          ({"tavern","room"}) : (: GetLong :),
          ({"table","tables"}) : "The tables are very beat up and most of them "
                                          "have names and phrases carved into them.",
          ({"chair","chairs"}) : "The chairs look rather uncomfortable.",
          ({"patron","patrons"}) : "One wouldn't want to look too closely, they "
                                             "might wind up with their throat slit.",
          ({"old bar","bar"}) : "The bar is large and made of dark wood.",
          ({"liquor","bottles","bottles of liquor"}) : "The bottles consist of just "
                                            "about every drink known on Kailie.",
           ({"light"}) : "There is little light in the tavern",
           ({"dust"}) : "Dust is everwhere, especially the windows.",
           ({"dusty windows","narrow windows","windows"}) :
                           "The windows are narrow and high upon the wall.",
           ({"wall","walls"}) : "There is nothing special about the walls.",
           ({"gas lanterns","lanterns"}) : "They emit a small amount of light."
          ]) );
     SetExits( ([
          "out" : D_ROOM + "/road04",
          ]) );

     SetInventory( ([
           D_NPC + "/barkeep" : 1,
        //   D_NPC + "/rogue" : 1,
          ]) );
     }
