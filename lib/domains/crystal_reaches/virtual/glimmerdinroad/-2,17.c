#include <lib.h>
#include <domains.h>

inherit CRYSTAL_REACHES_VIRTUAL "glimmerdinroad";
int DomainCheck();

static void create(int x, int y) {
  ::create(-2,17);
  AddExit("east", CRYSTAL_REACHES_AREAS "ungkh/room/road01", (: DomainCheck :) );
}

int DomainCheck() {
  if (this_player()->GetLevel() <= 49) {
    this_player()->eventPrint("After further review, you decide not to go into Ungkh.");
    return 0;
  }
  return 1;
}
