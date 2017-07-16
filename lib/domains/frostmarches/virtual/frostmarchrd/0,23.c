/*  Attachment to Vanyels Ice Area */
#include <lib.h>
#include <domains.h>
#define VANYEL_ICE 1
#define ICE_DIRECTION ({ "northwest", FROSTMARCHES_AREAS+"ice/room/road1" })
inherit FROSTMARCHES_VIRTUAL+"frostmarchrd";

static void create(int x, int y) {
  ::create(0, 23);
  SetExits( ([
      "north" : "0,24",
      "south" : "0,22",
    ]) );
  if (VANYEL_ICE) {
    SetLong( GetLong() +
       "An offshoot seems to lead to the northwest.");
    AddExit(ICE_DIRECTION[0], ICE_DIRECTION[1]);
    SetObviousExits("north, south, northwest");
    }
 }

