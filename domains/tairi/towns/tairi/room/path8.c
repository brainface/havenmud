#include <domains.h>
#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("at the end of Chrysanthemum path");
  SetExits( ([
     "east"      : TAIRI_AREAS "ninja_tower/room/n_path1",
     "southwest" : "path4",
     "west"      : "path7",
    ]) );
  SetLong("The path ends here in front of two buildings. "
          "To the north is the Taisoka Temple, with its "
          "small wooden frame it is a humble station of harmony "
          "within the small town. To the south is a dull building "
          "that seems to be of little import to the town.");
  SetItems( ([
    ({ "town", "tairi", "center" }) :
    	    "The center of town is west of the this interesection.",
    ({ "path", "road" }) :
          "This dirt path heads west towards town and southwest towards "
          "the inn.",
    "buildings" : 
    	    "The buildings are small and wood framed with paper walls. "
    	    "The southern building appears to be some kind of office, "
    	    "while the northern three floored on is the Temple of Taisoka.",
    ({ "temple", "building" }) :
          "The Taisoka Temple is a small three floored wooden building "
          "with paper walls that are well maintained.",
    ({ "office", "building" }) : 
    	    "The local post office is a dull building of little charm.",
    ]) );
  SetItemAdjectives( ([
    "town"     : ({ "small" }),
    "path"     : ({ "dirt" }),
    "building" : ({ "small", "wooden" }),
    "office"   : ({ "dull", "local", "post", "small" }),
    "temple"   : ({ "humble", "taisoka"}),
    ]) );
  SetEnters( ([
    "office" : TAI_RI_ROOM "post",
    "temple" : TAI_RI_ROOM "temple",
    ]) );
  SetSmell( ([
    "default" : "The scent of flowers is mixed with incense here.",
    ]) );
  SetListen( ([
    "default" : "A soft chant comes from the temple.",
    ]) );
  SetInventory( ([
    ]) );
}


