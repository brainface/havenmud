//
// An old skeleton
// created by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
 inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("skeleton");
  SetAdjectives("old");
  SetShort("an old skeleton");
  SetLong(
    "This skeleton, as far as skeleton's go, is on its last legs. He really"
    " is ancient, and time in this damp place has not been kind to him.");
  SetId( ({"skeleton"}) );
  SetRace("human");
  SetUndead(1);
  SetUndeadType("skeleton");
  SetNoCorpse(1);
  SetDie("The skeleton crumbles into dust.");
  SetClass("fighter");
  SetLevel(10 + random(10));
  SetCurrency("crystals",random(30) + 30);
  SetInventory( ([
    RNQ_OBJ + "rusty_sword" : "wield sword",
  ]) );

  SetAction(5, 
    ({"The old skeleton's bones clack together.",
    "The skeleton's leg falls off, and he absently fixes it back on.",
    "The skeleton's arm falls off, and he absently fixes it back on.",
    "The skeleton's head falls off, and he absently fixes it back on.",
    "The skeleton's jaw drops, so he picks it up again.",
    "!stagger tiredly",
    "!whistle"}) );
}
