#include <lib.h>
#include "../argoth.h"

inherit LIB_ROOM;
static void create() {
    room::create();
    SetShort("a large court");
    SetLong("The road passes the foot of the town hall which reaches up "
    "several stories. To the right of the town hall is the church, and "
    "the cemetery can also be seen. There is a pub to the left, and the "
    "bank lies to the right. The road continues to the south where it "
    "reaches the shores of the Ruined Sea.");
    SetItems( ([
    ({ "road" }) :
    "The road ends a few feet to the south, and extends quite a bit to the north.",
    ({ "town hall", "hall" }) :
    "The town hall of Argoth is one of the largest and most ornate buildings in Kailie.",
    ({ "church" }) :
    "The large black spires of the church rival those of the town hall.",
    ({ "cemetery" }) :
    "The cemetery lies behind the church, shrouded in darkness.",
    ({ "pub" }) :
    "This inn looks out of place amidst the larger buildings.",
    ({ "bank" }) :
    "The bank of Argoth stands here, guarding the wealth of the citizens",
]) );
    SetExits( ([
    "north" : ARGOTH_ROOM + "rd6",
    "south" : ARGOTH_ROOM + "rd8",
]) );
    SetEnters( ([
    "town hall" : ARGOTH_ROOM + "hall.c",
    "hall" : ARGOTH_ROOM + "hall.c",
    "bank" : ARGOTH_ROOM + "bank.c",
    "pub" : ARGOTH_ROOM + "pub.c",
    "church" : ARGOTH_ROOM + "church.c",
    "cemetery" : ARGOTH_ROOM + "cemetery.c",
]) );
    SetSmell( ([
    "default" : "The smell of food and drink wafts in from the pub.",
]) );
    SetListen( ([
    "default" : "Sounds of all kinds can be heard from all directions.",
]) );
    SetInventory( ([
    ARGOTH_NPC + "guard.c" : 1,
    ARGOTH_NPC + "soldier.c" : 3,
]) );
}
