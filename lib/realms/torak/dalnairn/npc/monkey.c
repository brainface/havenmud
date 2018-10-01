// Torak@Haven
// 11/11/12
// fiiiiiiiiiiiiiiiish
//
// turned into orange stealing monkey
// 8/june/2017

#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include <damage_types.h>
#include <size.h>
#include "../dalnairn.h"

inherit LIB_NPC;

void DoSteal();

static void create() {

  string pronoun = "He";
  string objective = "him";
  string possessive = "his";
  ::create();
  if(random(2)) { 
    SetGender("male"); 
    }
  else  {
    SetGender("female");
    pronoun = "She"; 
    objective = "her";
    possessive = "her";
    }

  SetKeyName("monkey");
  SetShort("a hairy grey monkey");
  SetId( ({
    "monkey"
  }) );
  SetAdjectives( ({ 
    "hairy", "grey"
  }) );
  SetLong(
    "This hairy monkey has a black face with a white fringe of hair, "
    "while the overall hair color is mostly grizzled-grey. "
    "Its lanky arms end in little black paws. "
    "A long muscalur tail flicks around in thought. "
  );
  SetMorality(0);
  SetFriends( ({
    "monkey",
  }) );
  SetRace("mammal");
  SetSize(SIZE_SMALL);
  SetClass("animal");
  SetSkill("disorient", 1, 1);
  SetSkill("brawling", 1, 1);
  SetSkill("disarm", 1, 1);
  SetSkill("swimming", 1, 1);
  SetSkill("stealing", 1, 1);
  SetLevel(8 + random(4));
  SetAction(50, (: DoSteal :));
  SetCombatAction(25 + random(6), ({
    "!punch",
    "!disorient",
    "!disarm",
    }) );
  SetInventory( ([
    DAL_OBJ "orange" : 1 + random(3),
  ]) );
  SetProperty("dalnoleave", 1);
  SetWander(5 + random(3) + random(3));
  SetLimit(12);
  AddFood(-2000);
}
void DoSteal() {
  object array people = ({ });
  people = filter(all_inventory(environment(this_object())), (: playerp :));

  if(sizeof(people)) {
    int number = random(sizeof(people));
    string person = (people[number]->GetKeyName());
    eventForce("steal first orange from " + person);
    eventForce("eat my first orange");
//    eventForce("attack " + person);
  }
}
