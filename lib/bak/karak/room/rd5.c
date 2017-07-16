#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("Center of Town");
  SetDayLong(
    "This cobbled street bears the tell-tale signs of frequent "
    "travel. It is here that Ahriman's Passage widens in to a "
    "small circle, forming the center of Karak-Varn. "
    "There is an open door and a large sign proclaiming a "
    "structure to the north as the General Store.  To the south "
    "is a little structure that serves as a Post Office."
  );
  SetNightLong(
    "Ahriman's Passage widens here, forming the center of "
    "Karak-Varn. The cobbled street widens into a small circle. "
    "A torch here lights the way to the General Store just "
    "through a small door to the north.  Across the dark cobbled "
    "street to the south is the local Post Office."
  );
  SetItems( ([
    ({ "cobbled street","street" }) :
       (: GetLong() :),
    ({ "torch","dark street","dark cobbled street" }) :
       (: GetNightLong() :),
    ({ "open door","door","general store","store" }) :
       "To the north of the street, an open door leads to a structure with "
       "a sign above it, reading: General Store.:",
    ({ "little structure","local post office","local office","local post",
       "post","office" }) :
       "To the south of the street, the Post Office sits."
  ]) );
  SetItemAdjectives( ([
    "office" : ({ "post", "town"}),
  ]) );
  SetEnters( ([
    ({ "general store","store" }) : K_ROOM + "/shop",
    ({ "post office","office","post" }) : K_ROOM + "/post"
  ]) );
  SetExits( ([
    "east" : K_ROOM + "/rd4",
    "west" : K_ROOM + "/rd6"
  ]) );
}
