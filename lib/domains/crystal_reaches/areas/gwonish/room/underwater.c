#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;


string DoSearch(string useless);

static void create()
{
  room::create();
  SetClimate("indoors");
  SetAmbientLight(10);
  SetShort("underwater");
  SetLong("Even with what light is available the water is too murky to see "
          "anything.");
  SetExits( ([ "up" : GWONISH "room/pool"]) );
  SetObviousExits("up");
  SetSearch( (["default" : (: DoSearch :) ]) );
}


string DoSearch(string useless)
{
  object ob;

/*
  if(MyUnique(GWONISH+"obj/diamond_pendant",7))
  {
    ob = new(GWONISH + "obj/diamond_pendant");
    ob->eventMove(environment(this_player()));
    return "You find a small pendant in the silt at the bottom of the pool.";
  }
*/
  return "You find only silt and sand at the bottom of the pool.";
}
