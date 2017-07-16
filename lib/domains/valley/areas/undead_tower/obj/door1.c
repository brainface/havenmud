//   Create by Severen   //
//        door1.c        //
//     Nov. 7th, 1998    //

#include <lib.h>
inherit LIB_DOOR;

static void create() {
    door::create();
    SetSide("out", ([ "id" : ({ "a wooden door","wooden door",
	  "door", }),
	"short" : "a wooden door",
	"long" : "This is the exit from the tower. It is "
	"hard and sturdy and in relatively "
	"good shape compared to the rest of the tower. "
	"There does not seem to be a lock on it.",
	"lockable" : 0,
	"keys" : 0,
      ]) );
    SetSide("tower", ([ "id" : ({ "a wooden door", "wooden door",
	  "door","tower door","a tower door" }),
	"short" : "a tower door",
	"long" : "The tower door stands here untouched "
	"by the effects of age that has ruined the "
	"rest of the tower. It is hard and sturdy "
	"wooden door. There does not seem to be a "
	"lock on it.",
	"lockable" : 0,
	"keys" : 0,
      ]) );
    SetClosed(1);
    SetLocked(0);
}
