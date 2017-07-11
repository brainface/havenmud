#include <lib.h>
inherit LIB_PLANET;

static void create(){
    ::create();
    SetName("hydrus");
    SetSystem("Sol");
    SetLandingZone("/domains/sol/worlds/hydrus/room/spaceport");
    SetLocation("10,5,-10");
    SetAppearance("a blue ocean planet");
}
