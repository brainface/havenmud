#include <lib.h>
#include <vendor_types.h>
#include "../grymxoria.h"
inherit LIB_CHAPEL;
 
static void create() {
  chapel::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("the Church of Saahagoth");
  SetLong(
    "The basilica of the mother church of Saahagoth.  "
    "This is a huge room built in the gothic style. "
    "Long rows of black marble benches line the room. "
    "At the end of the room is large black marble statue "
    "of the Dark Goddess of Saa'HaGoth. At the feet of "
    "the statues is a pulpit for uses by the Prophet.  "
    "At the back of the room is a large instrument that looks "
    "like a pipe organ."
  );
  SetReligion("Saahagoth", "Saahagoth");
  SetClasses( ({ "cleric" }) );
  SetAllowSacrifice(1);
  SetSacrificeType(VT_ALL);
  SetDeities(  ({ "Laoise" })  );
  SetItems( ([
    "benches" : "Long rows of black marble benches.",
    ({ "statue" }) : "A large statue of how the Dark "
    "Goddess is thought to look. It is a large imposing "
    "visage carved out of black marble.",
    "pulpit" : "A small pulpit at the foot of the statue, "
    "carved out of the same black stone as the rest of the "
    "church.",
    ({ "organ", "pipe organ" }) : "A large pipe organ. "
    "The large brass pipes stretch up to the high arched "
    "ceiling."
  ]) );
  SetListen( ([
    "default" : "Depressing and morbid organ music plays "
    "in the background."
  ]) );
  SetInventory(  ([
    G_NPC + "wotan" : 1,
  ])  );
  SetExits( ([ 
    "down" : G_ROOM "church2c" 
  ]) );
}

