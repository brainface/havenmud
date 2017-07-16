#include <lib.h>
#include <jump.h>
#include <meal_types.h>
#include "../rook.h"
inherit LIB_MEAL;
inherit LIB_JUMP;

int doJump();

static void create() {
  meal::create();
  jump::create();
  SetKeyName("river");
  SetId( ({ "river" }) );
  SetShort("a river");
  SetLong("This is a raging river.  The water is clear and clean.");
  SetPreventGet("You cant get a river.");
  SetMass(10000);
  SetJump( (: doJump :), JUMP_INTO);
  SetInvis(1);
  SetPreventGet("You cannot take a river.");
  SetEmptyItem(R_OBJ + "river");
  SetStrength(50);
  SetMealMessages( ({
    "$N drink from a river.",
    "$N drinks from a river.",
  }) );
}

int doJump() {
  send_messages( ({ "jump" }), "$agent_name $agent_verb "
    "into the %^BLUE%^river%^RESET%^ and is carried away by the current.",
    this_player(), 0, environment(this_player()));
  this_player()->eventMoveLiving("/domains/southern_coast/towns/haven/room/wharf");
  send_messages( ({ }), "$agent_name is washed up on the shore line "
    "by the incoming %^BLUE%^waves%^RESET%^.",
    this_player(), 0, environment(this_player()));
  return 1;
}
