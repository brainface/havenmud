#include <lib.h>
#include <std.h>
#include <dirs.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("A warm place");
  SetLong(
    "This is a workroom. It has no exits, because the owner "
    "is a newbie-killing fool. No feeding the donkey."    
  );
  SetInventory( ([ "/realms/kairehn/donkey" : 1,
                   "/realms/duuk/stuff/thing" : 1, ]) );
  SetObviousExits("nothing");
}
