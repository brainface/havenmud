/* 5/03 Libitina  /  newbie area  /  wooded vale  */

#include <lib.h>
#include "../wood.h"
#define EXIT "/domains/peninsula/virtual/vimp/0,6"
int CheckExit();
inherit LIB_ROOM;

static void create() {
    ::create();
    SetShort("entrance to a small wooded vale");
    SetLong("Various shrubs flow out of the vale, like foam on the waves of "
      "the sea. Several varieties grow in harmony, some producing berries "
      "and some flowers. A small path, littered with needles from the "
      "corsican pine trees leads north, further into the forest."
    );
    SetItems( ([
	"shrubs" : "Mostly about waist high, these plants grow closely "
	"together, "
	"intertwinning their branches, mixing their berries and flowers. "
	"Several bear sharp thorns that could be quite dangerous if not "
	"taken notice of.",
	"vale" : "This small vale is the home of several corsican pine trees, "
	"various plants, and several animals.",
	"berries" : "Dark purple berries grow on a few of the plants. "
	"They're only about "
	"the size of a pea, with a rather hairy skin.",
	"flowers" : "Small white flowers are sprinkled throughout the "
	"shrugs, giving "
	" off a delicate fragrance.",
	"path" : "Rather small, the path is lined with plants and small pine "
	"saplings.",
	"trees" : "Not nearly as large as many forest's varieties, the "
	"corsican pine "
	"trees of this vale are only mediocre in size, though not lacking "
	"in beauty.",
	"forest" : "Hardly able to be called a forest, this vale is home "
	"to beautiful "
	"trees "
	"and plants, and likely several animals as well. Most likely some "
	"decent small-game hunting available here.",
      ]) );
    SetSmell("default", "A faint, sweet scent hovers lightly "
      "in the air.");
    SetListen("default", "The vegitation rustles with each breath "
      "of wind.");
    SetExits( ([
	"north" : WOOD_ROOM "vale1.c"
      ]) );
    AddExit("west", EXIT, (: CheckExit :));
    SetDayLight(-5);
    AddWarmth(-10);
}

int CheckExit() {
  if (this_player()->id("animal_wander")) return 0;
  return 1;
}
