#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("temperate");
    SetDomain("Crystal Reaches");
    SetShort("a mining village");
    SetLong(
      "This is a village where the miners and their "
      "families reside. There is no true center; the houses "
      "are scattered about in a random manner. The "
      "houses are small, but enough to suffice for the simple "
      "life that the humans here live. The mine is towards "
      "the southeast and the farmlands are to the west."
    );
    SetItems( ([
      ({"town", "village"})  :  (: GetLong:),
      ({"houses", "house", "homes", "home"})  :
      "The miners homes are exceedingly small.  Even though "
      "they are scattered, "
      "they are densely concentrated around the trail leading "
      "to the mine.",
      "trail"  :
      "The trail is well trodden and is obviously the trail by "
      "which the miners reach their mine.",
      ({"farmland", "farmlands"})   :
      "Farmlands can be seen to the west.",
      "mine"   :
      "The trail going eastwards leads to the mine.",
      ({"grass", "grasses"})  :
      "The grass has been trampled by activities.",
      ({"top", "tops"})  :
      "The tops of the hills and rounded.",
      ({"fields", "field"})  :
      "Vast fields of wheat wave gently in the breeze and can be seen "
      "expanding out to the west.",
    ]) );
    SetItemAdjectives( ([
      "town"    :  ({"small", "mining"}),
      "houses"    :  ({"small", "mining"}),
      "farmland"    :  "western",
      "mine"  :  "eastern",
      "home"    :   ({"small", "mining"}),
      "trail"   :  ({"well-trodden", "used"}),
      "grass"    :  "trampled",
      "fields"    :  ({"vast", "wheat"}),
    ]) );
    SetSmell( ([
      "default"  :  "The smells of baking fills the air.",
    ]) );
    SetListen( ([
      "default"  :  "Children can be heard playing.",
    ]) );
    SetExits( ([
      "southeast"  :  ROOMS + "/gang2.c",
      "west"  :  ROOMS + "/field.c",
    ]) );
}
