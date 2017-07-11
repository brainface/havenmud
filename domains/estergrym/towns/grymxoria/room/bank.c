#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("grymxoria Bank");
  SetLong(
    "The Grymxoria bank, its stone block structure is "
    "reminiscent of a fortress. Tellers stand behind a "
    "marble counter, ready to help you with your banking "
    "needs. There is also a large iron door that leads to "
    "the vault."
  );
  SetItems( ([
    ({ "stone", "block", "stone block", "stone blocks",
    "blocks" }) : "Black stone blocks of an unknown type.",
    ({ "counter", "marble counter" }) : "The tellers counter, "
    "it is made of black marble.",
    ({ "door", "large door", "iron door", "large iron door" }) :
    "A large round iron door set on massive hinges."
  ]) );
  SetInventory( ([
    G_NPC + "rakkar" : 1,
  ]) );
  SetExits( ([ 
    "out" : G_ROOM "road13"
  ]) );
}
