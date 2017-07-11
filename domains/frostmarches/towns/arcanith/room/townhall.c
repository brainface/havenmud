/*  Den of the kobold mother
//  (townhall)
//  Mahkefel 2010
*/


#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort ("a den of kobolds");
  SetClimate("indoors");

  SetAmbientLight(50);
  SetExits( ([
    "down"   : ROOM "/store_relic",
  ]) );

  SetLong(
    "The upper story of this building seems to have been set aside "
    "as some sort of den or headquarters. Blankets and animal hides "
    "cover the floor, and a board of notices stands next to a small "
    "clerk's desk. "
    "A dark mural inset with twinkling lights "
    "stretches over the walls and ceiling, broken only by a set "
    "of windows overlooking the streets below. A staircase in the "
    "center of the floor descends to the lower story."
  );

  SetItems( ([
    ({"blanket","blankets","hides"}) :
      "Thick goat hides soften the cold stone floor.",
    ({"floor","moon","illumini"}) :
      "The floor seems to be a mural of stormy skies centered "
      "on the moon Illumini, but it is largely obscured by "
      "the pile of blankets.",
    ({"mural", "wall","walls","ceiling","serpent","serpents",
      "lion","lions","animals","constellations","lights"}) :
      "Fanciful serpents, lions, and other animals parade about "
      "the darkly painted walls matching the constellations of antiquity.",
    ({"window","windows","glass","frames"}) :
      "The glass and frames look new.",
    ({"staircase"}) :
      "The stairs lead back down to the storeroom",
    ({"streets"}) :
      "Once crowded streets now lie empty except for the occasional "
      "patrolling kobold or fortune seeker.",
    ({"desk","papers","maps"}) :
      "The desk is covered with papers and maps.",
  ]) );


  SetItemAdjectives( ([
    "blanket" : ({"animal","thick","pile","of"}),
    "floor" : ({"moon","cold","stone"}),
    "mural" : ({"dark","twinkling"}),
    "window" : ({"set","of"}),
    "desk" : ({"clerks","clerk","clerk's"}), // probably doesn't work cause of '
  ]) );

  SetNewsgroups( ({ "town.arcanith" }) );

  SetListen( ([
    "default"  : "The room is a cacophony of chattering voices.",
  ]) );

  SetSmell( ([
    "default" : "It smells of unwashed bodies and animal hides.",
  ]) );

   SetInventory( ([
    OBJ "/poster" : 1,
    NPC "/sage" : 1,
    NPC "/mayor" : 1,
    NPC "/kobold_childm" : 2,
   ]) );
}

void heart_beat() {
  string mural;
  ::heart_beat();
  switch(random(8)) {
    case 0:
      mural = "The floor %^BOLD%^BLUE%^shine%^RESET%^ with light under the blankets.";
    break;
    case 1:
      mural = "A flickering star %^BOLD%^WHITE%^shoots%^RESET%^ across the ceiling.";
    break;
    case 2:
      mural = "A stellar lion %^BOLD%^YELLOW%^roars%^RESET%^ silently above you.";
    break;
    case 3:
      mural = "A dark red moon %^RED%^crawls%^RESET%^ across the ceiling.";
    break;
    case 4:
      mural = "A huge serpent %^BOLD%^BLUE%^glitters%^RESET%^ as it coils around the walls.";
    break;
  }
  eventPrint(mural);
}

