//*       Created by Severen        *//
//*           entrance.c            *//
//*       Mid November 1998         *//

#include <lib.h>
#include "../defs.h"

inherit LIB_ROOM;

int PreExit();

static void create() {
    room::create();

    SetClimate("sub-arctic");
    SetDomain("Valley");
    SetAmbientLight(30);

    SetShort("before an ancient tower");
    SetLong(
      "Centuries old and weather beaten, a stone tower remains standing "
      "here in the shadows of the Crystal Reaches. Large trees make "
      "up the grove surrounding the tower and vines crawl almost to "
      "its top. A doorway stands at the southern end of the tower; "
      "carved runes run along the stone border, giving it the hint of a "
      "magical nature. A path runs south from the door leading down "
      "the mountainside towards a distant town."
    );

    SetItems(([
	({"tower"}) :
	"Grey, cracked stone make up its architecture. There are no "
	"windows or openings besides its south door. Parts of the "
	"tower are worn away but not enough to create holes in it.",
	({"shadow","shadows"}) :
	"The dark shadows of the mountains shade this place.",
	({"crystal reaches"}) :
	"Its caps gleam with snow, therefore giving its name.",
	({"tree","trees"}) :
	"Very old trees stand here and provide shade for the "
	"grove in which they live in.",
	({"grove","garden"}) :
	"A large garden surrounding the tower, only consisting "
	"of a few large trees and the vines covering the tower. ",
	({"vines","vine"}) :
	"Some green, some dead, the vines almost reach the top "
	"of the tower.",
	({"end"}) :
	"There is a doorway there.",
	({"doorway"}) :
	"There is a door in this doorway.",
	({"runes","rune"}) :
	"Strange archaic runes giving the tower a hint of a magical "
	"nature. They are painted red.",
	({"border"}) :
	"There are runes on it.",
	({"path"}) :
	"A dirt path leads from the tower's doorway to a distant town "
	"down the mountainside. It does not seem very well travelled.",
	({"mountainside"}) :
	"Part of the Crystal Reaches, it looks as if the tower was "
	"made from the stone of the mountain.",
	({"town"}) :
	"In the distance is the town of Jidoor.",
      ]));

    SetItemAdjectives(([
	"tower" : ({"old","weather beaten","stone","grey","cracked"}),
	"shadows" : ({"dark"}),
	"trees" : ({"old","large","very"}),
	"grove" : ({"large"}),
	"vines" : ({"green","dead","crawling"}),
	"end" : ({"southern"}),
	"runes" : ({"strange","archaic","red","painted"}),
	"border" : ({"stone"}),
	"path" : ({"dirt"}),
	"town" : ({"distant"}),
      ]));

    SetExits(([
	"southwest" : EXIT ,
      ]));

    AddEnter(
        "tower" , TROOM + "/foyer",
      (: PreExit :) );

    SetDoor("tower", TOBJ + "/door1");

}

int PreExit() {
  object who = this_player();
  
  if (who->GetLevel() < 2 && !creatorp(who)) {
    who->eventPrint("You think better of entering the cold, evil tower just yet.");
    who->eventPrint("<Restricted to level 2+>");
    return 0;
  }
  return 1;
}
