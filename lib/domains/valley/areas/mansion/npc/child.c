/* small child
   kyla 7-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  
  SetKeyName("child");
  SetId( ({"child"}) );
  SetAdjectives( ({"small", "child"}) );
  SetShort("a small blonde child");
  SetLong("This small blonde child is quite cute and obviously "
          "has rather attractive parents. He appears to be around "
          "six or seven years old.");

  SetRace("human");
  SetClass("rogue");
  SetGender("male");
  SetLevel(2);
  SetMorality(250);
  SetAction(6, ({"The child glances at you and goes back to "
              "playing."}) );
  SetInventory( ([
        ]) );
  }
