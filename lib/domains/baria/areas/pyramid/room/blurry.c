//
// Summary: dark room
// Created by Rhakz - Angel Cazares
// For the ancient pyramid in Jungle
// Date: 10/31/98
//
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("darkness");
  SetClimate("indoors");
  SetAmbientLight(0);
  SetLong("Darkness and mist is all that can be seen here.");
}

