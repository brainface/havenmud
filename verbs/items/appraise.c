#include <lib.h>
#include <daemons.h>

inherit LIB_VERB;

mixed can_appraise_obj();
mixed do_appraise_obj(object target);

static void create() {
    verb::create();
    SetVerb("appraise");
    SetRules("OBJ");
    SetErrorMessage("Appraise what?");
    SetHelp("Syntax: appraise OBJ\n\n"
        "A bargaining ability which allows people to figure out "
          "relative worth of an item.  The more experienced you are "
          "at bartering, the better chance you have of correctly judging "
          "the value of an item.\n\n");
}

mixed can_appraise_obj() {
int level;
  string name1, name2;

  if( this_player()->GetLevel() < 6 ) {
    return "You are not experienced enough to appraise the value of items accurately.";
    }
  if( !(this_player()->GetSkillLevel("bargaining")) ) {
    return "You do not have the skills to appraise items.";
    }
        if( 50 > this_player()->GetStaminaPoints() ) {
        return "You are too weary to appraise right now.";
    }
   if(this_player()->GetSleeping()){
   return "You cannot do that while sleeping!";
    }
  return 1;
}

mixed do_appraise_obj(object target) {
  int level;
  int obj1lvl, obj1lvl2;
  string name1;
  string currencytype;
  object caster = this_player();
  name1 = target->GetShort();
  currencytype = CURRENCY_D->GetTownCurrency(this_player()->GetNationality());


   level = caster->GetSkillLevel("bargaining");
   caster->eventPrint("You stare intently at "+name1+".");
   environment(caster)->eventPrint( (string)caster->GetName() +
             " concentrates on " + name1 + ".", caster);
      caster->AddStaminaPoints(-10);
        obj1lvl = (int)target->GetValue();

  if( level < (75 + random(25))) {
        obj1lvl2 = random(obj1lvl);
        obj1lvl2 = obj1lvl2 * currency_rate(currencytype);
        caster->eventPrint("You determine that " + name1 +
        " is worth " + obj1lvl2 + " " + currencytype + ".");

      return 1;
        }
                   /* Return the right answer */
        obj1lvl2 = obj1lvl * currency_rate(currencytype);
        caster->eventPrint("You determine that " + name1 +
        " is worth " + obj1lvl2 + " " + currencytype + ".");

  // mahkefel 2014
  // if your bargaining * 10 > the item's value, return history for gigs.
  if(caster->GetSkillLevel("bargaining") * 10 > target->GetValue()) {
    if (target->GetProperty("history")) {
      caster->eventPrint("You think you've heard about something like this: ");
      caster->eventPrint(target->GetProperty("history"));
    }
  }  
  return 1;
}


