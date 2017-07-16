//
// the void room for the void spell
// created by Vivake Gupta (Dunedain@Haven)
// 4 august 1998
//

#include <lib.h>

inherit LIB_ROOM;

int cmdGo( string dir );
static void create()
{
  ::create();
  SetShort("an endless void");
  SetLong("Chaos and darkness intermix in all directions.  No material "
          "objects are visible to the eye.  The surroundings suffocate "
          "and protect all who are within.");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetObviousExits("void");
  SetProperty("login", "/domains/haven/room/imperial_road/ir2");
}

static void init()
{
  ::init();
  add_action("cmdGo", "go");
}

int cmdGo( string dir )
{
  send_messages( "go", "$agent_name $agent_verb " + dir + ".", this_player(),
                 0, environment(this_player()) );
  this_player()->eventDescribeEnvironment();
  return 1;
}
