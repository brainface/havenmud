
// Ocean Cave Entrance
// Laoise
// 2001

#include <lib.h>
#include <domains.h>
#include <caves.h>

inherit AVERATH_LIB;

varargs static void create(int x, int y) {
  ::create(8,4,0);

    SetShort("a cairn of rocks");
    SetLong(
    "A large cairn of rocks dominates this section of the beach. It "
    "appears to be comprised of many moderate and large size boulders "
    "which were thrown together by the actions of the tides over time. "
    "The eastern side of the cairn is covered by sand, forming a large "
    "dune, while the western side has a dark opening in the center of "
    "it. This opening is quite large and appears to extend back into "
    "the cairn."
    );
    SetItems( ([
    ({ "beach" }) : (: GetLong :),
    ({ "sand", "dune" }) : "Sand covers the east side of the boulders, "
    "forming a large dune.",
    ({ "cairn", "rock", "rocks" }) : "This large cairn is comprised of "
    "several boulders, covered by sand on the eastern face and with a "
    "visible opening between the rocks to the west.",
    ({ "opening", "crack", "crevasse" }) : "This is an opening in the "
    "eastern side of the cairn of rocks which appears to extend back into "
    "the pile of rocks. This opening appears to be large enough to enter. ",
    ]) );
    SetItemAdjectives( ([
    "sand" : ({ "large", "high" }),
    "opening" : ({ "dark", "large" }),
    "rock" : ({ "medium", "large", "pile", "cairn" }),
     ]) );
/*
    RemoveExit("east");
*/
    SetEnters( ([ "opening" : ROOMS+"8,4,-1" ]) );
}
