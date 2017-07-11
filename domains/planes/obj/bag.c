//a modified version of Zeddicus@haven's burlap bag 
//edited by Syra@haven 6/98

#include <lib.h>
inherit LIB_TRAP;

static void create() {
  trap::create();
  SetKeyName("bag");
  SetId( ({"bag","trap"}) );
  SetAdjectives( ({"animal","large","burlap"}) );
  SetShort("a large, burlap bag");
  SetMass(15);
  SetMaterial("natural");
  SetValue(4);
  SetLong("It is a large, burlap bag, possible useful for trapping \n"
          "small animals. It is tightly woven to ensure strength, \n"
          "and, judging from its overall appearance, it was made by \n"
          "a skilled burler.");
  SetEscapeChance(5);
  SetMaxCapture(1);
  SetCanClose(1);
}

int CanCapture (object who, object target) {
      if (newbiep(target)) { 
      (who)->eventPrint("Don't pester something so weak!");
      return 0; 
      }
      if ((who)->GetLevel()/4 > (target)->GetLevel()) {
       return 1;
      }
   else {
    who->eventPrint(nominative(who) + 
                " is too powerful for you to capture.");
   return 0;
   }
 }
