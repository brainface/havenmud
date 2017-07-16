// modified version of zeddicus & syra's burlap bag
//  by mahkefel ~ 2010

#include <lib.h>
inherit LIB_TRAP;

static void create() {
  trap::create();
  SetKeyName("birdcage");
  SetId( ({"birdcage","cage"}) );
  SetAdjectives( ({"gilded","bird"}) );
  SetShort("a gilded birdcage");
  SetMass(30);
  SetMaterial("metal");
  SetValue(100);
  SetLong("This is an ornamental birdcage with delicate vines"
    " running up the thin gold-coated bars. You could use it to"
    " 'capture' a bird, or 'look in' it to see what it cages."
  );
  SetEscapeChance(2);
  SetMaxCapture(1);
  SetCanClose(1);
}

int CanCapture (object who, object target) {
  if (target->GetRace() != "bird") {
    (who)->eventPrint("The birdcage is only made for trapping"
      " birds!");
    return 0;
  }
  if ((target)->GetLevel() > 10) {
    (who)->eventPrint("The bird is far too dangerous and wily"
      " to be captured by such a simple trap.");
    return 0;
  }
  else {
    //who->eventPrint(nominative(who) +
    //  " naively flies into the birdcage, and the door slams"
    //  " shut with a clang!");
    return 1;
  }
}

