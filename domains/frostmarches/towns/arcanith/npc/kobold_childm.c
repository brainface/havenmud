/* A kobold child */

#include <lib.h>
#include "../ruins.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("kobold");
  SetId( ({ "child" }) );
  SetAdjectives( ({ "kobold" }) );
  SetShort("a kobold child");
  SetLong("The kobold child looks very similar to an adult.  Small and with "
          "a dog-like head, the child will grow as vicious and destructive "
          "as his parents.");

  
  SetRace("kobold");
  SetClass("rogue");
  SetGender("male");
  SetLevel(1);
  SetMorality(-5);

  SetAction(5, ({ "!whine", "!bark" }) );
  SetInventory( ([ OBJ "/knife_old" : "wield knife" ]) );
  SetDie("The kobold dies wimpering for his mother.");

}
