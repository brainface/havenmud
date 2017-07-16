#include "../keryth.h"
#include <lib.h>

inherit LIB_ROOM;

int CheckCleric();

static void create()
{
  room::create();
  SetClimate("indoors");
  SetAmbientLight(50);
  SetShort("the Temple of Soirin");
  SetLong("This tall structure serves as Keryth's place of worship for "
          "Soirin.  While it is not exceptionally spacious, there is room to "
          "move around.  A large altar rests in the middle of the room.  "
          "There is another room to the south.  Tremendous energy seems to "
          "eminate from there.");

  SetItems( ([
    ({ "structure", "temple", "room" }) : (: GetLong :),
    ({ "altar" }) : "The large altar dominates the room.",
    ({ "board room" }) : "The board room is for clerics of the Soirin faith."
  ]) );

  SetItemAdjectives( ([
    "structure" : ({ "functional", "sturdy" }),
    "altar" : ({ "stark", "granite", "large" }),
    "board room" : ({ "smaller", "less formal" })
  ]) );

  SetListen( ([ "default" : "A strange, low pitched hum fills the room." ]) );
  SetExits( ([ "out" : K_ROOM + "main_07" ]) );
  AddExit("south", K_ROOM + "temple_back", (: CheckCleric :));
}

int CheckCleric()
{
  object ob = this_player();

  if (creatorp(ob)) return 1;
  if (!(ob->ClassMember("cleric")) || (ob->GetReligion() != "Soirin"))
  {
    send_messages( ({ "are" }), "$agent_name $agent_verb prevented from "
                  "entering the board room by a mystical force.", ob, 0,
                  this_object());
    return 0;
  }

  return 1;
}
