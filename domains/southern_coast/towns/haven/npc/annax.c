#include <lib.h>
#include "haven.h"
inherit LIB_MAYOR;

static void create() {
  ::create();
  SetKeyName("annax");
  SetShort("Annax Banewulf, Mayor of Haven");
  SetId( ({ "annax", "banewulf", "annax banewulf", "mayor" }) );
  SetAdjectives( ({ "former" }) );
  SetLong("Annax Banewulf is huge for an elf.  Standing nearly \n"
          "seven feet tall, he is the biggest figure in Haven \n"
          "town, both literally and figuratively.");
  SetRace("elf");
  SetGender("male");
  SetClass("cavalier");
  SetLevel(48);
  SetTown("Haven");
  SetReligion("Kylin");
  SetMorality(1400);
  SetInventory( ([
   ]) );
  SetAction(5, ({
    "!speak The Church has allowed me my rule back!",
    "!speak You are welcome to become a citizen!",
    "!beam happily",
       }) );
  SetTax(50);
  SetLocalCurrency("imperials");
  }
