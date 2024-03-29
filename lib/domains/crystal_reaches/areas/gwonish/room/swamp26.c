#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int monsterFound;

int CheckMonster(string dir);
void SummonSquid();
string CheckPool(string useless);
int CheckIfGrappled(string dir);

static void create()
{
  room::create();
  SetClimate("indoors");
  SetShort("a shady cave");
  SetDayLong("Chaotic rays of sunlight illuminate the room by shooting in "
             "every possible crack to the outside.  A flickering effect "
             "dances about the room from light reflected off the pool of "
             "water in the northwest section of the cave.  Near the water, "
             "but above the tide line an altar rests.");
  SetNightLong("Soft moonlight filters in through cracks leading to the "
               "outside and provides a bit of illumination to this "
               "otherwise dark room.  In the nortwest section of the room, "
               "a deep pool of water laps against a small altar.");

  SetItems( ([ ({"pool","water"}) :
                        "Although apparently quite clean the depths of the "
                        "pool are not visible due to lighting conditions.",
               "altar" : "A large flat stone rests upon four smaller stones "
                         "forming a tabletop of sorts.  Dark stains filling "
                         "the cracks mar the otherwise clean surface of the "
                         "altar.",
               "cracks" : "The numerous cracks provide the only lightsource "
                          "for this room.  The largest might provide a way "
                          "out of the cave."]) );

  SetInventory(([GWONISH + "npc/lizardmanshaman.c": 1]) );

  monsterFound = 0;
  AddExit("out", GWONISH + "room/swamp25",(:CheckIfGrappled:));

  AddEnter("pool",GWONISH + "room/pool",(: CheckMonster :));

  SetSearch( (["pool" : (: CheckPool :) ]) );

  SetSmell( ([ "default" : "A thick briny smell fills your nose."]) );
  SetListen( ([ "default" : "The endless roar of the surf vibrates the "
                   "rocks around you." ]) );
  SetObviousExits("out");
}

int CheckMonster(string null)
{
  object ob = present("squid");

  if(ob && living(ob))
  {
    write("The giant squid slaps you away.");
    say(this_player()->GetName() + " approaches the pool but is slapped away "
         "by a large black tentacle.");
  return 0;
  }

  if(monsterFound)
  {
  return 1;
  }
  SummonSquid();
}

string CheckPool(string useless)
{
  object ob = present("squid");

  if(ob && living(ob))
  {
    return "The giant squid slaps you away.";
  }

  if(monsterFound)
  {
  return "The pool looks very deep.";
  }

  SummonSquid();
}


void SummonSquid()
{
  object ob;

  write("As you approach the water, a giant tentacle whips out and attacks!");
  say(this_player()->GetName()+ " approaches the pool and is attacked by a "
        "tentacle that explodes from the water.");

  ob = new(GWONISH "npc/squid");
  ob->eventMove(this_object());

  monsterFound = 1;
}


int CheckIfGrappled(string dir)
{
  object *squid;
  if(!creatorp(this_player()) && (this_player()->GetProperty("grappled")) &&
      sizeof(squid = filter(all_inventory(), (: $1->id("squid") && living($1) :) )))
  {
  message("environment",
          "The squid's grasp prevents you from leaving the room.",
          this_player());
  return 0;
  }

  return 1;
}


