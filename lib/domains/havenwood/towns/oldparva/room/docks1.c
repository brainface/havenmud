#include <lib.h>
#include "parva.h"
#include <domains.h>
#include "/domains/havenwood/areas/assassin_hall/assassin_hall.h"

#define GUILD "twilight"

inherit LIB_FISHING;

int PreExit(string dir);

static void create() {
   fishing::create();
   SetTown("Parva");
   SetProperty("coastal", 1);
   SetShort("on Parva's floating docks");
   SetDomain("HavenWood");
   SetLong("These docks float with the tide, so that smaller boats "
           "can hook up to it and stay there for a while.  "
           "A ramp leads up to the wharf, which is slightly "
           "west of and distinctly above here.  The docks spread "
           "out for a ways, but the way is blocked to those who "
           "don't own ships.  The only thing between the ocean "
           "and those standing on this dock is a stilt-like platform "
           "of boards that the dock floats on.");
   SetItems( ([
                ({ "Parvas floating docks","dock","docks" }) :
                   (: GetLong :),
                ({ "steep ramp","ramp" }) :
                   "The ramp leads up to the wharf.  It is very "
                   "step, so the bumps on it help to make it "
                   "possible to clamber up without slipping.",
                ({ "sturdy wharf","wharf" }) :
                   "The wharf is up and little to the west of here.  "
                   "It is a large sturdy thing that this dock is "
                   "attached to.",
                ({ "expansive ocean","ocean" }) :
                   "The ocean spreads out under the floating "
                   "docks and beyond.  It is dirty and many "
                   "sailors dump trast into it, but it probably "
                   "has a few fish here.",
           ]) );
   SetItemAdjectives( ([
                         "docks" : ({ "parva","parvas","floating" }),
                         "ramp" : ({ "steep" }),
                         "wharf" : ({ "sturdy", }),
                         "ocean" : ({ "dirty","expansive" }),
                    ]) );
   SetListen( ([
                 "default" : "The waves rock against the docks and "
                    "then crash noisily into the shore.  Fishermen "
                    "shout out at each other, and Parva's noises "
                    "drift in from the west.",
            ]) );
   SetSmell( ([
                "default" : "The salty ocean, gutted fish, and "
                   "trash thrown into the water make it stink pungently.",
           ]) );

   SetProperty("no bump", 1);
   SetExits( ([
                "up" : P_ROOM + "/wharf1",
           ]) );
   AddExit("down", AH_ROOM + "corridor1", (: PreExit :) );
   AddExit("east", INNERSEA_VIRTUAL "ocean/17,27");
   SetSpeed(8);
   SetFish( ([
               P_OBJ + "/smallfish" : 200,
               P_OBJ + "/trash" : 20,
          ]) );
   SetChance(50);
   SetMaxFishing(5);
   SetInventory( ([
                    P_NPC + "/fisherman" : 1,
                    P_OBJ + "/yacht"     : 1,
                    P_NPC + "/shipseller": 1,
               ]) );
}


int PreExit(string dir) {
  if ( (this_player()->GetGuild() == GUILD) || (creatorp(this_player()) ) )  return 1;
  message("my_action",
          "%^BLUE%^A wave crashes against the dock, swaying it violently "
          "and knocking you from your "
          "feet!%^RESET%^", this_player() );
  message("other_action", "%^BLUE%^A wave crashes against the dock, "
          "swaying it violently!%^RESET%^",
          this_object(), this_player());
  this_player()->eventCollapse();
  return 0;
}

string GetObviousExits() {
  if (this_player()->GetGuild() == GUILD) return ::GetObviousExits();
  return (implode(GetExits() - ({ "down" }), ", "));   
}

