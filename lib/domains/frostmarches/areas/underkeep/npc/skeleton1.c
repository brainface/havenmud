//
// A yellowing skeleton
// created by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
 inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("skeleton");
  SetAdjectives("yellowing");
  SetShort("a yellowing skeleton");
  SetLong(
    "This skeleton's bones are yellowed with age, and scratched slightly on "
    "his left shinbone where a rat had been gnawing. Black holes are all "
    "that remain where his eyes once were. All that holds him together is "
    "some invisible force that has propelled him down the eons. He looks "
    "pretty tough."),
  SetId( ({"skeleton"}) );
  SetRace("human");
  SetUndead(1);
  SetGender("male");
  SetUndeadType("skeleton");
  SetNoCorpse(1);
  SetDie("The skeleton crumbles into dust.");
  SetClass("fighter");
  SetLevel(random(10) + 20);
  SetCurrency("crystals",random(70)+15);
  SetInventory( ([
    RNQ_OBJ + "rusty_sword" : "wield sword",
    RNQ_OBJ + "key.c" : 1,
  ]) );
}
