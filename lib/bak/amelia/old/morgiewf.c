#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("near a dazzling waterfall");
    SetDayLong("This is a grassy meadow near a dazzling wilderness "
        "waterfall. A small stream tumbles, from far overhead, down "
        "over the rock face, bubbling and churning, into a deep pool "
        "of crystal clear water at its base. Many rainbows dance "
        "where the sun hits the fine mist from the falls, which waters "
        "the grass of the meadow and keeps it fresh and soft. The meadow "
        "itself is encircled by a deep coniferous forest that closes it "
        "off from the outside world, creating a private place of "
        "natural beauty.");
    SetNightLong("This is a grassy meadow near a dazzling wilderness "
        "waterfall. A small stream, tumbles, from the shadows far "
        "overhead, down over a rock face, bubbling and churning, into "
        "a deep pool of dark water. The whole meadow is light by the "
        "soft light of the moon overhead, casting everything in an "
        "enchanting pale glow. The meadow itself is encircled by "
        "a deep coniferous forest, creating a dark wall of trees "
        "that seals this private place off from the rest of the world.");
    SetClimate("indoors");
    SetDomain("Valley");
    SetItems( ([
        ({"meadow"}) : "The small meadow is surrounded on 3 sides by "
            "the deep forest, and on the other by a tall rock face. "
            "The grass is fresh and soft, watered daily by the mist "
            "from the falls. It looks like the perfect place to "
            "relax in peace for a while.",
        ({"waterfall"}) : "The small waterfall tumbles down from the "
            "stream above, falling nearly one-hundred feet into a "
            "deep pool. Raindows dance in the mist during the day, "
            "lending it an almost fairy-tale quality.",
		({"stream"}) : "The small stream tumbles down over the rock "
            "face above, forming the waterfall, and then winds away "
            "from the pool off into the forest. Its pleasant burbling "
            "sound is lost in the dull roar of the falls.",
        ({"pool"}) : "A deep pool of crystal clear water, carved over "
            "centuries by the waterfall, and fed by its waters. In the "
            "day one can see nearly to the bottom, though the depth is "
            "hard to determine. No fish swim in the water, and no "
            "plants grow in it, suggesting that it is fed by minerals "
            "seeping up from the ground below.",
        ({"rock face"}) : "The rock face is craggy and weathered, "
            "small plants clinging to clefts here and there, and moss "
            "covering much of the rest, fed by the mist of the fall.",
        ({"rainbow","rainbows"}) : "Beautiful rainbows dance in the "
            "mist of the falls where the sun strikes it, appearing "
            "and dissapearing as the water rushes by.",
        ({"mist","fine mist"}) : "A fine mist is thrown into the air "
            "by the fall of the water.",
        ({"grass"}) : "The grass is fresh, green, and soft. It seems "
            "to beg you to sit on it, lie in it, and generally "
            "frolick about.",
        ({"forest"}) : "The deep forest of firs and maples surrounds "
            "the meadow completely, leaving no gap except where the "
            "stream pierces its line and winds away. The trees are "
            "green and healthy, their limbs waving softly in the "
            "occasional gusts of wind. The scent of firs fills the "
            "air near the treeline.",
        ]) );
    SetItemAdjectives( ([
        "meadow" : "grassy",
        "waterfall" : ({"dazzling","wilderness"}),
        "stream" : "small",
        "pool" : "deep",
        "forest" : ({"deep","coniferous"}),
        ]) );
    SetListen( ([
        "default" : "The soft thunder of the waterfall is all about.",
        ]) );
    SetSmell( ([
        "default" : "The air is fresh and clear.",
        ]) );
    }

int CanReceive(object ob) {
    if(userp(ob)) {
        if(present("morgoth", this_object()))
            message("system", "%^BOLD%^GREEN%^The trees rustle as someone "
                "approaches the meadow.", find_living("morgoth"));
        if(present("amelia",this_object()))
            message("system", "%^BOLD%^GREEN%^The trees rustle as someone "
                "approaches the meadow.", find_living("amelia"));
        return 1;
        }
    return 1;
    }
