//Selket@Haven
//2006
#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {

  room::create();
  SetShort("inside a pen");
  SetClimate("indoors");
  SetAmbientLight(25);
  SetLong(
    "This area of the stable has become the home for some giant's "
    "version of a good pet: a drake. Old carcasses and decaying "
    "skeletons stand where dragon dung doesn't, and the only "
    "way out is back into the front part of the stable. "
    );
  SetSmell("The scent of dragon is strong here.");
  SetListen("Here no one can hear your screams.");
  SetItems( ([
    ({ "pen" }) :
       (: GetLong :),
    ({ "carcasses", "carcass", "skeleton", "skeletons" }) :
    "The carcasses are of large animals and people.",
    ({ "dung" }) : 
    "The piles of drake dung are large and very smelly.",
    ]) );
  SetExits( ([
    "out" : U_ROOM + "stable",
    ]) );
  SetInventory( ([
    U_NPC "flame" : 1,
    ]) );
  }
