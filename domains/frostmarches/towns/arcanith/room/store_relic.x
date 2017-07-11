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
    "templong: "
    "This room houses relics recovered from the ruins. "
    "A spiral staircase leads to an upstairs room. "
    "A sun mural decorates the ceiling. "
    "A mural of Kailie decorates the floor. "
  );

  SetItems( ([
    ({"staircase","stairs"}) : "An elegant spiral staircase "
      "ascends to the next floor. It is made of a transclucent "
      "green material, and gives the impression of a "
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

