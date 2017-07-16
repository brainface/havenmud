/*  A road leading to the Frost Marches */

/* New rooms added to enhance change    */
/* between the FrostMarchRoad and the   */
/* Barian Jungle done by Sev 2/4/99     */


#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static int XPosition, YPosition;
static void SetupRoom(int x, int y);

static void create(int x, int y) {
    string n, s;
    string e, nw;
    SetNoReplace(1);
    room::create();
    XPosition = x;
    YPosition = y;

    if (y == -10) {
          s = BARIA_VIRTUAL + "jungle/-10,10";
    }
    else {
        s = "frostmarchrd/" + (x) + "," + (y-1);
    }
    if (y < 60) {
        n = "frostmarchrd/" + (x) + "," + (y +1);
            }
    if (y == 60) {
            n = FROSTMARCHES_TOWNS + "keryth/room/trail1";
    }
    /* Switch from Arcanith and changed from 38 */
    if (y == 49) {
            e = GUROV_VIRTUAL "gurovrd/-40,0";
    }
    if (y == 18) {
          nw = FROSTMARCHES_VIRTUAL + "durgorothroad/0,0";
    }
    if (y == 24) {
        e = FROSTMARCHES_AREAS + "inn/room/entrance";
    }
    
    /* Switched from Gurove */ 
    if (y == 30) {
         e = FROSTMARCHES_TOWNS + "arcanith/room/path1";
    }
    if (y == 35) {
            e = FROSTMARCHES_AREAS + "caves/room/roomo1";
    }
    if (n) AddExit("north", n);
    if (nw) AddExit("northwest", nw);
    if (e) AddExit("east", e);
    if (s) AddExit("south", s);
    SetShort("a cold road through the Western Wastes");
    SetClimate("arctic");
    SetDomain("FrostMarches");
    SetupRoom(x, y);
}

static void SetupRoom(int x, int y) {
    string long;
    mapping items = ([ ]), inv = ([ ]), itemadj = ([ ]);
    long = "The road winds through the Western Wastes to the north and "
    "south. To the north the air becomes cooler and the clouds seem more "
    "apt to dump tons of snow than to give a friendly spring shower. "; 
    items = ([
      ({"steam"}) : "Billowing white condensation rises from the jungle.",
      ({"clouds","cloud"}) : "White puffy clouds in the sky cruise "
      "to the speed of the wind.",
      ({"path"}) : "The path leads north into the Western Wastes and "
      "south into the jungle.",
      ({"road"}) : "A road through the Western Wastes. It stretches "
      "from the vast wastes of its name to the land of "
      "Baria in the south.",
      ({"foothills","foothill","hill","hills"}) :
      "The foothills which this road travels through "
      "are not very large. They are grassy and not "
      "too craggy.",
      ({"jungle"}) : "Far to the south, the Barian Jungles border "
      "can be seen. Steam can be seen coming from its top.",
      ({"ground"}) : "The dirt of the road is very hard and packed "
      "from the many who travel on it.",
      ({"border"}) : "The edge of the jungle is mostly made up of trees.",
      ({"dirt"}) : " Brown, dusty, and if water is added, it will make mud",
    ]);
    itemadj = ([
      "steam" : ({"billowing","white","rising"}),
      "path" : ({"straight","winding","dirt","virtually"}),
      "road" : ({"straight","winding","dirt","virtually"}),
      "jungle" : ({"barian","green","luscious"}),
      "dirt" : ({"brown","dusty","hard","packed"}),
      "clouds" : ({"white","fluffy"}),
    ]);
    if (y == 60) {
        long += "There is some kind of valley to the north. ";
    }
    if (y == 49) {
        long += "To the east lies the Principality of Gurov. ";
    }
    if (y > 0 && y < 3) {
        SetShort("a winding road through the foothills");
        SetClimate("sub-arctic");
        long = "The road winds through foothills and a cool wind "
        "blows from the north. Far to the south, the edge of a "
        "jungle can be seen on the horizon if atop one of these "
        "hills. The ground is hard and the road looks well travelled.";
    }
    if (y < 0 && y >= -5) {
        SetShort("a cool road through the Western Wastes");
        SetClimate("sub-arctic");
        long = "Foothills accompanied by a cool breeze are noticeable "
        "in the north and to the south, the border of a luscious "
        "jungle can be seen. The road leads a straight path towards "
        "the jungle and starts its winding path through the foothills.";
    }
    if (y <= -5 && y >= -8) {
        SetShort("a straight road through the Western Wastes");
        SetClimate("temperate");
        long = "Near the border of the jungle, steam can be "
        "be seen rising from its top. A cool breeze from "
        "the north can be felt where the road stretches far into "
        "the foothills. The road also leads directly into the "
        "jungle to the south.";
        SetSmell( ([ "default" : "The smell of tropical plants are "
            "noticed here." ]) );
    }
    if ( (y == -9) || (y == -10) ) {
        SetShort("a straight road near the jungle");
        SetClimate("temperate");
        long = "The border of a jungle is just to the south "
        "on this road through the Western Wastes. The road "
        "leads directly into the jungle while it stretches "
        "far to the north in a virtually straight path.";
        SetSmell( ([ "default" : "The smell of tropical plants "
            "is strong here." ]) );
        SetListen( ([ "default" : "Chittering can be heard coming from "
            "the jungle." ]) );
    }
    SetLong(long);
    SetItems(items);
    SetInventory(inv);
    SetItemAdjectives(itemadj);
}
