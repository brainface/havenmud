#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

void DoDive(object who);
void DoSurface(object the_player);

static void create()
{
  room::create();
  SetClimate("outdoors");
  SetShort("deep pool");
  SetLong("The water is deep and very cold.  There is no telling what is "
          "hidden below its surface, as light does not seem to penetrate "
          "more than a few inches into its depths.");
  SetItems( ([
              "water" : "The water is so murky as to be black.  Light does "
                        "not penetrate very far into it's depths."]) );
/*
  SetDive( ([
             "underwater" : 1,
             ]) );
*/
  SetExits( ([ "out" : GWONISH + "room/swamp26"]) );
}


void DoDive(object who)
{
  message("environment",
          "Summoning a lungful of air, you dive beneath the surface of the "
          "water.",who);
  message("environment",
          who->GetName() + " takes a huge breath and dives beneath the "
          "surface.",environment(who),who);
  message("environment",
          who->GetName() + " takes a huge breath and dives beneath the "
          "surface of the pool.",GWONISH + "room/swamp26");
  who->eventMove(GWONISH + "room/underwater");
  who->eventForce("look");
  call_out("DoSurface",20,who);
}

void DoSurface(object who)
{
  message("environment",
          "Running out of air, you burst to the surface.",
          who);
  message("environment",
          who->GetName() + "swims quickly to the surface.",
          environment(who),who);
  message("environment",
          who->GetName() + " bursts to the surface of the pool gasping "
          "for air.",
          find_object(GWONISH + "room/pool"));
  message("environment",
          who->GetName() + " bursts to the surface of the pool gasping "
          "for air.",
          find_object(GWONISH + "room/swamp26"));
  who->eventMove(GWONISH + "room/pool");
  who->eventForce("look");
}

int eventDive(object who, string args)
{
 DoDive(who);
}

