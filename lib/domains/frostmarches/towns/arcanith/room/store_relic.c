/*  A room for recovered relics from the ruins
//  (essentially an armoury store)
//  Mahkefel 2010
*/


#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort ("a relic storeroom");
  SetClimate("indoors");

  SetAmbientLight(50);
  SetExits( ([
    "out"  : ROOM "/ruins5",
    "up"   : ROOM "/townhall",
  ]) );

  SetLong(
    "It appears this building has faired the ravages of time far better "
    "than the surrounding ruins. The floor is covered in a large mural of "
    "Kailie, paired with a stylized sun painted on the ceiling. Work tables "
    "and wooden shelves line the walls, holding artifacts in various states "
    "of repair. In the center of the room, a spiral staircase rises through "
    "the painted ceiling into the second story."
  );

  SetItems( ([
    ({"tables", "shelves", "artifacts" }) : "The tables and shelves hold "
      "pottery shards, rotten baskets, and rusted tools of great interest "
      "to the historian but little practical value.",
    ({"staircase","stairs"}) : "An elegant spiral staircase "
      "ascends to the next floor. It is made of a transclucent "
      "green glass, and gives the impression of a "
      "tower rising to the sun.",
    ({"sun mural","sun","ceiling"}) : "A stylized mural of the sun decorates "
      "the ceiling. Some enchantment is obviously in work, as the brilliant "
      "orange and red hues flicker and glow with slight warmth.",
    ({"clouds","cloud"}) : "Painted clouds occasionally drift across the "
      "marble ceiling.",
    ({"world mural", "kailie mural", "world", "kailie", "floor", "arcanith"}) :
      "A giant mural of Kailie covers the floor with muted greens and browns. "
      "The mural is obviously out of scale, as the city of Arcanith dominates "
      "the center, surrounding the staircase. Rivers and seas sparkle with "
      "the illusion of moving water, and lights flash and flicker from Arcanith "
      "and various other settlements across the mural.",
    ({"mural"}) :
      "Do you mean the sun mural or Kailie mural?",
  ]) );

  SetItemAdjectives( ([
    "tables" : ({"work","wooden"}),
    "staircase" : ({"spiral"}),
    "sun mural" : ({"stylized"}),
    "clouds" : ({"painted"}),
    "mural" : ({"large"}),
  ]) );

  SetListen( ([
    "default"  : "Many highpitched voices can be heard upstairs."
  ]) );

  SetInventory( ([
    NPC "/golem_smith" : 1,
    NPC "/koboldm" : 1,
    OBJ "/display_case" : 1,
  ]) );
}

void heart_beat() {
  string mural;
  ::heart_beat();
  switch(random(8)) {
    case 0:
      mural = "The sun mural %^BOLD%^YELLOW%^flickers%^RESET%^ with light.";
    break;
    case 1:
      mural = "The sun mural %^BOLD%^RED%^pulses%^RESET%^ with warmth.";
    break;
    case 2:
      mural = "Fluffy white %^BOLD%^WHITE%^clouds%^RESET%^ drift across the ceiling.";
    break;
    case 3:
      mural = "Dark, angry %^BOLD%^BLACK%^clouds%^RESET%^ roll across the ceiling.";
    break;
    case 4:
      mural = "Tiny, antsized ships %^BLUE%^sail%^RESET%^ across the floor.";
    break;
    case 5:
      mural = "The forests on the floor fade to a fall %^ORANGE%^orange%^RESET%^.";
    break;
    case 6:
      mural = "Snow slowly forms on the mountains along the floor.";
    break;
    default:
      mural = "Rivers %^CYAN%^shimmer%^RESET%^ along the floor.";
    break;
  }
  eventPrint(mural);
}

