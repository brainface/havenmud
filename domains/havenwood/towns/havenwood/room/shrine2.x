/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
// mahkefel 2013: gave a less funky short room desc. 
//  Duuk's clothes are no longer lying around.
 
#include <lib.h>
#include "../wood.h"
inherit LIB_CHAPEL;

static void create() {
  ::create();
  SetExits( ([
    "out" : HWD_ROOM "/gelf7",
    ]) );
  SetInventory( ([
    HWD_NPC "/gittia" : 1,
    ]) );
  SetProperty("no bump", 1);
  SetShort("inside the Shrine");
  SetLong(
    "Whatever tree once stood here must have been truly ancient, as the walls of "
    "the stump enclosing the shrine stand ten paces apart. Candles burning incense "
    "drip wax messily along the sides and interior. Tiny saplings, doubtless "
    "seedlings of the original tree, grow in cluttered fashion on the ground. Far "
    "above, the canopy of the Havenwood clouds the view of the sky with verdant "
    "leaves."
  );
  SetItems( ([
    ({ "ground", "floor" }) :
      "The floor of the shrine is a treacherous network of roots and saplings, "
      "dotted with crawling insects and the occasional slithering thing.",
    ({ "walls", "stump" }) :
      "The bark of the stump seems hardened with age, and is dotted with burning "
      "tapers and incense candles. Here and there, leafy sprouts grow still, "
       "indicating life has not quite left.",
    ({ "walls", "stump" }) :
      "The bark of the stump seems hardened with age, and is dotted with burning "
      "tapers and incense candles. Here and there, leafy sprouts grow still, "
       "indicating life has not quite left.",
    ({ "candles"}) :
      "Smoky candles of old beeswax line the walls of the stump.",
    ({ "saplings", "seedlings"}) :
      "Tiny seedlings sprout from the ground all about, crowding the peaceful shrine.",
    ({ "canopy", "leaves" }) :
      "The canopy of the surrounding trees nearly blocks out the sky, shading "
      "everything in verdant hues.",
      ]) );
  SetItemAdjectives( ([
    "candles" : ({ "incense" }),
    "saplings" : ({ "tiny" }),
    "leaves" : ({ "verdant" }),
    ]) );

  SetListen("Branches above sway and murmer in the wind.");
  SetSmell("A faint scent of incense sits in the air.");
  SetReligion( ({ "Eclat" }) );
  SetClimate("temperate");
  SetAmbientLight(20);

  
}

void heart_beat() {
  string mural;
  ::heart_beat();
  switch(random(8)) {
    case 0:
      mural = "Crickets chirp lively around you.";
    break;
    case 1:
      mural = "A hummingbird buzzes noisily about.";
    break;
    case 2:
      mural = "A flight of doves passes overhead.";
    break;
    case 3:
      mural = "Squirrels leap from tree to tree, chattering noisily.";
    break;
    case 4:
      mural = "A wolf howls mournfully somewhere in the distance.";
    break;
  }
  eventPrint(mural);
}

