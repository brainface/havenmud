#include <lib.h>
#include "../ungkh.h"

inherit LIB_SENTIENT;

void DoSteal();

string RACE;

static void create() {
  sentient::create();

  switch(random(4)) {
    case 0:
    RACE = "goblin";
    break;

    case 1:
    RACE = "gnoll";
    break;

    case 2:
    RACE = "orc";
    break;

    case 3:
    RACE = "kobold";
    break;

    case 4:
    RACE = "lizardman";
    break;

    }

  SetKeyName("citizen");
  SetId( ({ "ungkh citizen", "citizen", RACE }) );
  SetShort("a citizen of Ungkh");
  SetLong("This " + RACE + " travels through Ungkh, going about his "
          "business.");
  SetLevel(random(15)+1);
  SetRace(RACE);
  SetClass("rogue");
  SetGender("male");
  SetInventory( ([
    ]) );
  SetWander(22);
  SetAction(10, (: DoSteal :));
  }

void DoSteal() {
  object array people = ({ });
  people = filter(all_inventory(environment(this_object())), (: playerp :));

  if(sizeof(people)) {
    int number = random(sizeof(people));
    string person = (people[number]->GetKeyName());
    eventForce("steal money from "+person);
    }
  }
