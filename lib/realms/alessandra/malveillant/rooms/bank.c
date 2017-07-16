/*  Portia   12-9-98
    The bank of Malveillant.
    version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetTown("Malveillant");
  SetShort("The Bank of Malveillant");
  SetExits( ([
    "out" : MAL_ROOMS + "path13",
    ]) );
  SetListen( ([
    "default" : "The bank is deathly silent."
    ]) );
  SetSmell( ([
    "default" : "The rooms smells of money.",
    ]) );
  SetInventory( ([
    MAL_NPC + "karin" : 1,
    ]) );
  SetLong("The Bank of Malveillant is perfectly clean. The "
    "jet black obsidian floor sparkles without a trace of dust "
    "and the large obsidian counter shines immaculately. This "
    "counter is apparently used for all of the transactions of "
    "the bank as it is littered with papers and an assortment "
    "of coins. The operator of this bank is quite obviously "
    "quite orderly and requires all around her to be orderly "
    "as well.");
  SetItems( ([
    ({"bank", "bank of malveillant"}) : (:GetLong:),
    ({"floor", "counter"}) : "The obsidian floor and counter sparkle.",
    ({"papers", "paper", "coins", "coin"}) : "Papers and coins "
        "litter the counter.",
    ]) );
  SetItemAdjectives( ([
    "bank" : ({"clean", "perfectly"}),
    "floor" : ({"jet", "black", "obsidian", "large"}),
    ]) );
 }
