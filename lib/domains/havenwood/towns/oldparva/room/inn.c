#include <lib.h>
#include "parva.h"
#include "/domains/havenwood/areas/assassin_hall/assassin_hall.h"

#define GUILD "dark_council"

inherit LIB_ROOM;

string DefaultSearch();
string CaskSearch();
int PreExit(string dir);

static void create() {
   room::create();
   SetTown("Parva");
  SetAmbientLight(30);
   SetDomain("HavenWood");
   SetShort("Minkin's Inn");
  SetClimate("indoors");
   SetLong("Minkin's Inn is a dirty, messy old place that is "
           "open twenty-four hours a day.  All the sailors and "
           "residents of Parva come here for the great food "
           "and social atmosphere.  Several large casks of ale "
           "stand in the corner, ready to tap if the need arises. "
           "The door leads out to the main road of Parva south "
           "of here.");
   SetItems( ([
                 ({ "Minkin's Inn","inn","place" }) :
                    (: GetLong :),
                 ({ "main door","door","doors" }) :
                    "The main door is just an opening in the "
                    "building.  It leads out to the main road "
                    "of Parva.  Another door is on the east "
                    "side of the inn, concealed by a curtain.",
                 ({ "east door","door","doors" }) :
                    "A curtain conceals the door to the east.  "
                    "It probably gives direct access to the docks.",
                 ({ "plain curtain","curtain" }) :
                    "The plain curtain conceals the opening to "
                    "the east.",
                 ({ "main road","road" }) :
                    "The main road of Parva is south, through the "
                    "main door of the Inn.  It is dusty.",
                 ({"barrel", "casks", "large casks", "cask" }) :
                    "Great casks sit in the northwest corner of the room.",
           ]) );

   SetSearch( ([
                        "default" : (: DefaultSearch() :),
                        "cask" : (: CaskSearch() :)
                   ]) );

   SetItemAdjectives( ([
                         "inn" : ({ "minkins","minkin","inn of",
                                    "dirty","messy","old" }),
                         "road" : ({ "main" }),
                    ]) );
   SetSmell( ([
                "default" : "Sweat, fish, and spilled food and "
                   "beer mingle to create the unique smell of "
                   "Minkin's Inn.",
           ]) );
   SetListen( ([
                 "default" : "The Inn is rowdy day and night.",
            ]) );
SetInventory( ([
                    P_NPC + "/barkeep" : 1,
                    P_NPC + "/drunk" : 1+random(3),
                   P_NPC + "/barmaid" : 1,
                     P_NPC + "/newr" : 1,
               ]) );


   SetExits( ([
                "east" : P_ROOM + "/wharf1",
                "out"  : P_ROOM + "/path3",
           ]) );

   AddEnter( "cask", AH_ROOM + "underinn", (: PreExit :) );

   SetObviousExits("out");

   SetProperties ( (["no bump" : 1]) );
}


string DefaultSearch()
{
     if (this_player()->GetGuild() == GUILD)
          return "You notice something odd about the casks in the corner.";
     else
          return "You don't find a thing.";
}

string CaskSearch()
{
     if (this_player()->GetGuild() == GUILD)
     return "You find a hollow cask hidden among the casks full of ale, "
                       "it looks like one could enter it.";

     else return "You don't notice anything special.";
}


int PreExit(string dir)
{

     if(this_player()->GetProperty("parvanoleave")) return 0;

     else if ( (this_player()->GetGuild() == GUILD) ||
           (creatorp(this_player()) ) )
     {
          return 1;
     }
     else
     {
          message("my_action", "You can't enter that!", this_player() );

          return 0;
     }
}

void init()
{
     ::init();
     add_action("peer", "peer");
}

int peer()
{
     message("system", "You can't seem to peer in that direction.", this_player());
     return 1;
}


