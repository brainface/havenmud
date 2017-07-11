#include <lib.h>
#include <domains.h>
#include "../ice.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a tidy campsite");
  SetClimate("arctic");
  SetLong(
	"An orderly campsite is tucked away between the snowdrifts "
	"at the edge of the frozen lake. At its heart, a crackling "
	"fire glows invitingly. To one side, a sturdy tent made of "
	"hides and furs has been pitched. Several well-oiled traps "
	"hang from a tentpole, awaiting use, and two sealed barrels "
	"stand in the snow beside the tentflap. Out on the ice stands "
	"a small, wooden shack."
	);
  SetItems( ([
     ({ "camp", "campsite", "orderly campsite", "orderly camp", "tidy camp",
	"tidy campsite", "area" }) :
	"The campsite has been set up with an eye to neatness and "
	"protection. ",
     ({ "snow", "snowdrifts", "drifted snow", "drifts", }) :
	"Piles of snow protect the camp from casual observation and lessen "
	"the sharpness of the wind.",
     ({ "lake", "frozen lake", "ice", "ice lake", }) : 
	"All of the snow has been cleared from the surface of the lake, and "
	"a small wooden shack stands on the ice not too far from shore.",
     ({ "heart", "fire", "crackling fire", "glowing fire", "campfire", }) :
	"An inviting campfire crackles merrily at the center of the campsite.",
     ({ "tent", "hides", "sturdy tent", "furs", }) :
	"This tent looks as though it was built to take the coldest of "
	"weather.",
     ({ "shack", "wooden shack", "small shack", "small wooden shack", "ice "
	"fishing shack", "fishing shack", }) :
	"A small shed has been erected on the ice, to keep the wind off so "
	"a fisherman can go about his work in relative comfort. ",
     ({ "traps", "trap", "oiled traps", "well-oiled traps", "tentpole", "pole",
	 }) :
	"Some metal jaw-traps, well-cleaned and oiled against the weather, "
	"hang from one of the tent's support poles.",
     ({ "barrel", "barrels", "tentflap", "flap", "wooden barrel", "wooden "
	"barrels", 
	 }) :
	"These barrels contain nothing but dog food for the sled dogs. One "
	"is full of dry kibble, and the other contains hunks of frozen offal. ",
	]) );
  SetExits( ([
    "east" : FROSTMARCHES_AREAS "ice/room/icelake",
  ]) );
  SetEnters( ([
	"tent" : ICE_ROOM + "/tent",
	"shack" : ICE_ROOM + "/shack",
	]) );
  SetInventory( ([
	ICE_NPC + "/malamute" : 4,
	ICE_NPC + "/malamute_leader" : 1,
	 ]) );
  SetListen( ([ "default" : "The wind sighs eerily over the lake. "
	]));
  SetSmell( ([ "default" : "The smells of woodsmoke and dogs are strong here."
	]) );
}

/** Approved by Laoise at Fri Jul  9 20:19:39 2004. **/