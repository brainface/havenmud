#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;
int PreventWander(string dir);

static void create() {
  room::create();
  SetClimate("underground"); SetWarmth(45);
  SetAmbientLight(25);
  SetShort("the entrance to the Great Hall of Glimmerdin");
  SetLong(
     "Contrasting with the almost stark militarist decor of the tunnels "
     "leading the the great hall, the great hall itself is garrishly "
     "decorated, with banners and signs of all varieties hang randomly "
     "from walls and ceiling. A heavily fortified opening "
     "to the east must be the city's bank and a sign over the opening "
     "west of here marks it as the post office.  The great hall "
     "extends to the north and a small tunnel leads south, out of the "
     "hall.");
  SetProperty("no teleport",1);
  SetProperty("no conjuring",1);
  SetItems( ([
    ({ "decorations", "banners", "banner", "signs", "sign" }) :
      "Mixed in with the banners celebrating victory and accomplishment are "
      "hundreds of brightly colored signs, advertising this product or that.",
    ({ "bank", "opening", }) :
      "Barely hidden behind beautiful craftsmanship, the portal to the Bank "
      "of Glimmerdin's fortifications are incredible.  Bars of mithril steel "
      "are inset into either side of the opening, ready to be activated at a "
      "moments notice.",
    ({ "bars", "bar" }) :
      "The bars are easily as thick as a man's wrist and look near "
      "impervious.",
    ({ "office" }) :
      "The city's postal service is set in a drab, dull building.",
    ({ "tunnels", "tunnel" }) :
      "Dimmer than the hall, the tunnel leads south away from the hall.",
    ]) );
  SetItemAdjectives( ([
    "bank"   : ({ "heavily", "fortified", }),
    "office" : ({ "post", }),
    "tunnel" : ({ "small", "smaller" }),
    ]) );
  SetExits( ([
    "north" : G_ROOM "gh_central",
    ]) );
  AddExit("south", G_ROOM "tunnel2", (: PreventWander :) );
  SetEnters( ([
    "bank"   : G_ROOM "bank",
    "office" : G_ROOM "post_office"
    ]) );
  SetSmell( ([
    "default" : "The odors here are too numerous to catalog.",
    ]) );
  SetListen( ([
    "default" : "Trying to concentrate on listening to any one thing is much too difficult.",
    ]) );
  SetInventory( ([ 
    G_NPC "basic_guard" : 1,
    G_NPC "shoe_vendor" : 1,
    ]) );
}

int PreventWander(string dir) {
	object who = this_player();
	
	if (who->id("glim_wander")) return 0;
	return 1;
}
