
/*  entrance.c
 *  The entrance room to the desert crypt.
 *  Vaashan@Haven 9/14/09
 */
#include <lib.h>
#include "../crypt.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  //SetAmbientLight();
  SetClimate("arid");
  SetShort("before a large keep");
  SetDayLong(
     "The sun shines down from above with an unforgiving light, reflecting "
     "brightly off the pale-hued sand. A large fortified keep rises from the "
     "shifting sands here, reaching majestically for the sky with a tower at "
     "each of the four corners of the thick stone walls. Gently arching "
     "upwards, a dome stretches between the spires. A vast gate looms open, "
     "leading inside the keep."
     );
  SetNightLong(
     "The moon hangs low in the sky, which is full of tiny twinkling stars. "
     "A large fortified keep rises from the shifting sands here, reaching "
     "majestically for the sky with a tower at each of the four corners of "
     "the thick stone walls. Gently arching upwards, a dome stretches "
     "between the spires. A vast gate looms open, leading inside the keep."
     );
  SetSmell( ([
    "default" : "The desert air is remarkably clean and crisp.",
    ]) );
  SetListen( ([
    "default" : "Sand shifts and occasionally a deep rumble comes from the "
    "desert sands.",
    ]) );
  SetItems( ([
     ({"light","sunlight"}) : "The light reflects off the sand in a nearly "
       "blinding display.",
     ({"sand","ground","grains","rock"}) : "Countless tiny grains of finely "
     	 "divided rock and mineral particles spread out in all directions.",
     ({"keep","structure"}) : "An expansive and impressive structure of "
     	 "finely crafted stone.",
     ({"tower","towers","spire","spires"}) : "Imposing, crenellated "
     	 "structures dominate each corner of the keep, providing good "
     	 "visibility to anyone looking out over the desert expanse.",
     ({"dome","roof"}) : "A gentle curve of stone covers the roof of the "
     	 "keep, a section seems to be cut out to allow sunlight into some sort "
     	 "of central area.",
     ({"stars"}) : "Far above, the stars twinkle coldly in the night sky. ",
     ({"wall","walls"}) : "Closely fitted blocks of a light colored stone "
     	 "make up the walls of this keep.",
     ({"gate"}) : "A large gate, wide and tall enough for two men on camels "
     	 "to pass through at the same time.",
     ({"desert"}) : (:GetLong:),
    ]) );
  SetItemAdjectives( ([
     "light" : "unforgiving",
     "sand" : ({"pale-hued","shifting"}),
     "keep" : ({"fortified","majestic","domed","large"}),
     "tower" : ({"imposing","crenellated"}),
     "dome" : ({"curving","gently"}),
     "stars" : "twinkling",
     "wall" : ({"thick","stone"}),
     "gate" : "vast",
     ]) );
  SetEnters( ([
     "gate" : CRYPT_ROOM + "gate",
     ]) );
}