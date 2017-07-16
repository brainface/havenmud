#include <lib.h>
#include <damage_types.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("inside the forge");
  SetLong(
    "The forge is burning with heat!"
  );
  SetExits( ([ 
    "out" : G_ROOM + "black_smith" 
  ]) );
}

void init() {
  ::init();
  if( living(this_player()) && 
    (environment(this_player()) == this_object() ) ) {
      this_player()->eventReceiveDamage(0,HEAT,random(400) );
      call_out( (: init :), 5);
  }
}
