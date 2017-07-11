#include <lib.h>
#include "../newbie.h"
inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("decayed skeleton");
    SetRace("human", "skeleton");
    SetShort("a decayed skeleton");
    SetUndead(1);
    SetId( ({ "skeleton", "human" }) );
    SetAdjectives( ({ "decayed" }) );
    SetEncounter(30);
    SetClass("fighter");
    SetLevel(4);
    SetLong("This mass of bones seems to be held together by its mere \n"
      "evil aura.  The hideous gleam in its dead eyesockets tells \n"
      "of a penchant desire to slaughter and maim as many living \n"
      "beings as possible before it is dispersed.");
    SetMorality(-200);
    SetDie("The skeleton collapses into dust.");
    SetNoCorpse(1);
    SetInventory( ([
      NEWBIE_OBJ + "/sword" : "wield sword",
      ]) );
}
