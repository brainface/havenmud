//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "south" : LISHT_ROOM "gnoll/pr2",
    ]) );
  SetShort("Lisht Bazaar");
  SetLong(
    "This is the bustling, hustling bazaar of Lisht. Merchants "
    "cut bargains here, or purses when the situation calls for it. "
    "Brightly colored flags and signs fly, whipping in the wind, "
    "making the bazaar chaotic in design. Pharaoh's Road lies just "
    "to the south of this busy place."
    );
  SetListen("The bazaar is always busy, and always loud.");
  SetItems( ([
    ({ "flag", "flags", "sign", "signs" }) :
    "The flags and signs are of every color and style, and they hang "
    "from poles, posts, tents, and just about anything that can hold "
    "a sign or a flag throughout the bazaar.",
    ]) );
  SetItemAdjectives( ([
    "flag" : ({ "bright", "brightly-colored" }),
  ]) );
  SetInventory( ([
    LISHT_NPC "ptah" :1,
    LISHT_NPC "duamutef" :1,
    LISHT_NPC "citizen" :2,
  ]) );
}

void heart_beat() {
  string yell;
  ::heart_beat();
  if (!random(10)) {
    switch(random(10)) {
      case 0:
        yell = "A vendor yells out, \"Sugar dates! Sugar dates and figs!\"";
      break;
      case 1:
        yell = "This is no ordinary lamp!";
      break;
      case 2:
        yell = "Will not break! ...Oops, it broke.";
      break;
      case 3:
        yell = "Have it your way at McKhufu's!";
      break;
      case 4:
        yell = "Hey! This isn't the Book of the Dead!";
      break;
      case 5:  
        yell = "Talk about being PIG-headed!";
      break;
      case 6:
        yell = "Get your condo made of stone-a right here!";
      break;
      case 7:
        yell = "Get your kohl and incense here, ladies!";
      break;
      case 8:
        yell = "Your mother smells like a crocodile!";
      break;
      default:
        yell = "Peftjawybastet's: Best Tombs in Town!";
      break;
    }
    eventPrint("Someone yells out, \"%^BOLD%^GREEN%^" + yell +
"%^RESET%^\"");
}
}
