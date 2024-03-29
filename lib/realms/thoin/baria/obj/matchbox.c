//
// Summary: a small matchbox
// Created by: Rhakz@Haven -- Angel Cazares
// For: Baria
// Date: 12/28/98
//
#include <lib.h>

inherit LIB_STORAGE;

static void create() {
  storage::create();
  SetKeyName("matchbox");
  SetId( ({ "matchbox" }) );
  SetAdjectives( ({ "small","wooden" }) );
  SetShort("a small matchbox");
  SetLong("This is a small wooden matchbox. It has a small dragon "
          "carved on both sides of it.");
  SetInventory( ([
                  "/std/obj/light/match.c" : 20
              ]) );
  SetMass(15);
  SetValue(10);
  SetCanClose(1);
  SetClosed(1);
  SetMaxCarry(100);
}

