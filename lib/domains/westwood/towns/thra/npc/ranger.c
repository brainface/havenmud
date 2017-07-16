/*  A valkyr goblin */
#include <lib.h>
#include "../goblins.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("valkyr");
  SetShort("a small goblin valkyr");
  SetId( ({ "goblin", "valkyr" }) );
  SetAdjectives( ({ "small" }) );
  SetRace("goblin");
  SetClass("rogue");
  SetSkill("blunt combat",1,2);
  SetLevel(random(6) + 20);
  SetMorality(-25);
  SetFriends( ({ "markotal" }) );
  SetLong("This wiry goblin is a smaller and less dangerous version "
          "of the older valkyrs. He is still a dangerous opponent, "
          "if not the biggest of enemies.");
  SetGender("male");
  SetCurrency( ([
      "rounds" : random(300),
     ]) );
  SetInventory( ([
      GOBLIN_OBJ + "vest" : "wear vest",
     ]) );
  if (!random(4)) {
    new(GOBLIN_OBJ + "club")->eventMove(this_object());
    call_out( (: eventForce, "wield my club" :), 0);
  }
}
