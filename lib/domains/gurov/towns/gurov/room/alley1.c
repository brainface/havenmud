#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_ROOM;
string eventSearchPile();
int BeenSearched;

static void create() {
  ::create();
  BeenSearched = 0;
  SetClimate("sub-arctic");
  SetExits( ([
    "east" : GUROV_ROOM "cr6",
    ]) );
  SetShort("a dimly lit alleyway");
  SetLong(
    "This alley runs along the Gurov cemetery and has a commanding view of "
    "the Cathedral of Three Gods. The alley is dimly lit and has an obvious look "
    "of someplace that isn't well kept. A poorly constructed building at the "
    "end of the alley seems to serve as some kind of house. "
    "Piles of refuse seem to be littered at random around the alley."
    );
  SetSmell("Something smells like it may have died in the alley.");
  SetListen("Rats scurry about hidden from view.");
  SetDayLight(-15);
  SetItems( ([
    ({ "building", "house" }) : "This a a shabby and rundown looking house.",
    ({ "pile", "piles" }) : "The piles seem to be of random refuse.",
    ({ "refuse" }) : "There is refuse here, which seems to be heaped in "
    "in to various piles.",
    ]) );
  SetItemAdjectives( ([
    "building" : ({ "poorly", "constructed", "shabby", "rundown", }),
    "pile"     : ({ "refuse", }),
    ]) );
  SetSearch( ([
    "pile" : (: eventSearchPile :),
    ]) );
  SetEnters( ([
    "building"     : GUROV_ROOM "houses/house1",
    ]) );
}

varargs void reset(int count) {
  ::reset();
  BeenSearched = 0;
}

string eventSearchPile() {
  object who = this_player();
  
  if (BeenSearched) {
    return "You find nothing of value.";
  }
  BeenSearched = 1;
  if (!(who->GetQuestCompleted("Gurov Trash Search"))) {
    who->AddQuest("the Trash Picker", "Gurov Trash Search");
    who->AddDevelopmentPoints(2);
  }
  new(STD_CLOTHING "boot/laced_shoes")->eventMove(who);
  return "You find some new shoes!";
}
