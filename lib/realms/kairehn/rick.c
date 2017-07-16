#include <lib.h>
inherit LIB_NPC;

int eventRickroll(int num);
int lies = 0;

string *commitment = ({
        "dance",
	"speak we're no strangers to love",
	"speak you know the rules, and so do I",
	"speak a full commitment's what I'm thinking of",
	"speak you wouldn't get this from any other guy",
	"speak never gonna give you up",
	"speak never gonna let you down",
	"speak never gonna run around and desert you",
	"speak never gonna make you cry",
	"speak never gonna say goodbye",
	"speak never gonna tell a lie and hurt you",
        });

static void create() {
  ::create();
  SetKeyName("Rick");
  SetId( ({ "rick" }) );
  SetShort("Rick Astley");
  SetLong("He's never going to give you up.");
  SetRace("human");
  SetClass("merchant");
  SetLevel(35);
  SetMorality(100);
  SetGender("male");
  SetLimit(1);
  set_heart_beat(2);
}

void heart_beat() {
        ::heart_beat();
        eventRickroll(lies);
}

int eventRickroll(int num) {
        if (num < sizeof(commitment)) {
         eventForce(commitment[num]);
          lies++;
        }
        else
        {
        	eventDie();
        }
        return lies;
}