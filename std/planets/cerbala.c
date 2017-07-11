#include <lib.h>
inherit LIB_PLANET;

static void create() {
  ::create();
  SetName("cerbala");
  SetSystem("Cerbala");
  SetLandingZone("/domains/cerbala/worlds/cerbala/room/port");
  SetLocation("5,5,5");
  SetAppearance("a densely inhabited world with little vegetation");
}
