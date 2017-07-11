#include <lib.h>
#include "../newbie.h"
inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("yellowed skeleton");
    SetRace("human", "skeleton");
    SetShort("a yellowed skeleton");
    SetUndead(1);
    SetId( ({ "skeleton", "human" }) );
    SetAdjectives( ({ "yellowed" }) );
    SetEncounter(30);
    SetClass("fighter"); 
    SetLevel(6);
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
