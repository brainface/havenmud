#include <lib.h>
inherit LIB_PLANET;

static void create() {
  ::create();
  SetName("parva");
  SetLandingZone("/worlds/Parva/room/p01");
  SetLocation("0,0,0");
  SetAppearance("a dull grey planet that seems inhabited");
}
